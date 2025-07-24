//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_URL_SIZE 100

int main()
{
    char url[MAX_URL_SIZE];
    int status = 0;

    printf("*****Website Uptime Monitor*****\n\n");
    printf("Enter the website url: ");
    scanf("%s", url);

    while (1)
    {
        status = system("ping -c 1 -w 2 website-url");
        if (status == 0)
        {
            printf("\nWebsite is UP\n\n");
        }
        else
        {
            printf("\nWebsite is DOWN\n\n");
        }

        sleep(60); // Sleep for 1 minute
    }

    return 0;
}