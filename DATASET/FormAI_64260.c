//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: modular
#include <stdio.h>

void print_question(int question_num, char* question) {
    printf("Question %d:\n%s\n", question_num, question);
}

int prompt_answer() {
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);
    return answer;
}

int is_correct_answer(int answer, int correct_answer) {
    if (answer == correct_answer) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %d.\n", correct_answer);
        return 0;
    }
}

void ask_question(int question_num, char* question, int correct_answer) {
    print_question(question_num, question);
    int answer = prompt_answer();
    is_correct_answer(answer, correct_answer);
}

void periodic_table_quiz() {
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");

    ask_question(1, "What is the symbol for Oxygen?", 8);
    ask_question(2, "What is the atomic number of Gold?", 79);
    ask_question(3, "What is the symbol for Sodium?", 11);
    ask_question(4, "What element has the highest atomic number?", 118);

    printf("You scored %d out of 4!\n", score);
}

int main() {
    periodic_table_quiz();
    return 0;
}