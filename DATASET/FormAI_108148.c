//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// define the structure for a node in the linked list
typedef struct node {
  int data;
  struct node* next;
} node_t;

void bucket_sort(int arr[], int n) {
  // calculate the maximum element in the array
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // create an array of linked lists (buckets)
  node_t* buckets[max + 1];
  for (int i = 0; i < max + 1; i++) {
    buckets[i] = NULL;
  }

  // fill the buckets with elements from the input array
  for (int i = 0; i < n; i++) {
    node_t* new_node = malloc(sizeof(node_t));
    new_node->data = arr[i];
    new_node->next = buckets[arr[i]];
    buckets[arr[i]] = new_node;
  }

  // sort the individual linked lists
  for (int i = 0; i < max + 1; i++) {
    node_t* head = buckets[i];
    node_t* prev = NULL;
    while (head) {
      if (prev && prev->data > head->data) {
        prev->next = head->next;
        head->next = prev;
        if (prev == buckets[i]) {
          buckets[i] = head;
        } else {
          prev = buckets[i];
          while (prev->next != head) {
            prev = prev->next;
          }
        }
      } else {
        prev = head;
        head = head->next;
      }
    }
  }

  // copy the elements back into the input array
  int index = 0;
  for (int i = 0; i < max + 1; i++) {
    node_t* head = buckets[i];
    while (head) {
      arr[index++] = head->data;
      head = head->next;
    }
  }
}

int main() {
  int arr[] = {2, 5, 1, 8, 3, 9, 4, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  bucket_sort(arr, n);

  printf("Sorted array: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}