//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c){
    return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

int levenshtein(char *str1, char *str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    int distTable[len1+1][len2+1];

    for(int i=0; i<=len1; i++){
        for(int j=0; j<=len2; j++){
            if(i==0)
                distTable[i][j] = j;
            else if(j==0)
                distTable[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                distTable[i][j] = distTable[i-1][j-1];
            else
                distTable[i][j] = 1 + min(distTable[i-1][j], distTable[i][j-1], distTable[i-1][j-1]);
        }
    }
    return distTable[len1][len2];
}

int main(){
    char input1[100], input2[100];
    printf("Welcome to our Levenshtein Distance Calculator\n");
    printf("Enter the first word: ");
    scanf("%s", input1);
    printf("Enter the second word: ");
    scanf("%s", input2);

    int distance = levenshtein(input1, input2);
    printf("The Levenshtein Distance between %s and %s is: %d\n", input1, input2, distance);
    return 0;
}