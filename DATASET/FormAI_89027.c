//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
#include <string.h>

void main() {
	char sentence[1000]; //the input sentence
	int i, len, pos = 0, pos1 = 0, pos2 = 0;
	int pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0;
	float positiveCount = 0.0, negativeCount = 0.0, neutralCount = 0.0;
	
	printf("Please enter your sentence: ");
	fgets(sentence, sizeof(sentence), stdin); //get input from user

	len = strlen(sentence);

	// Loop through every word of the sentence
	for (i = 0; i < len; i++) {
		if (sentence[i] == ' ') { //if we find a space, it means we have reached the end of the current word
			if (i - pos > 1) { //if the length of the word is greater than 1 (excluding cases like "a" and "I")
				char word[50];
				strncpy(word, &sentence[pos], i - pos - 1); //extract the current word
				word[i - pos - 1] = '\0'; //add a null terminator at the end of the word

				if (strcmp(word, "good") == 0 || strcmp(word, "nice") == 0 || strcmp(word, "excellent") == 0) { //check if the word is positive
					positiveCount++;
				}
				else if (strcmp(word, "bad") == 0 || strcmp(word, "horrible") == 0 || strcmp(word, "terrible") == 0) { //check if the word is negative
					negativeCount++;
				}
				else { //if the word is neither positive nor negative, it is considered neutral
					neutralCount++;
				}
			}

			pos = i; //update the position of the starting index of the next word
		}

		if (i == len - 1) { //if we have reached the end of the sentence
			if (i - pos > 1) { //same as above
				char word[50];
				strncpy(word, &sentence[pos], i - pos);
				word[i - pos] = '\0';

				if (strcmp(word, "good") == 0 || strcmp(word, "nice") == 0 || strcmp(word, "excellent") == 0) {
					positiveCount++;
				}
				else if (strcmp(word, "bad") == 0 || strcmp(word, "horrible") == 0 || strcmp(word, "terrible") == 0) {
					negativeCount++;
				}
				else {
					neutralCount++;
				}
			}
		}
	}

	//calculate the percentage of positive, negative, and neutral words
	float totalWords = positiveCount + negativeCount + neutralCount;
	float positivePercent = (positiveCount / totalWords) * 100;
	float negativePercent = (negativeCount / totalWords) * 100;
	float neutralPercent = (neutralCount / totalWords) * 100;

	//print the results
	printf("\nPositive Words: %.0f%%\n", positivePercent);
	printf("Negative Words: %.0f%%\n", negativePercent);
	printf("Neutral Words: %.0f%%\n", neutralPercent);

	if (positivePercent > negativePercent && positivePercent > neutralPercent) {
		printf("\nOverall Sentiment: Positive\n");
	}
	else if (negativePercent > positivePercent && negativePercent > neutralPercent) {
		printf("\nOverall Sentiment: Negative\n");
	}
	else {
		printf("\nOverall Sentiment: Neutral\n");
	}
}