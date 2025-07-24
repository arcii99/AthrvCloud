//FormAI DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>

int main() {
    int surreal_array[] = {1, 6, 3, 8, 4, 5, 7, 2};
    int length = sizeof(surreal_array) / sizeof(surreal_array[0]);

    printf("Welcome to the surreal sorting program!\n");

    printf("Before sorting:\t");
    for(int i=0; i<length; i++) {
        printf("%d ", surreal_array[i]);
    }
    printf("\n\n");

    // Begin surreal sorting algorithm
    int current_index = 0;

    while(current_index < length) {
        printf("Current index: %d\n", current_index);

        int target_index = -1;

        for(int i=0; i<length; i++) {
            if(i == current_index) {
                continue;
            }

            if(surreal_array[i] % surreal_array[current_index] == 0) {
                target_index = i;
                break;
            }
        }

        if(target_index == -1) {
            printf("No valid targets found! Moving to next item.\n");
            current_index++;
            continue;
        }

        if(target_index < current_index) {
            printf("Target index (%d) is less than current index (%d). Swapping.\n", target_index, current_index);

            int temp = surreal_array[target_index];
            surreal_array[target_index] = surreal_array[current_index];
            surreal_array[current_index] = temp;
        } else {
            printf("Target index (%d) is greater than current index (%d). Moving to next item.\n", target_index, current_index);
        }

        printf("Current array state:\t");
        for(int i=0; i<length; i++) {
            printf("%d ", surreal_array[i]);
        }
        printf("\n\n");

        current_index++;
    }
    // End surreal sorting algorithm

    printf("After sorting:\t");
    for(int i=0; i<length; i++) {
        printf("%d ", surreal_array[i]);
    }
    printf("\n");

    return 0;
}