//FormAI DATASET v1.0 Category: Online Examination System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* define macros */
#define MAX_Q 50 /* maximum number of questions */
#define MAX_LEN 100 /* maximum length of a question or answer */
#define MAX_CHOICE 4 /* maximum number of choices for a multiple choice question */
#define CORRECT_ANS 10 /* marks for a correct answer */
#define INCORRECT_ANS -5 /* marks for an incorrect answer */
#define TOTAL_TIME 3600 /* total time for examination in seconds */

/* define structures */
typedef struct {
    char question[MAX_LEN+1];
    unsigned int num_options; /* 2 for true/false, 4 for MCQ */
    char options[MAX_CHOICE][MAX_LEN+1];
    int answer; /* index of the correct answer */
}Question;

/* define global variables */
Question questions[MAX_Q];
unsigned int num_questions = 0;

/* function prototypes */
int get_menu_choice(void);
void add_question(void);
void start_exam(void);
void ask_question(Question ques);
void give_result(int total_marks, int marks_obtained);

/* main function */
int main() {
    int choice;
    printf("Welcome to the Online Examination System!\n");
    do {
        choice = get_menu_choice();
        switch(choice) {
            case 1: add_question();
                    break;
            case 2: start_exam();
                    break;
            case 3: printf("Thank you for using the Online Examination System!\n");
                    break;
            default: printf("Invalid input, please try again.\n");
                     break;
        }
    } while(choice != 3);
    return 0;
}

/* function that displays the menu and returns user's choice */
int get_menu_choice(void) {
    int choice;
    printf("Please select one of the following options:\n");
    printf("1. Add a new question\n");
    printf("2. Start an exam\n");
    printf("3. Exit\n");
    scanf("%d", &choice);
    getchar();
    return choice;
}

/* function to add a new question */
void add_question(void) {
    if(num_questions == MAX_Q) {
        printf("Maximum number of questions reached.\n");
        return;
    }
    Question ques;
    printf("Enter the question:\n");
    fgets(ques.question, MAX_LEN+1, stdin);
    printf("Enter the number of options (2 for true/false, 4 for MCQ):\n");
    scanf("%u", &ques.num_options);
    getchar();
    for(int i=0; i<ques.num_options; i++) {
        printf("Enter option %d:\n", i+1);
        fgets(ques.options[i], MAX_LEN+1, stdin);
    }
    printf("Enter the index of the correct answer (1-%u):\n", ques.num_options);
    scanf("%d", &ques.answer);
    getchar();
    if(ques.answer < 1 || ques.answer > ques.num_options) {
        printf("Invalid input, question not added.\n");
        return;
    }
    questions[num_questions++] = ques; /* add question to database */
    printf("Question added successfully.\n");
}

/* function to start the exam */
void start_exam(void) {
    if(num_questions == 0) {
        printf("No questions in the database, please add questions first.\n");
        return;
    }
    int total_marks = 0, marks_obtained = 0;
    time_t start_time, end_time;
    time(&start_time);
    for(int i=0; i<num_questions; i++) {
        ask_question(questions[i]);
        printf("Enter your answer (1-%u):\n", questions[i].num_options);
        int ans;
        scanf("%d", &ans);
        getchar();
        if(ans == questions[i].answer) {
            marks_obtained += CORRECT_ANS;
        }
        else {
            marks_obtained += INCORRECT_ANS;
        }
        total_marks += CORRECT_ANS;
    }
    time(&end_time);
    int duration = (int) difftime(end_time, start_time);
    give_result(total_marks, marks_obtained);
    printf("Time taken: %d minutes %d seconds\n", duration/60, duration%60);
    if(duration > TOTAL_TIME) {
        printf("Time up! Exam ended.\n");
    }
}

/* function to ask a question */
void ask_question(Question ques) {
    printf("%s\n", ques.question);
    for(int i=0; i<ques.num_options; i++) {
        printf("%d) %s\n", i+1, ques.options[i]);
    }
}

/* function to display the result */
void give_result(int total_marks, int marks_obtained) {
    printf("Total marks: %d\n", total_marks);
    printf("Marks obtained: %d\n", marks_obtained);
    if(marks_obtained < 0) {
        printf("You failed the exam.\n");
    }
    else {
        printf("Congratulations! You passed the exam.\n");
    }
}