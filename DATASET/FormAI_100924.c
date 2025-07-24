//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: genious
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c){
    int min = a;
    if (b < min){
        min = b;
    }
    if (c < min){
        min = c;
    }
    return min;
}

int lev_distance(char *s1, char *s2, int n1, int n2){
    int m[n1+1][n2+1];

    int i, j;

    for(i=0; i<=n1; i++){
        m[i][0] = i;
    }
    for(i=0; i<=n2; i++){
        m[0][i] = i;
    }
    for(i=1; i<=n1; i++){
        for(j=1; j<=n2; j++){
            if (s1[i-1] == s2[j-1]){
                m[i][j] = m[i-1][j-1];
            }else{
                m[i][j] = minimum(m[i-1][j-1], m[i][j-1], m[i-1][j]) + 1;
            }
        }
    }
    return m[n1][n2];
}

int main(){
    char s1[100], s2[100];
    printf("Enter string 1:\n");
    scanf("%s", s1);
    printf("Enter string 2:\n");
    scanf("%s", s2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int result = lev_distance(s1, s2, n1, n2);
    printf("The Levenshtein Distance between %s and %s is %d", s1, s2, result);
    return 0;
}