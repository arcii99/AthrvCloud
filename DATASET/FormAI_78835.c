//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char word1[] = "jelly";
    char word2[] = "yawn";
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int matrix[len1 + 1][len2 + 1];
    
    // initialize the first row and column of the matrix
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            if(i == 0 || j == 0){
                matrix[i][j] = i + j;
            }
            else{
                matrix[i][j] = 0;
            }
        }
    }

    // calculate the Levenshtein distance between two words
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(word1[i - 1] == word2[j - 1]){
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else{
                int substitution = matrix[i - 1][j - 1] + 1;
                int insertion = matrix[i][j - 1] + 1;
                int deletion = matrix[i - 1][j] + 1;

                matrix[i][j] = substitution > insertion ? insertion : substitution;
                matrix[i][j] = matrix[i][j] > deletion ? deletion : matrix[i][j];
            }
        }
    }

    // print the matrix
    printf("Levenshtein Distance Matrix:\n");
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j <= len2; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // print the Levenshtein distance between the two words
    printf("\nThe Levenshtein Distance between '%s' and '%s' is %d.", word1, word2, matrix[len1][len2]);

    return 0;
}