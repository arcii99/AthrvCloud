//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
// C Bucket Sort Implementation
#include<stdio.h>
#include<stdlib.h>

void BucketSort(float arr[], int n){
    int i, j;
    float val;
  
    // create k empty buckets
    int k = 10; // number of buckets = 10
    float* bucket[k];
    for (i = 0; i < k; ++i){
        bucket[i] = NULL;
    }
  
    // put array elements to different buckets based on their values
    for (i = 0; i < n; ++i){
        val = arr[i];
        j = k * val; // bucket index
        if (bucket[j] == NULL) bucket[j] = malloc(100*sizeof(float));
        bucket[j][i] = val;
    }
  
    // sort individual buckets
    for (i = 0; i < k; ++i){
        if (bucket[i] != NULL){
            for (j = 1; j < n; ++j){
                if (bucket[i][j] < bucket[i][j-1]){
                    val = bucket[i][j];
                    int m = j-1;
                    while (m >= 0 && bucket[i][m] > val){
                        bucket[i][m+1] = bucket[i][m];
                        --m;
                    }
                    bucket[i][m+1] = val;
                }
            }
        }
    }
  
    // concatenate all buckets into arr[]
    int index = 0;
    for (i = 0; i < k; ++i){
        if (bucket[i] != NULL){
            for (j = 0; j < n; ++j){
                arr[index++] = bucket[i][j];
            }
            free(bucket[i]);
        }
    }
}

int main(){
    float arr[] = { 0.72, 0.42, 0.12, 0.24, 0.15, 0.98, 0.71, 0.03, 0.06, 0.19 };
    int n = sizeof(arr)/sizeof(arr[0]);
    BucketSort(arr, n);
  
    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i){
        printf("%f ", arr[i]);
    }
    printf("\n");

    return 0;
}