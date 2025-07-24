//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct question_struct {
    int number;
    char* question;
    char* options[4];
    char answer;
} question;

typedef struct result_struct {
    int correct;
    int total;
} result;

void init_questions(question* q_list) {
    q_list[0].number = 1;
    q_list[0].question = "What is the symbol for Carbon?";
    q_list[0].options[0] = "A) Cc";
    q_list[0].options[1] = "B) Ca";
    q_list[0].options[2] = "C) Co";
    q_list[0].options[3] = "D) Cr";
    q_list[0].answer = 'A';

    q_list[1].number = 2;
    q_list[1].question = "What is the atomic number of Helium?";
    q_list[1].options[0] = "A) 2";
    q_list[1].options[1] = "B) 4";
    q_list[1].options[2] = "C) 6";
    q_list[1].options[3] = "D) 8";
    q_list[1].answer = 'A';

    q_list[2].number = 3;
    q_list[2].question = "What is the symbol for Silver?";
    q_list[2].options[0] = "A) Sl";
    q_list[2].options[1] = "B) Si";
    q_list[2].options[2] = "C) Ag";
    q_list[2].options[3] = "D) Au";
    q_list[2].answer = 'C';

    q_list[3].number = 4;
    q_list[3].question = "What is the most abundant element in the universe?";
    q_list[3].options[0] = "A) Hydrogen";
    q_list[3].options[1] = "B) Helium";
    q_list[3].options[2] = "C) Oxygen";
    q_list[3].options[3] = "D) Carbon";
    q_list[3].answer = 'A';

    q_list[4].number = 5;
    q_list[4].question = "What element is used to make computer chips?";
    q_list[4].options[0] = "A) Silicon";
    q_list[4].options[1] = "B) Sodium";
    q_list[4].options[2] = "C) Silver";
    q_list[4].options[3] = "D) Sulfur";
    q_list[4].answer = 'A';

    q_list[5].number = 6;
    q_list[5].question = "What is the symbol for Gold?";
    q_list[5].options[0] = "A) Ag";
    q_list[5].options[1] = "B) Ge";
    q_list[5].options[2] = "C) Au";
    q_list[5].options[3] = "D) Ga";
    q_list[5].answer = 'C';

    q_list[6].number = 7;
    q_list[6].question = "What element has the atomic number 26?";
    q_list[6].options[0] = "A) Iron";
    q_list[6].options[1] = "B) Nickel";
    q_list[6].options[2] = "C) Copper";
    q_list[6].options[3] = "D) Zinc";
    q_list[6].answer = 'A';

    q_list[7].number = 8;
    q_list[7].question = "What element is used to make bleach?";
    q_list[7].options[0] = "A) Sodium";
    q_list[7].options[1] = "B) Chlorine";
    q_list[7].options[2] = "C) Calcium";
    q_list[7].options[3] = "D) Magnesium";
    q_list[7].answer = 'B';

    q_list[8].number = 9;
    q_list[8].question = "What element has the symbol Co?";
    q_list[8].options[0] = "A) Cobalt";
    q_list[8].options[1] = "B) Carbon";
    q_list[8].options[2] = "C) Copper";
    q_list[8].options[3] = "D) Chromium";
    q_list[8].answer = 'A';

    q_list[9].number = 10;
    q_list[9].question = "What is the atomic number of Nitrogen?";
    q_list[9].options[0] = "A) 6";
    q_list[9].options[1] = "B) 7";
    q_list[9].options[2] = "C) 8";
    q_list[9].options[3] = "D) 9";
    q_list[9].answer = 'B';
}

void shuffle_questions(question* q_list, int num_questions) {
    srand(time(NULL));
    for (int i = num_questions-1; i > 0; i--) {
        int j = rand() % (i+1);
        question temp = q_list[i];
        q_list[i] = q_list[j];
        q_list[j] = temp;
    }
}

char get_answer() {
    char answer;
    printf("Enter your answer (A/B/C/D): ");
    scanf(" %c", &answer);
    answer = toupper(answer);
    while (getchar() != '\n');
    if (answer < 'A' || answer > 'D') {
        printf("Invalid input, please try again.\n");
        return get_answer();
    }
    return answer;
}

void print_question(question q) {
    printf("\n\nQuestion #%d: %s\n", q.number, q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.options[i]);
    }
}

result generate_quiz(question* q_list, int num_questions) {
    result res = {0,0};
    for (int i = 0; i < num_questions; i++) {
        print_question(q_list[i]);
        char answer = get_answer();
        if (answer == q_list[i].answer) {
            printf("Correct! The answer is %c.\n", answer);
            res.correct++;
        } else {
            printf("Sorry, the correct answer is %c.\n", q_list[i].answer);
        }
        res.total++;
    }
    return res;
}

void print_results(result res) {
    printf("\n\nYou got %d out of %d questions correct!\n", res.correct, res.total);
}

int main() {
    question q_list[MAX_QUESTIONS];
    init_questions(q_list);
    shuffle_questions(q_list, MAX_QUESTIONS);

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the periodic table.\n", MAX_QUESTIONS);
    
    result res = generate_quiz(q_list, MAX_QUESTIONS);
    print_results(res);

    return 0;
}