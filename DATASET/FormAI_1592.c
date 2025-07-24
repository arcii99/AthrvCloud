//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Linus Torvalds
/**
 * Name: Levenshtein Distance
 * Language: C
 * Author: Linus Torvalds
 * Date: 19/09/2021
 * Description: A unique implementation of the Levenshtein Distance Calculator algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str1[] = "Levenshtein";
    char str2[] = "Distance";
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int mat[len1+1][len2+1];

    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i == 0){
                mat[0][j] = j;
            }
            else if(j == 0){
                mat[i][0] = i;
            }
            else if(str1[i-1] == str2[j-1]){
                mat[i][j] = mat[i-1][j-1];
            }
            else{
                int min = (mat[i-1][j] < mat[i][j-1]) ? mat[i-1][j] : mat[i][j-1];
                mat[i][j] = 1 + (min < mat[i-1][j-1] ? min : mat[i-1][j-1]);
            }
        }
    }

    printf("Distance between '%s' and '%s' is %d\n", str1, str2, mat[len1][len2]);

    return EXIT_SUCCESS;
}