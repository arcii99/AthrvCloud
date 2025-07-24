//FormAI DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>

int medieval_search(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            printf("Found the treasure at index %d, m'lord!\n", mid);
            return mid;
        }
        else if (arr[mid] < x) {
            printf("No treasure here, m'lord! Moving to the right...\n");
            left = mid + 1;
        }
        else {
            printf("No treasure here, m'lord! Moving to the left...\n");
            right = mid - 1;
        }
    }
    printf("Alas, we could not find the treasure :(\n");
    return -1;
}

int main() {
    int treasure_map[] = {2, 4, 7, 8, 10, 11, 13, 15, 16, 17, 20};
    int treasure_hunters = sizeof(treasure_map) / sizeof(treasure_map[0]);
    int treasure = 16;
    medieval_search(treasure_map, treasure_hunters, treasure);
    return 0;
}