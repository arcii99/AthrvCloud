//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {

    int n, sub[MAX], start, end, count = 0, i, j, temp;

    printf("Enter number of subarrays: ");
    scanf("%d", &n);

    //taking input of subarrays
    printf("Enter %d subarrays: \n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &sub[i]);
    }

    //sorting the subarrays
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (sub[i] > sub[j]) {
            temp = sub[i];
            sub[i] = sub[j];
            sub[j] = temp;
            }
        }
    }

    //finding the maximum number of non-overlapping subarrays
    start = sub[0];
    end = sub[0];
    for (i = 1; i < n; i++) {
        if (sub[i] > end) {
            end = sub[i];
            count++;
        }
    }

    printf("Maximum number of non-overlapping subarrays: %d", count+1);

    return 0;
}