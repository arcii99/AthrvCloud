//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// Define the maximum number of questions and the list of elements in the periodic table.
#define MAX_QUESTIONS 10
char periodic_table[118][3] ={
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
    "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
    "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
    "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm",
    "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W",
    "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
    "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf",
    "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

// Define the structure for each question
typedef struct {
    char question[50];
    char answer[3];
    char options[4][3];
} Question;

// Function to generate a unique random number from min to max
int generateRandomNumber(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

// Function to shuffle the options in a question
void shuffleOptions(char options[4][3]) {
    for(int i = 0; i < 4; i++) {
        int j = generateRandomNumber(0, 3);
        char temp[3];
        strcpy(temp, options[i]);
        strcpy(options[i], options[j]);
        strcpy(options[j], temp);
    }
}

int main() {
    printf("Welcome to the C Periodic Table Quiz! You have to answer %d questions.\n\n", MAX_QUESTIONS);

    // Generate MAX_QUESTIONS unique questions
    Question questions[MAX_QUESTIONS];
    int used_indices[MAX_QUESTIONS];
    int question_count = 0;

    for(int i = 0; i < MAX_QUESTIONS; i++) {
        // Generate a unique random index
        int index = generateRandomNumber(0, 117);
        int is_used = 0;
        for(int j = 0; j < question_count; j++) {
            if(used_indices[j] == index) {
                is_used = 1;
                break;
            }
        }
        if(is_used) {
            i--;
            continue;
        }
        used_indices[question_count] = index;

        // Generate the question and options
        char question[50];
        char answer[3];
        char options[4][3];

        sprintf(question, "What is the symbol for element number %d in the periodic table?", index+1);
        strcpy(answer, periodic_table[index]);
        strcpy(options[0], answer);

        for(int j = 1; j < 4; j++) {
            int wrong_index = generateRandomNumber(0, 117);
            while(strcmp(periodic_table[wrong_index], answer) == 0) {
                wrong_index = generateRandomNumber(0, 117);
            }
            strcpy(options[j], periodic_table[wrong_index]);
        }
        shuffleOptions(options);

        // Set the question in the questions array
        strcpy(questions[question_count].question, question);
        strcpy(questions[question_count].answer, answer);
        strcpy(questions[question_count].options[0], options[0]);
        strcpy(questions[question_count].options[1], options[1]);
        strcpy(questions[question_count].options[2], options[2]);
        strcpy(questions[question_count].options[3], options[3]);

        question_count++;
    }

    // Start the quiz
    int correct_answers = 0;
    for(int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        printf("a) %s   b) %s   c) %s.   d) %s\n", questions[i].options[0], questions[i].options[1], questions[i].options[2], questions[i].options[3]);

        char selected_option[3];
        printf("Enter your answer (a/b/c/d): ");
        scanf("%s", selected_option);

        if(strcmp(selected_option, "a") == 0 && strcmp(questions[i].options[0], questions[i].answer) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        }
        else if(strcmp(selected_option, "b") == 0 && strcmp(questions[i].options[1], questions[i].answer) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        }
        else if(strcmp(selected_option, "c") == 0 && strcmp(questions[i].options[2], questions[i].answer) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        }
        else if(strcmp(selected_option, "d") == 0 && strcmp(questions[i].options[3], questions[i].answer) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        }
        else {
            printf("Incorrect :( The correct answer is %s.\n\n", questions[i].answer);
        }
    }

    // Display the quiz results
    printf("Congratulations, you have completed the quiz!\n");
    printf("You got %d out of %d questions correct.\n", correct_answers, MAX_QUESTIONS);

    return 0;
}