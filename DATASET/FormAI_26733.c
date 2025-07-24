//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("**********************************************\n");
    printf("*                 CHECKSUM                    *\n");
    printf("*             CALCULATOR PROGRAM              *\n");
    printf("**********************************************\n\n");

    // Take input string from user
    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    // Calculate checksum
    int length = strlen(input);
    int sum = 0;
    for(int i=0; i<length; i++)
        sum += (int)input[i];

    // Display checksum
    printf("\nChecksum of the string '%s' is: %d\n\n", input, sum);

    return 0;
}