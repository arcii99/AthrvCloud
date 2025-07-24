//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 50

int min(int a, int b, int c){
    int result = a;
    if(b < result){
        result = b;
    }
    if(c < result){
        result = c;
    }
    return result;
}

int levenshteinDistance(char *str1, char *str2){
    int lengthStr1 = strlen(str1);
    int lengthStr2 = strlen(str2);
    int distance[lengthStr1+1][lengthStr2+1];
    
    for(int i=0; i<=lengthStr1; i++){
        distance[i][0] = i;
    }
    for(int j=0; j<=lengthStr2; j++){
        distance[0][j] = j;
    }
    
    for(int i=1; i<=lengthStr1; i++){
        char c1 = str1[i-1];
        for(int j=1; j<=lengthStr2; j++){
            char c2 = str2[j-1];
            if(c1 == c2){
                distance[i][j] = distance[i-1][j-1];
            } else {
                int deletion = distance[i-1][j] + 1;
                int insertion = distance[i][j-1] + 1;
                int substitution = distance[i-1][j-1] + 1;
                distance[i][j] = min(deletion, insertion, substitution);
            }
        }
    }
    return distance[lengthStr1][lengthStr2];
}

int main(){
    char str1[MAX_STRING_LEN], str2[MAX_STRING_LEN];
    printf("Enter the first string:\n");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string:\n");
    fgets(str2, sizeof(str2), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // remove newline character
    str2[strcspn(str2, "\n")] = '\0'; // remove newline character
    
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein distance between %s and %s is %d\n", str1, str2, distance);
    
    return 0;
}