//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Return minimum of three integers.
int min(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    else
        return z;
}

// Calculate the Levenshtein distance between two strings.
int levDist(char *s, char *t)
{
    int lenS = strlen(s), lenT = strlen(t);
    int dist[lenS+1][lenT+1];
    int i, j;

    for (i=0; i<=lenS; i++)
        for (j=0; j<=lenT; j++)
        {
            if (i == 0)
                dist[i][j] = j;

            else if (j == 0)
                dist[i][j] = i;

            else if (s[i-1] == t[j-1])
                dist[i][j] = dist[i-1][j-1];

            else
                dist[i][j] = 1 + min(dist[i][j-1],
                                     dist[i-1][j],
                                     dist[i-1][j-1]);
        }

    return dist[lenS][lenT];
}

// Main function to test the Levenshtein distance.
int main()
{
    char s[] = "kitten";
    char t[] = "sitting";

    printf("Levenshtein distance between '%s' and '%s' is %d\n",
            s, t, levDist(s, t));

    return 0;
}