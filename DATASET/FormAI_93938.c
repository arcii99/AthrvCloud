//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: invasive
#include<stdio.h>
#include<string.h>

int main(){
    char password[20];
    int n, i, digit=0, up_letter=0, low_letter=0, special_char=0;
    printf("Enter a password:\n");
    scanf("%s", password);
    n=strlen(password);
    if(n>=8){
        for(i=0; i<n; i++){
            if(isdigit(password[i])){
                digit=1;
            }
            else if(isupper(password[i])){
                up_letter=1;
            }
            else if(islower(password[i])){
                low_letter=1;
            }
            else{
                special_char=1;
            }
        }
        if(digit==1 && up_letter==1 && low_letter==1 && special_char==1){
            printf("Password is strong\n");
        }
        else{
            printf("Password is not strong\n");
        }
    }
    else{
        printf("Password is weak\n");
    }
    return 0;
}