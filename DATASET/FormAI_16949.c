//FormAI DATASET v1.0 Category: Sorting ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define PUZZLE_NUM 25 // The maximum number of puzzle pieces

int puzzle_pieces[PUZZLE_NUM] = {3, 9, 12, 8, 2, 16, 4, 24, 7, 15, 21, 20, 22, 13, 23, 11, 1, 18, 10, 14, 19, 17, 5, 6, 0}; // The puzzle pieces to sort

// A function to display the puzzle pieces in their current order
void display_puzzle()
{
    printf("Current order of puzzle pieces:\n");
    for (int i = 0; i < PUZZLE_NUM; i++)
    {
        printf("%d ", puzzle_pieces[i]);
    }
    printf("\n");
}

// A function that will sort the puzzle pieces
void sort_puzzle()
{
    // Start by choosing a random pivot piece
    int pivot_idx = rand() % PUZZLE_NUM;
    int pivot_val = puzzle_pieces[pivot_idx];
    
    // Then move the pivot piece to the end
    swap(puzzle_pieces[pivot_idx], puzzle_pieces[PUZZLE_NUM-1]);
    
    // Initialize variables
    int i = 0;
    int j = PUZZLE_NUM - 2;
    
    while (i <= j)
    {
        if (puzzle_pieces[i] < pivot_val)
        {
            i++;
        }
        else if (puzzle_pieces[j] >= pivot_val)
        {
            j--;
        }
        else
        {
            swap(puzzle_pieces[i], puzzle_pieces[j]);
            i++;
            j--;
        }
    }
    
    // Move the pivot piece back to its sorted position
    pivot_idx = i;
    swap(puzzle_pieces[pivot_idx], puzzle_pieces[PUZZLE_NUM-1]);
}

// A function to swap two puzzle pieces
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;  
}

int main()
{
    printf("Welcome to the puzzling sort!\n");
    printf("You have %d puzzle pieces to sort.\n", PUZZLE_NUM);
    
    display_puzzle();
    
    // Shuffle the puzzle pieces randomly before sorting
    for (int i = 0; i < PUZZLE_NUM; i++)
    {
        int random_idx = rand() % PUZZLE_NUM;
        swap(&puzzle_pieces[i], &puzzle_pieces[random_idx]);
    }
    
    sort_puzzle();
    
    printf("Congratulations! You have successfully sorted the puzzle pieces!\n");
    
    display_puzzle();
    
    return 0;
}