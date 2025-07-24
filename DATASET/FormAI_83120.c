//FormAI DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Romeo:";
    char str2[] = "Juliet:";

    printf("Enter your message, Romeo:\n");
    char message[100];
    fgets(message, 100, stdin);

    int len = strlen(message);

    // Reverse the message
    char reversed[100];
    for (int i = 0; i < len; i++) {
        reversed[i] = message[len - i - 1];
    }

    // Replace all uppercase letters with lowercase and vice versa
    for (int i = 0; i < len; i++) {
        char c = reversed[i];
        if (c >= 'A' && c <= 'Z') {
            reversed[i] = c + ('a' - 'A');
        } else if (c >= 'a' && c <= 'z') {
            reversed[i] = c - ('a' - 'A');
        }
    }

    // Print the conversation
    printf("\n%s %s\n", str1, message);
    printf("%s %s\n", str2, reversed);

    return 0;
}