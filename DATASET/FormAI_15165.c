//FormAI DATASET v1.0 Category: Error handling ; Style: Cryptic
#include <stdio.h>
#define ERROR_1 "You have made a grave mistake!\n"
#define ERROR_2 "Error: invalid input detected."
#define ERROR_3 "Error: unhandled exception found."
#define FATAL_ERROR "Fatal error. Shutting down."
#define PANIC_MODE 1

int main(void) {
    int input, result;

    printf("Enter a number: ");
    result = scanf("%d", &input);
    if (!result) {
        printf(ERROR_1);
        return PANIC_MODE;
    }
 
    if (input > 100) {
        printf(ERROR_2);
        return PANIC_MODE;
    } else if (input < 1) {
        printf(ERROR_3);
        return PANIC_MODE;
    }

    printf("Everything is OK!");

    return 0;
}