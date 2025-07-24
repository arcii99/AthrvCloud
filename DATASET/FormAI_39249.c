//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random password */
void generatePassword(char *password, int length) {
    int i;
    for (i = 0; i < length; i++) {
        int type = rand() % 3;
        if (type == 0) {  // Generate a random uppercase letter
            password[i] = 'A' + rand() % 26;
        } else if (type == 1) {  // Generate a random lowercase letter
            password[i] = 'a' + rand() % 26; 
        } else {  // Generate a random digit
            password[i] = '0' + rand() % 10;
        }
    }
    password[length] = '\0';  // Add null character to the end of the password
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    if (length <= 0) {
        printf("Invalid length\n");
        return 1;
    }

    char password[length+1];
    generatePassword(password, length);
    printf("Your secure password is: %s\n", password);

    return 0;
}