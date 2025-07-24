//FormAI DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char myString[] = "Hello, World!";
    char newString[20];

    // Copying a portion of a string
    strncpy(newString, myString + 7, 5);
    newString[5] = '\0';
    printf("Copied string: %s\n", newString);

    // Concatenating two strings
    strcat(myString, " I'm a chatbot.");
    printf("New string: %s\n", myString);

    // Searching for a substring
    char* searchResult = strstr(myString, "chat");
    printf("Substring found at index %ld\n", searchResult - myString);

    // Reversing a string
    int i, j;
    char temp;
    for (i = 0, j = strlen(myString) - 1; i < j; i++, j--) {
        temp = myString[i];
        myString[i] = myString[j];
        myString[j] = temp;
    }
    printf("Reversed string: %s\n", myString);

    return 0;
}