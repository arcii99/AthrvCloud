//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display periodic table
void display_table() {
    printf("\n");
    printf("  _____________________________________________________________________________\n");
    printf("  | H |                                                                 |He|\n");
    printf("  |___|_________________________________________________________________|___|\n");
    printf("  |   |                                                                 |   |\n");
    printf("  |Li |                          K    Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn| \n");
    printf("  |___|_________________________________________________________________|___|\n");
    printf("  |   |                                                                 |   |\n");
    printf("  |Na |                          Rb   Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd| \n");
    printf("  |___|_________________________________________________________________|___|\n");
    printf("  |   |                                                                 |   |\n");
    printf("  |K  |                          Cs   Ba-*Lu  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg| \n");
    printf("  |___|_________________________________________________________________|___|\n");
    printf("  |   | Lanthanide  Series                                             |   |\n");
    printf("  |   |                                                                 |   |\n");
    printf("  |   |La | Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er  Tm  Yb  Lu  Hf  **| \n");
    printf("  |___|_________________________________________________________________|___|\n");
    printf("  |   | Actinide   Series                                              |   |\n");
    printf("  |   |                                                                 |   |\n");
    printf("  |   |Ac | Th  Pa  U   Np  Pu  Am  Cm  Bk  Cf  Es  Fm  Md  No  Lr  Rf  **| \n");
    printf("  |___|_________________________________________________________________|___|\n\n");
}

// Function to generate random element symbol and get its atomic number
int random_question() {
    // List of elements in the periodic table
    const char *elements[21] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                                "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
                                "Sc"};
    int atomic_num[21] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};
    
    // Generate random number between 0 and 20
    srand(time(NULL));
    int random_num = rand() % 20;
    
    // Display the element symbol and get user's input for the atomic number
    printf("What is the atomic number for %s?\n", elements[random_num]);
    int user_input;
    scanf("%d", &user_input);
    
    // Check if user's input is correct
    if (user_input == atomic_num[random_num]) {
        printf("Correct! The atomic number for %s is %d.\n", elements[random_num], user_input);
        return 1; // Return 1 for correct answer
    } else {
        printf("Incorrect. The atomic number for %s is %d.\n", elements[random_num], atomic_num[random_num]);
        return 0; // Return 0 for incorrect answer
    }
}

// Main function
int main() {
    // Display the periodic table
    display_table();
    
    // Ask user if they want to start the quiz
    printf("Would you like to start the quiz? (y/n)\n");
    char user_ans;
    scanf("%c", &user_ans);
    
    // Loop the quiz until the user wants to quit
    while (user_ans == 'y') {
        int correct_score = 0;
        int total_score = 0;
        
        // Generate 10 random questions
        for (int i = 0; i < 10; i++) {
            printf("\nQuestion %d:\n", i+1);
            total_score++;
            int result = random_question();
            correct_score += result;
        }
        
        // Display the user's score
        printf("\nYou scored %d out of %d.\n", correct_score, total_score);
        
        // Ask user if they want to play again
        printf("Would you like to play again? (y/n)\n");
        scanf("%c", &user_ans);
    }
    
    printf("Thanks for playing! Goodbye.\n");
    return 0;
}