//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ephemeral
#include<stdio.h>
#include<string.h>

char pass[20];

int main() {

    printf("Please Enter Your Password:\n");
    scanf("%s", pass);

    int len = strlen(pass); // determining length of the password

    int special_chars = 0, upper_chars = 0, lower_chars = 0, numbers = 0;

    // Checking each character in the password for its type
    for(int i=0; i<len; i++) {
        if(pass[i] >= 48 && pass[i] <= 57) {
            numbers++;
        } else if(pass[i] >= 65 && pass[i] <= 90) {
            upper_chars++;
        } else if (pass[i] >= 97 && pass[i] <= 122) {
            lower_chars++;
        } else {
            special_chars++;
        }
    }

    if(len >= 8 && special_chars >= 1 && upper_chars >= 1 && lower_chars >= 1 && numbers >= 1) {
        printf("Your Password is Strong! Good job!\n");
    } else {
        printf("Your Password is Weak! Please try again!\n");
    }

    return 0;
}