//FormAI DATASET v1.0 Category: Error handling ; Style: genious
#include<stdio.h> 

void handleError(int errorCode)
{
    switch(errorCode)
    {
        case 0:
            printf("No error occurred\n");
            break;
        case 1:
            printf("Syntax error occurred\n");
            break;
        case 2:
            printf("Memory allocation error occurred\n");
            break;
        case 3:
            printf("File read error occurred\n");
            break;
        default:
            printf("Unknown error occurred\n");
            break;
    }
}

int main()
{
    int errorCode = 0;
    //Code that may generate error
    int arr[10];
    for(int i=0;i<=10;i++)
    {
        arr[i] = i;
        if(i==10)
        {
            errorCode=2; //Memory allocation error
        }
    }
    handleError(errorCode);
    return 0;
}