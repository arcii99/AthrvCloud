//FormAI DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining structure for indexing
typedef struct{
    int key;
    char value[50];
} Index;

int main(){

    Index collection[10] = {  // Initializing our collection data
        {1, "apple"},
        {2, "banana"},
        {3, "cherry"},
        {4, "date"},
        {5, "elderberry"},
        {6, "fig"},
        {7, "grape"},
        {8, "honeydew"},
        {9, "kiwi"},
        {10, "lemon"}
    };

    int num_of_items = sizeof(collection) / sizeof(Index);  // Calculating number of items in our collection

    // Defining a binary search function for our indexing system
    int binary_search(Index arr[], int low, int high, int key){
        while(low <= high){
            int mid = (low + high) / 2;
            if(key == arr[mid].key){
                return mid;
            } else if(key < arr[mid].key){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    // Asking user for input and searching 
    int user_input = 0;
    printf("Enter a number between 1 and 10: ");
    scanf("%d", &user_input);
    int result = binary_search(collection, 0, num_of_items - 1, user_input);

    if(result >= 0){
        printf("The value for the key %d is %s.\n", collection[result].key, collection[result].value);
    } else {
        printf("No matching key found.\n");
    }

    return 0;
}