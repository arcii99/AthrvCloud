//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Define the maximum number of questions
#define MAX_QUESTIONS 50

//Define a struct to hold question information
typedef struct {
    char question[100];
    char answer[3];
} Question;

//Function to shuffle the questions array
void shuffleQuestions(Question* questions, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

int main() {
    //Define an array of questions
    Question questions[MAX_QUESTIONS] = {
        {"What is the symbol for hydrogen?","H"},
        {"What is the symbol for helium?","He"},
        {"What is the symbol for lithium?","Li"},
        {"What is the symbol for beryllium?","Be"},
        {"What is the symbol for boron?","B"},
        {"What is the symbol for carbon?","C"},
        {"What is the symbol for nitrogen?","N"},
        {"What is the symbol for oxygen?","O"},
        {"What is the symbol for fluorine?","F"},
        {"What is the symbol for neon?","Ne"},
        {"What is the symbol for sodium?","Na"},
        {"What is the symbol for magnesium?","Mg"},
        {"What is the symbol for aluminum?","Al"},
        {"What is the symbol for silicon?","Si"},
        {"What is the symbol for phosphorus?","P"},
        {"What is the symbol for sulfur?","S"},
        {"What is the symbol for chlorine?","Cl"},
        {"What is the symbol for argon?","Ar"},
        {"What is the symbol for potassium?","K"},
        {"What is the symbol for calcium?","Ca"},
        {"What is the symbol for scandium?","Sc"},
        {"What is the symbol for titanium?","Ti"},
        {"What is the symbol for vanadium?","V"},
        {"What is the symbol for chromium?","Cr"},
        {"What is the symbol for manganese?","Mn"},
        {"What is the symbol for iron?","Fe"},
        {"What is the symbol for cobalt?","Co"},
        {"What is the symbol for nickel?","Ni"},
        {"What is the symbol for copper?","Cu"},
        {"What is the symbol for zinc?","Zn"},
        {"What is the symbol for gallium?","Ga"},
        {"What is the symbol for germanium?","Ge"},
        {"What is the symbol for arsenic?","As"},
        {"What is the symbol for selenium?","Se"},
        {"What is the symbol for bromine?","Br"},
        {"What is the symbol for krypton?","Kr"},
        {"What is the symbol for rubidium?","Rb"},
        {"What is the symbol for strontium?","Sr"},
        {"What is the symbol for yttrium?","Y"},
        {"What is the symbol for zirconium?","Zr"},
        {"What is the symbol for niobium?","Nb"},
        {"What is the symbol for molybdenum?","Mo"},
        {"What is the symbol for technetium?","Tc"},
        {"What is the symbol for ruthenium?","Ru"},
        {"What is the symbol for rhodium?","Rh"},
        {"What is the symbol for palladium?","Pd"}
    };
    
    //Shuffle the questions array
    shuffleQuestions(questions, MAX_QUESTIONS);
    
    //Welcome message
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given %d questions, and you will have to answer each question with the correct chemical symbol.\n", MAX_QUESTIONS);
    
    //Loop through each question and ask the user for an answer
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        char answer[3];
        printf("Your answer: ");
        scanf("%s", answer);
        //Convert the answer to uppercase for consistency
        for (int j = 0; j < strlen(answer); j++) {
            answer[j] = toupper(answer[j]);
        }
        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", questions[i].answer);
        }
    }
    
    //Print the final score
    printf("\nYour final score is %d out of %d.\n", score, MAX_QUESTIONS);
    
    return 0;
}