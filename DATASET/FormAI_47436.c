//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int n,i,j;    
    printf("Hey, wanna do some greedy stuff?\n");
    printf("How about we find the minimum sum that can be formed by combining two numbers repeatedly.\n");
    printf("Sounds great, doesn't it?\n");
    printf("Enter the number of elements you want in the array:\n");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));   //for randomizing the array contents
    for(i=0;i<n;i++){
        arr[i]=rand()%100; //random numbers from 0-99
    }
    printf("The array contents are: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int sum=0;  //our greedy work starts here
    i=0;
    j=n-1;
    while(i<j){
        if(arr[i]<arr[j]){
            sum+=arr[i];
            i++;
        }
        else{
            sum+=arr[j];
            j--;
        }
    }
    if(i==j){
        sum+=arr[i];
    }
    printf("The minimum sum is: %d\n",sum);
    printf("Aren't we the smart Greedy ones?\n");
    printf("Bye bye\n");
    return 0;
}