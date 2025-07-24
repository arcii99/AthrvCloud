//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

//function to print the table 
void printTable(int arr[10]) 
{ 
    printf("| %d | %d | %d | %d | %d | %d | %d | %d | %d | %d |\n", 
           arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]); 
} 

//function to check for a winning combination 
int checkWin(int arr[10]) 
{ 
    int sum = arr[0] + arr[1] + arr[2] + arr[3] + arr[4]; 
    if (sum == arr[5] + arr[6] + arr[7] + arr[8] + arr[9]) 
        return 1; 

    sum = arr[0] + arr[1] + arr[5] + arr[6]; 
    if (sum == arr[2] + arr[3] + arr[4] + arr[7] + arr[8] + arr[9]) 
        return 1; 

    sum = arr[0] + arr[2] + arr[5] + arr[7]; 
    if (sum == arr[1] + arr[3] + arr[4] + arr[6] + arr[8] + arr[9]) 
        return 1; 

    sum = arr[0] + arr[3] + arr[5] + arr[8]; 
    if (sum == arr[1] + arr[2] + arr[4] + arr[6] + arr[7] + arr[9]) 
        return 1; 

    sum = arr[0] + arr[4] + arr[5] + arr[9]; 
    if (sum == arr[1] + arr[2] + arr[3] + arr[6] + arr[7] + arr[8]) 
        return 1; 

    return 0; 
} 

int main() 
{ 
    int arr[10], input, count = 0; 
    srand(time(0)); 

    for (int i = 0; i < 10; i++) 
        arr[i] = rand() % 10 + 1; 

    printf("\nWELCOME TO THE C-TABLE GAME!\n\n"); 
    printf("Try to make all the rows and columns of the table add up to the same number!\n"); 
    printf("You may only swap two adjacent numbers per turn.\n"); 

    printTable(arr); 

    while(count < 20) 
    { 
        printf("\nEnter the indices of the two numbers you want to swap:\n"); 
        scanf("%d %d", &input, &input); 

        //check if input is within range 
        if(input < 0 || input > 9) 
        { 
            printf("\nInvalid input, please enter numbers from 0 to 9\n"); 
            continue; 
        } 

        //swap the elements 
        int temp = arr[input]; 
        arr[input] = arr[input+1]; 
        arr[input+1] = temp; 

        //print the updated table 
        printTable(arr); 

        //check if player has won 
        if(checkWin(arr)) 
        { 
            printf("\nCongratulations, you won the game in %d moves!\n", count+1); 
            break; 
        } 

        count++; 
    } 

    if(count == 20) 
        printf("\nYou have reached the maximum number of moves, try again next time!\n"); 

    return 0; 
}