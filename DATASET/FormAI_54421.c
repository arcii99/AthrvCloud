//FormAI DATASET v1.0 Category: Searching algorithm ; Style: artistic
#include<stdio.h>

// Artistic C Searching Algorithm
// Inspired by Van Gogh's Starry Night

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int search = 7;
    int i;
    int found = 0;

    printf("\n*****************\n");
    printf("      SEARCH     \n");
    printf("*****************\n\n");

    // Loop of stars
    for(i=0; i<10; i++)
    {
        if(arr[i] == search)
        {
            found = 1;  // Found the number
            break;      // Exit the loop
        }
        else
        {
            printf("* ");   // Print a star
        }
    }

    if(found)
    {
        printf("\n\n*****************\n");
        printf("   FOUND IT! :)\n");
        printf("*****************\n\n");
    }
    else
    {
        printf("\n\n*****************\n");
        printf("    NOT FOUND! :(\n");
        printf("*****************\n\n");
    }

    return 0;
}