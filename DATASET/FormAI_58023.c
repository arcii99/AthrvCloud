//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void bucketSort(int arr[], int n) {
    Node* buckets[BUCKET_SIZE];
    
    // Initialize buckets to null
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }
    
    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        if (buckets[index] == NULL) {
            buckets[index] = newNode;
        } else {
            Node* head = buckets[index];
            Node* prev = NULL;
            
            while (head != NULL && head->data <= newNode->data) {
                prev = head;
                head = head->next;
            }
            
            if (prev == NULL) {
                newNode->next = head;
                buckets[index] = newNode;
            } else {
                prev->next = newNode;
                newNode->next = head;
            }
        }
    }
    
    // Sort buckets and merge into arr
    int k = 0;
    
    for (int i = 0; i < BUCKET_SIZE; i++) {
        Node* head = buckets[i];
        int temp[BUCKET_SIZE];
        int j = 0;
        
        while (head != NULL) {
            temp[j++] = head->data;
            head = head->next;
        }
        
        // Sort temp
        for (int p = 0; p < j - 1; p++) {
            for (int q = p + 1; q < j; q++) {
                if (temp[p] > temp[q]) {
                    int temp1 = temp[p];
                    temp[p] = temp[q];
                    temp[q] = temp1;
                }
            }
        }
        
        // Merge temp into arr
        for (int p = 0; p < j; p++) {
            arr[k++] = temp[p];
        }
    }
}

int main() {
    int arr[10] = {7, 3, 9, 4, 8, 2, 6, 5, 1, 0};
    bucketSort(arr, 10);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}