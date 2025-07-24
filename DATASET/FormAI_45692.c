//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int a, int b, int c) {
    int temp = a<b?a:b;
    return temp<c?temp:c;
}

int LevenshteinDistance(char *word1, char *word2, int len1, int len2) {
    int DistanceMatrix[len1+1][len2+1];
    memset(DistanceMatrix, 0, sizeof(DistanceMatrix));
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            if(word1[i-1]==word2[j-1]) {
                DistanceMatrix[i][j] = DistanceMatrix[i-1][j-1];
            } else {
                DistanceMatrix[i][j] = 1 + min(DistanceMatrix[i-1][j],DistanceMatrix[i][j-1],DistanceMatrix[i-1][j-1]);
            }
        }
    }
    return DistanceMatrix[len1][len2];
}

int main() {
    char word1[100], word2[100];
    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter your first word:\n");
    scanf("%s",word1);
    printf("Please enter your second word:\n");
    scanf("%s",word2);
    int len1 = strlen(word1), len2 = strlen(word2);
    printf("The Levenshtein Distance between %s and %s is %d.\n",word1,word2,LevenshteinDistance(word1,word2,len1,len2));
    return 0;
}