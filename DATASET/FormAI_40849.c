//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 20

int main() {

    int numPasswords = 0; // keep track of number of passwords
    char passwords[MAX_PASSWORDS][PASSWORD_LENGTH]; // 2D array to store passwords
    
    // Surprise the user with a funny message
    printf("Welcome to the Password Management System! \n");
    printf("Congratulations on making it this far without getting hacked!\n");
    printf("We are here to protect your passwords so you can spend more time on important things like cat memes and Netflix. \n\n");
    
    // Let the user know how many passwords they can save
    printf("You can save up to %d passwords in this system.\n\n", MAX_PASSWORDS);
    
    // Loop through to get and save passwords
    while (numPasswords < MAX_PASSWORDS) {
        
        // Get user input for password
        char password[PASSWORD_LENGTH];
        printf("Please enter password #%d: ", numPasswords+1);
        fgets(password, PASSWORD_LENGTH, stdin);
        
        // Remove newline from input
        password[strcspn(password, "\n")] = 0;
        
        // Check if password is too short
        if (strlen(password) < 8) {
            printf("Password is too short. Must be at least 8 characters. Please try again. \n\n");
            continue; // go to next iteration of loop
        }
        
        // Check if password is too common
        if (strcmp(password, "password") == 0 || strcmp(password, "12345678") == 0 || strcmp(password, "qwerty") == 0) {
            printf("Password is too common. Please choose a different one. \n\n");
            continue; // go to next iteration of loop
        }
        
        // Save password in array
        strcpy(passwords[numPasswords], password);
        numPasswords++; // increment number of passwords saved
        
        // Surprise user with a random compliment for their password
        int randNum = rand() % 6; // generate random number between 0 and 5
        switch (randNum) {
            case 0:
                printf("Wow, what a strong password!\n\n");
                break;
            case 1:
                printf("You really know how to pick 'em!\n\n");
                break;
            case 2:
                printf("That password is almost as complex as Inception.\n\n");
                break;
            case 3:
                printf("You're password is like a fortress!\n\n");
                break;
            case 4:
                printf("That password is on par with Iron Man's security system.\n\n");
                break;
            case 5:
                printf("You must be a secret agent with a password like that!\n\n");
                break;
            default:
                printf("I am not programmed to give compliments on that password, but I'm sure it's great!\n\n");
        }
        
        // Let the user know how many more passwords they can save
        int passwordsLeft = MAX_PASSWORDS - numPasswords;
        printf("You have %d passwords left to save.\n\n", passwordsLeft);
        
        // Check if user wants to save more passwords
        char choice;
        printf("Do you want to save another password? (y/n): ");
        scanf(" %c", &choice);
        
        // Remove newline from input
        while ((getchar()) != '\n');
        
        // Check if user wants to save another password or exit program
        if (choice == 'y' || choice == 'Y') {
            continue; // go to next iteration of loop
        } else {
            break; // exit loop
        }
    }
    
    // Print out saved passwords
    printf("\n");
    printf("Here are the passwords you have saved:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("Password #%d: %s\n", i+1, passwords[i]);
    }
    
    // Thank the user for using the program
    printf("\nThank you for using our Password Management System and keeping your online identity safe!\n");
    printf("We hope you continue to enjoy your cat memes and Netflix.\n");

    return 0;
}