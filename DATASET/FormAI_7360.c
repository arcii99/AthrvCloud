//FormAI DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>

int main() {
    int arr[100], n, search, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &search);
    
    int flag = 0;
    for(i=0; i<n; i++) {
        if(arr[i] == search) {
            printf("%d found at position %d\n", search, i+1);
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) {
        printf("%d is not present in the array\n", search);
    }
    
    return 0;
}