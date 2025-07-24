//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: invasive
#include<stdio.h>
#include<string.h>

int min(int a, int b, int c);

int levenshtein_distance(char *str1, char *str2){
    int rows = strlen(str1)+1;
    int cols = strlen(str2)+1;

    int table[rows][cols];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i==0) table[i][j] = j;
            else if(j==0) table[i][j] = i;
            else if(str1[i-1] == str2[j-1]) table[i][j] = table[i-1][j-1];
            else
                table[i][j] = 1 + min(table[i-1][j], table[i][j-1], table[i-1][j-1]);
        }
    }
    return table[rows-1][cols-1];
}

int min(int a, int b, int c){
    if(a<b && a<c) return a;
    if(b<a && b<c) return b;
    return c;
}

int main(){
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Levenshtein Distance between %s and %s is %d", str1, str2, levenshtein_distance(str1,str2));
    return 0;
}