//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: happy
#include <stdio.h>
#include <string.h>

int main(){
    
    char password[50]; // initializing the password array
    int length, uppercaseCount=0, lowercaseCount=0, digitCount=0, symbolCount=0; // initializing variables
    
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your password of choice: ");
    scanf("%s", password); // getting user input
    
    length = strlen(password); // getting the length of the password
    
    for(int i=0; i<length; i++){
        // counting the number of uppercase letters
        if(password[i]>='A' && password[i]<='Z'){
            uppercaseCount++;
        }
        // counting the number of lowercase letters
        else if(password[i]>='a' && password[i]<='z'){
            lowercaseCount++;
        }
        // counting the number of digits
        else if(password[i]>='0' && password[i]<='9'){
            digitCount++;
        }
        // counting the number of symbols
        else{
            symbolCount++;
        }
    }
    
    // checking the strength of the password based on length and types of characters
    if(length>=8 && uppercaseCount>0 && lowercaseCount>0 && digitCount>0 && symbolCount>0){
        printf("Congratulations! Your password is strong!\n");
    }
    else if(length>=8 && (uppercaseCount>0 || lowercaseCount>0) && digitCount>0){
        printf("Your password is medium strength. Please consider adding symbols.\n");
    }
    else{
        printf("Your password is weak. Please consider adding more characters and symbol.\n");
    }
    
    return 0;
}