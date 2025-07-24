//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include <stdio.h>
#include <string.h>

int lev(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);

    int d[s1_len + 1][s2_len + 1];

    for(int i = 0; i <= s1_len; i++) {
        d[i][0] = i;
    }

    for(int j = 0; j <= s2_len; j++) {
        d[0][j] = j;
    }

    for(int i = 1; i <= s1_len; i++) {
        for(int j = 1; j <= s2_len; j++) {
            int cost;
            if(s1[i-1] == s2[j-1]) {
                cost = 0;
            }
            else {
                cost = 1;
            }

            int min = d[i-1][j] + 1;
            if(d[i][j-1] + 1 < min) {
                min = d[i][j-1] + 1;
            }
            if(d[i-1][j-1] + cost < min) {
                min = d[i-1][j-1] + cost;
            }
            d[i][j] = min;
        }
    }

    return d[s1_len][s2_len];
}

int main() {
    char s1[] = "This is a surreal C Levenshtein Distance Calculator";
    char s2[] = "It creates confusion and depth in a parallel universe";

    printf("The Levenshtein Distance is %d\n", lev(s1, s2));

    return 0;
}

/* Output:
The Levenshtein Distance is 48 */