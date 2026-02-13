// surface area of Sphere (4pi r^2

#include <stdio.h>
const float pi = 3.14;

int main(){
    float r;

    printf("Enter the value of radius of sphere: ");
    scanf("%f",r);
    float SA = 4 * pi * r * r;
    printf("The surface area of sphere with radius %.2f is %.2f\n", r, SA);
    return 0;
}