//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int length, char password[], int pos)
{
    // Define the character pool for the password
    char pool[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+{}|[]\\:\";',./<>?";
    
    // Check if the length of the password has been reached
    if(pos == length)
    {
        printf("Generated Password: %s\n", password); // Print the generated password
        return; // Exit the function
    }
    
    // Generate a random index to select a character from the pool
    int index = rand() % (sizeof(pool)-1);
    
    // Add the selected character to the password
    password[pos] = pool[index];
    
    // Recursively generate the rest of the password
    generatePassword(length, password, pos+1);
}

int main()
{
    int length;
    char password[50];
    
    // Get user input for the length of the password
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    
    srand(time(NULL)); // Seed the random number generator
    
    // Generate the password
    generatePassword(length, password, 0);
    
    return 0;
}