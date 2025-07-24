//FormAI DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Pre-apocalyptic search algorithm
int preapoc_search(int nums[], int target, int len) {
    int high = len - 1;
    int low = 0;
    int mid;

    while (low <= high) {
        mid = low + ((high - low) / 2);

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

// Post-apocalyptic search algorithm
int postapoc_search(int nums[], int target, int len) {
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high) {
        mid = low + ((high - low) / 2);

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            high = mid - 1;
        } else {
            // Zombie attack detected! Run for your life!
            printf("\nALERT: Zombie attack detected!\n");
            printf("Low on ammo. Switching to melee weapon.\n\n");

            int i;
            for (i = mid + 1; i <= high; i++) {
                if (nums[i] == target) {
                    return i;
                }
            }

            return -1;
        }
    }

    return -1;
}

int main() {
    int nums[] = {2, 5, 8, 11, 15, 18, 22, 27, 31, 35};
    int len = sizeof(nums) / sizeof(nums[0]);
    int target = 18;

    printf("Searching for %d using pre-apocalyptic search...\n", target);
    int preapoc_index = preapoc_search(nums, target, len);
    printf("Found %d at index %d.\n", target, preapoc_index);

    printf("\n\nPreparing for post-apocalyptic search...\n");
    printf("Gathering resources...\n");
    printf("Scavenging for food and supplies...\n");
    printf("Loading weapons...\n\n");

    printf("Searching for %d using post-apocalyptic search...\n", target);
    int postapoc_index = postapoc_search(nums, target, len);

    if (postapoc_index == -1) {
        printf("ALERT: %d not found. Zombies are approaching!\n", target);
    } else {
        printf("Found %d at index %d.\n", target, postapoc_index);
    }

    exit(0);
}