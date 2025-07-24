//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Sorting Circus!\n");
    printf("Prepare to be amazed as we sort numbers with magic!\n");

    int magic_nums[10] = {1, 8, 3, 5, 6, 2, 4, 7, 9, 0};
    int num_acts = 5;

    printf("\nIn our first act, we'll be using the Bubble Sort of Doom...\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (magic_nums[j] > magic_nums[j + 1]) {
                int temp = magic_nums[j];
                magic_nums[j] = magic_nums[j + 1];
                magic_nums[j + 1] = temp;
            }
        }
    }
    printf("And voila! Our numbers are now sorted with the power of bubbles!\n");

    printf("\nNext up, we have the Groovy Gnome Sort...\n");
    for (int i = 1; i < 10; i++) {
        if (magic_nums[i] < magic_nums[i - 1]) {
            int temp = magic_nums[i];
            magic_nums[i] = magic_nums[i - 1];
            magic_nums[i - 1] = temp;
            i = 0;
        }
    }
    printf("Wow, that gnome really had some moves! Our numbers are sorted once again!\n");

    printf("\nNow, prepare yourselves for the Quick Sort of Chaos...\n");
    quick_sort(magic_nums, 0, 9);
    printf("We just sorted those numbers faster than you can say 'quicksort'!\n");

    printf("\nFor our next trick, we'll be using the Super Sleek Selection Sort...\n");
    for (int i = 0; i < 10; i++) {
        int min_index = i;
        for (int j = i + 1; j < 10; j++) {
            if (magic_nums[j] < magic_nums[min_index]) {
                min_index = j;
            }
        }
        int temp = magic_nums[i];
        magic_nums[i] = magic_nums[min_index];
        magic_nums[min_index] = temp;
    }
    printf("And just like that, our numbers are sorted with the grace of a swan!\n");

    printf("\nFinally, we'll be using the Majestic Merge Sort...\n");
    merge_sort(magic_nums, 0, 9);
    printf("Our numbers have been sorted with the majesty of a bald eagle!\n");

    printf("\nThank you for joining us at the Sorting Circus! We hope you enjoyed the show!\n");

    return 0;
}

void quick_sort(int* arr, int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int partition(int* arr, int low, int high) {
    int pivot_value = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot_value) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void merge_sort(int* arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int* arr, int low, int mid, int high) {
    int left_len = mid - low + 1;
    int right_len = high - mid;

    int* left_half = (int*)malloc(sizeof(int) * left_len);
    int* right_half = (int*)malloc(sizeof(int) * right_len);

    for (int i = 0; i < left_len; i++) {
        left_half[i] = arr[low + i];
    }
    for (int i = 0; i < right_len; i++) {
        right_half[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < left_len && j < right_len) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        } else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < left_len) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < right_len) {
        arr[k] = right_half[j];
        j++;
        k++;
    }

    free(left_half);
    free(right_half);
}