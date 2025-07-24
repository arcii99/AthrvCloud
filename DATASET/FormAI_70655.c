//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 100

int main()
{
    int temp = 0;
    time_t now;

    printf("Welcome to the Temperature Monitor Program!\n");

    while(1)
    {
        printf("Enter the current temperature: ");
        scanf("%d", &temp);

        if(temp > MAX_TEMP)
        {
            printf("Warning! Temperature is above maximum limit.\n");
            now = time(NULL);
            printf("Timestamp: %s\n", ctime(&now));
        }
        else if(temp < 0)
        {
            printf("Warning! Temperature is below freezing point!\n");
            now = time(NULL);
            printf("Timestamp: %s\n", ctime(&now));
        }
        else
        {
            printf("Temperature is within the limit.\n");
        }

        char choice;
        printf("Do you want to continue monitoring? (Y/N) ");
        scanf(" %c", &choice);

        if(choice == 'N' || choice == 'n')
        {
            printf("Exiting Temperature Monitor Program.\n");
            exit(0);
        }
    }

    return 0;
}