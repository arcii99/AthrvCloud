//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <string.h>
#define MAX_CHARS 1000

void toUpperCase(char *str) {
    int i;
    int len = strlen(str);
    for(i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            // Convert lowercase to uppercase
            str[i] = str[i] - 32;
        }
    }
}

void toLowerCase(char *str) {
    int i;
    int len = strlen(str);
    for(i=0; i<len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            // Convert uppercase to lowercase
            str[i] = str[i] + 32;
        }
    }
}

void replace(char *str, char old_char, char new_char) {
    int i;
    int len = strlen(str);
    for(i=0; i<len; i++) {
        if(str[i] == old_char) {
            // Replace old character with new character
            str[i] = new_char;
        }
    }
}

void removeSpaces(char *str) {
    int i,j;
    int len = strlen(str);
    for(i=0; i<len; i++) {
        if(str[i] == ' ') {
            // Shift characters left to replace spaces
            for(j=i; j<len; j++) {
                str[j] = str[j+1];
            }
            i--;
            len--;
        }
    }
}

void swapCase(char *str) {
    int i;
    int len = strlen(str);
    for(i=0; i<len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            // Convert lowercase to uppercase
            str[i] = str[i] - 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') {
            // Convert uppercase to lowercase
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char str[MAX_CHARS];
    int choice;
    printf("Enter a string: ");
    fgets(str, MAX_CHARS, stdin);
    printf("\nPlease choose an option:\n");
    printf("1. Convert to uppercase\n");
    printf("2. Convert to lowercase\n");
    printf("3. Replace character\n");
    printf("4. Remove spaces\n");
    printf("5. Swap case\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            toUpperCase(str);
            printf("Result: %s", str);
            break;
        case 2:
            toLowerCase(str);
            printf("Result: %s", str);
            break;
        case 3:
            char old_char, new_char;
            printf("Enter character to replace: ");
            getchar(); // Consume newline character
            scanf("%c", &old_char);
            printf("Enter new character: ");
            getchar(); // Consume newline character
            scanf("%c", &new_char);
            replace(str, old_char, new_char);
            printf("Result: %s", str);
            break;
        case 4:
            removeSpaces(str);
            printf("Result: %s", str);
            break;
        case 5:
            swapCase(str);
            printf("Result: %s", str);
            break;
        default:
            printf("Invalid choice");
            break;
    }
    return 0;
}