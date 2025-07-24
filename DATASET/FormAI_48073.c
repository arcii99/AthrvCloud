//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define struct to hold linked list nodes
struct node {
  int data;
  struct node* next;
};

// Define function to insert node into linked list
void insert(struct node** head, int val) {
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = val;
  new_node->next = (*head);
  (*head) = new_node;
}

// Define function to perform bucket sort
void bucketSort(int arr[], int n) {
  // Initialize buckets
  int num_buckets = 10;
  struct node* buckets[num_buckets];
  
  // Set all buckets to NULL
  for(int i=0; i<num_buckets; i++) {
    buckets[i] = NULL;
  }
  
  // Insert elements into buckets
  for(int i=0; i<n; i++) {
    int bucket_idx = arr[i] / num_buckets;
    insert(&buckets[bucket_idx], arr[i]);
  }
  
  // Sort each bucket and merge results
  int idx = 0;
  for(int i=0; i<num_buckets; i++) {
    struct node* curr = buckets[i];
    int temp_arr[n];
    int j = 0;
    
    // Copy values from linked list node to temp array
    while(curr != NULL) {
      temp_arr[j] = curr->data;
      curr = curr->next;
      j++;
    }
    
    // Sort temp array using bubble sort
    for(int k=0; k<j-1; k++) {
      for(int l=0; l<j-k-1; l++) {
        if(temp_arr[l] > temp_arr[l+1]) {
          int temp = temp_arr[l];
          temp_arr[l] = temp_arr[l+1];
          temp_arr[l+1] = temp;
        }
      }
    }
    
    // Copy sorted values back into original array
    for(int k=0; k<j; k++) {
      arr[idx] = temp_arr[k];
      idx++;
    }
  }
}

// Define main function to test bucket sort
int main() {
  int arr[] = { 54, 46, 83, 66, 95, 92, 43 };
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("Before sorting:\n");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  bucketSort(arr, n);
  
  printf("After sorting:\n");
  for(int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}