//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>

// function to convert date to puzzle-like message
void date_puzzle(int day, int month, int year) {
    int puzzle_num = ((day * month) % year) + 1; // calculate puzzle number
    char puzzle_msg[50]; // declare puzzle message string
    switch(puzzle_num) {
        case 1:
            sprintf(puzzle_msg, "One eye on future, one eye on the past, the present is %d/%d/%d", day, month, year);
            break;
        case 2:
            sprintf(puzzle_msg, "In a circle of life, you've completed another %d/%d/%d", day, month, year);
            break;
        case 3:
            sprintf(puzzle_msg, "A milestone reached on %d/%d/%d, cherish the moment forevermore", day, month, year);
            break;
        case 4:
            sprintf(puzzle_msg, "A journey of %d/%d/%d begins with a single step", day, month, year);
            break;
        // add more cases for more puzzle messages
        default:
            sprintf(puzzle_msg, "Another day, another puzzle to solve on %d/%d/%d", day, month, year);
            break;
    }
    printf("%s\n", puzzle_msg); // print the puzzle message
}

// main function
int main() {
    int day, month, year;
    printf("Enter date in dd/mm/yyyy format: ");
    scanf("%d/%d/%d", &day, &month, &year);
    if(day<1 || day>31 || month<1 || month>12 || year<1) {
        printf("Invalid date!\n");
        return 0;
    }
    date_puzzle(day, month, year); // call function to convert date to puzzle
    return 0;
}