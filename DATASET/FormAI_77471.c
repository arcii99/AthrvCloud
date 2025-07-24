//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to perform sentiment analysis
int sentimentAnalysis(char *sentence) {

	// Define positive and negative word lists
	char positiveWords[5][10] = {"happy", "excited", "joyful", "love", "great"};
	char negativeWords[5][10] = {"sad", "angry", "frustrated", "hate", "terrible"};

	int positiveCount = 0, negativeCount = 0;
	char *word = strtok(sentence, " ");

	while (word != NULL) {
		for (int i = 0; i < 5; i++) {
			if (strcmp(word, positiveWords[i]) == 0) {
				positiveCount++;
			}
			if (strcmp(word, negativeWords[i]) == 0) {
				negativeCount++;
			}
		}
		word = strtok(NULL, " ");
	}

	if (positiveCount > negativeCount) {
		// Positive sentiment
		return 1;
	} else if (negativeCount > positiveCount) {
		// Negative sentiment
		return -1;
	} else {
		// Neutral sentiment
		return 0;
	}
}

int main() {

	// Test cases
	char sentence1[] = "I love spending time with my family and friends.";
	char sentence2[] = "I hate doing homework.";
	char sentence3[] = "Today was a great day.";
	char sentence4[] = "I am so frustrated with this project.";

	// Perform sentiment analysis on each sentence
	int result1 = sentimentAnalysis(sentence1);
	int result2 = sentimentAnalysis(sentence2);
	int result3 = sentimentAnalysis(sentence3);
	int result4 = sentimentAnalysis(sentence4);

	// Print out results
	printf("Result for sentence 1: %d\n", result1);
	printf("Result for sentence 2: %d\n", result2);
	printf("Result for sentence 3: %d\n", result3);
	printf("Result for sentence 4: %d\n", result4);

	return 0;
}