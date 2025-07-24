//FormAI DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Surrealist Password Management Program

void printHeader();
void createPassword(char password[]);
void printPassword(char password[], int passLen);
void savePasswordToFile(char password[], char filename[]);
void loadPasswordFromFile(char password[], char filename[]);
void encryptPassword(char password[], int key);
void decryptPassword(char password[], int key);
int getMenuSelection();
void clearInputBuffer();

int main() {
    char password[100] = "";
    int passLen = 0;

    printHeader();

    int menuSelection = 0;
    while (menuSelection != 5) {
        menuSelection = getMenuSelection();

        switch (menuSelection) {
            case 1:
                createPassword(password);
                passLen = strlen(password);
                printf("\nSurrealist Password: ");
                printPassword(password, passLen);
                break;
            case 2: 
                savePasswordToFile(password, "password.txt");
                printf("\nPassword saved to file.\n");
                break;
            case 3:
                loadPasswordFromFile(password, "password.txt");
                passLen = strlen(password);
                printf("\nPassword loaded from file: ");
                printPassword(password, passLen);
                break;
            case 4:
                int key;
                printf("\nEnter key for encryption: ");
                scanf("%d", &key);
                encryptPassword(password, key);
                passLen = strlen(password);
                printf("\nEncrypted password: ");
                printPassword(password, passLen);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default: 
                printf("\nInvalid menu option.\n");
                break;
        }
    }

    return 0;
}

void printHeader() {
    printf("Welcome to the Surrealist Password Management Program!\n");
    printf("*******************************************************\n\n");
    printf("1. Create a Surrealist Password\n");
    printf("2. Save Surrealist Password to file\n");
    printf("3. Load Surrealist Password from file\n");
    printf("4. Encrypt Surrealist Password\n");
    printf("5. Exit\n\n");
}

void createPassword(char password[]) {
    printf("\nEnter a phrase to transform into a Surrealist Password: ");
    fgets(password, 100, stdin);

    // Remove newline character from password
    int len = strlen(password);
    if (password[len-1] == '\n') {
        password[len-1] = '\0';
    }

    // Transform password into Surrealist Password
    for (int i = 0; i < len; i++) {
        if (password[i] == ' ') {
            password[i] = '_';
        } else if (password[i] == 'a') {
            password[i] = '@';
        } else if (password[i] >= '0' && password[i] <= '9') {
            password[i] = '!';
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            password[i] += 32;
        }
    }
}

void printPassword(char password[], int passLen) {
    srand(time(NULL));
    for (int i = 0; i < passLen; i++) {
        if (password[i] == '_') {
            printf(" surreal ");
        } else if (password[i] == '@') {
            printf(" meta ");
        } else if (password[i] == '!') {
            printf(" absurdist ");
        } else {
            int randNum = rand() % 5;
            switch (randNum) {
                case 0:
                    printf("existential ");
                    break;
                case 1:
                    printf("dadaist ");
                    break;
                case 2:
                    printf("avant-garde ");
                    break;
                case 3:
                    printf("surrealist ");
                    break;
                case 4: 
                    printf("dream-like ");
                    break;
                default:
                    break;
            }
        }
    }
    printf("\n");
}

void savePasswordToFile(char password[], char filename[]) {
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("\nUnable to write to file.\n");
    } else {
        int len = strlen(password);
        for (int i = 0; i < len; i++) {
            fputc(password[i], fp);
        }
        fclose(fp);
    }
}

void loadPasswordFromFile(char password[], char filename[]) {
    FILE *fp;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nUnable to read file.\n");
    } else {
        int i = 0;
        char c;
        while ((c = fgetc(fp)) != EOF) {
            password[i] = c;
            i++;
        }
        password[i] = '\0';
        fclose(fp);
    }
}

void encryptPassword(char password[], int key) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        password[i] += key;
    }
}

void decryptPassword(char password[], int key) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        password[i] -= key;
    }
}

int getMenuSelection() {
    int selection;
    printf("\nEnter a menu option: ");
    scanf("%d", &selection);
    clearInputBuffer();
    return selection;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}