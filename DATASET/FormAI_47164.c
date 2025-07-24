//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

/* Define node structure for linked list */
typedef struct node {
    int data;
    struct node* next;
} node_t;

/* Function to insert element into linked list */
void insert(node_t** head, int data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    
    /* Check if head is empty */
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        node_t* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

/* Function to print linked list */
void print_list(node_t* head) {
    node_t* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/* Function to sort array using bucket sort */
void bucket_sort(int arr[], int n) {
    int i, j;
    node_t* buckets[BUCKET_SIZE] = { NULL };
    
    /* Insert elements into buckets */
    for (i = 0; i < n; i++) {
        int bucket_index = arr[i] / BUCKET_SIZE;
        insert(&buckets[bucket_index], arr[i]);
    }
    
    /* Sort elements within each bucket */
    for (i = 0; i < BUCKET_SIZE; i++) {
        node_t* curr = buckets[i];
        int temp_arr[BUCKET_SIZE] = { 0 };
        while (curr != NULL) {
            temp_arr[curr->data % BUCKET_SIZE]++;
            curr = curr->next;
        }
        curr = buckets[i];
        for (j = 0; j < BUCKET_SIZE && curr != NULL; j++) {
            while (temp_arr[j] > 0 && curr != NULL) {
                curr->data = i * BUCKET_SIZE + j;
                temp_arr[j]--;
                curr = curr->next;
            }
        }
    }
    
    /* Copy sorted elements back into original array */
    int k = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        node_t* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

/* Main program */
int main() {
    int arr[] = { 29, 25, 3, 49, 9, 37, 21, 43 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bucket_sort(arr, n);
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}