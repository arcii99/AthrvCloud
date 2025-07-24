//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: funny
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printDivider(){
    printf("\n******************************************************\n");
}

int main(){
    char password[50];
    int length, upper=0, lower=0, digit=0, special=0, strength=0, i;

    printf("Welcome to my Password Strength Checker!\n");
    printDivider();

    printf("Enter your password (maximum of 50 characters): ");
    fgets(password, 50, stdin);
    length = strlen(password) - 1;

    printf("Analyzing your password ...\n");

    for(i=0; i<length; i++){
        if(isupper(password[i])) {
            upper = 1;
        } else if(islower(password[i])) {
            lower = 1;
        } else if(isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    if(upper) strength++;
    if(lower) strength++;
    if(digit) strength++;
    if(special) strength++;

    if(strength == 0){
        printDivider();
        printf("Your password is so weak, it couldn't even break an egg!\n");
        printf("Please try again and make sure you include at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        printDivider();
    } else if(strength == 1){
        printDivider();
        printf("Your password is weak.\n");
        printf("Please try again and make sure you include at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        printDivider();
    } else if(strength == 2){
        printDivider();
        printf("Your password is okay, but could be stronger.\n");
        printf("Consider adding more uppercase letters, lowercase letters, digits, or special characters.\n");
        printDivider();
    } else if(strength == 3){
        printDivider();
        printf("Your password is strong!\n");
        printf("But don't get too comfortable. A skilled hacker could still crack it.\n");
        printDivider();
    } else {
        printDivider();
        printf("Your password is so secure, the CIA would envy you!\n");
        printf("But seriously, how did you come up with that?!\n");
        printDivider();
    }

    return 0;
}