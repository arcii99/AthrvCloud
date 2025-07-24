//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 12

char* generate_password() {
    char password[LENGTH + 1];
    srand(time(NULL));
    const char* letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* symbols = "!@#$%^&*()-_+=~`[]\\{}|;:',.<>/?";
    const char* numbers = "0123456789";
    
    int i;
    for (i = 0; i < LENGTH; i++) {
        int choice = rand() % 3;
        if (choice == 0) { // select a random letter
            int index = rand() % strlen(letters);
            password[i] = letters[index];
        } else if (choice == 1) { // select a random symbol
            int index = rand() % strlen(symbols);
            password[i] = symbols[index];
        } else if (choice == 2) { // select a random number
            int index = rand() % strlen(numbers);
            password[i] = numbers[index];
        }
    }
    
    password[LENGTH] = '\0';
    
    char* generated_password = (char*)malloc(sizeof(char) * (LENGTH + 1));
    strcpy(generated_password, password);
    return generated_password;
}

int main() {
    char* password = generate_password();
    printf("Your secure password is: %s\n", password);
    free(password);
    return 0;
}