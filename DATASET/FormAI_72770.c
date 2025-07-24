//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if password meets length requirements
int is_length_okay(const char* password);

// Function to check if password contains uppercase letters
int has_uppercase(const char* password);

// Function to check if password contains lowercase letters
int has_lowercase(const char* password);

// Function to check if password contains digits
int has_digits(const char* password);

// Function to check if password contains special characters
int has_special_characters(const char* password);

int main() {
    char password[100];
    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);

    if(is_length_okay(password) && 
       has_uppercase(password) &&
       has_lowercase(password) && 
       has_digits(password) &&
       has_special_characters(password)) {
        printf("Password meets strength requirements!\n");
    } else {
        printf("Password does not meet strength requirements.\n");
    }
    return 0;
}

int is_length_okay(const char* password) {
    if(strlen(password) < 8) {
        printf("Password is too short.\n");
        return 0;
    } else {
        return 1;
    }
}

int has_uppercase(const char* password) {
    int i;
    for(i = 0; password[i] != '\0'; ++i) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    printf("Password does not contain uppercase letters.\n");
    return 0;
}

int has_lowercase(const char* password) {
    int i;
    for(i = 0; password[i] != '\0'; ++i) {
        if(islower(password[i])) {
            return 1;
        }
    }
    printf("Password does not contain lowercase letters.\n");
    return 0;
}

int has_digits(const char* password) {
    int i;
    for(i = 0; password[i] != '\0'; ++i) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    printf("Password does not contain digits.\n");
    return 0;
}

int has_special_characters(const char* password) {
    int i, count = 0;
    char special_characters[] = "~`!@#$%^&*()-_+={}[]\\|;:'\",<.>/?";
    for(i = 0; password[i] != '\0'; ++i) {
        if(strchr(special_characters, password[i])) {
            count++;
        }
    }
    if(count > 0) {
        return 1;
    } else {
        printf("Password does not contain special characters.\n");
        return 0;
    }
}