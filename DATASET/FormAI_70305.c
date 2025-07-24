//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: genious
#include<stdio.h>
#include<string.h>

int main(){
    char password[50];
    int length, upper=0, lower=0, digit=0, special=0;

    printf("Enter the password: ");
    scanf("%s", &password);

    length = strlen(password);

    for(int i=0;i<length;i++){
        if(password[i]>='A' && password[i]<='Z') upper++;
        else if(password[i]>='a' && password[i]<='z') lower++;
        else if(password[i]>='0' && password[i]<='9') digit++;
        else special++;
    }

    if(length>=8 && length<=20 && upper>0 && lower>0 && digit>0 && special>0){
        printf("The password is strong!");
    }
    else if(length>=8 && length<=20 && upper>0 && lower>0 && digit>0 && special==0){
        printf("The password is moderately strong.");
        printf("\nAdd special characters like '@', '$', '*' etc. to make it stronger.");
    }
    else{
        printf("The password is weak.");
        printf("\nPassword Criteria:\nLength : Between 8 to 20 characters\nUppercase letters : Atleast 1\nLowercase letters : Atleast 1\nDigits : Atleast 1\nSpecial characters : Atleast 1");
    }

    return 0;
}