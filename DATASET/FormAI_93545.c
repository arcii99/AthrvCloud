//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 100

int min(int a, int b, int c){
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

int levenshtein_distance(char* str1, char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp_table[len1+1][len2+1];
    
    for (int i = 0; i <= len1; i++){
        for (int j = 0; j <= len2; j++){
            if (i == 0) dp_table[i][j] = j;
            else if (j == 0) dp_table[i][j] = i;
            else if (str1[i-1] == str2[j-1]) dp_table[i][j] = dp_table[i-1][j-1];
            else dp_table[i][j] = 1 + min(dp_table[i-1][j], dp_table[i][j-1], dp_table[i-1][j-1]);
        }
    }
    return dp_table[len1][len2];
}

int main(){
    char str1[MAX_STRING_LEN], str2[MAX_STRING_LEN];
    printf("Enter the first string: ");
    fgets(str1, MAX_STRING_LEN, stdin);
    printf("Enter the second string: ");
    fgets(str2, MAX_STRING_LEN, stdin);
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between %s and %s is %d.", str1, str2, distance);
    return 0;
}