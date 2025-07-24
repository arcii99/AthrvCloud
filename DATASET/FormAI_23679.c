//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 32

char *generate_password() {
    char *password = malloc(sizeof(char) * (MAX_LENGTH + 1));
    memset(password, 0, sizeof(char) * (MAX_LENGTH + 1));
    
    int length = rand() % (MAX_LENGTH - 8) + 8; // password should have at least 8 characters
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}:\"<>?,./;'[]\\-=`¬|~";
    int charset_length = strlen(charset);
    
    for (int i = 0; i < length; i++) {
        int index = rand() % charset_length;
        password[i] = charset[index];
    }
    
    return password;
}

int main() {
    srand(time(NULL)); // seeding random number generator
    int num_passwords = 5; // generate 5 passwords
    
    printf("Generating %d secure passwords...\n", num_passwords);
    printf("------------------------------------\n");

    for (int i = 0; i < num_passwords; i++) {
        char *password = generate_password();
        printf("Password %d: %s\n", i+1, password);
        free(password); // free memory to avoid memory leaks
    }

    return 0;
}