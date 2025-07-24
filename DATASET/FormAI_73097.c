//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare necessary variables
    char input[100];
    int length;
    int i = 0;
    int count = 0;

    // Take user input
    printf("Enter a string:\n");
    scanf("%s", input);
    length = strlen(input);

    // Check for intrusions
    for(i=0; i<length; i++)
    {
        if(input[i] == '\'' || input[i] == '\"' || input[i] == '(' || input[i] == ')' || input[i] == '[' || input[i] == ']' || input[i] == '{' || input[i] == '}')
        {
            count++;
        }
    }

    // Print out if there are any intrusions or not
    if(count == 0)
    {
        printf("No Intrusions Detected.\n");
    }
    else
    {
        printf("Intrusion Detected.\n");
    }

    return 0;
}