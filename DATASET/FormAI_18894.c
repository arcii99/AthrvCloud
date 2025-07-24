//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ken Thompson
#include<stdio.h>
#include<string.h>

void main(){
    char password[20];
    int length, digit=0, upper=0, lower=0, special=0;
    printf("Enter the password: ");
    scanf("%s", password);
    length = strlen(password);
    for(int i=0; i<length; i++){
        if(password[i]>47 && password[i]<58){
            digit ++;
        }
        else if(password[i]>64 && password[i]<91){
            upper ++;
        }
        else if(password[i]>96 && password[i]<123){
            lower ++;
        }
        else{
            special ++;
        }
    }
    if(length>=8 && digit>=1 && upper>=1 && lower>=1 && special>=1){
        printf("Strong Password");
    }
    else if(length>=6 && digit>=1 && upper>=1 && lower>=1 && (special==0 || special==1)){
        printf("Medium Password");
    }
    else{
        printf("Weak Password");
    }
}