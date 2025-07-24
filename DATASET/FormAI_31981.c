//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shocked
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    int len, i, upper_case = 0, lower_case = 0, digits = 0, special_chars = 0;
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    len = strlen(password);

    if(len < 8){
        printf("Error: Password must be at least 8 characters long\n");
        exit(1);
    }

    for(i = 0; i < len; i++){
        if(isupper(password[i])) upper_case++;
        if(islower(password[i])) lower_case++;
        if(isdigit(password[i])) digits++;
        if(strchr("!@#$%^&*()-_+=~`[]{}\\|;:'\",.<>?/", password[i])) special_chars++;
    }

    if(upper_case == 0){
        printf("Error: Password must contain at least one uppercase letter\n");
    }

    if(lower_case == 0){
        printf("Error: Password must contain at least one lowercase letter\n");
    }

    if(digits == 0){
        printf("Error: Password must contain at least one digit\n");
    }

    if(special_chars == 0){
        printf("Error: Password must contain at least one special character\n");
    }

    if(upper_case > 0 && lower_case > 0 && digits > 0 && special_chars > 0){
        printf("Password meets the required strength\n");
    }

    return 0;
}