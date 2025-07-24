//FormAI DATASET v1.0 Category: Firewall ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[20];

    printf("Welcome to my Firewall Example Program!\n");
    printf("Please enter your secret access key: ");
    scanf("%s", input);

    if (strcmp(input, "SuperSecret123") == 0)
    {
        printf("Access Granted!\n");
        // Firewall rules go here
    }
    else
    {
        printf("Access Denied!\n");
        printf("Intruder Alert! Initiating self-destruct sequence...\n");

        // Self-destruct sequence code goes here
        // Don't worry, it's just a joke! We wouldn't actually destroy anything :)
    }

    return 0;
}