//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>

void sort(int arr[], int n) { // sort in non-ascending order
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, i, j, count = 0; // n = number of jobs, count = number of jobs scheduled
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int s[n], f[n], t[n]; // s = start time, f = finish time, t = time taken
    printf("Enter the start time and time taken for each job:\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d",&s[i],&t[i]);
        f[i] = s[i] + t[i];
    }
    sort(f, n); // sort finish times in non-ascending order
    int schedule[n]; // list of scheduled jobs
    schedule[count++] = 0; // schedule first job
    j = 0; // index of last selected job
    for (i = 1; i < n; i++) {
        if (s[i] >= f[j]) { // if job doesn't overlap with last selected job
            schedule[count++] = i; // schedule job
            j = i; // update last selected job
        }
    }
    printf("Optimal schedule: ");
    for (i = 0; i < count; i++) {
        printf("%d ", schedule[i]+1); // print job numbers
    }
    printf("\nTotal jobs scheduled: %d\n", count);
    return 0;
}