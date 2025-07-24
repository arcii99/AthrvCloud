//FormAI DATASET v1.0 Category: Browser Plugin ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main() { 
    int num;
    printf("Enter a positive integer to generate a pattern: ");
    scanf("%d", &num);

    if(num <= 0) {
        printf("Number should be positive");
        exit(0);
    }

    char pattern[num];

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            if(j % 2 == 0) {
                pattern[j] = '#';
            }
            else {
                pattern[j] = '@';
            }
        }
        printf("%.*s\n", i+1, pattern);
    }

    for(int i = num-1; i >= 1; i--) {
        printf("%.*s\n", i, pattern);
    }

    return 0;
}