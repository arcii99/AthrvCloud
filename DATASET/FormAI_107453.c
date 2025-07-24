//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LENGTH 100
#define MAX_THREADS 10

char ASCII_ART[10][6][56] = {
    {
    " _______ ",
    "/       \\",
    "|  0  0 |",
    "|   _   |",
    "|  \\_/  |",
    "\\_______\\"
    },
    {
    "    /\\   ",
    "   /  \\  ",
    "  / ++ \\ ",
    " /  00  \\",
    "/_______\\"
    },
    {
    "========",
    " ||    ||",
    " ||====||",
    " ||    ||",
    "========"
    },
    {
    "_______ ",
    "|       |",
    "|  ^_^  |",
    "|   -   |",
    "|_______|",
    "        "
    },
    {
    "  _____ ",
    " (0 @ 0)",
    "((_____)",
    " \\     /",
    "  // \\\\",
    " ((   ))"
    },
    {
    "     /|\\",
    "    / | \\",
    "   /  |  \\",
    "  /__ | __\\",
    " (____|____)",
    "[|   / \\   |]",
    " |____/ \\____|"
    },
    {
    "       .--.",
    "     / o  o \\",
    "    /   .    \\",
    " __/_      _\\__",
    "/   _`----'    \\",
    "\\_/           \\_/",
    "               "
    },
    {
    "  .----.",
    " /'''''\\",
    "( don't )",
    " \\ stomp /",
    "  '-'-'-'",
    "         "
    },
    {
    " /\\-----/\\",
    "( /\\---/\\ )",
    " '._\\/_.'",
    "    '"
    },
    {
    "    ,_",
    "    | \\__,--._",
    "  .-' |_#__\\/_ )",
    " /  _ '-\_( )__\\",
    "`-'\`\__(_ )_))",
    "    <___/\\___/"
    }
};

typedef struct thread_args {
    char text[MAX_LENGTH];
    int index;
} thread_args;

void *generate_ascii_art(void *arg) {
    thread_args *args = (thread_args *) arg;

    int length = strlen(args->text);
    int row = args->index;

    for (int i=0; i < length; i++) {
        char c = args->text[i];
        int column = (i * 6) + 3;

        // ignore non-ASCII characters
        if (c < 0 || c > 126) continue;

        // print the ASCII art character
        for (int j=0; j < 6; j++) {
            printf("%c", ASCII_ART[row][(int)(c - ' ' + j) % 6][column]);
        }
    }

    printf("\n");
    pthread_exit(NULL);
}

int main() {
    // initialize variables
    char text[MAX_LENGTH];
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    thread_args args[MAX_THREADS];

    // get input from user
    printf("Enter a string to convert to ASCII art:\n");
    fgets(text, sizeof(text), stdin);

    // remove newline character from input
    strtok(text, "\n");

    // calculate number of threads needed
    int length = strlen(text);
    if (length % 6 == 0) {
        num_threads = length / 6;
    } else {
        num_threads = (length / 6) + 1;
    }

    // create threads and print ASCII art
    for (int i=0; i < num_threads; i++) {
        args[i].index = i;

        // copy a portion of the input string to each thread's argument struct
        strncpy(args[i].text, text + (i * 6), 6);
        args[i].text[6] = '\0';

        // create the thread
        pthread_create(&threads[i], NULL, generate_ascii_art, &args[i]);

        // wait for the thread to finish
        pthread_join(threads[i], NULL);
    }

    return 0;
}