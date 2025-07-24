//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define an array of characters to hold the allowed characters for the password
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789~!@#$%^&*()_+`-={}|[]\\:\";'<>?,./";

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    
    int length; // Variable to hold the desired length of the password
    printf("Enter the desired length of the password: ");
    scanf("%d", &length); // Read in the desired length
    
    char password[length+1]; // Create a character array to hold the password, add 1 for the null terminator
    int i;
    for(i=0; i<length; i++)
    {
        int rand_index = rand() % strlen(allowed_chars); // Get a random index within the allowed character array
        password[i] = allowed_chars[rand_index]; // Set the current character of the password to a random allowed character
    }
    password[length] = '\0'; // Add the null terminator to the end of the password
    
    printf("Your new password is: %s\n", password); // Print out the generated password
    
    return 0;
}