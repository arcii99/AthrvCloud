//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main()
{
    char password[PASSWORD_LENGTH+1];
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    int charset_length = sizeof(charset) - 1;   
    srand(time(NULL));

    for(int i=0; i<PASSWORD_LENGTH; i++)
    {
        int index = rand() % charset_length;
        password[i] = charset[index];
    }

    password[PASSWORD_LENGTH] = '\0';
    printf("Generated Password: %s\n", password);
    return 0;
}