//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* This program calculates a checksum of the input string */
int main()
{
    char input_string[50];
    int checksum = 0;

    printf("Enter your input string: ");
    scanf("%s", input_string);

    /* Calculate checksum */
    for(int i=0; i<strlen(input_string); i++)
    {
        checksum += (int)input_string[i];
    }

    /* Display the checksum */
    printf("The checksum of the input string is: %d\n", checksum);

    return 0;
}