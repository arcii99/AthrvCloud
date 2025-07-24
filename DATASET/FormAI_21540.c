//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char* words[100];
    int num_words;
} Sentence;

Sentence analyze_sentiment(char* sentence) {
    Sentence result;
    int index = 0;
    char* curr_word = strtok(sentence, " ");
  
    while (curr_word != NULL) {
        result.words[index] = curr_word;
        index++;
        curr_word = strtok(NULL, " ");
    }
    result.num_words = index;
  
    return result;
}

int count_positive_words(Sentence sentence) {
    char* positive_words[] = {"happy", "good", "joyful", "love", "excited", "great"};
    int num_positive = 0;
  
    for (int i=0;i<sentence.num_words;i++) {
        for (int j=0;j<6;j++) {
            if (strcmp(sentence.words[i], positive_words[j]) == 0) {
                num_positive++;
            }
        }
    }
  
    return num_positive;
}

int count_negative_words(Sentence sentence) {
    char* negative_words[] = {"hate", "angry", "sad", "terrible", "bad", "upset"};
    int num_negative = 0;
  
    for (int i=0;i<sentence.num_words;i++) {
        for (int j=0;j<6;j++) {
            if (strcmp(sentence.words[i], negative_words[j]) == 0) {
                num_negative++;
            }
        }
    }
  
    return num_negative;
}

int get_sentiment_score(Sentence sentence) {
    int positive = count_positive_words(sentence);
    int negative = count_negative_words(sentence);
    int score = (positive - negative) * 100 / (positive + negative + 1);
    return score;
}

bool is_positive(Sentence sentence) {
    return get_sentiment_score(sentence) > 0;
}

bool is_negative(Sentence sentence) {
    return get_sentiment_score(sentence) < 0;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to analyze sentiment: ");
    fgets(sentence, 1000, stdin);

    Sentence analyzed_sentence = analyze_sentiment(sentence);
    int sentiment_score = get_sentiment_score(analyzed_sentence);

    if (is_positive(analyzed_sentence)) {
        printf("The sentiment of the sentence is positive!\n");
    } else if (is_negative(analyzed_sentence)) {
        printf("The sentiment of the sentence is negative!\n");
    } else {
        printf("The sentiment of the sentence is neutral.\n");
    }

    printf("Sentiment score: %d\n", sentiment_score);

    return 0;
}