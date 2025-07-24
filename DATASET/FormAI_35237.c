//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LEN 100

int get_minimum(int a, int b, int c)
{
    int temp = a < b ? a : b;
    return temp < c ? temp : c;
}

int calculate_levenshtein_distance(char* str1, char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 == 0) return len2;
    if (len2 == 0) return len1;

    int matrix[len1+1][len2+1];
    int i, j, cost;

    for (i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        matrix[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = (str1[i-1] == str2[j-1]) ? 0 : 1;

            matrix[i][j] = get_minimum(matrix[i-1][j] + 1,
                                        matrix[i][j-1] + 1,
                                        matrix[i-1][j-1] + cost);
        }
    }

    return matrix[len1][len2];
}

int main(void)
{
    char input1[MAX_INPUT_LEN+1];
    char input2[MAX_INPUT_LEN+1];

    printf("Enter the first string: ");
    fgets(input1, MAX_INPUT_LEN+1, stdin);

    printf("Enter the second string: ");
    fgets(input2, MAX_INPUT_LEN+1, stdin);

    int distance = calculate_levenshtein_distance(input1, input2);

    printf("Levenshtein distance between \"%s\" and \"%s\" is %d\n",
            input1, input2, distance);

    return 0;
}