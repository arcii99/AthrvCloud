//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>

#define MAX_SUSPECTS 10

struct suspect {
    char name[50];
    int score;
};

void find_killer(struct suspect suspects[], int num_suspects) {
    int max_score = -1;
    char *killer_name;
    for (int i = 0; i < num_suspects; i++) {
        if (suspects[i].score > max_score) {
            max_score = suspects[i].score;
            killer_name = suspects[i].name;
        }
    }
    printf("The killer is %s!\n", killer_name);
}

int main() {
    struct suspect suspects[MAX_SUSPECTS] = {
        {"John Doe", 0},
        {"Jane Smith", 0},
        {"Bob Johnson", 0},
        {"Mike Davis", 0},
        {"Sara White", 0},
        {"Tom Wilson", 0},
        {"Patricia Green", 0},
        {"Jason Lee", 0},
        {"Chris Brown", 0},
        {"Alex Turner", 0}
    };

    // Process evidence and calculate scores for each suspect
    // ...

    // Call the find_killer function
    find_killer(suspects, MAX_SUSPECTS);

    return 0;
}