//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min3(a,b,c) (((a<b)?a:b)<c)?((a<b)?a:b):c

int get_levenshtein_distance(const char *s1, const char *s2);

int main(){
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);
    
    int levDistance = get_levenshtein_distance(str1, str2);
    
    printf("Levenshtein Distance between %s and %s is: %d\n", str1, str2, levDistance);
}

int get_levenshtein_distance(const char *s1, const char *s2){
    int s1_len = strlen(s1);
    int s2_len= strlen(s2);
    int lev_distance_matrix[s1_len+1][s2_len+1];
    
    for(int i=0; i<=s1_len; i++)
        lev_distance_matrix[i][0] = i;
    for(int j=0; j<=s2_len; j++)
        lev_distance_matrix[0][j] = j;
    
    for(int i = 1; i <= s1_len; ++i)
        for(int j = 1; j <= s2_len; ++j)
            lev_distance_matrix[i][j] = min3(
                                         lev_distance_matrix[i-1][j] + 1,
                                         lev_distance_matrix[i][j-1] + 1,
                                         lev_distance_matrix[i-1][j-1] + (int)(s1[i-1] != s2[j-1])
                                       );
    return lev_distance_matrix[s1_len][s2_len];
}