//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    int n, i, j;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    int s[n], f[n];
    printf("Enter the start and finish times of activities:\n");
    for(i = 0; i < n; i++) {
        printf("Activity %d: ", i+1);
        scanf("%d %d", &s[i], &f[i]);
    }
    // sort the activities in non-decreasing order of finish time
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(f[i] > f[j]) {
                int temp = f[i];
                f[i] = f[j];
                f[j] = temp;
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("\nSelected activities are:\n");
    i = 0;
    printf("Activity %d\n", i+1);
    for(j = 1; j < n; j++) {
        if(s[j] >= f[i]) {
            printf("Activity %d\n", j+1);
            i = j;
        }
    }
    return 0;
}