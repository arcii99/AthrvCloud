//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int editDist(char *str1, char *str2, int len1, int len2){
    int dist[len1+1][len2+1];
    for (int i=0; i<=len1; i++){
        for (int j=0; j<=len2; j++){
            if (i==0)
                dist[i][j] = j;
            else if (j==0)
                dist[i][j]=i;
            else if (str1[i-1] == str2[j-1])
                dist[i][j] = dist[i-1][j-1];
            else
                dist[i][j] = 1 + min( dist[i][j-1], dist[i-1][j], dist[i-1][j-1]);
        }
    }
    return dist[len1][len2];
}

int min(int a, int b, int c){
    if (a<b && a<c)
        return a;
    else if (b<a && b<c)
        return b;
    else
        return c;
}

int main(){
    char str1[] = "Hello world!";
    char str2[] = "Hllo words!";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int distance = editDist(str1, str2, len1, len2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d.", str1, str2, distance);
    return 0;
}