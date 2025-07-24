//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b, int c){
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int calculateLevenshteinDistance(char *s1, char *s2){
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int i, j, cost, **matrix;

    matrix = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for(i = 0; i <= len_s1; i++){
        matrix[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for(i = 0; i <= len_s1; i++){
        matrix[i][0] = i;
    }

    for(i = 0; i <= len_s2; i++){
        matrix[0][i] = i;
    }

    for(i = 1;i<=len_s1;i++){
        for(j = 1;j<=len_s2;j++){
            cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + cost);
        }
    }

    return matrix[len_s1][len_s2];
}

int main(){
    char *s1 = "levenshtein";
    char *s2 = "distance";
    int distance = calculateLevenshteinDistance(s1, s2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d", s1, s2, distance);
    return 0;
}