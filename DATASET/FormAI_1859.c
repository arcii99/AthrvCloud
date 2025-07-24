//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Question {       // Question struct which will store question and options
    char text[500];
    char option1[100];
    char option2[100];
    char option3[100];
    char option4[100];
    int correctOption;
};

struct Question questions[10];    // Array to store 10 questions
int score = 0;    // variable to store the score of the participant

int startExam() {      // function to start the exam and ask questions
    int i;
    for (i=0; i<10; i++) {    // Loop through the array of questions
        printf("%d. %s\n", i+1, questions[i].text);    // Print the Question
        printf("1. %s\n2. %s\n3. %s\n4. %s\n", questions[i].option1, questions[i].option2, questions[i].option3, questions[i].option4);   // Print the options
        int option;
        scanf("%d", &option);
        if (option == questions[i].correctOption) {   // Check if the participant gave the correct answer
            score++;     
        }
    }
    printf("Your score is %d out of 10", score);    // Print the Final Score
    return 0;
}

int main() {
    strcpy(questions[0].text, "What is the capital of India?");     // Question 1
    strcpy(questions[0].option1, "Mumbai");
    strcpy(questions[0].option2, "Delhi");
    strcpy(questions[0].option3, "Kolkata");
    strcpy(questions[0].option4, "Chennai");
    questions[0].correctOption = 2; 

    strcpy(questions[1].text, "What is the currency of Japan?");    // Question 2
    strcpy(questions[1].option1, "Dollar");
    strcpy(questions[1].option2, "Yen");
    strcpy(questions[1].option3, "Euro");
    strcpy(questions[1].option4, "Pound");
    questions[1].correctOption = 2;

    strcpy(questions[2].text, "Who is the current CEO of Microsoft?");   // Question 3
    strcpy(questions[2].option1, "Bill Gates");
    strcpy(questions[2].option2, "Steve Ballmer");
    strcpy(questions[2].option3, "Satya Nadella");
    strcpy(questions[2].option4, "Mark Zuckerberg");
    questions[2].correctOption = 3;

    strcpy(questions[3].text, "What is the chemical formula for water?");   // Question 4
    strcpy(questions[3].option1, "H2SO4");
    strcpy(questions[3].option2, "NH3");
    strcpy(questions[3].option3, "H2O");
    strcpy(questions[3].option4, "C6H12O6");
    questions[3].correctOption = 3;

    strcpy(questions[4].text, "Who wrote the famous book 'To Kill a Mockingbird'?");  // Question 5
    strcpy(questions[4].option1, "Mark Twain");
    strcpy(questions[4].option2, "Harper Lee");
    strcpy(questions[4].option3, "Charles Dickens");
    strcpy(questions[4].option4, "William Shakespeare");
    questions[4].correctOption = 2;

    strcpy(questions[5].text, "What is the SI unit of Force?");  // Question 6
    strcpy(questions[5].option1, "Newton");
    strcpy(questions[5].option2, "Joule");
    strcpy(questions[5].option3, "Watt");
    strcpy(questions[5].option4, "Pascal");
    questions[5].correctOption = 1;

    strcpy(questions[6].text, "What is the national animal of India?");   // Question 7
    strcpy(questions[6].option1, "Horse");
    strcpy(questions[6].option2, "Tiger");
    strcpy(questions[6].option3, "Lion");
    strcpy(questions[6].option4, "Elephant");
    questions[6].correctOption = 2;

    strcpy(questions[7].text, "Who invented the telephone?");   // Question 8
    strcpy(questions[7].option1, "Thomas Alva Edison");
    strcpy(questions[7].option2, "Alexander Graham Bell");
    strcpy(questions[7].option3, "Albert Einstein");
    strcpy(questions[7].option4, "Nikola Tesla");
    questions[7].correctOption = 2;

    strcpy(questions[8].text, "What is the national bird of USA?");   // Question 9
    strcpy(questions[8].option1, "Eagle");
    strcpy(questions[8].option2, "Swan");
    strcpy(questions[8].option3, "Peacock");
    strcpy(questions[8].option4, "Flamingo");
    questions[8].correctOption = 1;

    strcpy(questions[9].text, "Which company owns Whatsapp?");   // Question 10
    strcpy(questions[9].option1, "Microsoft");
    strcpy(questions[9].option2, "Google");
    strcpy(questions[9].option3, "Facebook");
    strcpy(questions[9].option4, "Twitter");
    questions[9].correctOption = 3;

    printf("Welcome to the Online Exam System!\n");
    printf("You will be asked 10 multiple choice questions.\n");
    printf("Please select the correct option.\n\n");
    startExam();   // Start the exam
    return 0;
}