//FormAI DATASET v1.0 Category: Browser Plugin ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void puzzle(int input, int size){
    int result = input;

    for(int i = 0; i < size; i++){
        int a = result;
        int b = size - i;
        result = (a * (b*a + (i+1))) % (size * 2);
    }

    printf("The resulting puzzle number is: %d\n", result);
}

int main(){

    int input, size;

    printf("Welcome to the Puzzle Browser Plugin Example Program!\n\n");

    printf("Please enter a starting number: ");
    scanf("%d", &input);

    printf("Please enter a size for the puzzle: ");
    scanf("%d", &size);

    puzzle(input, size);

    return 0;
}