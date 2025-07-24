//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include<stdio.h>

void surreal_sort(int arr[], int n, int b_count) {
    int b[b_count][n];
    int bucket_size[b_count];

    for(int i=0; i<b_count; i++) {
        bucket_size[i] = 0; 
    }

    for(int i=0; i<n; i++) {
        int bi = b_count * arr[i];
        b[bi][bucket_size[bi]] = arr[i];
        bucket_size[bi]++;
    }

    for(int i=0; i<b_count; i++) {
        int j=0;
        while(j<bucket_size[i]) {
            int smallest = b[i][j];
            int smallest_index = j;
            for(int k=j+1; k<bucket_size[i]; k++) {
                if(b[i][k] < smallest) {
                    smallest = b[i][k];
                    smallest_index = k;
                }
            }
            b[i][smallest_index] = b[i][j];
            b[i][j] = smallest;
            j++;
        }
    }

    int index = 0;
    for(int i=0; i<b_count; i++) {
        for(int j=0; j<bucket_size[i]; j++) {
            arr[index] = b[i][j];
            index++;
        }
    }
}

int main() {
    int arr[] = {4, 8, 3, 6, 2, 7, 1, 9, 5, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int b_count = 8;
    surreal_sort(arr, n, b_count);
    printf("The surrealistically sorted array is: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}