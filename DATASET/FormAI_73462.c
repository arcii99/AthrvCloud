//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,m,n,sum;

    //Taking input from user
    printf("Enter the number of words: ");
    scanf("%d",&n);

    char **str = malloc(n*sizeof(char*));

    //Allocating memory for each word and getting input from user
    for(i=0;i<n;i++)
    {
        printf("Enter word %d: ",i+1);
        scanf("%s",str[i]);
    }

    //Calculating checksum
    for(i=0;i<n;i++)
    {
        sum=0;

        //Adding ascii values of each character in the word
        for(j=0;str[i][j]!='\0';j++)
        {
            sum+= str[i][j];
        }

        //Calculating the 1's complement of sum
        k=sum%256;
        m=255-k;

        //Printing the checksum
        printf("Checksum for %s: %d\n",str[i],m);
    }

    free(str);

    return 0;
}