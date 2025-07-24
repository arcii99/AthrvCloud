//FormAI DATASET v1.0 Category: String manipulation ; Style: configurable
#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 50

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void capitalizeString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ' && i + 1 < len) {
            str[i + 1] = toupper(str[i + 1]);
        }
    }
    str[0] = toupper(str[0]);
}

void replaceCharacters(char* str, char match, char replace) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == match) {
            str[i] = replace;
        }
    }
}

int main() {
    char str[BUFFER_SIZE];
    printf("Enter a string: ");
    fgets(str, BUFFER_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character

    int choice;
    printf("Choose an operation:\n");
    printf("1. Reverse string\n");
    printf("2. Capitalize string\n");
    printf("3. Replace characters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Remove newline character from input buffer

    switch (choice) {
        case 1:
            reverseString(str);
            printf("Reversed string: %s\n", str);
            break;
        case 2:
            capitalizeString(str);
            printf("Capitalized string: %s\n", str);
            break;
        case 3:
            char match, replace;
            printf("Enter a character to replace: ");
            scanf("%c", &match);
            getchar();
            printf("Enter a replace with: ");
            scanf("%c", &replace);
            replaceCharacters(str, match, replace);
            printf("Replaced string: %s\n", str);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}