//FormAI DATASET v1.0 Category: Text processing ; Style: cheerful
#include<stdio.h>
#include<string.h>

int main() {
    printf("Hi there! Let's play with some text processing!\n");
    printf("Enter a string of characters: ");
    char str[100];
    fgets(str, 100, stdin);
    printf("Great choice! Here's what we can do with it:\n");
    printf("1. Count the number of characters in the string\n");
    printf("2. Reverse the string\n");
    printf("3. Convert the string to upper case\n");
    printf("4. Convert the string to lower case\n");
    printf("What would you like to do? (1/2/3/4): ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("The string has %lu characters.\n", strlen(str)-1);
            break;
        case 2:
            printf("The reverse of the string is: ");
            for(int i=strlen(str)-2;i>=0;i--) {
                printf("%c", str[i]);
            }
            printf("\n");
            break;
        case 3:
            printf("The string in upper case is: ");
            for(int i=0;i<strlen(str)-1;i++) {
                printf("%c", toupper(str[i]));
            }
            printf("\n");
            break;
        case 4:
            printf("The string in lower case is: ");
            for(int i=0;i<strlen(str)-1;i++) {
                printf("%c", tolower(str[i]));
            }
            printf("\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid choice (1/2/3/4)\n");
            break;
    }
    printf("Thanks for playing with text processing, bye!\n");
    return 0;
}