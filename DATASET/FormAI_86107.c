//FormAI DATASET v1.0 Category: Data validation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define MAX_SIZE 10
 
int main()
{
    char num[MAX_SIZE];
    int len, i, sum = 0;
 
    printf("Enter a %d-digit number for data validation: ", MAX_SIZE - 1);
    scanf("%s", num);
 
    len = strlen(num);
 
    if(len != MAX_SIZE-1)
    {
        printf("Invalid input! Please enter a %d-digit number.\n", MAX_SIZE - 1);
        exit(1);
    }
 
    for(i = 0; i < len; i++)
    {
        if(!isdigit(num[i]))
        {
            printf("Invalid input! Please enter a %d-digit number.\n", MAX_SIZE - 1);
            exit(1);
        }
        sum += (num[i] - '0') * (i + 1);
    }
 
    if(sum % 11 == 0)
    {
        printf("Data validated successfully!\n");
        return 0;
    }
    else
    {
        printf("Data validation failed! Check digit is incorrect.\n");
        return 1;
    }
}