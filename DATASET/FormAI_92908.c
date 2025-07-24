//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <string.h>

int main() {
    char input[100]; // input buffer
    int count = 0; // counter for spam messages
    int max_count = 5; // maximum allowed spam messages

    while(1) // infinite loop for user input
    {
        printf("Enter message: ");
        fgets(input, 100, stdin); // get user input
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        if(strstr(input, "buy") != NULL) // check for spam message
        {
            count++; // increment counter
        }

        if(count >= max_count) // check if maximum spam count reached
        {
            printf("You have been flagged for spamming.\n");
            break; // end program
        }

        printf("Message sent.\n"); // acknowledge message sent
    }

    return 0;
}