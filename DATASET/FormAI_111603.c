//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <string.h>

int main()
{
    char input[50];
    int sum = 0;
    
    printf("Enter your input string: ");
    scanf("%s", input);
    
    for(int i=0; i<strlen(input); i++)
    {
        sum += input[i];
    }
    
    printf("The checksum value of '%s' is %d.", input, sum % 256);
    
    return 0;
}