//FormAI DATASET v1.0 Category: Educational ; Style: ephemeral
#include<stdio.h>

int main(){
    // Declaration
    int list_size, max_val;

    // Taking user inputs
    printf("Enter size of List: ");
    scanf("%d", &list_size);
    printf("Enter Maximum Value: ");
    scanf("%d", &max_val);

    // Generating random values for list
    int list[list_size];
    srand(time(0));
    for(int i=0; i<list_size; i++) {
        list[i] = rand() % max_val;
    }

    // Sorting the list using bubble sort algorithm
    for(int i=0; i<list_size-1; i++) {
        for(int j=0; j<list_size-i-1; j++) {
            if(list[j] > list[j+1]) {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    // Printing the sorted list
    for(int i=0; i<list_size; i++) {
         printf("%d ", list[i]);
    }

    return 0;
}