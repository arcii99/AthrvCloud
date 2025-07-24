//FormAI DATASET v1.0 Category: Benchmarking ; Style: innovative
#include<stdio.h>
#include<time.h>

#define MAX_SIZE 10000

void print_array(int a[], int len){
    int i;
    printf("[ ");
    for(i=0;i<len;i++){
        printf("%d ",a[i]);
    }
    printf("]\n");
}
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int a[],int len){
    int i,j;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-i-1;j++){
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
            }
        }
    }
}

void insertion_sort(int a[],int len){
    int i,j,key;
    for(i=1;i<len;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

void selection_sort(int a[],int len){
    int i,j,min_index;
    for(i=0;i<len-1;i++){
        min_index=i;
        for(j=i+1;j<len;j++){
            if(a[j]<a[min_index]){
                min_index=j;
            }
        }
        swap(&a[i],&a[min_index]);
    }
}

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    int j;
    for(j=low;j<=high-1;j++){
        if(a[j]<pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

void quick_sort(int a[],int low,int high){
    if(low<high){
        int pi=partition(a,low,high);
        quick_sort(a,low,pi-1);
        quick_sort(a,pi+1,high);
    }
}

void merge(int a[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int L[n1],R[n2];
    int i,j,k;
    for(i=0;i<n1;i++){
        L[i]=a[low+i];
    }
    for(j=0;j<n2;j++){
        R[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void generate_random_array(int a[],int len){
    int i;
    for(i=0;i<len;i++){
        a[i]=rand()%MAX_SIZE;
    }
}

int main(){
    int arr1[MAX_SIZE],arr2[MAX_SIZE],arr3[MAX_SIZE],arr4[MAX_SIZE],arr5[MAX_SIZE];
    clock_t start,end;
    double cpu_time_used;
    int len=MAX_SIZE;
    generate_random_array(arr1,len);
    generate_random_array(arr2,len);
    generate_random_array(arr3,len);
    generate_random_array(arr4,len);
    generate_random_array(arr5,len);
    printf("Bubble Sort Benchmarking\n");
    printf("Before Sorting: \n");
    //print_array(arr1,len);
    start=clock();
    bubble_sort(arr1,len);
    end=clock();
    printf("After Sorting: \n");
    //print_array(arr1,len);
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n",cpu_time_used);
    printf("\n");
    printf("Insertion Sort Benchmarking\n");
    printf("Before Sorting: \n");
    //print_array(arr2,len);
    start=clock();
    insertion_sort(arr2,len);
    end=clock();
    printf("After Sorting: \n");
    //print_array(arr2,len);
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n",cpu_time_used);
    printf("\n");
    printf("Selection Sort Benchmarking\n");
    printf("Before Sorting: \n");
    //print_array(arr3,len);
    start=clock();
    selection_sort(arr3,len);
    end=clock();
    printf("After Sorting: \n");
    //print_array(arr3,len);
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n",cpu_time_used);
    printf("\n");
    printf("Quick Sort Benchmarking\n");
    printf("Before Sorting: \n");
    //print_array(arr4,len);
    start=clock();
    quick_sort(arr4,0,len-1);
    end=clock();
    printf("After Sorting: \n");
    //print_array(arr4,len);
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n",cpu_time_used);
    printf("\n");
    printf("Merge Sort Benchmarking\n");
    printf("Before Sorting: \n");
    //print_array(arr5,len);
    start=clock();
    merge_sort(arr5,0,len-1);
    end=clock();
    printf("After Sorting: \n");
    //print_array(arr5,len);
    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n",cpu_time_used);
    return 0;
}