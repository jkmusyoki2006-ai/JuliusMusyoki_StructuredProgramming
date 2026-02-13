#include <stdio.h>

int main(){
    int x ;
    int y ;
    char operation;
    printf("Enter two numbers to perform operation on:\n");
    printf("x: ");
    scanf("%d",x);
    printf("y: ");
    scanf("%d",y);
    printf("Enter operand to be used i.e +,-,*,%,/: ");
    scanf("%c",operation);

    int result = 0;

    if (operation ==  '+'){
        result = x + y;
        printf("The sum of %d and %d is %d\n", x, y, result);
    }
    if( operation == '-'){
        result = x - y;
        printf("The difference of %d and %d is %d\n", x, y, result);
    }
    if(operation == '*'){
        result = x * y;
        printf("The product of %d and %d is %d\n", x, y, result);
    }
    if(operation == '/'){
        if (y == 0) {
            fprintf(stderr, "Error: division by zero\n");
        } else {
            result = x / y;
            printf("The division of %d by %d is %d\n", x, y, result);
        }
    }
    if(operation == '%'){
        if (y == 0) {
            fprintf(stderr, "Error: modulus by zero\n");
        } else {
            result = x % y;
            printf("The modulus of %d and %d is %d\n", x, y, result);
        }
    }
    else{
        fprintf(stderr, "Unknown operation: %c\n", operation);
    }
    
}