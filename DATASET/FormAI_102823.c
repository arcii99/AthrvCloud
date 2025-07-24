//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Welcome to the Text Transformation Application!\n");
    printf("Please enter some text: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    printf("\nYour input: %s\n", input);

    printf("\nProcessing your input...\n");
    int length = strlen(input);
    for(int i = 0; i < length; i++) {
        if(i % 2 == 0) {
            printf("%c", toupper(input[i]));
        } else {
            printf("%c", tolower(input[i]));
        }
    }
    printf("\n");

    printf("\nThank you for using the Text Transformation Application!\n");

    return 0;
}