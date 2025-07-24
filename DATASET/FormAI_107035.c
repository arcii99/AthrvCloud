//FormAI DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, i, j, k, count=0, max_count=0;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int *arr = (int*) malloc(n * sizeof(int));
    printf("Enter the integers:\n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<n; i++){
        count = 0;
        for(j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                for(k=j; k<n-1; k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
        if(count > max_count){
            max_count = count;
        }
    }

    printf("After removing duplicates, the array is: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("The maximum number of duplicates is: %d\n", max_count);

    free(arr);

    return 0;
}