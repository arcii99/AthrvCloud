//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<a && b<c)
        return b;
    else
        return c;
}

int levenshtein(char* string1, char* string2, int length1, int length2){
    int matrix[length1+1][length2+1];
    int i,j;
    for(i=0; i<=length1; i++){
        for(j=0; j<=length2; j++){
            if(i==0)
                matrix[i][j] = j;
            else if(j==0)
                matrix[i][j] = i;
            else if(string1[i-1]==string2[j-1])
                matrix[i][j] = matrix[i-1][j-1];
            else
                matrix[i][j] = 1 + min(matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]);
        }
    }
    return matrix[length1][length2];
}

int main(){
    char string1[100], string2[100];
    printf("Input first string: ");
    scanf("%s", string1);
    printf("Input second string: ");
    scanf("%s", string2);
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int levenshtein_distance = levenshtein(string1, string2, length1, length2);
    printf("Levenshtein Distance is %d\n", levenshtein_distance);
    return 0;
}