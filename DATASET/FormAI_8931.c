//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int atomic_number[20] = {1, 3, 4, 5, 6, 8, 9, 11, 12, 13, 14, 15, 16, 17, 19, 20, 26, 29, 30, 35};
    char symbol[20][3] = {"H ","Li","Be","B ","C ","O ","F ","Na","Mg","Al","Si","P ","S ","Cl","K ","Ca","Fe","Cu","Zn","Br"};
    char name[20][20] = {"Hydrogen","Lithium","Beryllium","Boron","Carbon","Oxygen","Fluorine","Sodium","Magnesium",
                      "Aluminum","Silicon","Phosphorus","Sulfur","Chlorine","Potassium","Calcium","Iron","Copper","Zinc","Bromine"};
    int i, j, rand_num, user_ans, correct_ans, score = 0;
    srand(time(0)); // setting seed for random number generation
    
    // Welcome Message
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("------------------------------------\n");
    printf("Test your knowledge of the Periodic Table by identifying the elements from their symbols.\n");
    printf("Each question will have 4 options to choose from and you will have to select the correct one.\n");
    printf("Let's get started!\n\n");
    
    // Quiz
    for (i = 1; i <= 10; i++) {
        rand_num = rand() % 20; // generating random number between 0 and 19
        printf("%d. What is the symbol for the element '%s'?\n", i, name[rand_num]);
        printf("   a) %s   b) %s   c) %s   d) %s\n", symbol[rand_num], symbol[rand_num+2], symbol[rand_num+4], symbol[rand_num+6]); // giving options
        printf("   Enter your answer (a/b/c/d): ");
        scanf(" %c", &user_ans);
        // checking if user's answer is correct and updating score
        if (user_ans == 'a') correct_ans = 0;
        else if (user_ans == 'b') correct_ans = 1;
        else if (user_ans == 'c') correct_ans = 2;
        else if (user_ans == 'd') correct_ans = 3;
        if (atomic_number[rand_num] + correct_ans == atomic_number[rand_num+correct_ans]) {
            printf("   Correct answer!\n");
            score++;
        }
        else printf("   Incorrect answer. The correct answer is '%s'\n", symbol[rand_num]);
        printf("\n");
    }
    
    // Displaying score
    printf("Quiz Ended!\n");
    printf("You scored %d out of 10.\n", score);
    
    return 0;
}