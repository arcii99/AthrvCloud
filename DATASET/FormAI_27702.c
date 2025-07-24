//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element {
    char sym[3], name[30];
    int atomic_num, period, group;
    float atomic_mass;
};

struct Element *periodic_table;

void load_periodic_table() {
    FILE *fp = fopen("periodic_table.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open file.\n");
        exit(1);
    }
    char line[100];
    int num_elements = 0;
    while (fgets(line, 100, fp) != NULL) {
        num_elements++;
    }
    fseek(fp, 0, SEEK_SET);
    periodic_table = malloc(num_elements * sizeof(struct Element));
    int i = 0;
    while (fgets(line, 100, fp) != NULL) {
        sscanf(line, "%d %s %s %f %d %d", &periodic_table[i].atomic_num, periodic_table[i].sym,
               periodic_table[i].name, &periodic_table[i].atomic_mass, &periodic_table[i].period, &periodic_table[i].group);
        i++;
    }
    fclose(fp);
}

void quiz() {
    int score = 0;
    int total_questions = 10;
    int question_num = 0;
    char response[10];
    int random_index;
    printf("Welcome to the Periodic Table Quiz.\n");
    printf("There are %d questions in total.\n", total_questions);
    printf("Guess the element from the symbol or name.\n");
    for (int i = 0; i < total_questions; i++) {
        question_num++;
        random_index = rand() % 118;
        printf("Question %d: ", question_num);
        if (rand() % 2 == 0) {
            printf("%s - ", periodic_table[random_index].sym);
            scanf("%s", response);
            if (strcmp(response, periodic_table[random_index].name) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", periodic_table[random_index].name);
            }
        } else {
            printf("%s - ", periodic_table[random_index].name);
            scanf("%s", response);
            if (strcmp(response, periodic_table[random_index].sym) == 0) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %s.\n", periodic_table[random_index].sym);
            }
        }
    }
    printf("Quiz complete. You scored %d out of %d.\n", score, total_questions);
}

int main() {
    load_periodic_table();
    quiz();
    free(periodic_table);
    return 0;
}