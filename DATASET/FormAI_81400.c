//FormAI DATASET v1.0 Category: Random ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_RANDS 1000

int main()
{
    int i,j,count=0;
    double nums[NUM_RANDS] = {0};
    srand(time(NULL));
    for(i=0;i<NUM_RANDS;i++){
        nums[i] = 1.0/rand();
    }
    for(i=0;i<NUM_RANDS/2;i++){
        for(j=i+1;j<NUM_RANDS;j++){
            if(nums[i]>nums[j]){
                double temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
    printf("The first 100 sorted random numbers are:\n");
    for(i=0;i<100;i++){
        printf("%d: %0.9lf\n", i+1, nums[i]);
    }
    printf("The last 100 sorted random numbers are:\n");
    for(i=NUM_RANDS-100;i<NUM_RANDS;i++){
        printf("%d: %0.9lf\n", (++count), nums[i]);
    }
    return 0;
}