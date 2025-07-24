//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8 //Minimum password length
#define MAX_LENGTH 16 //Maximum password length

//Function to generate random passwords
char *generate_password()
{
    int length = rand() % (MAX_LENGTH - MIN_LENGTH + 1) + MIN_LENGTH; //Generate password length
    char *password = malloc(length + 1); //Allocate memory for password
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+<>?:{[]}"; //Set of characters to choose from
    
    srand(time(NULL)); //Seed the random number generator
    
    for (int i = 0; i < length; i++)
    {
        password[i] = charset[rand() % (sizeof(charset) - 1)]; //Choose a random character from charset and add to password
    }
    
    password[length] = '\0'; //Add null character to end the string
    
    return password;
}

int main()
{
    int num_passwords;
    
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &num_passwords);
    
    for (int i = 0; i < num_passwords; i++)
    {
        char *password = generate_password(); //Call function to generate password
        printf("Password %d: %s\n", i+1, password);
        free(password); //Free memory used by password
    }
    
    return 0;
}