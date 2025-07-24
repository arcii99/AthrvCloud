//FormAI DATASET v1.0 Category: Benchmarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <time.h>

int main(){
    int a[100000]; //Initializing an array with 100000 integers
    clock_t start, end; //To measure the execution time of a program
    
    //Populating the array
    for(int i=0;i<100000;i++){
        a[i]=i;
    }
    
    //Measuring the execution time of linear search
    start = clock(); //Start time
    int index = -1;
    for(int i=0;i<100000;i++){
        if(a[i] == 76543){
            index = i;
            break;
        }
    }
    end = clock(); //End time
    printf("Execution time of linear search: %lf seconds\n", (double) (end-start)/CLOCKS_PER_SEC);
    printf("Index of element 76543 in the array: %d\n", index);
    
    //Measuring the execution time of binary search
    start = clock(); //Start time
    int low = 0, high = 100000-1, mid;
    index = -1;
    while(low <= high){
        mid = (low+high)/2;
        if(a[mid] == 76543){
            index = mid;
            break;
        }
        else if(a[mid] < 76543) low = mid+1;
        else high = mid-1;
    }
    end = clock(); //End time
    printf("Execution time of binary search: %lf seconds\n", (double) (end-start)/CLOCKS_PER_SEC);
    printf("Index of element 76543 in the array: %d\n", index);
    
    return 0;
}