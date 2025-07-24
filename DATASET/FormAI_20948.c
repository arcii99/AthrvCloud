//FormAI DATASET v1.0 Category: Searching algorithm ; Style: secure
#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE], size, i, element, index = -1;
    
    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter elements in array: ");
    for(i=0; i<size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("\nEnter element to search: ");
    scanf("%d", &element);
    
    // Linear search algorithm
    for(i=0; i<size; i++) {
        if(array[i] == element) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        printf("\n%d not found in the array.\n", element);
    }
    else {
        printf("\n%d found at position %d in the array.\n", element, index+1);
    }
    
    return 0;
}