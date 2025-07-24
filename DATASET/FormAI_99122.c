//FormAI DATASET v1.0 Category: Data validation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char phone[20];
    int valid = 0; // assume input is invalid until proven otherwise
    printf("Enter a phone number (format: (xxx) xxx-xxxx): ");
    fgets(phone, 20, stdin); // read user input

    // check that input is exactly 14 characters long (including parentheses and hyphen)
    if(strlen(phone) != 14) {
        printf("Invalid phone number\n");
        return 0;
    }

    // check that each character is a digit, parentheses, or hyphen
    for(int i = 0; i < strlen(phone) - 1; i++) {
        if(!isdigit(phone[i]) && phone[i] != '(' && phone[i] != ')' && phone[i] != ' ') {
            printf("Invalid phone number\n");
            return 0;
        }
    }

    // check that parentheses and hyphen are in the correct positions
    if(phone[0] != '(' || phone[4] != ')' || phone[5] != ' ' || phone[9] != '-') {
        printf("Invalid phone number\n");
        return 0;
    }

    // if all tests passed, then input is valid
    printf("Valid phone number. Thanks!\n");
    return 0;
}