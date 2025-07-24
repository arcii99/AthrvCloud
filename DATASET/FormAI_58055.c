//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, num_count=0, upper_count=0, lower_count=0, special_count=0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            num_count++;
        }
        if(isupper(password[i])) {
            upper_count++;
        }
        if(islower(password[i])) {
            lower_count++;
        }
        if(!isdigit(password[i]) && !isalpha(password[i])) {
            special_count++;
        }
    }

    printf("==============================\n");
    printf("Password Strength Analysis\n");
    printf("==============================\n");

   if(length < 6 || length > 20) {
        printf("Error: Password length should be between 6 and 20 characters.\n");
    }
    else if(num_count == 0 || upper_count == 0 || lower_count == 0 || special_count == 0) {
        printf("Error: Password should contain atleast one uppercase, one lowercase, one digit and one special character.\n");
    }
    else {
        printf("Your password is strong!\n");
    }

    return 0;
}