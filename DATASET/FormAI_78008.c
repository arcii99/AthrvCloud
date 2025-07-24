//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct activity {
  int start, finish;
};

int cmp(const void* a, const void* b) {
    return ((struct activity*)a)->finish - ((struct activity*)b)->finish;
}
 
void printMaxActivities(struct activity arr[], int n) {
    qsort(arr, n, sizeof(struct activity), cmp);
    int i = 0, j;
    printf("\nSelected activities are: ");
    printf("(Start Time, Finish Time)\n");
    printf("(%d, %d) ", arr[i].start, arr[i].finish);
    for (j = 1; j < n; j++){
      if (arr[j].start >= arr[i].finish) {
        printf("(%d, %d) ", arr[j].start, arr[j].finish);
        i = j;
      }
    }
}
 
int main() {
    struct activity arr[] = {{1, 2}, {3, 4}, {0, 5}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}