//FormAI DATASET v1.0 Category: Online Examination System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//function to generate random numbers
int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

//structure to hold the details of a question
struct Question {
    int id;
    char question[1000];
    char options[4][1000];
    char answer;
};

int main() {

    //array to hold the questions
    struct Question questions[10];

    //seed the random number generator
    srand(time(0));

    //populate questions array with sample questions
    questions[0].id = 1;
    strcpy(questions[0].question, "What is the capital of Egypt?");
    strcpy(questions[0].options[0], "a. Cairo");
    strcpy(questions[0].options[1], "b. Alexandria");
    strcpy(questions[0].options[2], "c. Giza");
    strcpy(questions[0].options[3], "d. Luxor");
    questions[0].answer = 'a';

    questions[1].id = 2;
    strcpy(questions[1].question, "What is the highest mountain in the world?");
    strcpy(questions[1].options[0], "a. Mount Everest");
    strcpy(questions[1].options[1], "b. K2");
    strcpy(questions[1].options[2], "c. Mount Kilimanjaro");
    strcpy(questions[1].options[3], "d. Mount Fuji");
    questions[1].answer = 'a';

    questions[2].id = 3;
    strcpy(questions[2].question, "What is the largest country by area?");
    strcpy(questions[2].options[0], "a. Russia");
    strcpy(questions[2].options[1], "b. Canada");
    strcpy(questions[2].options[2], "c. China");
    strcpy(questions[2].options[3], "d. Australia");
    questions[2].answer = 'a';

    questions[3].id = 4;
    strcpy(questions[3].question, "What is the largest ocean in the world?");
    strcpy(questions[3].options[0], "a. Pacific Ocean");
    strcpy(questions[3].options[1], "b. Atlantic Ocean");
    strcpy(questions[3].options[2], "c. Indian Ocean");
    strcpy(questions[3].options[3], "d. Southern Ocean");
    questions[3].answer = 'a';

    questions[4].id = 5;
    strcpy(questions[4].question, "What is the number of players on a standard soccer team?");
    strcpy(questions[4].options[0], "a. 11");
    strcpy(questions[4].options[1], "b. 12");
    strcpy(questions[4].options[2], "c. 10");
    strcpy(questions[4].options[3], "d. 9");
    questions[4].answer = 'a';

    questions[5].id = 6;
    strcpy(questions[5].question, "What is the smallest continent in the world?");
    strcpy(questions[5].options[0], "a. Australia");
    strcpy(questions[5].options[1], "b. Europe");
    strcpy(questions[5].options[2], "c. South America");
    strcpy(questions[5].options[3], "d. Africa");
    questions[5].answer = 'a';

    questions[6].id = 7;
    strcpy(questions[6].question, "What is the national currency of Japan?");
    strcpy(questions[6].options[0], "a. Yen");
    strcpy(questions[6].options[1], "b. Peso");
    strcpy(questions[6].options[2], "c. Lira");
    strcpy(questions[6].options[3], "d. Franc");
    questions[6].answer = 'a';

    questions[7].id = 8;
    strcpy(questions[7].question, "What is the largest bird in the world?");
    strcpy(questions[7].options[0], "a. Ostrich");
    strcpy(questions[7].options[1], "b. Eagle");
    strcpy(questions[7].options[2], "c. Condor");
    strcpy(questions[7].options[3], "d. Albatross");
    questions[7].answer = 'a';

    questions[8].id = 9;
    strcpy(questions[8].question, "What is the smallest country in the world?");
    strcpy(questions[8].options[0], "a. Vatican City");
    strcpy(questions[8].options[1], "b. Monaco");
    strcpy(questions[8].options[2], "c. San Marino");
    strcpy(questions[8].options[3], "d. Liechtenstein");
    questions[8].answer = 'a';

    questions[9].id = 10;
    strcpy(questions[9].question, "What is the highest waterfall in the world?");
    strcpy(questions[9].options[0], "a. Angel Falls");
    strcpy(questions[9].options[1], "b. Niagara Falls");
    strcpy(questions[9].options[2], "c. Victoria Falls");
    strcpy(questions[9].options[3], "d. Iguazu Falls");
    questions[9].answer = 'a';

    int score = 0;
    int i;

    //loop through the questions and ask them
    for (i = 0; i < 5; i++) {
        int randomIndex = generateRandomNumber(0, 9);
        printf("Question %d: %s\n", i+1, questions[randomIndex].question);
        printf("%s\n", questions[randomIndex].options[0]);
        printf("%s\n", questions[randomIndex].options[1]);
        printf("%s\n", questions[randomIndex].options[2]);
        printf("%s\n", questions[randomIndex].options[3]);

        char answer;
        printf("Enter your answer:");
        scanf(" %c", &answer);

        if (answer == questions[randomIndex].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", questions[randomIndex].answer);
        }
    }

    printf("Your score is %d out of 5.\n", score);

    return 0;
}