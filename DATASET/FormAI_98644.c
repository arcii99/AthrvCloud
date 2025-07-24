//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>
 
int main()
{
    char pwd[100];
 
    int upper_count = 0, lower_count = 0, digit_count = 0, spec_char_count = 0;
    int len, i;
 
    printf("Enter password : ");
    scanf("%s", pwd);
 
    len = strlen(pwd);
 
    if (len < 8)
    {
        printf("Password is too short. It should be a minimum of 8 characters.\n");
        return 0;
    }
 
    for (i = 0; i < len; i++)
    {
        if (pwd[i] >= 'A' && pwd[i] <= 'Z')
            upper_count++;
        else if (pwd[i] >= 'a' && pwd[i] <= 'z')
            lower_count++;
        else if (pwd[i] >= '0' && pwd[i] <= '9')
            digit_count++;
        else
            spec_char_count++;
    }
 
    if (upper_count == 0 || lower_count == 0 || digit_count == 0 || spec_char_count == 0)
    {
        printf("Password must contain atleast one uppercase letter, one lowercase letter, one digit and one special character.\n");
        return 0;
    }
 
    printf("Password is strong. Good job!\n");
 
    return 0;
}