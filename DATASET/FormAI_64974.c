//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>

int main() {
    char password[50];
    int length, i, uppercase, lowercase, number, special_char;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);
    uppercase = lowercase = number = special_char = 0;
    
    for(i=0; i<length; i++){
        if(password[i]>='A' && password[i]<='Z'){
            uppercase++;
        }else if(password[i]>='a' && password[i]<='z'){
            lowercase++;
        }else if(password[i]>='0' && password[i]<='9'){
            number++;
        }else if((password[i]>=33 && password[i]<=47) || (password[i]>=58 && password[i]<=64) || (password[i]>=91 && password[i]<=96) || (password[i]>=123 && password[i]<=126)){
            special_char++;
        }
    }
    // Password Strength Criteria
    if(length >= 8 && uppercase >= 1 && lowercase >= 1 && number >= 1 && special_char >= 1){
        printf("Great! Your password is Strong.");
    }else if(length >= 8 && ((uppercase >= 1 && lowercase >= 1) || (lowercase >= 1 && number >= 1) || (number >= 1 && special_char >= 1))){
        printf("Good! Your password is Moderate.");
    }else{
        printf("Weak! Your password should contain 8 or more characters, a combination of uppercase/lowercase letters, numbers and special characters.");
    }
    
    return 0;
}