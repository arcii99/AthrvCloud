//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// function to calculate the frequency of each word
void calc_frequencies(char *text, int n, char words[][50], int frequency[]) {
    char *word = strtok(text, " \n");

    while (word != NULL) {
        for (int i = 0; i < n; i++) {
            if (strcmp(words[i], word) == 0) {
                frequency[i]++;
                break;
            }
        }
        word = strtok(NULL, " \n");
    }
}

// function to find the maximum frequency word
int find_max_frequency(int n, int frequency[]) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (frequency[i] > max) {
            max = frequency[i];
        }
    }
    return max;
}

// function to print the summary
void print_summary(char *text, int summary_length, char words[][50], int frequency[]) {
    printf("\n****SUMMARY****\n");
    int i = 0;
    while (summary_length > 0) {
        if (frequency[i] == find_max_frequency(10, frequency)) {
            printf("%s ", words[i]);
            summary_length--;
        }
        i++;
    }
}

int main() {
    char text[] = "Two households, both alike in dignity,\nIn fair Verona, where we lay our scene,\nFrom ancient grudge break to new mutiny,\nWhere civil blood makes civil hands unclean.\nFrom forth the fatal loins of these two foes\nA pair of star-cross'd lovers take their life;\nWhose misadventured piteous overthrows\nDo with their death bury their parents' strife.";

    char words[10][50] = {"households,", "alike", "dignity,", "Verona,", "scene,", "ancient", "mutiny,", "civil", "foes", "lovers"};
    int frequency[10] = {0};

    calc_frequencies(text, 10, words, frequency);

    print_summary(text, 5, words, frequency);

    return 0;

}