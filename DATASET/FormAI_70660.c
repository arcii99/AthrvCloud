//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

    char password[20];  
    int length,lower=0,upper=0,digit=0,special=0,i,strength=0;

    printf("\nEnter your password: ");
    fgets(password,sizeof(password),stdin);
    length=strlen(password)-1;  //excluding the '\n' character
    printf("Password length : %d\n",length);

    for(i=0;i<length;i++) {

        if(islower(password[i]))
            lower++;
        else if(isupper(password[i]))
            upper++;
        else if(isdigit(password[i]))
            digit++;
        else if(ispunct(password[i]))
            special++;
    }

    //Calculating the strength of password based on given criteria
    if(length>=8 && length<=12)
        strength+=10;
    else if(length>12)
        strength+=25;

    if(lower>0 && upper>0)
        strength+=20;

    if(digit>0 && special>0)
        strength+=25;

    if(lower>0 && upper>0 && digit>0 && special>0)
        strength+=20;

    //Printing the strength of the password
    if(strength>=70)
        printf("\n\nThe strength of password is STRONG (%d%%)\n",strength);
    else if(strength>=40 && strength<70)
        printf("\n\nThe strength of password is MEDIUM (%d%%)\n",strength);
    else
        printf("\n\nThe strength of password is WEAK (%d%%)\n",strength);


    return 0;
}