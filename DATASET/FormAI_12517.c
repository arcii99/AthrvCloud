//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>

int main() {
    int n, m;
    printf("Enter n and m respectively: ");
    scanf("%d %d", &n, &m);
    char words[n][m];
    printf("Enter %d words each of which has maximum length of %d: \n", n, m);
    for(int i = 0; i < n; i++) {
        scanf("%s", &words[i]);
    }

    printf("\n Here are the words in the array: \n");
    for(int i = 0; i < n; i++) {
        printf("%s \n", words[i]);
    }

    // Bubble sort to sort the words in the array in alphabetical order
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            int k = 0;
            while(words[j][k] == words[j+1][k]) {
                k++;
            }
            if(words[j][k] > words[j+1][k]) {
                char temp[m];
                for(int l = 0; l < m; l++) {
                    temp[l] = words[j][l];
                    words[j][l] = words[j+1][l];
                    words[j+1][l] = temp[l];
                }
            }
        }
    }

    printf("\n Here are the words sorted in alphabetical order: \n");
    for(int i = 0; i < n; i++) {
        printf("%s \n", words[i]);
    }

    return 0;
}