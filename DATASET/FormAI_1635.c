//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void detect_intrusion(char *input)
{
    char buffer[MAX_SIZE];
    int count = 0;
    strncpy(buffer, input, MAX_SIZE);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (buffer[i] == '(')
        {
            count++;
        }
        else if (buffer[i] == ')')
        {
            count--;
        }
        else if (buffer[i] == ';')
        {
            break;
        }
    }

    if (count != 0)
    {
        printf("\n\nALERT! Intrusion detected! Closing program...\n");
        exit(0);
    }
}

int main()
{
    char input[MAX_SIZE];

    printf("Welcome to the Intrusion Detection System!\n");

    while (1)
    {
        printf("> ");
        fgets(input, MAX_SIZE, stdin);
        detect_intrusion(input);
    }
    
    return 0;
}