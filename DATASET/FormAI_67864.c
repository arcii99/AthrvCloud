//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A program to generate a secure password fit for two star-crossed lovers */

int main() {
    srand(time(NULL)); // Seed the RNG with the current time
    char password[11]; // Create an array to store the password
    int i;

    printf("O Romeo, O Romeo, what is thy name?\n"); // Prompt for Romeo's name
    char romeoName[20];
    scanf("%s", romeoName);

    printf("How about Juliet? What name shall we give her?\n"); // Prompt for Juliet's name
    char julietName[20];
    scanf("%s", julietName);

    printf("Let us create a password worthy of a love so true.\n"); // Begin password generation

    for(i = 0; i < 3; i++) {
        password[i] = rand() % 26 + 65; // Generate a random uppercase letter
        password[i+3] = rand() % 26 + 97; // Generate a random lowercase letter
        password[i+6] = rand() % 10 + 48; // Generate a random number between 0-9
    }

    password[9] = rand() % 15 + 33; // Generate a random special character from ASCII table
    password[10] = '\0'; // Null-terminate the password

    printf("Behold! Your love-inspired password is:\n");
    printf("%s\n", password);

    printf("Shall we try again? (yes or no)\n"); // Prompt to generate another password

    char anotherTry[5];
    scanf("%s", anotherTry);

    if(strcmp(anotherTry, "yes") ==  0) {
        main(); // Generate another password if requested
    } else {
        printf("Farewell, %s and %s. May your love be eternal.\n", romeoName, julietName); // End program
    }

    return 0;
}