//FormAI DATASET v1.0 Category: Educational ; Style: peaceful
#include<stdio.h>

// This program prints a peaceful message in rainbow colors

int main() 
{
    printf("\033[0;31m"); // set color to red
    printf("Let ");
    printf("\033[0;33m"); // set color to yellow
    printf("us ");
    printf("\033[0;32m"); // set color to green
    printf("all ");
    printf("\033[0;36m"); // set color to cyan
    printf("live ");
    printf("\033[0;34m"); // set color to blue
    printf("in ");
    printf("\033[0;35m"); // set color to magenta
    printf("peace!\n");  
    printf("\033[0;0m"); // reset color to default

    return 0;
}