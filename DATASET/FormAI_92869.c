//FormAI DATASET v1.0 Category: Graph representation ; Style: introspective
#include<stdio.h>

//defining a function to print the graph
void graph(int arr[], int n){
    int i, j, max = 0;
    //finding the maximum value in the array
    for(i=0;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
    }

    printf("\n\nGraph:\n\n");

    //looping through each row and column
    for(i=max;i>0;i--){
        //printing y-axis labels on the left
        if(i%10==0){
            printf("%d -", i);
        }
        else{
            printf("    |");
        }

        for(j=0;j<n;j++){
            //printing the graph using '*' for values greater than the current row number
            if(arr[j]>=i){
                printf("  * ");
            }
            else{
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("   ");
    //printing x-axis labels on the bottom
    for(i=0;i<n;i++){
        if(i%10==0){
            printf("%d  ", i+1);
        }
        else if(i>8){
            printf("   %d", i+1);
        }
        else{
            printf("  %d", i+1);
        }
    }
}

int main(){
    //creating an example array
    int arr[] = {2, 5, 8, 12, 6, 3, 7, 9, 4, 1, 15, 10, 11, 13, 7, 18, 14, 20, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    //printing the input array
    printf("Input Array:\n\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    //calling the graph function to print the graph
    graph(arr, n);

    return 0;
}