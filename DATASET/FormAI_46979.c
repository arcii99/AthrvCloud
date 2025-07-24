//FormAI DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size, *arr, *dup, i, j, count = 0;

    printf("Enter the size of the array (should be even): ");
    scanf("%d", &size);

    arr = (int*)malloc(size*sizeof(int));
    dup = (int*)malloc(size*sizeof(int));

    srand(time(NULL));

    for(i=0; i<size; i+=2){
        arr[i] = rand()%100 + 1;
        arr[i+1] = arr[i];
    }

    for(i=0; i<size; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(i=0; i<size; i++){
        dup[i] = -1;
    }

    while(count < size){

        int input1, input2;

        printf("Enter the indices of two elements (separated by space): ");
        scanf("%d %d", &input1, &input2);

        if(input1 >= size || input2 >= size){
            printf("Invalid input! Please enter again.\n");
            continue;
        }

        if(input1 == input2){
            printf("Invalid input! Please enter again.\n");
            continue;
        }

        if(dup[input1] == 1 || dup[input2] == 1){
            printf("These elements have already been matched! Please enter again.\n");
            continue;
        }

        if(arr[input1] != arr[input2]){
            printf("Sorry! The elements do not match. Please try again.\n");
            dup[input1] = 0;
            dup[input2] = 0;
        }
        else{
            printf("Awesome! You have got a match.\n");
            dup[input1] = 1;
            dup[input2] = 1;
            count += 2;
        }

    }

    printf("Congratulations! You have matched all the elements in the array.\n");

    free(arr);
    free(dup);

    return 0;
}