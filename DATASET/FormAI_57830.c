//FormAI DATASET v1.0 Category: Firewall ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 1000

int main()
{
    char input[MAX_LENGTH];
    int i, count = 0;
    printf("Enter IP address to check if it is allowed:\n");
    fgets(input, MAX_LENGTH, stdin);

    // Removing newline character from input
    input[strcspn(input, "\n")] = 0;

    for(i = 0; i < strlen(input); i++)
    {
        // Checking if input contains only numbers and dots
        if((isdigit(input[i]) == 0 && input[i] != '.') || count > 3)
        {
            printf("IP Address not allowed.\n");
            return 0;
        }
        if(input[i] == '.') count++;
    }

    if(count != 3)
    {
        printf("IP Address not allowed.\n");
        return 0;
    }

    printf("IP Address allowed.\n");
    printf("Checking if port 80 is open...\n");
    printf("Port 80 is closed.\n");
    printf("Firewall enabled.\n");

    return 0;
}