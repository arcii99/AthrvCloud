//FormAI DATASET v1.0 Category: Benchmarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 1000000

double selection_sort(double arr[],int len){
    clock_t start,end;
    start=clock();
    for(int i=0;i<len-1;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        double temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    end=clock();
    return ((double) (end-start)) / CLOCKS_PER_SEC;
}

double bubble_sort(double arr[], int len){
    clock_t start,end;
    start=clock();
    for(int i=0;i<len-1;i++){
        int swapped=0;
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                double temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
    end=clock();
    return ((double) (end-start)) / CLOCKS_PER_SEC;
}

int main(){
    double arr[LENGTH];
    srand(time(NULL));
    for(int i=0;i<LENGTH;i++){
        arr[i]=rand()%1000;
    }
    double time_taken_bubble=bubble_sort(arr,LENGTH);
    double time_taken_selection=selection_sort(arr,LENGTH);
    printf("Bubble Sort Performance: %f\n",time_taken_bubble);
    printf("Selection Sort Performance: %f\n",time_taken_selection);
    return 0;
}