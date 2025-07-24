//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int levenshtein_distance(char *str1, char *str2);

int main()
{
    char player1[MAX_LEN];
    char player2[MAX_LEN];

    printf("Player 1, enter a word: ");
    fgets(player1, MAX_LEN, stdin); // get input from the player 1
    player1[strcspn(player1, "\n")] = '\0';

    printf("Player 2, enter a word: ");
    fgets(player2, MAX_LEN, stdin); // get input from the player 2
    player2[strcspn(player2, "\n")] = '\0';

    printf("\nCalculating Levenshtein Distance...\n\n");

    int dist = levenshtein_distance(player1, player2);

    printf("The Levenshtein Distance between %s and %s is %d\n", player1, player2, dist);

    return 0;
}

int levenshtein_distance(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distances[MAX_LEN][MAX_LEN];

    // Initialize the border of the matrix to their indices
    for (int i = 0; i <= len1; ++i)
        distances[i][0] = i;

    for (int j = 0; j <= len2; ++j)
        distances[0][j] = j;

    // Compute the rest of the matrix
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

            int del = distances[i-1][j] + 1;
            int ins = distances[i][j-1] + 1;
            int sub = distances[i-1][j-1] + cost;

            distances[i][j] = (del < ins) ? del : ins;
            distances[i][j] = (sub < distances[i][j]) ? sub : distances[i][j];
        }
    }

    return distances[len1][len2];
}