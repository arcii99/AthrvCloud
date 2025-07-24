//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int main() {
    int num1 = 23, num2 = 18;
    printf("Let's start the puzzle!\n");

    // Puzzle #1: Check if both numbers are odd
    if (!(num1 & 1) && !(num2 & 1)) {
        printf("Question 1: What do you call a fart that doesn't stink?\n");
        printf("Answer: A short circuit!\n");
    }
    else {
        printf("Question 1: Why do programmers prefer dark mode?\n");
        printf("Answer: Less wattage, more voltage!\n");
    }

    // Puzzle #2: Swap the values of the numbers
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
    printf("Question 2: Why don't scientists trust atoms?\n");
    printf("Answer: Because they make up everything!\n");

    // Puzzle #3: Check if num1 is divisible by 4
    if (num1 & 3) {
        printf("Question 3: Why did the tomato turn red?\n");
        printf("Answer: Because it saw the salad dressing!\n");
    }
    else {
        printf("Question 3: What kind of music do planets like?\n");
        printf("Answer: Nep-tunes!\n");
    }

    // Puzzle #4: Check if num1 is greater than num2
    if (num1 >> 31 || num1 - num2 > 0) {
        printf("Question 4: Why did the phone go to bed?\n");
        printf("Answer: Because it wanted to charge!\n");
    }
    else {
        printf("Question 4: Why did the scarecrow win an award?\n");
        printf("Answer: Because he was outstanding in his field!\n");
    }

    // Puzzle #5: Set num2 to the next highest power of 2
    num2--;
    num2 |= num2 >> 1;
    num2 |= num2 >> 2;
    num2 |= num2 >> 4;
    num2 |= num2 >> 8;
    num2 |= num2 >> 16;
    num2++;
    printf("Question 5: Why do programmers always mix up Halloween and Christmas?\n");
    printf("Answer: Because Oct 31 equals Dec 25!\n");

    printf("Congratulations! You have solved the puzzles!\n");

    return 0;
}