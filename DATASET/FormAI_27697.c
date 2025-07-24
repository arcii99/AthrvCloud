//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASS_LEN 30

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Characters allowed in the password
    char uppercase[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[26] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[10] = "0123456789";
    char special[8] = "!@#$%^&*";

    // Combine the character sets into one master string
    char all_chars[MAX_PASS_LEN+1];
    strcpy(all_chars, uppercase);
    strcat(all_chars, lowercase);
    strcat(all_chars, numbers);
    strcat(all_chars, special);

    // Generate a random password
    char password[MAX_PASS_LEN+1];
    int i;
    for(i = 0; i < MAX_PASS_LEN; i++)
    {
        password[i] = all_chars[rand() % strlen(all_chars)];
    }
    password[MAX_PASS_LEN] = '\0'; // Null-terminate the string

    // Print the password
    printf("Your secure password is: %s\n", password);

    return 0;
}