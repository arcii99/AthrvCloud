//FormAI DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question(char* q, char** a, int c, int* u) {
    printf("%s\n", q);
    for (int i = 0; i < c; i++) {
        printf("%d. %s\n", i+1, a[i]);
    }
    printf("Enter your answer: ");
    scanf("%d", u);
}

int main() {
    int score = 0;
    int questions[5][3] = {{1, 2, 3}, {2, 3, 1}, {3, 1, 2}, {1, 3, 2}, {3, 2, 1}};
    char* q[5] = {"What is the capital of France?", "What is the largest organ in the human body?", "What is the nickname given to the NBA's Chicago team?", "What's the highest mountain in the world?", "When was the first iPhone released?"};
    char* a[5][3] = {{"Paris", "Berlin", "Madrid"}, {"Liver", "Lung", "Skin"}, {"Bulls", "Warriors", "Celtics"}, {"Mount Kilimanjaro", "Mount Everest", "Mount Fuji"}, {"June 29, 2007", "June 29, 2006", "June 29, 2008"}};
    int ua[5];
    srand(time(NULL));
    int order[5];
    for (int i = 0; i < 5; i++) {
        order[i] = i;
    }
    for (int i = 0; i < 5; i++) {
        int j = rand() % 5;
        int t = order[i];
        order[i] = order[j];
        order[j] = t;
    }
    for (int i = 0; i < 5; i++) {
        question(q[order[i]], a[order[i]], 3, &ua[order[i]]);
        ua[order[i]]--;
        if (ua[order[i]] == questions[order[i]][0]) {
            score += 2;
        } else if (ua[order[i]] == questions[order[i]][1]) {
            score += 1;
        }
    }
    printf("Your final score is: %d\n", score);
    return 0;
}