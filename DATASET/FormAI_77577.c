//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include<stdio.h>
#include<string.h>

int main(){
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int len = strlen(password);
    int score = 0;
    if(len > 8) score++;
    if(len > 12) score++;
    int upper = 0, lower = 0, specialchar = 0, digit = 0;
    for(int i=0; i<len; i++){
        if(password[i]>='A' && password[i]<='Z')
            upper++;
        if(password[i]>='a' && password[i]<='z')
            lower++;
        if(password[i]>='0' && password[i]<='9')
            digit++;
        if(password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='&' || password[i]=='*')
            specialchar++;
    }
    if(upper > 0) score++;
    if(lower > 0) score++;
    if(digit > 0) score++;
    if(specialchar > 0) score++;
    printf("Your password has a strength score of %d out of 6\n", score);
    if(score < 3)
        printf("Weak password! Please try again with a stronger password.\n");
    else if(score == 3 || score == 4)
        printf("Good password! It can be made stronger with a few modifications.\n");
    else
        printf("Excellent password! Your account is now secure.\n");
    return 0;
}