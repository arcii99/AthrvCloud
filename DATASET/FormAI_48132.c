//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char email[] = "eoljgk6Gkt8Csn3sl@ravens.com";
    char password[] = "Fi6Rgk4h2";
    int emailLength = strlen(email);
    int passwordLength = strlen(password);

    for (int i = 0; i < emailLength; i++) {
        email[i] = email[i] + 1;
    }
    for (int j = 0; j < passwordLength; j++) {
        password[j] = password[j] + 2;
    }

    printf("Welcome to the mysterious email client...\n\n");
    printf("You can access your email at %s\n", email);
    printf("Your password has been encrypted: %s\n", password);
    printf("Hint: Subtract 2 from each character to decrypt it\n\n");

    char input[25];
    printf("Enter your decrypted password: ");
    scanf("%s", input);

    if (strcmp(input, password - 2) == 0) {
        printf("\nAccess granted. Welcome to your inbox.\n");
    } else {
        printf("\nAccess denied. Incorrect password.\n");
    }

    return 0;
}