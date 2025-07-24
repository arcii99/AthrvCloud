//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    printf("Greetings! I'm your password strength checker, be prepared to keep your stuff protected!\n");
    while(1) {
        printf("Please enter your password (at least 8 characters): ");
        scanf("%s", &password);
        int length = strlen(password);
        if(length < 8) {
            printf("Oops! Your password must contain at least 8 characters. Try again.\n");
            continue;
        }
        int upperCount = 0, lowerCount = 0, numberCount = 0, specialCharCount = 0;
        for(int i = 0; i < length; i++) {
            char c = password[i];
            if(c >= 'A' && c <= 'Z') {
                upperCount++;
            } else if(c >= 'a' && c <= 'z') {
                lowerCount++;
            } else if(c >= '0' && c <= '9') {
                numberCount++;
            } else {
                specialCharCount++;
            }
        }
        if(upperCount < 1 || lowerCount < 1 || numberCount < 1 || specialCharCount < 1) {
            printf("Uh oh! Your password must contain at least one uppercase letter, one lowercase letter, one number and one special character. Try again.\n");
            continue;
        }
        printf("Congratulations! Your password is strong and secure.\n");
        break;
    }
    return 0;
}