//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000000 // Define maximum number of elements in the array

typedef struct node { // Define a structure for a node in linked list
int value;
struct node* next;
}node;

void bucket_sort(int arr[], int n) { // Define the function bucket_sort that takes an array and its size as inputs
node* buckets[N]; // Create an array of N nodes, where N is the maximum number of elements in the array
for(int i=0;i<N;i++) // Initialize all nodes to NULL initially
buckets[i] = NULL; 
for(int i=0;i<n;i++) { // Traverse through all elements in the input array
int index = arr[i]/10; // Determine the index of bucket to which the element should go
node* temp = (node*) malloc(sizeof(node)); // Create a new node for the element
temp->value = arr[i];
temp->next = NULL; // Initialize the next pointer to NULL
if(buckets[index] == NULL) // If the bucket is empty, insert the new node as the head of the linked list
buckets[index] = temp;
else { // If the bucket is not empty, insert the new node at its correct position in the linked list
node* curr = buckets[index];
node* prev = NULL;
while(curr != NULL && curr->value < temp->value) {
prev = curr;
curr = curr->next;
}
if(prev == NULL) {
temp->next = buckets[index];
buckets[index] = temp;
}
else {
temp->next = prev->next;
prev->next = temp;
}
}
}
int j = 0;
for(int i=0;i<N;i++) { // Traverse through all buckets
node* curr = buckets[i];
while(curr != NULL) { // Traverse through the linked list in each bucket
arr[j++] = curr->value; // Copy the element to the output array
node* temp = curr;
curr = curr->next; // Move to the next element in the linked list
free(temp); // Free the memory of the current node
}
buckets[i] = NULL; // Reset the bucket to NULL
}
}

int main() {
int arr[N], n;
srand(time(NULL)); // Seed the random number generator with current time
for(int i=0;i<N;i++) // Generate random numbers and store them in the input array
arr[i] = rand()%N;
clock_t t1, t2;
t1 = clock(); // Record start time before sorting
bucket_sort(arr, N); // Sort the array using bucket sort
t2 = clock(); // Record end time after sorting
double elapsed_time = (double) (t2-t1)/CLOCKS_PER_SEC;
printf("Time elapsed for bucket sort: %lf seconds\n", elapsed_time); // Display time taken for sorting
return 0;
}