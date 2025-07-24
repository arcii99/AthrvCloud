//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* generatePassword(int length);

int main() {
    srand(time(NULL));
    printf("Welcome to the Happy Password Generator!\n\n");
    int length;
    char password[50];
    char choice;

    do {
        printf("How many characters would you like your password to be? (8-50)\n>");
        scanf("%d", &length);
        while (length < 8 || length > 50) {
            printf("Invalid input. Please enter a number between 8 and 50.\n>");
            scanf("%d", &length);
        }
        printf("Generating happy password...\n");
        strcpy(password, generatePassword(length));
        printf("Your happy password is: %s\n\n", password);

        printf("Would you like to generate another happy password? (Y/N)\n>");
        scanf(" %c", &choice);
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            printf("Invalid input. Please enter Y or N.\n>");
            scanf(" %c", &choice);
        }
    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for using the Happy Password Generator! Have a nice day!\n");
    return 0;
}

char* generatePassword(int length) {
    const char *happyWords[10] = {"love", "sunshine", "happiness", "smile", "laugh", "joy", "peace", "kindness", "bliss", "harmony"};
    char *password = (char*)malloc(sizeof(char) * (length + 1));
    int i, randomIndex;
    for (i = 0; i < length; i++) {
        randomIndex = rand() % 10;
        password[i] = happyWords[randomIndex][rand() % strlen(happyWords[randomIndex])];
    }
    password[length] = '\0';
    return password;
}