//FormAI DATASET v1.0 Category: Data mining ; Style: surprised
#include<stdio.h>

int main()
{
    printf("Wow! I just found something incredible!\n");

    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    double avg;

    for(int i=0; i<10; i++){
        sum += data[i];
    }

    avg = sum / 10.0;

    printf("After mining the data, I found out that the sum of all the numbers in the array is %d\n", sum);

    printf("And wait for it...the average value is %lf!\n", avg);

    printf("I am thrilled with this discovery! I bet no one has ever found this before!\n");

    return 0;
}