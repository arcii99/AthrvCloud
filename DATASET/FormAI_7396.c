//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: lively
#include<stdio.h>
#include<string.h>

int main(){

    char password[50];
    int uppercase=0,lowercase=0,digit=0,specialchar=0,i,length,strength;

    printf("Enter Password to check its strength:\n");
    scanf("%s",password);

    length=strlen(password);

    for(i=0;i<length;i++){
        if(password[i]>='A' && password[i]<='Z')
            uppercase++;
        else if(password[i]>='a' && password[i]<='z')
            lowercase++;
        else if(password[i]>='0' && password[i]<='9')
            digit++;
        else
            specialchar++;
    }

    strength=length+(uppercase*2)+(lowercase*2)+(digit*3)+(specialchar*5);

    printf("Password Strength: %d\n",strength);

    if(strength<=10)
        printf("Password is very weak! Change it!\n");
    else if(strength>10 && strength<=20)
        printf("Password is weak! Try to improve it!\n");
    else if(strength>20 && strength<=30)
        printf("Password is ok! But can be made stronger!\n");
    else if(strength>30 && strength<=40)
        printf("Password is good! Keep it up!\n");
    else
        printf("Password is very strong! Well done!\n");

    return 0;
}