//FormAI DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char message[] = "The game is afoot, my dear Watson!";
    char keyword[] = "Watson";
    char new_text[] = "Holmes";

    // Find the index of the keyword in the message string
    char* keyword_location = strstr(message, keyword);
    int keyword_index = keyword_location - message;

    // Replace the keyword with the new text
    for (int i = 0; i < strlen(new_text); i++) {
        message[keyword_index + i] = new_text[i];
    }
    
    // Print the updated message
    printf("The new message is: %s\n", message);

    // Count the number of occurrences of a particular character in a string
    char evidence[] = "The murderer left a bloody footprint.";
    char suspect = 'e';
    int count = 0;

    for (int i = 0; i < strlen(evidence); i++) {
        if (evidence[i] == suspect) {
            count++;
        }
    }

    // Print the number of occurrences
    printf("The suspect '%c' appears %d times in the evidence.\n", suspect, count);

    // Reverse a string
    char name[] = "Sherlock Holmes";
    char reversed_name[strlen(name) + 1];

    for (int i = 0; i < strlen(name); i++) {
        reversed_name[i] = name[strlen(name) - i - 1];
    }
    reversed_name[strlen(name)] = '\0';

    // Print the reversed name
    printf("The reversed name is: %s\n", reversed_name);

    return 0;
}