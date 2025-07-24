//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: satisfied
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

int levenshtein_distance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int cost[m+1][n+1];
    
    for (int i = 0; i <= m; i++) cost[i][0] = i;
    for (int j = 0; j <= n; j++) cost[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int substitution_cost = (s[i-1] == t[j-1]) ? 0 : 1;
            int deletion_cost = cost[i-1][j] + 1;
            int insertion_cost = cost[i][j-1] + 1;
            int substitution = cost[i-1][j-1] + substitution_cost;
            cost[i][j] = min(deletion_cost, insertion_cost, substitution);
        }
    }
    
    return cost[m][n];
}

int main() {
    char s[100], t[100];
    printf("Enter the first string: ");
    scanf("%s", s);
    printf("Enter the second string: ");
    scanf("%s", t);
    int result = levenshtein_distance(s, t);
    printf("\nLevenshtein Distance between \"%s\" and \"%s\" is %d\n\n", s, t, result);
    return 0;
}