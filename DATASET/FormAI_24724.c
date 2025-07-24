//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int a, int b, int c) {
   return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshtein_distance(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int distance[MAX_LENGTH][MAX_LENGTH];

    for(int i = 0; i <= s1_len; i++){
        for(int j = 0; j <= s2_len; j++){
            if(i == 0){
                distance[i][j] = j;
            }
            else if(j == 0){
                distance[i][j] = i;
            }
            else if(s1[i-1] == s2[j-1]){
                distance[i][j] = distance[i-1][j-1];
            }
            else{
                distance[i][j] = min(distance[i-1][j], distance[i][j-1], distance[i-1][j-1]) + 1;
            }
        }
    }
    
    return distance[s1_len][s2_len];
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance between %s and %s is %d", str1, str2, distance);

    return 0;
}