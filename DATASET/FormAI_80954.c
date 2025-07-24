//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char happy[] = "I am happy today!";
    char new_happy[50];

    // Copying first 5 characters
    strncpy(new_happy, happy, 5);
    new_happy[5] = '\0'; // Adding terminating character
    printf("Copied string: %s\n", new_happy);

    // Concatenating more happiness
    strcat(new_happy, " Because I am having a great day!");
    printf("Concatenated string: %s\n", new_happy);

    // Checking if string contains 'happy'
    if (strstr(new_happy, "happy") != NULL) {
        printf("The string contains 'happy'!\n");
    } else {
        printf("The string does not contain 'happy'.\n");
    }

    // Replacing 'today' with 'everyday'
    char *p = strstr(new_happy, "today");
    if (p != NULL) {
        strcpy(p, "everyday");
    }

    printf("Final string: %s\n", new_happy);

    return 0;
}