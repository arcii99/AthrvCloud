//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ada Lovelace
/* ***********************************************************
   * Password Strength Checker                               
   * By: Ada Lovelace                                         
   * Description: This program is designed to indicate the 
   *  strength of a password based on specific criteria. 
   *  Password strength is measured on length of password 
   *  as well as a variety of character types included. 
   * ***********************************************************/
   
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, upper, lower, digit, special;
    
    printf("Please enter a password: ");
    fgets(password, 100, stdin);
    
    length = strlen(password) - 1;
    
    // Initialize counters
    upper = 0;
    lower = 0;
    digit = 0;
    special = 0;
    
    for(int i = 0; i < length; i++) {
        if(isupper(password[i])) {
            upper++;
        } else if(islower(password[i])) {
            lower++;
        } else if(isdigit(password[i])) {
            digit++;
        } else {
            special++;
        }
    }
    
    printf("\nThe strength of your password is:\n");
    
    if(length >= 12 && upper >= 1 && lower >= 1 && digit >= 1 && special >= 1) {
        printf("Strong!");
    } else if(length >= 8 && upper >= 1 && lower >= 1 && digit >= 1) {
        printf("Moderate.");
    } else {
        printf("Weak...");
    }
    
    return 0;
}