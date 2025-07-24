//FormAI DATASET v1.0 Category: Searching algorithm ; Style: creative
//Welcome to the magical world of searching with the Silver Seeker!

#include<stdio.h>
#include<time.h>

void search(int arr[], int n, int key);

int main(){
    int n, key, i;
    printf("Welcome to the Silver Seeker!\nPlease enter the number of elements you want in your array: ");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter %d elements in the array: ", n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\nPlease enter the element you want to search: ");
    scanf("%d",&key);
    clock_t start, end;
    start = clock();
    search(arr, n, key);
    end = clock();
    double time_taken = ((double)end - start)/CLOCKS_PER_SEC; //calculate the time taken by the algorithm
    if(time_taken < 0.000001)
        printf("Wow! That was fast!\n");
    else
        printf("The Silver Seeker took %f seconds to search the element %d in the array of %d elements.\n", time_taken, key, n);
    return 0;
}

void search(int arr[], int n, int key){
    int pos = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == key){
            pos = i;
            break;
        }
    }
    if(pos == -1)
        printf("Element not found!\n");
    else
        printf("Element found at position %d\n", pos+1);
}

// The End of Silver Seeker! Thank You for using this awesome algorithm!