//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Length of the password to be generated */
#define PASSWORD_LENGTH 16

/* Character arrays for each type of character to be used in the password */
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char specialcharacters[] = "!@#$%^&*()_+{}[]|\\/-=?<>.,;:'\"";

/* Function to generate a random integer between two values */
int random_int(int min, int max) {
    /* Seed the random number generator */
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

/* Function to generate the secure password */
char* generate_password() {
    /* Allocate memory for the password string */
    char* password = (char*)malloc(sizeof(char) * (PASSWORD_LENGTH + 1));
    if (password == NULL) {
        printf("Error: Unable to allocate memory for password\n");
        exit(EXIT_FAILURE);
    }
    /* Set all characters to NUL initially */
    memset(password, '\0', sizeof(password));

    /* Generate a random index to determine which type of character should be selected */
    int type_index = random_int(0, 3);

    /* Loop through the password length and add a character of the selected type to the password */
    int i;
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        char character;
        switch (type_index) {
            case 0:
                /* Select a random lowercase character */
                character = lowercase[random_int(0, strlen(lowercase) - 1)];
                break;
            case 1:
                /* Select a random uppercase character */
                character = uppercase[random_int(0, strlen(uppercase) - 1)];
                break;
            case 2:
                /* Select a random number */
                character = numbers[random_int(0, strlen(numbers) - 1)];
                break;
            case 3:
                /* Select a random special character */
                character = specialcharacters[random_int(0, strlen(specialcharacters) - 1)];
                break;
        }
        /* Add the character to the password string */
        password[i] = character;
        /* Generate a new index for the next character type */
        type_index = random_int(0, 3);
    }

    /* Return the generated password */
    return password;
}

/* Main function */
int main() {
    /* Generate the password */
    char* password = generate_password();

    /* Print the password */
    printf("Secure Password: %s\n", password);

    /* Free the allocated memory */
    free(password);

    return 0;
}