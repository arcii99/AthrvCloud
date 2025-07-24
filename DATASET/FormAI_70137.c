//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minimum(int a, int b, int c) {
    if(a<=b && a<=c) 
        return a;
    if(b<=a && b<=c) 
        return b;
    else 
        return c;
}

int LevenshteinDistance(char *source, char *target) {
    int sourceLength = strlen(source);
    int targetLength = strlen(target);

    int distance[sourceLength+1][targetLength+1];
    for(int i=0; i<=sourceLength; i++) {
        for(int j=0; j<=targetLength; j++) {
            if(i==0)
                distance[i][j] = j;
            else if(j==0)
                distance[i][j] = i;
            else if(source[i-1] == target[j-1])
                distance[i][j] = distance[i-1][j-1];
            else
                distance[i][j] = 1 + minimum(distance[i][j-1], distance[i-1][j-1], distance[i-1][j]);
        }
    }

    return distance[sourceLength][targetLength];
}

int main() {
    char source[100], target[100];
    printf("Enter source string: ");
    scanf("%s", &source);
    printf("Enter target string: ");
    scanf("%s", &target);

    int distance = LevenshteinDistance(source, target);
    printf("Levenshtein Distance between %s and %s is: %d", source, target, distance);

    return 0;
}