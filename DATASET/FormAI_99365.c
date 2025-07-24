//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scientific
#include <stdio.h>
#include <string.h>

#define NUM_ELEMENTS 118

// Define each element as a struct
typedef struct Element {
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicWeight;
} Element;

void printTable(Element elements[]);
int getAnswer();
void checkAnswer(int answer, Element elements[], int index);
void printResults(int score);

int main() {
    // Create an array of Element structs for each element in the Periodic Table
    Element elements[NUM_ELEMENTS] = {
        {"H", "Hydrogen", 1, 1.008},
        {"He", "Helium", 2, 4.003},
        {"Li", "Lithium", 3, 6.941},
        /* Elements ommitted for brevity */ 
        {"C", "Carbon", 6, 12.011}
    };
    
    // Print out the Periodic Table for reference
    printf("Periodic Table:\n");
    printTable(elements);
    printf("\n\n");
    
    // Initialize variables for quiz
    int numQuestions = 0;
    int score = 0;
    
    // Ask user how many questions they want to answer
    printf("How many questions would you like to answer? (Max %d): ", NUM_ELEMENTS);
    scanf("%d", &numQuestions);
    
    // Loop through the number of questions requested and ask a random question
    for (int i = 0; i < numQuestions; i++) {
        // Randomly choose an element
        int randomIndex = rand() % NUM_ELEMENTS;
        Element question = elements[randomIndex];
        
        // Print out the question
        printf("\nQuestion %d: What is the atomic weight of %s? ", i+1, question.name);
        
        // Get the user's answer and check if it's correct
        int answer = getAnswer();
        checkAnswer(answer, elements, randomIndex);
        
        // Update the user's score
        if (answer == question.atomicWeight) {
            score++;
        }
    }
    
    // Print out the user's results
    printf("\n\n");
    printResults(score);
    
    return 0;
}

// Prints the Periodic Table
void printTable(Element elements[]) {
    printf("%-4s%-20s%-15s%s\n", "No", "Name", "Symbol", "Weight");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        Element element = elements[i];
        printf("%-4d%-20s%-15s%.4f\n", element.atomicNumber, element.name, element.symbol, element.atomicWeight);
    }
}

// Gets the user's answer
int getAnswer() {
    int answer = 0;
    scanf("%d", &answer);
    return answer;
}

// Checks if the user's answer is correct
void checkAnswer(int answer, Element elements[], int index) {
    Element question = elements[index];
    if (answer == question.atomicWeight) {
        printf("Correct!");
    } else {
        printf("Incorrect. The atomic weight of %s is %.4f", question.name, question.atomicWeight);
    }
}

// Prints out the user's score and a message based on their score
void printResults(int score) {
    printf("Quiz score: %d/%d\n", score, NUM_ELEMENTS);
    if (score == NUM_ELEMENTS) {
        printf("Congratulations! You have mastered the Periodic Table!");
    } else if (score >= NUM_ELEMENTS/2) {
        printf("Good job! You have a decent knowledge of the Periodic Table.");
    } else {
        printf("Keep studying! You still have much to learn about the Periodic Table.");
    }
}