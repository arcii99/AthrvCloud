//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

int main(){
    char password[25];
    int length=0, upper=0, lower=0, digit=0, special=0, i=0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    if(length<8){
        printf("\nPassword length should be at least 8\n");
        return 0;
    }
    for(i=0;i<length;i++){
        if(password[i]>='A' && password[i]<='Z'){
            upper++;
        }
        else if(password[i]>='a' && password[i]<='z'){
            lower++;
        }
        else if(password[i]>='0' && password[i]<='9'){
            digit++;
        }
        else{
            special++;
        }
    }
    if(upper==0){
        printf("\nPassword should contain at least one uppercase letter\n");
        return 0;
    }
    else if(lower==0){
        printf("\nPassword should contain at least one lowercase letter\n");
        return 0;
    }
    else if(digit==0){
        printf("\nPassword should contain at least one digit\n");
        return 0;
    }
    else if(special==0){
        printf("\nPassword should contain at least one special character\n");
        return 0;
    }
    else{
        printf("\nPassword is strong\n");
    }
    return 0;
}