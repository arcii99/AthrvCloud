//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
    char password[20];
    int len, upper=0, lower=0, digit=0, special=0, score=0;

    printf("Enter your password: ");
    scanf("%s", password);

    len = strlen(password); // finding length of password

    for(int i=0;i<len;i++){ // checking password for uppercase, lowercase, digits and special characters
        if(isupper(password[i])) upper++;
        else if(islower(password[i])) lower++;
        else if(isdigit(password[i])) digit++;
        else special++;
    }

    if(len<6) score=20; // score calculation based on length of password
    else if(len>=6 && len<=8) score=40;
    else score=80;

    if(upper>0 && lower>0) score+=20; // score calculation based on presence of uppercase and lowercase letters
    if(digit>0) score+=20; // score calculation based on presence of digits
    if(special>0) score+=20; // score calculation based on presence of special characters

    if(score>=90) printf("Password strength is Strong"); // categorizing password into Strength Categories
    else if(score>=60 && score<90) printf("Password strength is Medium");
    else printf("Password strength is Weak");

    return 0;
}