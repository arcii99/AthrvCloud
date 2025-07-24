//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: high level of detail
#include<stdio.h>
#include<string.h>

//function to check password strength
int checkPassword(char password[]){
    int len=strlen(password);
    int caps=0, smalls=0, digits=0, specials=0;

    for(int i=0;i<len;i++){
        if(password[i]>='A' && password[i]<='Z'){
            caps++;
        }
        else if(password[i]>='a' && password[i]<='z'){
            smalls++;
        }
        else if(password[i]>='0' && password[i]<='9'){
            digits++;
        }
        else{
            specials++;
        }
    }

    if(len>=8 && len<=16 && caps>0 && smalls>0 && digits>0 && specials>0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char userPassword[100];
    printf("Enter password to check strength: ");
    scanf("%s", userPassword);

    int strength=checkPassword(userPassword);

    if(strength==1){
        printf("Password is strong!");
    }
    else{
        printf("Password is weak! Please enter a strong password.");
    }

    return 0;
}