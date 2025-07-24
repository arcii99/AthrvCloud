//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

void insert(struct node** head_ref, int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void bucketSort(float arr[], int n) {
    struct node* buckets[n];
    int i, j;
    
    for (i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] * n;
        insert(&buckets[bucket_index], arr[i]);
    }
    
    for (i = 0; i < n; i++) {
        struct node* curr = buckets[i];
        float temp_arr[n];
        int idx = 0;
        
        while (curr) {
            temp_arr[idx] = curr->val;
            idx++;
            curr = curr->next;
        }
        
        for (j = 0; j < idx - 1; j++) {
            int min_idx = j;
            for (int k = j + 1; k < idx; k++) {
                if (temp_arr[k] < temp_arr[min_idx]) {
                    min_idx = k;
                }
            }
            
            float temp = temp_arr[j];
            temp_arr[j] = temp_arr[min_idx];
            temp_arr[min_idx] = temp;
        }
        
        curr = buckets[i];
        idx = 0;
        while (curr) {
            curr->val = temp_arr[idx];
            curr = curr->next;
            idx++;
        }
    }
    
    int index = 0;
    for (i = 0; i < n; i++) {
        struct node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->val;
            curr = curr->next;
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bucketSort(arr, n);
    
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}