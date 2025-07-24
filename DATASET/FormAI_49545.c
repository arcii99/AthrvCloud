//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include<stdio.h>
#include<stdlib.h>

//Function to find Checksum
int checksum(int data[], int n){

    int sum = 0, i;

    //Calculating Sum of Data
    for(i=0;i<n;i++){
        sum += data[i];
    }

    //Calculating Checksum
    sum = ~sum;

    return sum;
}

int main(){

    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    //Dynamic memory allocation for Data array
    int *data = (int*)malloc(n*sizeof(int));

    //Taking input from User
    printf("Enter data elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &data[i]);
    }

    //Calling Checksum Function
    int sum = checksum(data, n);

    //Displaying Checksum
    printf("Checksum: %d", sum);

    free(data);
    return 0;
}