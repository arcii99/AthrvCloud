//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char message[100] = "Hail, brave knight!";
    char new_message[100];
    int choice;

    printf("Welcome to the medieval message editor!\n\n");
    printf("Your message is: %s\n\n", message);

    // Options menu
    printf("What would you like to do?\n");
    printf("1. Add a title of respect\n");
    printf("2. Remove the knight's name\n");
    printf("3. Replace a word with another\n");
    printf("4. Convert message to all caps\n");
    printf("5. Convert message to all lowercase\n");
    printf("6. Encrypt message with a shift cipher\n");
    printf("7. Decrypt message with a shift cipher\n");
    printf("8. Exit\n");

    // User's choice
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Add title of respect
            printf("\nEnter the knight's name: ");
            char knight_name[20];
            scanf("%s", knight_name);
            strcat(new_message, knight_name);
            strcat(new_message, ", ");
            strcat(new_message, message);
            printf("\n%s\n", new_message);
            break;

        case 2: // Remove knight's name
            char *space;
            space = strchr(message, ' ');
            strcpy(new_message, (space + 1));
            printf("\n%s\n", new_message);
            break;

        case 3: // Replace word with another
            char search_word[20], replace_word[20];
            printf("\nEnter the word you want to replace: ");
            scanf("%s", search_word);
            printf("Enter the word you want to replace it with: ");
            scanf("%s", replace_word);
            char *word;
            word = strtok(message, " ");
            while (word != NULL) {
                if (strcmp(word, search_word) == 0) {
                    strcat(new_message, replace_word);
                    strcat(new_message, " ");
                } else {
                    strcat(new_message, word);
                    strcat(new_message, " ");
                }
                word = strtok(NULL, " ");
            }
            printf("\n%s\n", new_message);
            break;

        case 4: // Convert to all caps
            for (int i = 0; i < strlen(message); i++) {
                new_message[i] = toupper(message[i]);
            }
            printf("\n%s\n", new_message);
            break;

        case 5: // Convert to all lowercase
            for (int i = 0; i < strlen(message); i++) {
                new_message[i] = tolower(message[i]);
            }
            printf("\n%s\n", new_message);
            break;

        case 6: // Encrypt with shift cipher
            int key;
            printf("\nEnter encryption key (1-25): ");
            scanf("%d", &key);
            for (int i = 0; i < strlen(message); i++) {
                if (message[i] >= 'a' && message[i] <= 'z') {
                    new_message[i] = 'a' + ((message[i] - 'a' + key) % 26);
                } else if (message[i] >= 'A' && message[i] <= 'Z') {
                    new_message[i] = 'A' + ((message[i] - 'A' + key) % 26);
                } else {
                    new_message[i] = message[i];
                }
            }
            printf("\n%s\n", new_message);
            break;

        case 7: // Decrypt with shift cipher
            int decrypt_key;
            printf("\nEnter decryption key (1-25): ");
            scanf("%d", &decrypt_key);
            for (int i = 0; i < strlen(message); i++) {
                if (message[i] >= 'a' && message[i] <= 'z') {
                    new_message[i] = 'a' + ((message[i] - 'a' - decrypt_key + 26) % 26);
                } else if (message[i] >= 'A' && message[i] <= 'Z') {
                    new_message[i] = 'A' + ((message[i] - 'A' - decrypt_key + 26) % 26);
                } else {
                    new_message[i] = message[i];
                }
            }
            printf("\n%s\n", new_message);
            break;

        case 8: // Exit
            printf("\nFarewell, brave knight!\n");
            break;

        default: // Invalid input
            printf("\nInvalid input. Please try again.\n");
            break;
    }

    return 0;
}