//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c) return a;
    else if(b < a && b < c) return b;
    else return c;
}

int levDist(char* str1, char* str2, int len1, int len2) {
    int** distTable = (int**)malloc((len1+1)*sizeof(int*));
    for(int i=0; i<len1+1; i++)
        distTable[i] = (int*)malloc((len2+1)*sizeof(int));
    
    for(int i=0; i<len1+1; i++) {
        for(int j=0; j<len2+1; j++) {
            if(i==0) distTable[i][j]=j;
            else if(j==0) distTable[i][j]=i;
            else if(str1[i-1] == str2[j-1]) distTable[i][j] = distTable[i-1][j-1];
            else distTable[i][j] = 1 + min(distTable[i-1][j], distTable[i][j-1], distTable[i-1][j-1]);
        }
    }
    int dist = distTable[len1][len2];
    for(int i=0; i<len1+1; i++) free(distTable[i]);
    free(distTable);
    return dist;
}

int main() {
    char str1[100], str2[100];
    printf("Enter string 1 : ");
    scanf("%s", str1);
    printf("Enter string 2 : ");
    scanf("%s", str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dist = levDist(str1, str2, len1, len2);
    printf("Levenshtein Distance : %d\n", dist);
    return 0;
}