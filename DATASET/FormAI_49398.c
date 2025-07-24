//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int score = 0;

void printHeader() {
    printf("\n");
    printf("\t\t      *   *   ********   *******   *\n");
    printf("\t\t      *   *   *          *         *\n");
    printf("\t\t      *****   ******     *****     *\n");
    printf("\t\t      *   *   *          *         \n");
    printf("\t\t      *   *   ********   *******   *\n");
    printf("\n");
}

void printQuestion(char *question, char *option1, char *option2, char *option3, char *option4, int answer) {
    printf("\n%s\n", question);
    printf("1. %s\n", option1);
    printf("2. %s\n", option2);
    printf("3. %s\n", option3);
    printf("4. %s\n", option4);
    int useranswer;
    printf("\nEnter your answer: ");
    scanf("%d", &useranswer);
    if(useranswer == answer) score++;
}

void printResult() {
    printf("\nYour score is: %d\n", score);
    if(score == 5) printf("You are a Cyberpunk Chemistry Master!\n");
    else if(score >= 3) printf("You have potential, but need more study!\n");
    else printf("You are not a Cyberpunk, go back to school!\n");
}

int main() {
    char questions[5][100] = {"Which element is represented by the symbol H?", "Which element is represented by the symbol O?", "Which of the following elements is a noble gas?", "What is the only liquid metal at room temperature?", "Which of the following elements is not a metal?"};
    char options[5][4][50] = {{"Helium", "Hydrogen", "Helix", "Hafnium"}, {"Oxygen", "Osmium", "Octane", "Oscillate"}, {"Neon", "Nickle", "Nitrogen", "Nonillion"}, {"Gallium", "Gallien", "Gibberish", "Gold"}, {"Iron", "Iodine", "Indium", "Ivory"}};
    int answers[5] = {2, 1, 0, 0, 1};

    printHeader();
    for(int i = 0; i < 5; i++) {
        printQuestion(questions[i], options[i][0], options[i][1], options[i][2], options[i][3], answers[i]);
    }
    printResult();
    return 0;
}