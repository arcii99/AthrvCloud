//FormAI DATASET v1.0 Category: Firewall ; Style: puzzling
#include<stdio.h>
#include<string.h>

int main()
{
    char input[256];
    int flag = 0;

    printf("Enter a website URL: ");
    scanf("%s", input);

    for(int i=0; i<strlen(input); i++)
    {
        if(input[i] == '.' && flag == 0)
        {
            flag = 1;
            continue;
        }
        else if(input[i] == '.' && flag == 1)
        {
            printf("Invalid URL\n");
            return 0;
        }
        else if((input[i] < 'a' || input[i] > 'z') && (input[i] < '0' || input[i] > '9'))
        {
            printf("Invalid URL\n");
            return 0;
        }
    }

    printf("Valid URL\n");

    return 0;
}