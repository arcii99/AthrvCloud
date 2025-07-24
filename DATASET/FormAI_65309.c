//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c)
        return a;
    else if (b < a && b < c)
        return b;
    else
        return c;
}

int leven(int ** arr, char * str1, char * str2, int len1, int len2) {
    for (int i = 0; i <= len1; i++)
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                arr[i][j] = j;
            else if (j == 0)
                arr[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                arr[i][j] = arr[i - 1][j - 1];
            else
                arr[i][j] = 1 + min(arr[i - 1][j], arr[i][j - 1], arr[i - 1][j - 1]);
        }
    return arr[len1][len2];
}

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    int len1 = strlen(a), len2 = strlen(b);
    int ** arr = (int **) malloc(sizeof(int *) * (len1 + 1));
    for (int i = 0; i <= len1; i++)
        arr[i] = (int *) malloc(sizeof(int) * (len2 + 1));
    int ans = leven(arr, a, b, len1, len2);
    printf("The Levenshtein Distance between %s and %s is %d.", a, b, ans);
    for (int i = 0; i <= len1; i++)
        free(arr[i]);
    free(arr);
    return 0;
}