//FormAI DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include <stdio.h>
#include <string.h>

int main(){
    char text[1000] = "Fair lady in the castle up high, please lend me your ears as I speak true. For this program shall summarize thy words, in a manner befitting a knight as myself. Enter the text thou wishes to be summarised here:";
    int len = strlen(text);
    char summary[1000] = "The summary of thy words is as follows:";
    printf("%s\n", text);
    fgets(text, 1000, stdin);
    text[strcspn(text, "\n")] = 0;
    strcat(summary, "\n");

    int word_count = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        if (word_count < 10) {
            strcat(summary, word);
            strcat(summary, " ");
            word_count++;
        } else {
            strcat(summary, "...");
            break;
        }
        word = strtok(NULL, " ");
    }

    int summary_len = strlen(summary);
    printf("%s", summary);

    char farewell[1000] = "\nFarewell, fair lady in the castle, may thy days be filled with joy and wonder";
    printf("%s", farewell);
    return 0;
}