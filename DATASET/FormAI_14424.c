//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_chars, i;
    char password[51] = "";
    srand(time(0));
    
    printf("Welcome to the Secure Password Generator\n");
    printf("Please enter the number of characters you want in your password (maximum 50): ");
    scanf("%d", &num_of_chars); // get input from user
     
    // check if user input is valid
    while (num_of_chars < 1 || num_of_chars > 50)
    {
        printf("Invalid input. Please enter a number from 1 to 50: ");
        scanf("%d", &num_of_chars);
    }
    
    // generate random password
    for (i = 0; i < num_of_chars; i++)
    {
        int random_num = rand() % 94 + 32; // generate random number between 32 and 126 (ASCII table: printable characters)
        password[i] = (char)random_num; // convert random number to character and add it to password
    }
    password[i] = '\0'; // add NULL character at the end to terminate the string
    
    printf("Your secure password is:\n%s\n", password);
    
    return 0;
}