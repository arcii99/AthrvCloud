//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50

bool validate_name(char name[]) {
    int length = strlen(name);

    if (length < 2 || length > 20) {
        printf("Error: Name must be between 2 and 20 characters long.\n");
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            printf("Error: Name must contain only letters and spaces.\n");
            return false;
        }
    }
    
    return true;
}

bool validate_email(char email[]) {
    int length = strlen(email);
    char domain[MAX_LENGTH];
    int domain_pos = -1;

    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            domain_pos = i + 1;
            break;
        }
    }

    if (domain_pos == -1 || domain_pos == length || !isalpha(email[0])) {
        printf("Error: Invalid email format.\n");
        return false;
    }

    int j = 0;
    for (int i = domain_pos; i < length; i++) {
        domain[j++] = email[i];
    }
    domain[j] = '\0';

    if (strcmp(domain, "com") != 0 && strcmp(domain, "org") != 0 && strcmp(domain, "net") != 0) {
        printf("Error: Invalid email domain.\n");
        return false;
    }

    return true;
}

bool validate_password(char password[]) {
    int length = strlen(password);

    if (length < 8) {
        printf("Error: Password must be at least 8 characters long.\n");
        return false;
    }

    bool has_uppercase = false, has_lowercase = false, has_digit = false, has_special = false;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            has_uppercase = true;
        if (islower(password[i]))
            has_lowercase = true;
        if (isdigit(password[i]))
            has_digit = true;
        if (!isalnum(password[i]))
            has_special = true;
    }

    if (!has_uppercase || !has_lowercase || !has_digit || !has_special) {
        printf("Error: Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return false;
    }

    return true;
}

int main() {
    char name[MAX_LENGTH], email[MAX_LENGTH], password[MAX_LENGTH];

    printf("Please enter your name: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Please enter your email: ");
    fgets(email, MAX_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Please enter your password: ");
    fgets(password, MAX_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';

    if (validate_name(name) && validate_email(email) && validate_password(password)) {
        printf("Registration successful!\n");
    } else {
        printf("Registration failed.\n");
    }

    return 0;
}