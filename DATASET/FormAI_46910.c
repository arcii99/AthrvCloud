//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: random
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else
        return c;
}

int Levenshtein_Distance_Calculator(char *s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 == 0)
        return len2;
    if(len2 == 0)
        return len1;
    int cost;
    int d[len1+1][len2+1];
    for(int i=0; i<=len1; i++)
        d[i][0] = i;
    for(int j=0; j<=len2; j++)
        d[0][j] = j;
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            if(s1[i-1] == s2[j-1])
                cost = 0;
            else
                cost = 1;
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+cost);
        }
    }
    return d[len1][len2];
}

int main(){
    char s1[50], s2[50];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int result = Levenshtein_Distance_Calculator(s1, s2);
    printf("Levenshtein distance between %s and %s is %d", s1, s2, result);
    return 0;
}