//FormAI DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("Welcome to the Online Examination System!\n");

    // Creating an array of questions and answers
    char questions[10][100] = {"1. What is the capital of India?", "2. Who is the CEO of Apple?", "3. Which is the largest desert in the world?", "4. Who won the 2020 Australian Open?", "5. What is the chemical symbol for Gold?",
                               "6. Who directed the movie the Dark Knight?", "7. Who is the Chairman of Microsoft?", "8. Which is the smallest state in the USA?", "9. Who was the first person to climb Mount Everest?", "10. What is the largest island in the world?"};
    char answers[10][100] = {"a) New Delhi b) Mumbai c) Kolkata d) Chennai", "a) Tim Cook b) Steve Jobs c) Bill Gates d) Mark Zuckerberg", "a) Sahara b) Gobi c) Arctic d) Antarctic", "a) Rafael Nadal b) Novak Djokovic c) Roger Federer d) Dominic Thiem", "a) Au b) Ag c) Cu d) Fe",
                             "a) Christopher Nolan b) Quentin Tarantino c) Steven Spielberg d) James Cameron", "a) Satya Nadella b) Bill Gates c) Jeff Bezos d) Sundar Pichai", "a) Rhode Island b) Connecticut c) Delaware d) Hawaii", "a) Sir Edmund Hillary b) Tenzing Norgay c) Reinhold Messner d) George Mallory", "a) Greenland b) Madagascar c) Cuba d) Borneo"};

    // Generating random questions to be asked in the exam
    int i, j, random_numbers[5];
    for(i=0;i<5;i++) {
        int random_num = rand() % 10;
        for(j=0;j<i;j++) {
            if(random_numbers[j] == random_num) {
                random_num = rand() % 10;
                j=-1;
            }
        }
        random_numbers[i] = random_num;
    }

    // Keeping track of the score of the user
    int score = 0;

    // Displaying the questions and getting the user's answers
    for(i=0;i<5;i++) {
        printf("%s\n", questions[random_numbers[i]]);
        char user_answer[2];
        scanf("%s", &user_answer);
        if(user_answer[0] == answers[random_numbers[i]][0]) {
            printf("Correct Answer!\n");
            score += 2;
        }
        else {
            printf("Incorrect Answer.\n");
            score -= 1;
        }
        printf("\n");
    }

    // Displaying the final score of the user
    printf("You've scored a total of %d out of 10 marks in the exam!\n", score);
    return 0;
}