//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {

    char password[30];
    printf("Greetings traveller! Please enter a password to test its strength: ");
    scanf("%s", password);

    int length = strlen(password);
    int contains_uppercase = 0, contains_lowercase = 0, contains_digit = 0, contains_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            contains_uppercase = 1;
        }
        if (password[i] >= 'a' && password[i] <= 'z') {
            contains_lowercase = 1;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            contains_digit = 1;
        }
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$') {
            contains_special_char = 1;
        }
    }

    if (length < 8) {
        printf("The password is too weak, my lord. It should contain at least 8 characters.\n");
    }
    else if (contains_uppercase == 0 || contains_lowercase == 0) {
        printf("The password is too weak, my lord. It should contain both uppercase and lowercase letters.\n");
    }
    else if (contains_digit == 0) {
        printf("The password is too weak, my lord. It should contain at least one digit.\n");
    }
    else if (contains_special_char == 0) {
        printf("The password is too weak, my lord. It should contain at least one special character (!, @, # or $).\n");
    }
    else {
        printf("The password is strong enough, my lord. It will keep your treasures safe!\n");
    }

    return 0;
}