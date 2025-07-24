//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>

/*
 * This program implements a secure linear search algorithm.
 * It searches for an integer value in a given array of integers.
 * If the value is found, it returns the index of the value in the array.
 * If the value is not found, it returns -1.
 * The program is designed to prevent buffer overflows and other attacks.
 */

int secure_linear_search(int array[], int size, int key){
    int index = -1;
    
    if(size <= 0){
        return -1;
    }
    
    for(int i = 0; i < size; i++){
        if(array[i] == key){
            index = i;
            break;
        }
    }
    
    return index;
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int key, index;
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    index = secure_linear_search(array, size, key);
    
    if(index == -1){
        printf("Key not found.\n");
    }
    else{
        printf("Key found at index %d.\n", index);
    }
    
    return 0;
}