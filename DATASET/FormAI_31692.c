//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: excited
#include<stdio.h>
#include<string.h>

int main(void){

    printf("Welcome to the exciting world of Password Strength Checker!!!\n\n");
    printf("Enter your password below: ");

    char password[50];
    fgets(password, 50, stdin);

    int length = strlen(password);
    int score = 0;

    if (length >= 8){
        score++;
        printf("Length check passed! (+1 score)\n");
    }
    else
        printf("Password should be at least 8 characters long.\n");

    int uppercase_flag = 0;
    int lowercase_flag = 0;
    int digit_flag = 0;
    int special_char_flag = 0;

    for (int i = 0; i < length; i++){

        if (password[i] >= 'A' && password[i] <= 'Z' && !uppercase_flag){
            score++;
            uppercase_flag = 1;
            printf("Uppercase character check passed! (+1 score)\n");
        }
        else if (password[i] >= 'a' && password[i] <= 'z' && !lowercase_flag){
            score++;
            lowercase_flag = 1;
            printf("Lowercase character check passed! (+1 score)\n");
        }
        else if (password[i] >= '0' && password[i] <= '9' && !digit_flag){
            score++;
            digit_flag = 1;
            printf("Digit check passed! (+1 score)\n");
        }
        else if ((password[i] >= '!' && password[i] <= '/') ||
                 (password[i] >= ':' && password[i] <= '@') ||
                 (password[i] >= '[' && password[i] <= '`') ||
                 (password[i] >= '{' && password[i] <= '~') && !special_char_flag){
            score++;
            special_char_flag = 1;
            printf("Special character check passed! (+1 score)\n");
        }

    }

    printf("\n");

    switch(score){

        case 0:
            printf("Password strength: EXTREMELY WEAK!\n");
            break;
        case 1:
            printf("Password strength: VERY WEAK!\n");
            break;
        case 2:
            printf("Password strength: WEAK!\n");
            break;
        case 3:
            printf("Password strength: STRONG!\n");
            break;
        case 4:
            printf("Password strength: VERY STRONG!\n");
            break;
        default:
            printf("Error: Invalid score detected!\n");

    }

    return 0;

}