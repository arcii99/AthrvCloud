//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];

    printf("Please enter some text: ");
    fgets(text, 100, stdin);

    // Remove trailing newline character
    text[strcspn(text, "\n")] = 0;

    int length = strlen(text);

    // Convert all characters to lowercase
    for (int i = 0; i < length; i++) {
        text[i] = tolower((unsigned char)text[i]);
    }

    // Replace all instances of "hate" with "love"
    char *ptr = strstr(text, "hate");
    while (ptr) {
        strncpy(ptr, "love", 4);
        ptr = strstr(ptr + 4, "hate");
    }

    // Replace all instances of "war" with "peace"
    ptr = strstr(text, "war");
    while (ptr) {
        strncpy(ptr, "peace", 5);
        ptr = strstr(ptr + 5, "war");
    }

    // Capitalize the first letter of each sentence
    for (int i = 0; i < length; i++) {
        text[i] = toupper((unsigned char)text[i]);
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            while (i < length && (text[i+1] == ' ' || text[i+1] == '\t' || text[i+1] == '\n')) {
                i++;
            }
            if (i < length) {
                text[i+1] = toupper((unsigned char)text[i+1]);
            }
        }
    }

    printf("Here is your text in a more peaceful style:\n%s\n", text);

    return 0;
}