//FormAI DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[20];
    int i, j, n, m, count = 0;

    printf("Enter some text : ");
    gets(text);

    printf("Enter a pattern : ");
    gets(pattern);

    n = strlen(text);
    m = strlen(pattern);

    for(i=0; i<=(n-m); i++) {
        for(j=0; j<m; j++) {
            if(text[i+j] != pattern[j]) {
                break;
            }
        }
        if(j == m) {
            count++;
        }
    }

    printf("Total occurrences of the pattern is : %d", count);

    return 0;
}