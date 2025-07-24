//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scientific
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c){
    if(a <= b && a <= c){
        return a;
    }else if(b <= a && b <= c){
        return b;
    }else{
        return c;
    }
}

int levenshtein_distance(char *s1, char *s2, int len1, int len2){
    int m[len1+1][len2+1];
    memset(m, 0, sizeof(m));

    int i,j;
    for(i=1;i<=len1;i++){
        m[i][0] = i;
    }
    for(j=1;j<=len2;j++){
        m[0][j] = j;
    }

    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            int cost;
            if(s1[i-1]==s2[j-1]){
                cost = 0;
            }else{
                cost = 1;
            }

            m[i][j] = min(m[i-1][j]+1, m[i][j-1]+1, m[i-1][j-1]+cost);
        }
    }

    return m[len1][len2];
}

int main(){
    char *s1 = "Hello";
    char *s2 = "Holla";

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    printf("Levenshtein Distance: %d\n", levenshtein_distance(s1, s2, len1, len2));

    return 0;
}