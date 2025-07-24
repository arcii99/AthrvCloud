//FormAI DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct question {
    char prompt[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_option;
};

typedef struct question Question;

int main() {
    int total_questions = 5;
    int marks_per_question = 2;
    Question question_list[5];

    //initialize questions and options
    strcpy(question_list[0].prompt, "Which of the following language is not an Object-Oriented Programming language?");
    strcpy(question_list[0].option1, "C++");
    strcpy(question_list[0].option2, "Java");
    strcpy(question_list[0].option3, "C#");
    strcpy(question_list[0].option4, "C");
    question_list[0].correct_option = 4;

    strcpy(question_list[1].prompt, "What is the output of the following code snippet?\nint a = 1;\nint b = 2;\nint c = a + b;\nprintf(\"%d\", c);\n");
    strcpy(question_list[1].option1, "3");
    strcpy(question_list[1].option2, "12");
    strcpy(question_list[1].option3, "Error");
    strcpy(question_list[1].option4, "None of the above");
    question_list[1].correct_option = 1;

    strcpy(question_list[2].prompt, "Which of the following is a data structure used to implement LIFO?");
    strcpy(question_list[2].option1, "Stack");
    strcpy(question_list[2].option2, "Queue");
    strcpy(question_list[2].option3, "Tree");
    strcpy(question_list[2].option4, "Array");
    question_list[2].correct_option = 1;

    strcpy(question_list[3].prompt, "What is the size of a char variable in C?");
    strcpy(question_list[3].option1, "2 bytes");
    strcpy(question_list[3].option2, "1 byte");
    strcpy(question_list[3].option3, "4 bytes");
    strcpy(question_list[3].option4, "Depends on the system");
    question_list[3].correct_option = 2;

    strcpy(question_list[4].prompt, "What is the output of the following code snippet?\nint i = 1;\nwhile(i <= 5) {\n    printf(\"%d \", i);\n    i++;\n}\n");
    strcpy(question_list[4].option1, "12345");
    strcpy(question_list[4].option2, "54321");
    strcpy(question_list[4].option3, "15");
    strcpy(question_list[4].option4, "Error");
    question_list[4].correct_option = 1;

    int total_marks = 0;
    int choice;
    for(int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i+1, question_list[i].prompt);
        printf("1. %s\n", question_list[i].option1);
        printf("2. %s\n", question_list[i].option2);
        printf("3. %s\n", question_list[i].option3);
        printf("4. %s\n", question_list[i].option4);
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if(choice == question_list[i].correct_option) {
            total_marks += marks_per_question;
        }
    }

    printf("\nTotal marks: %d\n", total_marks);

    return 0;
}