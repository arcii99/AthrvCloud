//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Definition for a singly linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to insert a node at the beginning of a linked list
void insert_at_beginning(struct ListNode **head, int val) {
    struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

// Function to insert a node at the end of a linked list
void insert_at_end(struct ListNode **head, int val) {
    struct ListNode *new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
    new_node->val = val;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct ListNode *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Function to print the elements of a linked list
void print_list(struct ListNode *head) {
    struct ListNode *temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to perform bucket sort
void bucket_sort(int arr[], int size) {
    // Create an array of linked lists (buckets)
    struct ListNode *buckets[size];

    // Initialize the buckets
    for (int i = 0; i < size; i++) {
        buckets[i] = NULL;
    }

    // Insert the elements into the appropriate buckets
    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / 10;
        insert_at_end(&buckets[bucket_index], arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < size; i++) {
        struct ListNode *head = buckets[i];
        struct ListNode *current = head;
        while(current != NULL) {
            int key = current->val;
            struct ListNode *prev = NULL;
            struct ListNode *temp = head;

            while(temp != current && temp->val < key) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == current) {
                current = current->next;
                continue;
            }

            if (prev == NULL) {
                head = current;
            } else {
                prev->next = current;
            }

            struct ListNode *next_node = current->next;
            current->next = temp;

            current = next_node;
        }
        buckets[i] = head;
    }

    // Merge all the sorted buckets
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct ListNode *head = buckets[i];
        while(head != NULL) {
            arr[index++] = head->val;
            head = head->next;
        }
    }
}

int main() {
    // Initialize the array
    int arr[] = { 87, 67, 34, 56, 90, 23, 45, 78, 12, 23 };
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform bucket sort
    bucket_sort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}