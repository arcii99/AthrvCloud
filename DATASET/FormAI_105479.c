//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter two words:\n");

    char word1[100], word2[100];
    scanf("%s%s", word1, word2);

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int dist_matrix[len1+1][len2+1];

    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0)
                dist_matrix[i][j] = j;
            else if(j==0)
                dist_matrix[i][j] = i;
            else if(word1[i-1] == word2[j-1])
                dist_matrix[i][j] = dist_matrix[i-1][j-1];
            else
                dist_matrix[i][j] = 1 + minimum(dist_matrix[i-1][j], dist_matrix[i][j-1], dist_matrix[i-1][j-1]);
        }
    }

    printf("The Levenshtein Distance between %s and %s is %d.\n", word1, word2, dist_matrix[len1][len2]);

    return 0;
}

int minimum(int a, int b, int c){
    if(a <= b && a <= c)
        return a;
    else if(b <= a && b <= c)
        return b;
    else
        return c;
}