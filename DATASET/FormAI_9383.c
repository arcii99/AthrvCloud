//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a, b;
    printf("Enter two numbers: ");
    if(scanf("%d %d", &a, &b) != 2){
        printf("Error: Invalid input!\n");
        exit(EXIT_FAILURE); // handle error and exit program
    }
    if(b == 0){
        fprintf(stderr, "Error: Division by zero!\n"); // write error message to standard error stream
        exit(EXIT_FAILURE); // handle error and exit program
    }
    int result = a / b; // divide a by b
    printf("%d divided by %d is %d\n", a, b, result);
    return 0;
}