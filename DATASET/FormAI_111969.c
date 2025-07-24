//FormAI DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>

int main() {
    int secret_number = 837492;

    printf("Enter a number: ");
    int user_input;
    scanf("%d", &user_input);

    if (user_input == secret_number) {
        printf("Access Granted.\n");
    } else {
        printf("Access Denied.\n");
        return 0;
    }

    printf("Welcome to the Paranoid C Programming Example.\n");
    printf("This program will encrypt any message you input.\n");
    printf("Note: Once a message is encrypted, it cannot be decrypted.\n");
    printf("Only the person with the secret key can decrypt the message.\n\n");

    printf("Enter your message: ");
    char message[1000];
    scanf("%[^\n]s", message);

    srand(time(NULL));
    int key = rand() % 100;

    printf("\nYour encrypted message is: ");
    for (int i = 0; message[i] != '\0'; i++) {
        char character = message[i] + key;
        printf("%c", character);
    }

    printf("\nYour secret key is: %d\n", key);

    return 0;
}