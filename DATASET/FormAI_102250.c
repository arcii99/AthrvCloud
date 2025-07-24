//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int matrix[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++)
        matrix[i][0] = i;

    for (int j = 0; j <= len2; j++)
        matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] != s2[j - 1]);
            int deletion = matrix[i - 1][j] + 1;
            int insertion = matrix[i][j - 1] + 1;
            int substitution = matrix[i - 1][j - 1] + cost;

            matrix[i][j] = substitution;

            if (deletion < matrix[i][j])
                matrix[i][j] = deletion;

            if (insertion < matrix[i][j])
                matrix[i][j] = insertion;
        }
    }

    return matrix[len1][len2];
}

int main()
{
    char s1[] = "hello";
    char s2[] = "world";

    printf("Levenshtein distance between '%s' and '%s' is %d\n", s1, s2, levenshtein_distance(s1, s2));

    return 0;
}