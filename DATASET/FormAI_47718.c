//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Seed the random number generator with current time
    int length;

    printf("Enter the size of the password: ");
    scanf("%d", &length);

    char password[length+1]; // Initialize a character array to store the password

    for (int i = 0; i < length; i++) {
        int choice = rand() % 3;

        switch (choice) {
            case 0:
                password[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
                break;
            case 1:
                password[i] = rand() % 26 + 'A'; // Generate a random uppercase letter
                break;
            case 2:
                password[i] = rand() % 10 + '0'; // Generate a random digit
                break;
        }
    }

    password[length] = '\0'; // Terminate the string with null character

    printf("The generated password is: %s", password);

    return 0;
}