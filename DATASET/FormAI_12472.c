//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int wordcount = 0;
    char c;
    int starttime, endtime, totaltime;
    int correct = 0, incorrect = 0;

    // Prompting the user to get ready
    printf("Welcome to the Typing Speed Test.\n");
    printf("Type the following passage as fast and accurately as possible:\n\n");

    // the passage for the user to type
    printf("If you can keep your head when all about you\nAre losing theirs and blaming it on you,\nIf you can trust yourself when all men doubt you,\nBut make allowance for their doubting too;\n\nIf you can wait and not be tired of waiting,\nOr being lied about, don't deal in lies,\nOr being hated, don't give way to hating,\nAnd yet do not look too good, nor talk too wise:\n\nIf you can dream—and not make dreams your master;\nIf you can think—and not make thoughts your aim;\nIf you can meet with Triumph and Disaster\nAnd treat those two impostors just the same;\n\nIf you can bear to hear the truth you've spoken\nTwisted by knaves to make a trap for fools,\nOr watch the things you gave your life to, broken,\nAnd stoop and build 'em up with worn-out tools:\n\nIf you can make one heap of all your winnings\nAnd risk it on one turn of pitch-and-toss,\nAnd lose, and start again at your beginnings\nAnd never breathe a word about your loss;\n\nIf you can force your heart and nerve and sinew\nTo serve your turn long after they are gone,\nAnd so hold on when there is nothing in you\nExcept the Will which says to them: ‘Hold on!’\n\nIf you can talk with crowds and keep your virtue,\nOr walk with Kings—nor lose the common touch,\nIf neither foes nor loving friends can hurt you,\nIf all men count with you, but none too much;\n\nIf you can fill the unforgiving minute\nWith sixty seconds’ worth of distance run,\nYours is the Earth and everything that’s in it,\nAnd—which is more—you’ll be a Man, my son!\n\n");

    // Recording the start time of typing
    printf("Press enter when you are ready to start typing...");
    getchar(); // waiting for user input

    starttime = time(0);

    // Repeating the passage until it is fully typed
    while (c != '\n' || wordcount < 301) { // 301 is the number of words in the passage
        c = getchar();
        if (c == ' ' || c == '\n') {
            wordcount++;
        }
    }

    endtime = time(0);
    totaltime = endtime - starttime;

    // Counting correct and incorrect characters
    printf("Time taken: %d seconds.\n", totaltime);
    printf("You typed %d words.\n", wordcount);
    printf("Now let's see how accurate you were:\n");

    c = getchar(); // clearing the newline character from the buffer

    // Repeating the passage to compare typed input
    printf("\n");
    printf("Result:\n");

    // Starting timer for displaying each word – add more time for longer words
    starttime = time(0);
    int prevtime = starttime;
    int elapsedtime = 0;

    // Repeating the passage to compare the typed input
    wordcount = 0; // Resetting the word count
    while (c != '\n' || wordcount < 301) {
        c = getchar();
        // Counting correct and incorrect characters
        if (c == ' ' || c == '\n') {
            wordcount++; // count the words by space and newline
            char passage[] = "If you can keep your head";
            int size = sizeof(passage)/sizeof(passage[0]); // Size of the passage
            char typed[size];
            fgets(typed, size, stdin);
            for (int i = 0; i < size-1; i++) {
                if (passage[i] != typed[i]) {
                    incorrect++;
                } else {
                    correct++;
                }
            }
            elapsedtime = time(0) - prevtime;
            // Displaying each word and time taken
            printf("'%s'...%ds\n", passage, elapsedtime);
            prevtime = time(0); // resetting the timer for the next word
        }
    }

    // Correctness and accuracy statistics
    int totalcharacters = correct + incorrect;
    float accuracy = ((float) correct / (float) totalcharacters) * 100;
    float cpm = ((float) totalcharacters / (float) totaltime) * 60;
    printf("Total Words Typed: %d\n", wordcount);
    printf("Correctly Typed Characters: %d\n", correct);
    printf("Incorrectly Typed Characters: %d\n", incorrect);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing Speed: %.0f CPM (Characters Per Minute)\n", cpm);

    return 0;
}