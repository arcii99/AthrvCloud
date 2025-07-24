//FormAI DATASET v1.0 Category: Email Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT 255

/* This is a structure that holds the email message */
typedef struct email_message {
    char to[101];
    char from[101];
    char subject[101];
    char message_body[1001];
} email_message_t;

/**
 * This function checks if the given string is a valid email address.
 * @param email The email address to check
 * @return 1 if the email is valid, 0 otherwise
 */
int is_email_valid(char* email) {
    int i, at_count = 0, dot_count = 0;

    if (email == NULL || strlen(email) > 100) return 0;

    for (i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@')
            at_count++;
        else if (email[i] == '.')
            dot_count++;
        else if (!isalnum(email[i]) && email[i] != '_' && email[i] != '-')
            return 0;
    }

    return at_count == 1 && dot_count > 0;
}

/**
 * This function prompts the user to enter an email address and validates it.
 * If the email is invalid, it prompts the user to enter it again.
 * @param prompt The prompt to display to the user
 * @return A valid email address
 */
char* get_valid_email(char* prompt) {
    char input[MAX_INPUT], *email = malloc(101);

    do {
        printf("%s", prompt);
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0';
    } while (!is_email_valid(input));

    strcpy(email, input);
    return email;
}

/**
 * This function prompts the user to enter a string with a maximum length.
 * If the input is too long, the function prompts the user to enter it again.
 * @param prompt The prompt to display to the user
 * @param max_length The maximum allowed length of the input
 * @return A string with length less than or equal to max_length
 */
char* get_input_with_max_length(char* prompt, int max_length) {
    char input[MAX_INPUT], *string = malloc(max_length + 1);
    int input_length;

    do {
        printf("%s", prompt);
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = '\0';
        input_length = strlen(input);
    } while (input_length == 0 || input_length > max_length);

    strncpy(string, input, max_length);
    string[max_length] = '\0';
    return string;
}

int main(void) {
    email_message_t email_message;

    printf("Welcome to the C Email Client!\n\n");

    strncpy(email_message.from, "user@example.com", 100);
    strncpy(email_message.to, get_valid_email("Enter recipient email address: "), 100);
    strncpy(email_message.subject, get_input_with_max_length("Enter email subject: ", 100), 100);
    strncpy(email_message.message_body, get_input_with_max_length("Enter email message: ", 1000), 1000);

    printf("\n\nYour email has been sent!\n\n");

    return 0;
}