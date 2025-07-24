//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void generatePassword(int length);

// Main function
int main()
{
    printf("Welcome to the Happy Password Generator!\n");
    printf("What length of password would you like to generate? (Enter an integer between 6 and 20):\n");
    
    int length;
    scanf("%d", &length);
    
    if (length < 6 || length > 20)
    {
        printf("Invalid length! Please enter a value between 6 and 20.\n");
        return 1; // Return error code
    }

    srand(time(NULL)); // Seed random number generator with current time

    printf("Your password is: ");
    generatePassword(length);
    printf("\n");

    printf("Thank you for using the Happy Password Generator! Have a great day!\n");

    return 0; // Return success code
}

// Function to generate password
void generatePassword(int length)
{
    char* password = malloc(sizeof(char) * length); // Allocate memory for password

    for (int i = 0; i < length; i++)
    {
        int randomChar = rand() % 94 + 33; // Generate random ASCII value between 33 and 126
        password[i] = (char)randomChar; // Cast the ASCII value to a char and assign to password array
    }

    printf("%s", password);

    free(password); // Free memory allocated for password
}