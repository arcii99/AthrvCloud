//FormAI DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>

/* Define array */
int arr[] = {5, 2, 7, 12, 9, 4, 15, 21};

/* Define function to search for target value */
int search(int target){
    int i;
    for(i = 0; i < sizeof(arr)/sizeof(int); i++){
        if(arr[i] == target){
            printf("Target value %d found at index %d\n", target, i);
            return i;
        }
    }
    printf("Target value %d not found\n", target);
    return -1;
}

int main(){
    int target = 15;
    
    /* Call search function */
    search(target);
    
    return 0;
}