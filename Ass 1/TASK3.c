#include <stdio.h>
#include <string.h>

int main(void) {
    char str[256];

    printf("Enter a string: ");
    /* Read a full line (including spaces) up to newline */
    if (scanf("%255[^\\n]", str) != 1) {
        /* If scanf didn't read (e.g. input was empty), fall back to fgets */
        if (fgets(str, sizeof str, stdin) == NULL) {
            str[0] = '\0';
        } else {
            /* remove trailing newline if present */
            size_t len = strcspn(str, "\n");
            str[len] = '\0';
        }
    }

    printf("You entered: %s\n", str);
    printf("Length: %zu\n", strlen(str));

    return 0;
}


