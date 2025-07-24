//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Define ASCII characters for each digit from 0 to 9
const char *ascii_digits[10] = {
    " 000 ", " 1 1 ", "2222", " 333 ", "4  4", 
    "5555", "6666", " 777 ", "8888", " 999 "
};

int main() {
    int number, digit, i, j, k, rows, cols;
    
    // Ask user to input a number
    printf("Enter a number: ");
    scanf("%d", &number);
    
    // Count number of digits in the number
    rows = 5;  // ASCII art digits are 5 rows tall
    cols = 0;
    int temp = number;
    while (temp != 0) {
        cols++;
        temp /= 10;
    }
    cols *= 5;  // Each digit is 5 columns wide
    
    int digits[cols];
    
    // Extract each digit and store it in an array
    for (i = cols-1; i >= 0; i -= 5) {
        digit = number % 10;
        number /= 10;
        for (j = 0, k = i; j < rows; j++, k += cols) {
            digits[k] = ascii_digits[digit][j];
        }
    }
    
    // Print the ASCII art representation of the number
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", digits[i*cols+j]);
        }
        printf("\n");
    }
    
    return 0;
}