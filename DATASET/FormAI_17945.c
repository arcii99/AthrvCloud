//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[50]; //This is where the user enters the password
    int n, lower=0, upper=0, digit=0, special=0; //Variables to store password length, lower case letter count, upper case letter count, digit count and special character count
 
    printf("Enter a password: "); //Asks the user to enter a password
    scanf("%s", password); //Gets the user input
 
    n = strlen(password); //Calculates the length of the password
 
    for(int i=0; i<n; i++){ //Loop through each character of the password
        if(islower(password[i])){ //Check if the character is a lower case letter
            lower++; //increment lower case count
        }
        else if(isupper(password[i])){ //Check if the character is an upper case letter
            upper++; //increment upper case count
        }
        else if(isdigit(password[i])){ //Check if the character is a digit
            digit++; //increment digit count
        }
        else{ //Otherwise, it must be a special character
            special++; //increment special character count
        }
    }
 
    //Print Stength of Password
    if(n<8 || lower==0 || upper==0 || digit==0 || special==0){
        printf("\nPassword Strength: Weak");
        printf("\nLength: %d", n);
        printf("\nLowercase letters: %d", lower);
        printf("\nUppercase letters: %d", upper);
        printf("\nDigits: %d", digit);
        printf("\nSpecial characters: %d", special);
    }
    else if(n>8 && lower>=1 && upper>=1 && digit>=1 && special>=1){
        printf("\nPassword Strength: Strong");
        printf("\nLength: %d", n);
        printf("\nLowercase letters: %d", lower);
        printf("\nUppercase letters: %d", upper);
        printf("\nDigits: %d", digit);
        printf("\nSpecial characters: %d", special);
    }
 
    return 0;
}