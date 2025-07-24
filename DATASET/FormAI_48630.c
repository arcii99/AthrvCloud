//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Define maximum limit of characters in the string.
#define MAX_LIMIT 100

int main()
{
    // Declare character array to store input string.
    char str[MAX_LIMIT];

    printf("Enter a string of characters: ");

    // Read string from the user input.
    fgets(str, MAX_LIMIT, stdin);

    int i = 0;
    while (str[i] != '\0')
    {   
        // Check if character is not alphanumeric or white space.
        if (!(isalnum(str[i]) || isspace(str[i])))
        {
            printf("Intrusion detected! Non-alphanumeric character found: %c\n", str[i]);
            exit(0);
        }
        i++;
    }

    printf("No intrusion detected. String is safe for processing.\n");

    return 0;
}