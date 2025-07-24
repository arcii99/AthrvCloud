//FormAI DATASET v1.0 Category: String manipulation ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char message[100] = "Hello, World! This is a shocked example program for C String manipulation.";
    char search[] = "shocked";
    char replace[] = "amazed";
    int count = 0;
    char *ptr = NULL;
    char temp[100] = "";

    printf("Original message: %s\n", message);

    // Count the number of occurrences of the search word
    ptr = strstr(message, search);
    while(ptr != NULL) {
        count++;
        ptr = strstr(ptr + strlen(search), search);
    }

    // Replace the search word with the replacement word
    ptr = strstr(message, search);
    while(ptr != NULL) {
        strncpy(temp, message, ptr - message);
        temp[ptr - message] = '\0';
        strcat(temp, replace);
        strcat(temp, ptr + strlen(search));
        strcpy(message, temp);
        ptr = strstr(message, search);
    }

    printf("Modified message: %s\n", message);
    printf("Number of occurrences of \"%s\" in the message: %d\n", search, count);

    // Remove all vowels from the message
    char vowels[] = "aeiouAEIOU";
    for(int i = 0; i < strlen(message); i++) {
        for(int j = 0; j < strlen(vowels); j++) {
            if(message[i] == vowels[j]) {
                for(int k = i; k < strlen(message); k++) {
                    message[k] = message[k + 1];
                }
                i--;
            }
        }
    }

    printf("Message without vowels: %s\n", message);

    // Reverse the message
    char reversed[100];
    int index = 0;
    for(int i = strlen(message) - 1; i >= 0; i--) {
        reversed[index] = message[i];
        index++;
    }
    reversed[index] = '\0';

    printf("Reversed message: %s\n", reversed);

    return 0;
}