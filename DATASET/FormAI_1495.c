//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function to generate password
char *generatePassword(int length) {
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+/\\<>,.?;:'{}[]|~`";
    char *password = malloc(sizeof(char) * (length + 1));
    srand(time(NULL));
   
    if (password) {
        for (int i = 0; i < length; i++) {
            int index = rand() % strlen(charset);
            password[i] = charset[index];
        }
        password[length] = '\0';
    }
    return password;
}

int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("Length should be greater than zero!");
        return 0;
    }
    char *password = generatePassword(length);
    if (password) {
        printf("Generated password is: %s", password);
        free(password);
    } else {
        printf("Memory allocation error!");
        return 1;
    }
    return 0;
}