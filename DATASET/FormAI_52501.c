//FormAI DATASET v1.0 Category: Image Editor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[100];
    char operation[20];
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    printf("Enter the operation you want to perform: ");
    scanf("%s", operation);
    
    if(strcmp(operation,"crop") == 0)
    {
        // code to crop the image
    }
    else if(strcmp(operation,"rotate") == 0)
    {
        // code to rotate the image
    }
    else
    {
        printf("Invalid operation");
    }
    
    return 0;
}