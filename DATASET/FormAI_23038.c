//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include<stdio.h>

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(){
    int arr[] = {50, 20, 10, 40, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("Before Merge Sort:");
    for(i=0;i<n;i++){
        printf(" %d", arr[i]);
    }

    mergeSort(arr, 0, n-1);

    printf("\nAfter Merge Sort:");
    for(i=0;i<n;i++){
        printf(" %d", arr[i]);
    }

    return 0;
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1], R[n2];

    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }

    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}