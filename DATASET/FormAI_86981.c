//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include<stdio.h>

int main(){

    int array[100];
    int i, n, search, found=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: \n");
    
    for(i=0;i<n;i++){
        scanf("%d", &array[i]);
    }
    
    printf("Enter the number you want to search: ");
    scanf("%d", &search);
    
    for(i=0;i<n;i++){
        if(array[i] == search){
            printf("%d is found at index %d\n", search, i);
            found = 1;
        }
    }
    
    if(found == 0){
        printf("Sorry, %d was not found in the array\n", search);
    }
    
    return 0;
}