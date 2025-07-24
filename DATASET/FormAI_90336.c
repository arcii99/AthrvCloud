//FormAI DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h> 
#include <time.h> 
  
int main() 
{ 
    int a[1000], b[1000], result[1000], i, j, k; 
    clock_t tic, toc; 
    double time_taken; 
    // Initialize arrays a and b
    for(i=0;i<1000;i++){
        a[i] = i*2;
        b[i] = i*3;
    }
    // Multiplication of two arrays and benchmarking the time taken
    tic = clock(); 
    for (i = 0; i < 1000; i++){ 
        result[i] = a[i] * b[i]; 
    }
    toc = clock(); 
    time_taken = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\n Time taken for multiplication of two arrays: %f seconds", time_taken); 
    
    // Sorting an array using Bubble Sort and benchmarking the time taken 
    int temp; 
    tic = clock(); 
    for(i=0;i<1000;i++){ 
        for(j=0;j<1000-i-1;j++){ 
            if(a[j]>a[j+1]){ 
                // Swapping elements
                temp=a[j]; 
                a[j]=a[j+1]; 
                a[j+1]=temp; 
            } 
        } 
    } 
    toc = clock(); 
    time_taken = (double)(toc - tic) / CLOCKS_PER_SEC;
    printf("\n Time taken for sorting an array using bubble sort: %f seconds", time_taken); 
    
    // Searching an element in an array using linear search and benchmarking the time taken 
    int element = 800, flag=0; 
    tic = clock(); 
    for(i=0;i<1000;i++){
        if(a[i] == element){
            flag = 1;
            break; 
        }
    }
    toc = clock(); 
    time_taken = (double)(toc - tic) / CLOCKS_PER_SEC;
    if(flag)
        printf("\n Time taken for finding an element using linear search: %f seconds", time_taken); 
    else 
        printf("\n Element not found"); 
    
    return 0; 
}