//FormAI DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>

int main() 
{
    int arr[10] = {22, 33, 44, 55, 66, 77, 88, 99, 111, 222};
    int length = sizeof(arr)/sizeof(arr[0]);
    int search_number = 77;
    int index = -1;
  
    for(int i=0; i<length; i++) 
    {
        if(arr[i] == search_number) 
        {
            index = i;
            break;
        }
    }

    if(index != -1) 
    {
        printf("Number found at index %d", index);
    } 
    else 
    {
        printf("Number not found in array");
    }
    return 0;
}