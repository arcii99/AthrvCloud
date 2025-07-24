//FormAI DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>

int main() {
    //Declare variables for numbers to be entered
    int num1, num2, num3;

    //Prompt the user to enter three numbers
    printf("Enter three numbers:\n");

    //Get user input and store in the variables
    scanf("%d %d %d", &num1, &num2, &num3);

    //Print out the numbers in ascending order
    if (num1 <= num2 && num1 <= num3) {
        printf("%d ", num1);
        if (num2 <= num3) {
            printf("%d %d\n", num2, num3);
        } else {
            printf("%d %d\n", num3, num2);
        }
    } else if (num2 <= num1 && num2 <= num3) {
        printf("%d ", num2);
        if (num1 <= num3) {
            printf("%d %d\n", num1, num3);
        } else {
            printf("%d %d\n", num3, num1);
        }
    } else {
        printf("%d ", num3);
        if (num1 <= num2) {
            printf("%d %d\n", num1, num2);
        } else {
            printf("%d %d\n", num2, num1);
        }
    }

    return 0;
}