//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include<stdio.h>

int main(){
    int arr[6] = {4, 5, 2, 3, 1, 6};
    printf("Welcome to the sorting puzzle!\n");
    printf("Can you guess the sorting algorithm used in this program?\n");
    printf("Here is your puzzle: \n\n");

    for(int i = 0; i < 6; i++){
        for(int j = i+1; j < 6; j++){
            if(arr[i] > arr[j]){
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }

    printf("Congratulations! You have solved the puzzle.\n");
    printf("But wait, there's more! Can you guess the time complexity of this algorithm?\n");

    printf("Enter your guess: ");
    int guess;
    scanf("%d", &guess);

    if(guess == 3){
        printf("Correct! The time complexity of this sorting algorithm is O(n^2).\n");
    } else {
        printf("Sorry, that's not correct. The time complexity of this sorting algorithm is O(n^2).\n");
    }

    printf("\nThank you for playing the sorting puzzle!\n");

    return 0;
}