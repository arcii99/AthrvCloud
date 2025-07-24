//FormAI DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

char* strrev(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

int main() {
    char message[MAX_SIZE];
    printf("Enter a message to be reversed:\n");
    fgets(message, MAX_SIZE, stdin);

    // Remove new line character from message
    message[strcspn(message, "\n")] = 0;

    // Reverse message
    char* reversed = strrev(message);

    printf("Reversed message: %s\n", reversed);

    return 0;
}