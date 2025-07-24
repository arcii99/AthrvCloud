//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Defining Macros
#define MAX 100

// Defining Functions
int countLowercase(char*);
int countUppercase(char*);
int countDigits(char*);
int countSpecialChars(char*);
int getPasswordStrength(int, int, int, int);

// Main Function
int main(){

    // Local Variables
    char password[MAX];
    int lowercase, uppercase, numbers, specialChars, strength;

    // Taking User Input
    printf("Enter Your Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    // Calculating Password Strength
    lowercase = countLowercase(password);
    uppercase = countUppercase(password);
    numbers = countDigits(password);
    specialChars = countSpecialChars(password);
    strength = getPasswordStrength(lowercase, uppercase, numbers, specialChars);

    // Printing Password Strength Result
    printf("\n");

    if(strength == 4){
        printf("Your Password Strength is Very Strong! :)\n");
    }
    else if(strength == 3){
        printf("Your Password Strength is Strong! :)\n");
    }
    else if(strength == 2){
        printf("Your Password Strength is Moderate! :|\n");
    }
    else if(strength == 1){
        printf("Your Password Strength is Weak! :(\n");
    }
    else{
        printf("Please Enter a Valid Password!\n");
    }

    return 0;
}

// Function to Count Lowercase Characters in a Password
int countLowercase(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(islower(password[i])){
            count += 1;
        }
    }
    return count;
}

// Function to Count Uppercase Characters in a Password
int countUppercase(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(isupper(password[i])){
            count += 1;
        }
    }
    return count;
}

// Function to Count Numeric Digits in a Password
int countDigits(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(isdigit(password[i])){
            count += 1;
        }
    }
    return count;
}

// Function to Count Special Characters in a Password
int countSpecialChars(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(!isalnum(password[i])){
            count += 1;
        }
    }
    return count;
}

// Function to Get Password Strength
int getPasswordStrength(int lowercase, int uppercase, int numbers, int specialChars){
    int strength = 0;

    if(lowercase >= 1 && uppercase >= 1 && numbers >= 1 && specialChars >= 1){
        strength = 4;
    }
    else if(lowercase >= 1 && uppercase >= 1 && numbers >= 1){
        strength = 3;
    }
    else if(lowercase >= 1 && uppercase >= 1){
        strength = 2;
    }
    else if(lowercase >= 1 && numbers >= 1){
        strength = 2;
    }
    else if(uppercase >= 1 && numbers >= 1){
        strength = 2;
    }
    else if(lowercase >= 1 || uppercase >= 1){
        strength = 1;
    }
    else{
        strength = 0;
    }

    return strength;
}