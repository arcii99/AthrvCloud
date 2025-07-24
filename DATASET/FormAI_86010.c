//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generatePassword(char * password, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; i++) {
        password[i] = charset[rand() % sizeof(charset)];
    }
    password[len] = '\0';
}

int main() {
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please choose the length of the password: ");
    
    int len;
    scanf("%d", &len);
    
    if (len < 8) {
        printf("The password must be at least 8 characters long.\nExiting...\n");
        return 0;
    }

    char * password = (char*)malloc((len+1)*sizeof(char));
    generatePassword(password, len);

    printf("Secure password generated: %s\n", password);
    printf("Thank you for using the Secure Password Generator!\n");

    free(password);
    return 0;
}