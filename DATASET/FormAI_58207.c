//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// function to detect intrusion
int detectIntrusion(char *sInput)
{
    // check for common intrusion patterns
    if (strstr(sInput, "SELECT")) return 1;
    if (strstr(sInput, "UPDATE")) return 1;
    if (strstr(sInput, "DELETE")) return 1;
    if (strstr(sInput, "DROP")) return 1;

    // no intrusion detected
    return 0;
}

int main()
{
    char sInput[MAX_SIZE];
    int bIntrusionDetected = 0;

    // get user input
    printf("Enter SQL query:\n");
    fgets(sInput, MAX_SIZE, stdin);

    // check for intrusion
    bIntrusionDetected = detectIntrusion(sInput);

    if (bIntrusionDetected)
    {
        printf("Intrusion detected!\n");
    }
    else
    {
        printf("No intrusion detected.\n");
    }

    return 0;
}