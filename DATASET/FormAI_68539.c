//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100
#define MAX_SUMMARY 200

// Function to calculate ratio of overlapping words
float overlap_ratio(char* s1, char* s2) {
    int overlap = 0;
    char *word1, *word2;
    // Find each word in s1
    for (word1 = strtok(s1, " "); word1 != NULL; word1 = strtok(NULL, " ")) {
        // Find each word in s2
        for (word2 = strtok(s2, " "); word2 != NULL; word2 = strtok(NULL, " ")) {
            if (strcmp(word1, word2) == 0) {
                overlap++;
                break;
            }
        }
    }
    return (float)overlap / (float)(strlen(s1) + strlen(s2));
}

int main() {
    char lines[MAX_LINES][MAX_CHARS_PER_LINE+1], summary[MAX_SUMMARY+1];
    int num_lines = 0;
    float max_score;
    int i, j, max_index;
    // Read in lines of text until encountering end of file or too many lines
    while (num_lines < MAX_LINES && fgets(lines[num_lines], MAX_CHARS_PER_LINE+1, stdin) != NULL) {
        num_lines++;
    }
    // Generate summary by selecting lines with highest overlap ratios
    summary[0] = '\0';
    while (strlen(summary) < MAX_SUMMARY && num_lines > 0) {
        max_score = -1.0;
        max_index = -1;
        // Find line with highest overlap score to add to summary
        for (i = 0; i < num_lines; i++) {
            float score = 0.0;
            for (j = 0; j < num_lines; j++) {
                if (i != j) {
                    float ratio = overlap_ratio(lines[i], lines[j]);
                    score += ratio;
                }
            }
            if (score > max_score) {
                max_score = score;
                max_index = i;
            }
        }
        // Add selected line to summary and remove it from list of lines
        strcat(summary, lines[max_index]);
        memmove(lines[max_index], lines[max_index+1], (num_lines-max_index-1)*(MAX_CHARS_PER_LINE+1));
        num_lines--;
    }
    // Print the summary
    printf("%s", summary);
    return 0;
}