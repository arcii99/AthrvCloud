//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a simple linked-list node to store elements in each bucket
struct node {
    int value;
    struct node *next;
};

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucket_sort(int arr[], int n) {
    // create n buckets, initialize them as empty linked-lists
    struct node *buckets[n];
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // distribute the array elements into different buckets based on their value
    for (int i = 0; i < n; i++) {
        int indx = arr[i] / n;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->value = arr[i];
        new_node->next = NULL;
        if (buckets[indx] == NULL) {
            buckets[indx] = new_node;
        } else {
            struct node *temp = buckets[indx];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    // sort elements within each bucket using Insertion Sort
    for (int i = 0; i < n; i++) {
        if (buckets[i] != NULL) {
            struct node *temp = buckets[i];
            int len = 0;
            while (temp != NULL) {
                len++;
                temp = temp->next;
            }
            int temp_arr[len];
            temp = buckets[i];
            for (int j = 0; j < len; j++) {
                temp_arr[j] = temp->value;
                temp = temp->next;
            }
            insertion_sort(temp_arr, len);
            temp = buckets[i];
            for (int j = 0; j < len; j++) {
                temp->value = temp_arr[j];
                temp = temp->next;
            }
        }
    }

    // merge all sorted buckets into the original array
    int indx = 0;
    for (int i = 0; i < n; i++) {
        if (buckets[i] != NULL) {
            struct node *temp = buckets[i];
            while (temp != NULL) {
                arr[indx] = temp->value;
                temp = temp->next;
                indx++;
            }
        }
    }
}

int main() {
    int arr[] = {42, 12, 34, 26, 39, 81, 43, 33, 55, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}