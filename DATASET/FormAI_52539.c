//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define PASSWORD_LENGTH 16

int main()
{
    char password[PASSWORD_LENGTH+1];    //+1 for null terminator
    srand(time(0));                     //seed the random number generator with current time

    const char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    const char numbers[] = "0123456789";
    const char special_chars[] = "!@#$%^&*()";

    //Generate characters of the password
    for(int i=0; i<PASSWORD_LENGTH; i++)
    {
        int char_type = (rand() % 4);   //0 for upper case, 1 for lower case, 2 for numbers, 3 for special characters

        switch(char_type)
        {
            case 0:
                password[i] = upper_case[rand() % strlen(upper_case)];
                break;
            case 1:
                password[i] = lower_case[rand() % strlen(lower_case)];
                break;
            case 2:
                password[i] = numbers[rand() % strlen(numbers)];
                break;
            case 3:
                password[i] = special_chars[rand() % strlen(special_chars)];
                break;
            default:
                break;
        }
    }

    password[PASSWORD_LENGTH] = '\0';   //add null terminator to the end of the password string

    //Print the generated password
    fprintf(stdout, "Generated password: %s\n",password);

    return 0;
}