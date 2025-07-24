//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main() {

    char password[100];
    int length, upper = 0, lower = 0, number = 0, special = 0;
    
    printf("Welcome to the Surrealist Password Strength Checker.\n");
    printf("Please enter a password to be assessed: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i=0;i<length;i++) {
        if(password[i]>='A' && password[i]<='Z') {
            upper++;
        }
        else if(password[i]>='a' && password[i]<='z') {
            lower++;
        }
        else if(password[i]>='0' && password[i]<='9') {
            number++;
        }
        else {
            special++;
        }
    }

    if(length>=10 && upper>=2 && lower>=2 && number>=2 && special>=2) {
        printf("\nCongratulations! Your password is exceptionally surreal.\n");
    }
    else if(length>=8 && upper>=1 && lower>=1 && number>=1 && special>=1) {
        printf("\nYour password is definitely surreal, but lacks that certain je ne sais quoi.\n");
    }
    else if(length>=6 && upper>=1 && lower>=1 && number>=1) {
        printf("\nYour password is a bit too realistic for our liking. Please try again.\n");
    }
    else {
        printf("\nWe're sorry, but your password is simply too mainstream. Please try again.\n");
    }

    return 0;
}