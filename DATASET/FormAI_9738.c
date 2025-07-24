//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: introspective
#include <stdio.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int me(char* s1, char* s2, int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (s1[m-1] == s2[n-1]) return me(s1, s2, m-1, n-1);
    return 1 + min(me(s1, s2, m, n-1), me(s1, s2, m-1, n), me(s1, s2, m-1, n-1));
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    int m = strlen(s1);
    int n = strlen(s2);
    printf("\nLevenshtein Distance: %d\n", me(s1, s2, m, n));
    return 0;
}