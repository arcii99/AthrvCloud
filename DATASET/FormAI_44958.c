//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define function to check for intrusion
void check_intrusion(char *s)
{
    int i, flag = 0;
    char keywords[6][10] = {"system", "exec", "rm", "sh", "vi", "sudo"};

    for(i = 0; i < 6; i++)
    {
        // Check if keyword present in input
        if(strstr(s, keywords[i]))
        {
            printf("Warning: Intrusion detected! Keyword '%s' found in input.\n", keywords[i]);
            flag = 1;
        }
    }

    if(!flag) printf("No Intrusion detected.\n");
}

int main()
{
    char input[100];

    // Get user input
    printf("Enter your input: ");
    fgets(input, 100, stdin);

    // Check for intrusion
    check_intrusion(input);

    return 0;
}