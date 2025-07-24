//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sentiment Analysis Tool
void sentiment_analysis(char *review) {
    int sentiment = 0; // sentiment score
    int i, len = strlen(review);

    // checking for positive words
    char positive_words[8][10] = {"awesome", "great", "good", "fantastic", "amazing", "excellent", "perfect", "superb"};

    for (i = 0; i < 8; i++) {
        char *pos = strstr(review, positive_words[i]);
        if (pos != NULL) {
            sentiment++;
        }
    }

    // checking for negative words
    char negative_words[5][10] = {"bad", "terrible", "awful", "horrible", "poor"};

    for (i = 0; i < 5; i++) {
        char *neg = strstr(review, negative_words[i]);
        if (neg != NULL) {
            sentiment--;
        }
    }

    // output the sentiment score
    if (sentiment > 0) {
        printf("Positive review\n");
    } else if (sentiment < 0) {
        printf("Negative review\n");
    } else {
        printf("Neutral review\n");
    }
}

int main() {
    // sample reviews
    char review1[100] = "This restaurant has great food and fantastic service!";
    char review2[100] = "The hotel was terrible. I had a horrible experience!";
    char review3[100] = "The movie was good, not great, but good.";

    // applying sentiment analysis on each review
    sentiment_analysis(review1);
    sentiment_analysis(review2);
    sentiment_analysis(review3);

    return 0;
}