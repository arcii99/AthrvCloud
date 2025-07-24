//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: automated
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if(a < b && a < c) {
        return a;
    } else if(b < c) {
        return b;
    } else {
        return c;
    }
}

int lev_distance(char *str1, char *str2, int len1, int len2) {
    if(len1 == 0) {
        return len2;
    } else if(len2 == 0) {
        return len1;
    }

    int a, b, c;

    if(str1[len1 - 1] == str2[len2 - 1]) {
        return lev_distance(str1, str2, len1 - 1, len2 - 1);
    } else {
        a = lev_distance(str1, str2, len1 - 1, len2) + 1;
        b = lev_distance(str1, str2, len1, len2 - 1) + 1;
        c = lev_distance(str1, str2, len1 - 1, len2 - 1) + 1;

        return min(a, b, c);
    }
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    printf("Levenshtein Distance between %s and %s is: %d", str1, str2, lev_distance(str1, str2, len1, len2));

    return 0;
}