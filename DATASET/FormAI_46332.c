//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define struct for the buckets
struct node {
    int value;
    struct node *next;
};

// Bucket Sort Function
void bucketSort(int arr[], int n) {
    // Initialize an array of buckets
    struct node *buckets[n];
    
    // Initialize every bucket with a NULL value
    for(int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }
    
    // Add elements to buckets
    for(int i = 0; i < n; i++) {
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        new_node->value = arr[i];
        new_node->next = NULL;
        
        int bucket_index = n * arr[i];
        
        // If the bucket is empty, add the element to the start of the list
        if(buckets[bucket_index] == NULL) {
            buckets[bucket_index] = new_node;
        }
        else {
            // Otherwise, add the element to the end of the list
            struct node *current = buckets[bucket_index];
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    
    // Sort the elements in each bucket using insertion sort
    for(int i = 0; i < n; i++) {
        struct node *current = buckets[i];
        
        while(current != NULL) {
            struct node *temp = current->next;
            
            while(temp != NULL && current->value > temp->value) {
                int temp_value = current->value;
                current->value = temp->value;
                temp->value = temp_value;
                
                temp = temp->next;
            }
            
            current = current->next;
        }
    }
    
    // Combine the sorted buckets into one array
    int index = 0;
    for(int i = 0; i < n; i++) {
        struct node *current = buckets[i];
        
        while(current != NULL) {
            arr[index] = current->value;
            index++;
            current = current->next;
        }
    }
}

// Main Function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bucketSort(arr, n);
    
    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}