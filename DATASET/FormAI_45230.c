//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {

    char str1[100], str2[100];
    int len1, len2, count = 0;

    printf("Hello there! I am the Levenshtein Distance Calculator.\n");
    printf("Please enter the first string: ");
    fgets(str1, 100, stdin);

    printf("Great, now please enter the second string: ");
    fgets(str2, 100, stdin);

    len1 = strlen(str1) - 1;
    len2 = strlen(str2) - 1;

    int table[len1+1][len2+1];
    memset(table, 0, sizeof(table));

    printf("\nCalculating the Levenshtein Distance...\n\n");

    for(int i = 1; i <= len1; i++){
        table[i][0] = i;
    }

    for(int j = 1; j <= len2; j++){
        table[0][j] = j;
    }

    for(int i = 1; i <= len1; i++){
        for(int j=1; j <= len2; j++){
            if(str1[i-1]==str2[j-1]){
                table[i][j] = table[i-1][j-1];
            }
            else{
                table[i][j] = 1 + minimum(table[i-1][j-1], table[i-1][j], table[i][j-1]);
            }
        }
    }

    printf("Levenshtein Distance: %d\n",table[len1][len2]);

    printf("\nThank you for using the Levenshtein Distance Calculator! I hope your strings were not too far apart.\n");

    return 0;
}

int minimum(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }
    return min;
}