//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *nouns[] = {"aliens", "illuminati", "government", "big pharma", "media", "tech companies"};
char *verbs[] = {"are manipulating", "are controlling", "are brainwashing", "are monitoring", "are sedating", "are influencing"};
char *adjectives[] = {"secret", "hidden", "dangerous", "unknown", "powerful", "sinister"};
char *objects[] = {"humanity", "the weather", "the economy", "our thoughts", "our health", "our elections"};

char *generate_conspiracy() {
    srand(time(NULL));
    int n_index = rand() % (sizeof(nouns) / sizeof(nouns[0]));
    int v_index = rand() % (sizeof(verbs) / sizeof(verbs[0]));
    int adj_index = rand() % (sizeof(adjectives) / sizeof(adjectives[0]));
    int o_index = rand() % (sizeof(objects) / sizeof(objects[0]));
    char *conspiracy = calloc(100, sizeof(char));
    sprintf(conspiracy, "%s %s %s %s", adjectives[adj_index], nouns[n_index], verbs[v_index], objects[o_index]);
    return conspiracy;
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    while (1) {
        char *conspiracy = generate_conspiracy();
        printf("Did you know...\n%s?\n\n", conspiracy);
        free(conspiracy);
        printf("Want another conspiracy theory? (y/n) ");
        char input;
        scanf(" %c", &input);
        if (input == 'n' || input == 'N') {
            break;
        }
    }
    printf("Thank you for using the Random Conspiracy Theory Generator!\n");
    return 0;
}