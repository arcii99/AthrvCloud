//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include<stdio.h>
#include<time.h>

int main()  
{  
    int n, i, j, swap;  
    int arr[10000];

    // Generate Random Numbers of size 10000
    srand(time(0));  
    for(i=0;i<10000;i++)  
        arr[i] = rand()%10000;  

    // Bubble Sort Algorithm
    clock_t start = clock();             
    for(i=0;i<10000-1;i++)  
    {  
        for(j=0;j<10000-i-1;j++)  
        {  
            if(arr[j]>arr[j+1])  
            {  
                swap=arr[j];  
                arr[j]=arr[j+1];  
                arr[j+1]=swap;  
            }  
        }  
    }   
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken by Bubble Sort Algorithm: %f\n", duration);

    // Selection Sort Algorithm
    for(i=0;i<10000;i++)  
        arr[i] = rand()%10000;  

    start = clock();             
    for(i=0;i<10000-1;i++)  
    {  
        int minIndex = i;  
        for(j=i+1;j<10000;j++)  
        {  
            if(arr[j]<arr[minIndex])  
                minIndex = j;  
        }  

        swap = arr[i];  
        arr[i] = arr[minIndex];  
        arr[minIndex] = swap;  
    }   
    end = clock();

    duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken by Selection Sort Algorithm: %f\n", duration);   

    return 0;  
}