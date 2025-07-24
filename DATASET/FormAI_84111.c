//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h> 
#include <string.h> 

int min(int a, int b, int c) 
{ 
    if(a <= b && a <= c) 
        return a; 
    if(b <= a && b <= c) 
        return b; 
    else
        return c; 
} 

int levenshtein_distance(char *str1, char *str2, int len1, int len2) 
{ 
    int ldist[len1 + 1][len2 + 1]; 
    for(int i = 0; i <= len1; i++) 
    { 
        for(int j = 0; j <= len2; j++) 
        { 
            if(i == 0) 
                ldist[i][j] = j; 
            else if(j == 0) 
                ldist[i][j] = i; 
            else if (str1[i - 1] == str2[j - 1]) 
                ldist[i][j] = ldist[i - 1][j - 1]; 
            else
                ldist[i][j] = 1 + min(ldist[i - 1][j], ldist[i][j - 1], ldist[i - 1][j - 1]); 
        } 
    } 
    return ldist[len1][len2]; 
} 

int main() 
{ 
    char str1[] = "kitten"; 
    char str2[] = "sitting"; 
    int len1 = strlen(str1); 
    int len2 = strlen(str2); 
    
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, levenshtein_distance(str1, str2, len1, len2)); 

    return 0; 
}