//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    char text[1000];
    int positiveCount = 0, negativeCount = 0;
    float score;

    printf("Enter some text for sentiment analysis:\n");
    fgets(text, sizeof(text), stdin);

    int len = strlen(text);

    for(int i = 0; i < len; i++) {
        if(text[i] == 'G' || text[i] == 'g') {
            if(text[i+1] == 'O' || text[i+1] == 'o') {
                if(text[i+2] == 'O' || text[i+2] == 'o') {
                    if(text[i+3] == 'D' || text[i+3] == 'd') {
                        positiveCount++; // If the words 'good' or 'Good' appears, increase positive count
                    }
                }
            }
            if(text[i+1] == 'R' || text[i+1] == 'r') {
                if(text[i+2] == 'E' || text[i+2] == 'e') {
                    if(text[i+3] == 'A' || text[i+3] == 'a') {
                        if(text[i+4] == 'T' || text[i+4] == 't') {
                            negativeCount++; // If the word 'great' or 'Great' appears, increase negative count
                        }
                    }
                }
            }
        }
        if(text[i] == 'B' || text[i] == 'b') {
            if(text[i+1] == 'A' || text[i+1] == 'a') {
                if(text[i+2] == 'D' || text[i+2] == 'd') {
                    negativeCount++; // If the word 'bad' or 'Bad' appears, increase negative count
                }
            }
        }
        if(text[i] == 'T' || text[i] == 't') {
            if(text[i+1] == 'E' || text[i+1] == 'e') {
                if(text[i+2] == 'R' || text[i+2] == 'r') {
                    if(text[i+3] == 'R' || text[i+3] == 'r') {
                        if(text[i+4] == 'I' || text[i+4] == 'i') {
                            if(text[i+5] == 'B' || text[i+5] == 'b') {
                                if(text[i+6] == 'L' || text[i+6] == 'l') {
                                    if(text[i+7] == 'E' || text[i+7] == 'e') {
                                        negativeCount++; // If the word 'Terrible' or 'terrible' appears, increase negative count
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    score = (float) positiveCount / (positiveCount + negativeCount); // Calculate sentiment score

    printf("\nThe sentiment score is: %.2f\n", score);

    if(score > 0.5) {
        printf("The sentiment is positive.\n");
    } else {
        printf("The sentiment is negative.\n");
    }

    return 0;
}