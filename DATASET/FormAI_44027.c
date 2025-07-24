//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function to generate a secure password */
int generate_password(char *password)
{
    int length = 12; 
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    int charset_length = strlen(charset);

    srand(time(NULL)); 

    for (int i = 0; i < length; i++) 
    {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0'; 

    return 0;
}

/* Main function */
int main()
{
    char password[13]; 

    generate_password(password); 

    printf("The generated password is: %s\n", password);

    return 0;
}