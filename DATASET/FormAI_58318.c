//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int minimum(int a, int b, int c){
    if(a<b)
        if(a<c)
            return a;
        else 
            return c;
    else if(b<c)
            return b;
    else
        return c;
}

int main(){
    char s1[100], s2[100];
    int len1, len2, i, j;

    printf("Enter string 1: ");
    scanf("%s", s1);

    printf("Enter string 2: ");
    scanf("%s", s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    int table[len1+1][len2+1];

    for(i=0; i<=len1; i++)
        table[i][0] = i;

    for(j=0; j<=len2; j++)
        table[0][j] = j;

    for(i=1; i<=len1; i++){
        for(j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1])
                table[i][j] = table[i-1][j-1];
            else
                table[i][j] = minimum(table[i-1][j], table[i][j-1], table[i-1][j-1]) + 1;
        }
    }

    printf("Levenshtein Distance: %d", table[len1][len2]);

    return 0;
}