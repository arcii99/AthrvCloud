//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
// Romeo and Juliet C Error Handling Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int execution_status_code = 0;
    printf("Enter the password to continue execution: ");
    char password[20];
    fgets(password, 20, stdin); // read user input
    if (strcmp(password, "romeoandjuliet") == 0) {
        printf("Correct Password! Initiating Execution...\n");
    } else {
        printf("Incorrect Password! Execution Denied.\n");
        execution_status_code = 1;
    }
    if (execution_status_code == 0) {
        // code block to randomly generate an error
        srand(time(NULL));
        int random_number = rand() % 4 + 1;
        if (random_number == 1) {
            printf("Execution Status Code: %d\n", execution_status_code);
            printf("Error: Division by zero!\n");
            execution_status_code = 2;
        }
        else if (random_number == 2) {
            printf("Execution Status Code: %d\n", execution_status_code);
            printf("Error: Segmentation Fault!\n");
            execution_status_code += 3;
        }
        else if (random_number == 3) {
            printf("Execution Status Code: %d\n", execution_status_code);
            printf("Error: Invalid Memory Access!\n");
            execution_status_code = 5;
        }
        else {
            printf("Execution Status Code: %d\n", execution_status_code);
            printf("Error: Stack Overflow!\n");
            execution_status_code = 7;
        }
    }
    printf("Execution Completed with Status Code %d\n", execution_status_code);
    return execution_status_code;
}