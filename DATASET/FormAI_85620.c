//FormAI DATASET v1.0 Category: Text processing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1000];
    printf("Enter your grateful message:\n");
    fgets(message, sizeof(message), stdin);

    // Processing Text
    int len = strlen(message);
    for (int i = 0; i < len; i++)
    {
        // Replacing 'a' with '4'
        if (message[i] == 'a')
            message[i] = '4';

        // Replacing 'e' with '3'
        if (message[i] == 'e')
            message[i] = '3';

        // Replacing 'i' with '1'
        if (message[i] == 'i')
            message[i] = '1';

        // Replacing 'o' with '0'
        if (message[i] == 'o')
            message[i] = '0';

        // Replacing 'u' with '^'
        if (message[i] == 'u')
            message[i] = '^';
    }

    // Printing Grateful message
    printf("\nGrateful Message:\n");
    for (int i = 0; i < len; i++)
        printf("%c", message[i]);

    return 0;
}