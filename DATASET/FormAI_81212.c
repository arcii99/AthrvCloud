//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    char elements[118][3] = {   "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
                                "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", 
                                "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", 
                                "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", 
                                "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", 
                                "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", 
                                "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", 
                                "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", 
                                "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", 
                                "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", 
                                "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", 
                                "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    int atomic_nums[118] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
                            11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 
                            21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 
                            31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 
                            41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 
                            51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 
                            61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 
                            71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 
                            81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 
                            91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 
                            101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 
                            111, 112, 113, 114, 115, 116, 117, 118};

    char categories[5][12] = {  "Alkali", "Alkaline", "Transition", "Metalloid", "Nonmetal" };
    int cat_num[5] = { 7, 6, 40, 7, 44 };

    int i, j, k;
    int num_questions = 10;
    int correct_answers = 0;
    int incorrect_answers = 0;
    int answer_indices[num_questions];

    // Create an array of random question indices
    srand(time(NULL));
    for (i = 0; i < num_questions; i++) {
        answer_indices[i] = rand() % 118;
    }

    // Ask the user the random questions
    for (i = 0; i < num_questions; i++) {
        printf("Question #%d: ", i+1);
        printf("What is the symbol for element with atomic number %d?\n", atomic_nums[answer_indices[i]]);
        char user_answer[3];
        scanf("%s", user_answer);

        // Check if the user's answer is correct
        if (strcmp(user_answer, elements[answer_indices[i]]) == 0) {
            printf("Correct!\n");
            correct_answers++;
        }
        else {
            printf("Incorrect. Correct answer is %s\n", elements[answer_indices[i]]);
            incorrect_answers++;
        }
    }

    printf("===============================\n");
    printf("Quiz finished!\n");

    // Print statistics
    printf("You answered %d questions correctly and %d questions incorrectly.\n", correct_answers, incorrect_answers);

    printf("The percentage of correct answers is %d%%\n", (int)(((float)correct_answers / num_questions)*100));

    printf("Here are the categories of elements with the number of elements in each category:\n");
    for (i = 0; i < 5; i++) {
        int element_count = 0;
        for (j = 0; j < cat_num[i]; j++) {
            for (k = 0; k < 118; k++) {
                if (strcmp(categories[i], elements[k]) == 0) {
                    element_count++;
                }
            }
        }
        printf("%s: %d\n", categories[i], element_count);
    }

    return 0;
}