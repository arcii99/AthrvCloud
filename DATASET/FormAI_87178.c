//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024      // Maximum input buffer size
#define MAX_USERNAME_SIZE 50     // Maximum username size
#define MAX_PASSWORD_SIZE 50     // Maximum password size

int main()
{
    char username[MAX_USERNAME_SIZE], password[MAX_PASSWORD_SIZE];
    char input_buffer[MAX_INPUT_SIZE];

    printf("Enter your username: ");
    fgets(input_buffer, MAX_INPUT_SIZE, stdin);
    sscanf(input_buffer, "%s", username);

    printf("Enter your password: ");
    fgets(input_buffer, MAX_INPUT_SIZE, stdin);
    sscanf(input_buffer, "%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
        printf("Access granted.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}