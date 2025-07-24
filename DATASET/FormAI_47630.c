//FormAI DATASET v1.0 Category: Password management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables
char *username = "chatbot"; // Default username
char *password; // Password entered by user
int password_attempts = 0; // Number of attempts user has made to enter password

// Function to check if entered password is correct
int check_password(char* input) {
    char *correct_password = "Surprise!ThisIsThePassword"; // Hidden password
    if(strcmp(input, correct_password) == 0) { // Password matches
        return 1;
    }
    return 0; // Password does not match
}

// Function to print out password policy
void password_policy() {
    printf("Password must contain:\n");
    printf("- At least 8 characters\n");
    printf("- At least one uppercase letter\n");
    printf("- At least one lowercase letter\n");
    printf("- At least one digit\n");
    printf("- At least one special character (!@#$%%^&*)\n");
}

// Function to validate password according to policy
int validate_password(char *input) {
    char *special_chars = "!@#$%%^&*";
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    
    if(strlen(input) < 8) { // Password too short
        return 0;
    }
    
    for(int i = 0; i < strlen(input); i++) {
        if(isupper(input[i])) {
            has_upper = 1;
        } else if(islower(input[i])) {
            has_lower = 1;
        } else if(isdigit(input[i])) {
            has_digit = 1;
        } else if(strchr(special_chars, input[i]) != NULL) {
            has_special = 1;
        }
    }
    
    if(has_upper && has_lower && has_digit && has_special) { // All criteria met
        return 1;
    } else { // Criteria not met
        return 0;
    }
}

int main() {
    printf("Welcome to Surprise Password Management System!\n");
    printf("Please enter your username: ");
    char input[50];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input
    
    if(strcmp(input, username) != 0) { // Incorrect username
        printf("Invalid username. Exiting...\n");
        exit(0);
    }
    
    printf("Please enter your password: ");
    scanf("%s", password);
    
    while(!check_password(password)) { // Incorrect password
        password_attempts++;
        if(password_attempts >= 3) { // Too many attempts
            printf("Too many attempts. Exiting...\n");
            exit(0);
        }
        printf("Incorrect password. Please try again. (%d attempts remaining)\n", 3 - password_attempts);
        printf("Forgot your password? Use the password policy to create a new one:\n");
        password_policy();
        printf("Enter new password: ");
        scanf("%s", password);
        if(!validate_password(password)) { // New password does not meet policy
            printf("Password does not meet policy. Please try again.\n");
        }
    }
    
    printf("Access granted!\n");
    printf("Do you want to change your password? (y/n): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    
    if(strcmp(input, "y") == 0) { // User wants to change password
        printf("Use the password policy to create a new password:\n");
        password_policy();
        printf("Enter new password: ");
        scanf("%s", password);
        while(!validate_password(password)) { // New password does not meet policy
            printf("Password does not meet policy. Please try again.\n");
            password_policy();
            printf("Enter new password: ");
            scanf("%s", password);
        }
        printf("Password changed!\n");
    }
    
    printf("Thank you for using Surprise Password Management System!\n");
    
    return 0;
}