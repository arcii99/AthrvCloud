//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a<b && a<c) ? a : (b<a && b<c) ? b : c;
}

int levenshtein_distance(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int* d = (int*)malloc((len1+1)*(len2+1)*sizeof(int));

    for(int i=0; i<=len1; i++) {
        for(int j=0; j<=len2; j++) {
            if(i==0) {
                *(d+j*(len1+1)) = j;
            }
            else if(j==0) {
                *(d+i) = i;
            }
            else {
                int substitution_cost = (*(s1+i-1) == *(s2+j-1)) ? 0 : 1;
                *(d+i+j*(len1+1)) = min(*(d+i-1+j*(len1+1))+1, *(d+i+(j-1)*(len1+1))+1, *(d+i-1+(j-1)*(len1+1))+substitution_cost);
            }
        }
    }

    int ld = *(d+len1+len2*(len1+1));
    free(d);
    return ld;
}

int main() {
    char* s1 = "mind-bending";
    char* s2 = "Levenshtein Distance";

    int ld = levenshtein_distance(s1, s2);

    printf("The Levenshtein distance between %s and %s is: %d\n", s1, s2, ld);

    return 0;
}