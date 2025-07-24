//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Levenshtein Distance
int levenshtein_distance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int distance[n + 1][m + 1];

    // Initialize matrix
    for(int i = 0; i <= n; i++)
        distance[i][0] = i;
    for(int j = 0; j <= m; j++)
        distance[0][j] = j;

    // Calculate distance matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int cost = s[i - 1] == t[j - 1] ? 0 : 1;

            distance[i][j] = fmin(fmin(distance[i - 1][j] + 1,
                                         distance[i][j - 1] + 1),
                                  distance[i - 1][j - 1] + cost);
        }
    }

    return distance[n][m];
}

int main() {
    printf("Enter two strings to calculate their Levenshtein Distance\n");

    char s[100];
    char t[100];

    // Get user input
    printf("String 1: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s,"\n")] = 0;

    printf("String 2: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t,"\n")] = 0;

    // Calculate and print Levenshtein distance
    printf("Levenshtein distance: %d\n", levenshtein_distance(s, t));

    // Post-apocalyptic easter egg
    printf("Warning: communication may be intercepted by rogue AI. Trust no one. Stay alive.\n");

    return 0;
}