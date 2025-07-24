//FormAI DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_MAX_LENGTH 1024

// Struct to hold email data
typedef struct {
    char from[200];
    char to[200];
    char cc[200];
    char subject[200];
    char message[EMAIL_MAX_LENGTH];
} Email;

// Function to get user input
void get_input(char *prompt, char *input, int size) {
    printf("%s", prompt);
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
}

// Function to validate email address format
int is_valid_email(char *email) {
    char *at = strchr(email, '@');
    if (!at || at == email || !strstr(at, ".")) {
        return 0;
    }
    for (int i = 0; i < strlen(email); i++) {
        if (!isalnum(email[i]) && email[i] != '@' && email[i] != '.' && email[i] != '-' && email[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    Email email;
    char input[EMAIL_MAX_LENGTH];

    // Get sender email
    do {
        get_input("Enter your email address: ", input, sizeof(input));
        if (!is_valid_email(input)) {
            printf("Invalid email address. Please try again.\n");
        }
    } while (!is_valid_email(input));
    strcpy(email.from, input);

    // Get recipient email
    do {
        get_input("Enter recipient's email address: ", input, sizeof(input));
        if (!is_valid_email(input)) {
            printf("Invalid email address. Please try again.\n");
        }
    } while (!is_valid_email(input));
    strcpy(email.to, input);

    // Get CC email (optional)
    printf("Enter CC email address (optional): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    if (is_valid_email(input)) {
        strcpy(email.cc, input);
    } else {
        email.cc[0] = '\0';
    }

    // Get subject
    get_input("Enter email subject: ", email.subject, sizeof(email.subject));

    // Get message
    printf("Enter email message (max %d characters):\n", EMAIL_MAX_LENGTH);
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    strcpy(email.message, input);

    // Print email details
    printf("\n\nEmail sent!\n");
    printf("From: %s\n", email.from);
    printf("To: %s\n", email.to);
    if (strlen(email.cc) > 0) {
        printf("CC: %s\n", email.cc);
    }
    printf("Subject: %s\n", email.subject);
    printf("Message: %s\n", email.message);

    return 0;
}