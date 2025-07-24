//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integer between min(inclusive) and max(inclusive)
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to shuffle an array of integers
void shuffleArray(int *array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = generateRandomNumber(0, i);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    // Initialize the periodic table elements array
    char elements[118][3] = {
        "H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne",
        "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
        "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
        "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
        "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };

    // Initialize the atomic numbers array
    int atomicNumbers[118];
    for (int i = 0; i < 118; i++) {
        atomicNumbers[i] = i + 1;
    }

    // Shuffle the atomic numbers array
    shuffleArray(atomicNumbers, 118);

    // Initialize variables for the quiz
    int correctAnswers = 0;
    int totalQuestions = 0;
    int answer;

    // Start the quiz
    printf("Welcome to the Periodic Table Quiz! Answer the following questions with the atomic symbol.\n");

    while (1) {
        // Generate a random atomic number
        int atomicNumber = atomicNumbers[totalQuestions % 118];

        // Get the element name from the atomic number
        char *elementName = elements[atomicNumber - 1];

        // Print the question and get the answer
        printf("What is the atomic symbol for #%d (%s)? ", atomicNumber, elementName);
        scanf("%s", &answer);

        // Check the answer and give feedback
        if (strcmp(answer, elementName) == 0) {
            printf("Correct! Congratulations!\n");
            correctAnswers++;
        } else {
            printf("Sorry, the correct answer is %s.\n", elementName);
        }

        // Increment the total questions
        totalQuestions++;

        // Ask the user if they want to continue or quit
        printf("Do you want to answer another question (y/n)? ");
        char continueAnswer;
        scanf(" %c", &continueAnswer);
        if (continueAnswer == 'n' || continueAnswer == 'N') {
            break;
        }
    }

    // Print the user's score
    printf("You answered %d out of %d questions correctly.\n", correctAnswers, totalQuestions);

    return 0;
}