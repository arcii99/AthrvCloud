//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: complete
#include<stdio.h>
#include<stdlib.h>

//creating a node for linked list
struct node {
    int data;
    struct node* next;
};

void bucketSort(int arr[], int n) {
    //creating an array of linked list
    struct node* bucket[n];
    int i, j;
    
    //initializing linked list as empty
    for(i = 0; i < n; i++) {
        bucket[i] = NULL;
    }
    
    //inserting elements into the linked list
    for(i = 0; i < n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;
        
        //finding the index of bucket
        int index = (n*arr[i])/10;
        
        //inserting the node into the linked list at the appropriate index
        if(bucket[index] == NULL) {
            bucket[index] = newNode;
        } else {
            struct node* temp = bucket[index];
            
            //inserting the node at the appropriate position in the linked list
            if(temp->data > newNode->data) {
                newNode->next = temp;
                bucket[index] = newNode;
            } else {
                while(temp->next && temp->next->data < newNode->data) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    
    //sorting the elements in the linked list
    for(i = 0; i < n; i++) {
        struct node* temp = bucket[i];
        
        //sorting the linked list using insertion sort algorithm
        while(temp) {
            struct node* next = temp->next;
            int k = i;
            while(k > 0 && temp->data < bucket[k-1]->data) {
                bucket[k] = bucket[k-1];
                k--;
            }
            bucket[k] = temp;
            temp->next = NULL;
            temp = next;
        }
    }
    
    //concatenating the linked lists into the final sorted array
    j = 0;
    for(i = 0; i < n; i++) {
        struct node* temp = bucket[i];
        while(temp) {
            arr[j++] = temp->data;
            temp = temp->next;
        }
    }
}

//function to print the elements of the array
void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 7, 5, 3, 9, 8, 1, 4, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted Array: ");
    printArray(arr, n);
    return 0;
}