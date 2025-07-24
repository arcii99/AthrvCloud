//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char password[100];
    bool has_lower = false, has_upper = false, has_digit = false;
    int length = 0;

    printf("\nEnter your password: ");
    scanf("%s", password);

    for(int i=0; password[i]!='\0'; i++) {
        length++;

        if(islower(password[i])) {
            has_lower = true;
        }

        if(isupper(password[i])) {
            has_upper = true;
        }

        if(isdigit(password[i])) {
            has_digit = true;
        }
    }

    printf("\nPassword length: %d\n", length);

    if(has_lower && has_upper && has_digit && length>=8 && length<=20) {
        printf("\nYour password is strong\n");
    }
    else {
        printf("\nYour password is weak, please choose a stronger one\n");
    }

    return 0;
}