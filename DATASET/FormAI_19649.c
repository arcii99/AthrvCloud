//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void happy_sort(int arr[], int n){
    // It's time to sort like there's no tomorrow!
    printf("Sorting in progress... (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧\n");
    
    // Randomize the order of elements just to make it more fun
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Bubble sort algorithm with a twist
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                // Let's swap these elements (づ｡◕‿‿◕｡)づ
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                // Let's celebrate this momentous occasion with a dance party!
                printf("\n＼(＾O＾)／ Sorting party!! ＼(＾O＾)／\n\n");
            }
        }
    }
    
    // Congratulations! You've successfully sorted your array!
    printf("Congratulations on sorting your array!! (•̀ᴗ•́)و\n\n");
}

int main(){
    // We need to make an array to sort first
    int arr[] = {7, 2, 5, 9, 1, 4, 6, 8, 3};
    int n = sizeof(arr)/sizeof(int);
    
    // Let's print the original array first
    printf("Original array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Let's sort the array using our own custom sorting algorithm
    happy_sort(arr, n);
    
    // Let's print the sorted array now (っ＾▿＾)۶🍸🌟🍺٩(^‿^ )
    printf("Sorted array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // End program with a fun message! (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧
    printf("Thanks for sorting with me! Sorting is fun! (っ˘ڡ˘ς)\n");

    return 0;
}