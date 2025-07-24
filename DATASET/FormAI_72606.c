//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Shape shifter function
void shapeShifter(int num) {
    switch(num) {
        case 1:
            printf("if(condition) {\n\tstatement;\n}\nelse {\n\tstatement;\n}\n");
            break;
        case 2:
            printf("for(iterator = start_value; iterator < end_value; iterator++) {\n\tstatement;\n}\n");
            break;
        case 3:
            printf("while(condition) {\n\tstatement;\n}\n");
            break;
        case 4:
            printf("do {\n\tstatement;\n} while(condition);\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }
}

int main() {
    int choice;

    printf("Welcome to the Shape Shifter Syntax Generator!\n");
    printf("Please choose a number between 1-4 to see a different syntax shape: \n");
    printf("\t1. if/else\n");
    printf("\t2. for loop\n");
    printf("\t3. while loop\n");
    printf("\t4. do/while loop\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    shapeShifter(choice);

    return 0;
}