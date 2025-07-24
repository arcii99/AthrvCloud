//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    }
    else if(b < a && b < c) {
        return b;
    }
    else {
        return c;
    }
}

int recursiveLevenshteinDistance(char* str1, char* str2, int m, int n) {
    if(m == 0) {
        return n;
    }
    else if(n == 0) {
        return m;
    }
    else if(str1[m-1] == str2[n-1]) {
        return recursiveLevenshteinDistance(str1, str2, m-1, n-1);
    }
    else {
        return 1 + min(recursiveLevenshteinDistance(str1, str2, m, n-1),      //Insert 
                        recursiveLevenshteinDistance(str1, str2, m-1, n),     //Remove
                        recursiveLevenshteinDistance(str1, str2, m-1, n-1));  //Replace
    }
}

int main() {
    char str1[100], str2[100];
    int m, n, result;
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    m = strlen(str1);
    n = strlen(str2);
    
    result = recursiveLevenshteinDistance(str1, str2, m, n);
    printf("The Levenshtein Distance between %s and %s is %d\n", str1, str2, result);
    return 0;
}