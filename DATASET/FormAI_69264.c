//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100

/* Function to read Wi-Fi signal strength from a file */
int read_signal_strength(const char *filename) {
    FILE *fp;
    char buf[256];
    int strength = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fgets(buf, sizeof(buf), fp);
    strength = atoi(buf);

    fclose(fp);

    return strength;
}

/* Function to display Wi-Fi signal strength */
void display_signal_strength(int strength) {
    printf("Wi-Fi Signal Strength: %d%%\n", strength);
    if (strength >= 70) {
        printf("Signal strength is excellent\n");
    } else if (strength >= 50) {
        printf("Signal strength is good\n");
    } else if (strength >= 30) {
        printf("Signal strength is fair\n");
    } else {
        printf("Signal strength is poor\n");
    }
}

/* Main function */
int main(int argc, char *argv[]) {
    int signal_strength = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <signal_strength_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal_strength = read_signal_strength(argv[1]);

    if (signal_strength < 0 || signal_strength > MAX_SIGNAL_STRENGTH) {
        fprintf(stderr, "Invalid signal strength: %d\n", signal_strength);
        exit(EXIT_FAILURE);
    }

    display_signal_strength(signal_strength);

    return 0;
}