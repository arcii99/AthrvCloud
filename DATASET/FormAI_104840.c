//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function to calculate minimum of three numbers
int minimum(int a,int b,int c)
{
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

// Function to calculate the levenshtein distance
int calculateLevenshteinDistance(char *str1,char *str2,int len1,int len2)
{
    int distance[len1+1][len2+1],i,j;

    // initializing the first row and column with increasing numbers
    for(i=0;i<=len1;i++)
        distance[i][0]=i;
    for(j=0;j<=len2;j++)
        distance[0][j]=j;

    // filling the distance array
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                distance[i][j]=distance[i-1][j-1];
            else
                distance[i][j]=1+minimum(distance[i-1][j],distance[i][j-1],distance[i-1][j-1]);
        }
    }
    // returning the distance between two strings
    return distance[len1][len2];
}

int main()
{
    // two strings for which distance is to be calculated
    char str1[]="levenshtein";
    char str2[]="distance";
    int len1=strlen(str1),len2=strlen(str2);

    printf("The levenshtein distance between '%s' and '%s' is: %d",str1,str2,calculateLevenshteinDistance(str1,str2,len1,len2));
    return 0;
}