//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random alphanumeric character
char randomChar() {
    int randVal = rand() % 62;
    if (randVal < 26) {
        return 'a' + randVal;
    } else if (randVal < 52) {
        return 'A' + randVal - 26;
    } else {
        return '0' + randVal - 52;
    }
}

int main() {
    int length;
    printf("Enter desired password length: ");
    scanf("%d", &length);
    srand(time(NULL));
    char password[length+1]; // Create a char array with space for null terminator
    for (int i = 0; i < length; i++) {
        password[i] = randomChar(); // Generate a random alphanumeric character and add to the password
    }
    password[length] = '\0'; // Add null terminator to end of password
    printf("Generated password: %s\n", password);
    return 0;
}