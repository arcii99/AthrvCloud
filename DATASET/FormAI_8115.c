//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char log[1000];
    printf("Enter Log: ");
    fgets(log, 1000, stdin);
    char *split;
    int count = 0;
    
    printf("\nSearching logs for potential cyber attack...\n\n");
    split = strtok(log, " ");
    while(split !=NULL)
    {
        if(strcmp(split, "hack") == 0 || strcmp(split, "attack") == 0 || strcmp(split, "virus") == 0 || strcmp(split, "security") == 0)
        {
            printf("\nPotential threat detected...\n");
            printf("Warning level: High\n");
            printf("Initiating countermeasures...\n");
            count++;
        }
        split = strtok(NULL, " ");
    }
    if(count == 0)
    {
        printf("\nNo cyber threats detected.\n");
    }
    else
    {
        printf("\n%d potential threats detected.\n", count);
    }
    
    printf("\n--------------------------------");
    printf("\nLog analysis complete.\n");
    return 0;
}