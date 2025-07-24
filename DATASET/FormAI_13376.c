//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>

void sorting(int array[], int n) {
    int temp;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(array[i]>array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    printf("------------------------------------------\n");
    printf("\tSorting Algorithm\n");
    printf("------------------------------------------\n");

    int n;
    printf("\nEnter the size of the array : ");
    scanf("%d", &n);

    int array[n];
    printf("\nEnter the elements of the array :\n");
    for(int i=0;i<n;i++) {
        scanf("%d", &array[i]);
    }

    sorting(array, n);

    printf("\nThe sorted array :\n");
    for(int i=0;i<n;i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("------------------------------------------\n");

    return 0;
}