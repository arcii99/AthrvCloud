//FormAI DATASET v1.0 Category: Searching algorithm ; Style: invasive
#include<stdio.h>

//function to print the array
void PrintArray(int A[], int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

//function to perform Invasive Searching
void InvasiveSearch(int A[], int size, int key) {
    int i, j;
    for(i=0; i<size; i++) {
        //if key is found, replace it with 0
        if(A[i] == key) {
            A[i] = 0;
            printf("Key found at index %d!\n", i);
            printf("Invading the element and replacing it with 0...\n");
            printf("Array After Invasion: ");
            PrintArray(A, size);
            
            //search for the next occurrence of the key
            for(j=i+1; j<size; j++) {
                if(A[j] == key) {
                    A[j] = 0;
                    printf("Key found again at index %d!\n", j);
                    printf("Invading the element and replacing it with 0...\n");
                    printf("Array After Invasion: ");
                    PrintArray(A, size);
                }
            }
            return;
        }
    }
    printf("Key not found in the array.\n");
}

int main() {
    int A[] = {10, 20, 30, 30, 40, 50, 60};
    int size = sizeof(A)/sizeof(A[0]);
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    InvasiveSearch(A, size, key);
    return 0;
}