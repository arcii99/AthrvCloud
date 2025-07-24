//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levDist(char* str1, char* str2, int len1, int len2)
{
    // initialize to 0
    int dist[len1+1][len2+1];
    memset(dist, 0, sizeof(dist));

    // create indices
    int i,j;

    // initialize 1st dimension
    for(i=0;i<=len1;i++)
    {
        dist[i][0] = i;
    }

    // initialize 2nd dimension
    for(j=0; j<=len2;j++)
    {
        dist[0][j] = j;
    }

    // calculate distance
    for(i=1; i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            int cost = 0;
            
            if(str1[i-1] != str2[j-1])
            {
                cost = 1;
            }
            
            // get minimum value from the matrix
            int minVal = dist[i-1][j] + 1;
            if(dist[i][j-1] + 1 < minVal)
            {
                minVal = dist[i][j-1] + 1;
            }
            if(dist[i-1][j-1] + cost < minVal)
            {
                minVal = dist[i-1][j-1] + cost;
            }
            dist[i][j] = minVal;
        }
    }

    return dist[len1][len2];
}

int main()
{
    char* str1 = "Hello";
    char* str2 = "Hi";
    
    // calculate distance
    int distance = levDist(str1, str2, strlen(str1), strlen(str2));

    printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}