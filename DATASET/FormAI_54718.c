//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Initialize variables
    char* password = "my_secret_password";
    char* input_password = malloc(sizeof(char) * 20);

    printf("Enter password: ");
    fgets(input_password, 20, stdin);

    // Check if passwords match
    if (strcmp(input_password, password) == 0) {
        printf("Access granted. Welcome user.\n");
    } else {
        printf("Access denied. Your IP address has been logged. Expect a visit from the authorities soon.\n");
    }

    // Clear password from memory for added security
    memset(input_password, 0, sizeof(char) * 20);
    free(input_password);
    input_password = NULL;

    return 0;
}