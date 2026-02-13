#include <stdio.h>

int main() {
    int arr[6][4] = {
        {43, 5, 13, 4},
        {47, 23, 0, 9},
        {1, 24, 9, 1},
        {22, 3, 2, 19},
        {6, 2, 31, 9},
        {1, 4, 12,10}
    };

    printf("Array elements are:\n");

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); 
    }

    return 0;
}
