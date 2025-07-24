//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_NUM 10
#define ARRAY_SIZE 100

typedef struct list_node{
    int value;
    struct list_node *next;
}ListNode;

ListNode *buckets[BUCKET_NUM];

void insert(bucket_index, value){
    // Create new node
    ListNode *new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = NULL;

    // Add new node to the bucket
    if(buckets[bucket_index] == NULL){
        buckets[bucket_index] = new_node;
    }else{
        ListNode *prev = NULL;
        ListNode *cur = buckets[bucket_index];
        while(cur != NULL && cur->value <= value){
            prev = cur;
            cur = cur->next;
        }

        if(prev == NULL){
            new_node->next = buckets[bucket_index];
            buckets[bucket_index] = new_node;
        }else{
            new_node->next = cur;
            prev->next = new_node;
        }
    }
}

void bucket_sort(int array[], int size){
    // Initialize each bucket
    for(int i = 0; i < BUCKET_NUM; i++){
        buckets[i] = NULL;
    }

    // Insert each item in the array into its corresponding bucket
    for(int i = 0; i < size; i++){
        int bucket_index = array[i]/BUCKET_NUM;
        insert(bucket_index, array[i]);
    }

    // Sort each bucket and concatenate the sorted buckets
    int j = 0;
    for(int i = 0; i < BUCKET_NUM; i++){
        ListNode *cur = buckets[i];
        while(cur != NULL){
            array[j++] = cur->value;
            cur = cur->next;
        }
    }
}

int main(){
    int array[ARRAY_SIZE];

    // Initialize the array with random numbers
    for(int i = 0; i < ARRAY_SIZE; i++){
        array[i] = rand() % 1000;
    }

    // Sort the array using bucket sort
    bucket_sort(array, ARRAY_SIZE);

    // Print the sorted array
    printf("Sorted Array:\n");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}