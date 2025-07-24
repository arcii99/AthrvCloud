//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: lively
#include <stdio.h> 

int main(void) {

    char input[100];
    printf("Welcome to the C Alien Language Translator.\n");

    while (1) {
        printf("Please enter your phrase in the C Alien language or type 'quit' to exit: ");
        fgets(input, 100, stdin);

        if (strcmp(input, "quit\n") == 0) {
            printf("Thank you for using the C Alien Language Translator. Goodbye!\n");
            break;
        }

        int i = 0;
        while (input[i] != '\0') {
            if (input[i] == 'c') {
                printf("ka");
            } else if (input[i] == 'C') {
                printf("Ka");
            } else if (input[i] == ' ') {
                printf(" ");
            } else {
                printf("%c", input[i]);
            }
            i++;
        }
        
        printf("\n");
    }

    return 0;
}