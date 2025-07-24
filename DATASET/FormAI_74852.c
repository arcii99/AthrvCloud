//FormAI DATASET v1.0 Category: Computer Biology ; Style: bold
#include<stdio.h>
#include<string.h>

int main()
{
    char dna1[100], dna2[100];
    int i, j, count=0;

    //Taking input of first DNA sequence
    printf("Enter the first DNA sequence: ");
    scanf("%s", dna1);

    //Taking input of second DNA sequence
    printf("Enter the second DNA sequence: ");
    scanf("%s", dna2);

    // Checking the length of both DNA sequences
    int len1 = strlen(dna1);
    int len2 = strlen(dna2);

    // Finding the larger sequence among the two
    if (len1>len2)
        j = len1;
    else
        j = len2;

    // Comparing the two DNA sequences
    for(i=0;i<j;i++)
    {
        if(dna1[i] == dna2[i])
        {
            printf("%c", dna1[i]);
            count++;
        }
        else
        {
            printf("*");
        }
    }

    // Printing the matching percentage of the two DNA sequences
    int matching_percentage = ((count*2)/((len1+len2)*1.0))*100;
    printf("\nMatching Percentage of the two DNA sequences: %d%%\n", matching_percentage);

    return 0;
}