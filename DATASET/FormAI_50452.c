//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char text[1000], temp[1000];

    printf("Welcome! Please enter some text to process: ");
    fgets(text, 1000, stdin);

    while(1) {
        printf("\nPlease choose a text processing option:\n");
        printf("1. Convert text to all uppercase\n");
        printf("2. Convert text to all lowercase\n");
        printf("3. Reverse the text\n");
        printf("4. Remove all spaces\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(int i = 0; i < strlen(text); i++) {
                    temp[i] = toupper(text[i]);
                }
                printf("\nText converted to all uppercase: %s", temp);
                strcpy(text, temp);
                break;
            case 2:
                for(int i = 0; i < strlen(text); i++) {
                    temp[i] = tolower(text[i]);
                }
                printf("\nText converted to all lowercase: %s", temp);
                strcpy(text, temp);
                break;
            case 3:
                int len = strlen(text);
                for(int i = 0; i < len; i++) {
                    temp[i] = text[len - i - 1];
                }
                printf("\nText reversed: %s", temp);
                strcpy(text, temp);
                break;
            case 4:
                int j = 0;
                for(int i = 0; i < strlen(text); i++) {
                    if(text[i] != ' ') {
                        temp[j] = text[i];
                        j++;
                    }
                }
                printf("\nSpaces removed: %s", temp);
                strcpy(text, temp);
                break;
            case 5:
                printf("\nThank you for using this text processing program!");
                return 0;
            default:
                printf("\nInvalid choice, please try again.");
        }
    }
}