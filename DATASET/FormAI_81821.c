//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include<stdio.h>

int main()
{
    char input[100];
    int i,checksum=0;

    printf("Welcome to Checksum Calculator!!\n\n");
    printf("Please enter the input string: ");
    fgets(input, sizeof(input), stdin);  // This allows string input with spaces

    for(i=0;input[i]!='\0';i++)
    {
        if(input[i]==' ')
           continue;   // Ignore spaces

        checksum+=input[i];  // Adds each character ascii value
    }

    printf("\nChecksum: %d\n",checksum);

    return 0;
}