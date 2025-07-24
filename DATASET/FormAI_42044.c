//FormAI DATASET v1.0 Category: modern Encryption ; Style: happy
#include <stdio.h>
#include <string.h>

char* encrypt(char* plain_text, int key) {
    int length = strlen(plain_text);
    char* encrypted_text = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        encrypted_text[i] = (char)((int)plain_text[i] + key);
    }

    return encrypted_text;
}

int main() {
    printf("Welcome to our happy encryption program!\n");
    printf("Please enter your message: ");

    // Get user input
    char input[100];
    fgets(input, 100, stdin);

    // Get encryption key
    int key;
    printf("Please enter a positive integer encryption key: ");
    scanf("%d", &key);

    // Encrypt message
    char* encrypted_message = encrypt(input, key);

    // Print encrypted message
    printf("Your encrypted message is: %s\n", encrypted_message);

    // Free up memory
    free(encrypted_message);

    printf("Thank you for using our program. Have a great day!\n");
    
    return 0;
}