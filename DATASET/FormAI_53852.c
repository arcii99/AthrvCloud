//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char input[50];
    printf("Welcome to the Happy ASCII Generator!\n");
    printf("Please enter a word or phrase: ");
    scanf("%s", &input);
    int length = strlen(input);

    printf("\nYour Happy ASCII Art:\n\n", input);

    //Top of the Happy Face
    printf("      ************\n");
    printf("   ****        ****\n");
    printf(" **               **\n");
    printf("**     ");
    for (int i = 0; i < length; i++) {
        printf("%c  ", input[i]);
    }
    printf("   **\n");

    //Bottom of the Happy Face
    printf("**                   **\n");
    printf(" **                 **\n");
    printf("   ****         ****\n");
    printf("      ***********\n\n");

    return 0;
}