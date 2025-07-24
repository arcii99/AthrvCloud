//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 16

/* Function to generate a random uppercase letter */
char random_uppercase() {
    return (rand() % 26 + 65);
}

/* Function to generate a random lowercase letter */
char random_lowercase() {
    return (rand() % 26 + 97);
}

/* Function to generate a random digit */
char random_digit() {
    return (rand() % 10 + 48);
}

/* Function to generate a random special character */
char random_special() {
    char special_characters[] = "!@#$%^&*()_+-=[]\\{}|;':\",./<>?";
    return special_characters[rand() % sizeof(special_characters)];
}

/* Main function for generating secure password */
int main() {
    char password[PASSWORD_LENGTH];
    srand(time(0));
    
    /* Generate random characters for the password */
    for(int i = 0; i < PASSWORD_LENGTH; i++) {
        int random_type = rand() % 4;
        switch(random_type) {
            case 0:
                password[i] = random_uppercase();
                break;
            case 1:
                password[i] = random_lowercase();
                break;
            case 2:
                password[i] = random_digit();
                break;
            case 3:
                password[i] = random_special();
                break;
        }
    }
    
    /* Print the generated password */
    printf("Secure Password: %s\n", password);
    return 0;
}