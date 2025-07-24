//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

// function to calculate time difference between two timespec structs
double diff_in_sec(struct timespec start_time, struct timespec end_time) {
    double diff_sec = (double) (end_time.tv_sec - start_time.tv_sec);
    double diff_nsec = (double) (end_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;
    return diff_sec + diff_nsec;
}

int main() {
    // welcome message
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be provided with a random sentence which you have to type as quickly and accurately as possible.\n");
    printf("Press any key to start...\n");
    getchar();

    // array of possible sentences to type
    char sentences[][BUFFER_SIZE] = {
        "The quick brown fox jumps over the lazy dog.",
        "Jackdaws love my big sphinx of quartz.",
        "How vexingly quick daft zebras jump!",
        "The five boxing wizards jump quickly.",
        "Quick zephyrs blow, vexing daft Jim.",
        "Sphinx of black quartz, judge my vow.",
        "The jay, pig, fox, zebra and my wolves quack!",
        "Waltz, nymph, for quick jigs vex Bud.",
        "Pack my box with five dozen liquor jugs.",
        "The quick onyx goblin jumps over the lazy dwarf.",
        "Jaded zombies acted quaintly but kept driving their oxen forward.",
        "The job requires extra pluck and zeal from every young wage earner.",
        "How razorback jumping frogs can level six piqued gymnasts.",
        "Grumpy wizards make toxic brew for the evil queen and jack.",
        "Fox nymphs grab quick-jived waltz.",
        "Crazy Frederick bought many very exquisite opal jewels.",
        "The quick brown fox jumps over a lazy dog.",
        "The five boxing wizards jump quickly."
    };
    int num_sentences = sizeof(sentences) / sizeof(sentences[0]);

    // generate a random sentence
    srand(time(NULL));
    int random_index = rand() % num_sentences;
    char sentence[BUFFER_SIZE];
    strncpy(sentence, sentences[random_index], BUFFER_SIZE);

    // display the sentence for the user to type
    printf("Your sentence is:\n\n%s\n\n", sentence);

    // get start time
    struct timespec start_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // get user input
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);

    // get end time
    struct timespec end_time;
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // calculate time taken and words per minute
    double time_taken = diff_in_sec(start_time, end_time);
    int num_words = 1;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            num_words++;
        }
    }
    double wpm = (double) num_words / time_taken * 60.0;

    // display results
    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Words per minute: %.2f\n", wpm);

    return 0;
}