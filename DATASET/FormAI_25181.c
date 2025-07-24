//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Linux Linus Torvalds Style */
#define ERR(prog, msg) { \
    fprintf(stderr, "\033[31;1mError in %s:\033[0m %s\n", prog, msg); \
    exit(EXIT_FAILURE); \
}

#define WARN(prog, msg) { \
    fprintf(stderr, "\033[33;1mWarning in %s:\033[0m %s\n", prog, msg); \
}

#define INFO(prog, msg) { \
    fprintf(stdout, "\033[32;1mInfo in %s:\033[0m %s\n", prog, msg); \
}

#define MAX_FORTUNE_LEN 100

char *fortunes[] = {
    "A good beginning is half the task.",
    "A sound mind in a sound body.",
    "All good things come to those who wait.",
    "Fortune favors the brave.",
    "You will soon discover a hidden talent.",
    "Good things come in small packages.",
    "You will overcome your difficulties.",
    "Hard work pays off in the end.",
    "You will be rewarded for your efforts.",
    "The best things in life are free.",
    "Life is a journey, enjoy the ride.",
    "You will find happiness in unexpected places.",
    "Believe in yourself and anything is possible.",
    "Your true love is just around the corner.",
    "You will achieve great things in life.",
    "Your future is bright.",
    "Success is just around the corner.",
    "You will discover something new and exciting.",
    "Good things come to those who persevere.",
    "Every cloud has a silver lining."
};

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed RNG with current time
    int fortune_count = sizeof(fortunes) / sizeof(char *);
    if (argc != 2) {
        WARN(argv[0], "Usage: ./fortune-teller <name>");
    }
    char *name = argv[1];
    int fortune_idx = rand() % fortune_count;
    char *fortune = fortunes[fortune_idx];
    printf("Hello %s, your fortune for today is:\n%s\n", name, fortune);
    if (strlen(fortune) > MAX_FORTUNE_LEN) {
        ERR(argv[0], "Maximum fortune length exceeded.");
    }
    return EXIT_SUCCESS;
}