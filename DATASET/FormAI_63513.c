//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

#define MAX_LEN 100
#define INFINITY_MAX 99999

int min(int a, int b, int c){
    int min = a;
    if(b < min)
        min = b;
    if(c < min)
        min = c;
    return min;
}

int levenshteinDistance(char *s1, char *s2){
    int len1 = strlen(s1), len2 = strlen(s2);
    int distance[len1+1][len2+1];
    int i, j;

    for(i=0; i<=len1; i++){
        for(j=0; j<=len2; j++){
            if(i==0 || j==0)
                distance[i][j] = i+j;
            else if(s1[i-1] == s2[j-1])
                distance[i][j] = distance[i-1][j-1];
            else
                distance[i][j] = min(distance[i-1][j-1], distance[i][j-1], distance[i-1][j]) + 1;
        }
    }
    return distance[len1][len2];
}

int main(){
    char str1[MAX_LEN], str2[MAX_LEN];
    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = 0; //to remove the newline character
    str2[strcspn(str2, "\n")] = 0;

    int distance = levenshteinDistance(str1, str2);
    printf("Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);
    return 0;
}