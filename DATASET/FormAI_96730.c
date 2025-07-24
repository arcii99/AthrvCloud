//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64

char generateRandomChar();
char* generateRandomPassword(int length);

int main() {
    int length;
    printf("Welcome to the Secure Password Generator!\n");
    printf("How long would you like your password to be? ");
    scanf("%d", &length);

    if (length > MAX_PASSWORD_LENGTH) {
        printf("Sorry, the maximum password length is %d.\n", MAX_PASSWORD_LENGTH);
    } 
    else if (length < 1) {
        printf("Sorry, the minimum password length is 1.\n");
    } 
    else {
        char* password = generateRandomPassword(length);
        printf("Your new secure password is:\n\n");
        printf("%s\n", password);
    }

    return 0;
}

char generateRandomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    int charsetLength = strlen(charset);
    int index = rand() % charsetLength;
    return charset[index];
}

char* generateRandomPassword(int length) {
    char* password = (char*) malloc((length + 1) * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomChar();
    }
    password[length] = '\0';
    return password;
}