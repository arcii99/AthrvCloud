//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random characters
char randomChar() {
    int random = rand() % 62;
    if (random < 26) {
        return 'a' + random;
    } else if (random < 52) {
        return 'A' + random - 26;
    } else {
        return '0' + random - 52;
    }
}

int main() {
    int length;
    printf("Please enter the length of the password: ");
    scanf("%d", &length);

    // Generate the password
    char password[length];
    srand(time(0));
    for (int i = 0; i < length; i++) {
        password[i] = randomChar();
    }
    password[length] = '\0';

    // Print the password
    printf("Your secure password is: %s\n", password);
    return 0;
}