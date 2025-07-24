//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: active
#include <stdio.h>
#include <string.h>

int main(){
    char password[100];
    int length, lowercase=0, uppercase=0, digits=0, special=0;
    
    printf("Enter Password: ");
    scanf("%s", password);
    
    length = strlen(password);
    
    if(length<8){// Checking if password has at least 8 characters
        printf("Password must have at least 8 characters!\n");
        return 0;
    }
    
    for(int i=0; i<length; i++){
        if(password[i]>='a' && password[i]<='z'){// Checking if password has lowercase letters
            lowercase++;
        }
        
        if(password[i]>='A' && password[i]<='Z'){// Checking if password has uppercase letters
            uppercase++;
        }
        
        if(password[i]>='0' && password[i]<='9'){// Checking if password has digits
            digits++;
        }
        
        if((password[i]<='/' || password[i]>=':' && password[i]<='@' || password[i]>='[' && password[i]<='`' || password[i]>='{' && password[i]<='~')){// Checking if password has special characters
            special++;
        }
    }
    
    if(lowercase==0 || uppercase==0 || digits==0 || special==0){// Checking if password meets the minimum requirement
        printf("Password is weak, it must contain at least one lowercase, one uppercase letter, one digit and one special character!");
        return 0;
    }
    else{
        printf("Password is strong and secure!");
    }
    return 0;
}