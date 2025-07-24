//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int length, num, cap, sym, i;
    char password[100];
    srand(time(0));
    
    // Taking user input for password criteria
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    printf("Include numbers? (0 for No, 1 for Yes): ");
    scanf("%d", &num);
    printf("Include capital letters? (0 for No, 1 for Yes): ");
    scanf("%d", &cap);
    printf("Include symbols? (0 for No, 1 for Yes): ");
    scanf("%d", &sym);
    
    // Generating password based on criteria
    for(i=0; i<length; i++)
    {
        int random = rand() % 4;
        
        if(random == 0 && num == 1)
        {
            password[i] = rand() % 10 + 48; // ASCII code for numbers (48-57)
        }
        else if(random == 1 && cap == 1)
        {
            password[i] = rand() % 26 + 65; // ASCII code for capital letters (65-90)
        }
        else if(random == 2 && sym == 1)
        {
            password[i] = rand() % 15 + 33; // ASCII code for symbols (33-47)
        }
        else
        {
            password[i] = rand() % 26 + 97; // ASCII code for lower case letters (97-122)
        }
    }
    
    // Printing the generated password
    printf("Your secure password is: %s", password);
    
    return 0;    
}