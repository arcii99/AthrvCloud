//FormAI DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

int main() {
	printf("Welcome to the Text-Processing Program!\n\n");
	printf("Please enter a sentence:\n");

	char sentence[1000];
	fgets(sentence, 1000, stdin);

	// Remove trailing newline character
	sentence[strcspn(sentence, "\n")] = 0;

	// Count the number of words in the sentence
	int word_count = 0;
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] == ' ' || sentence[i] == '\t') {
			word_count++;
		}
	}
	word_count++; // Add one for the last word

	printf("\nProcessing your sentence...\n\n");

	// Reverse the order of the words in the sentence
	char* words[1000];
	char* word = strtok(sentence, " ");
	while (word != NULL) {
		words[word_count - 1] = word;
		word_count--;
		word = strtok(NULL, " ");
	}

	// Print the reversed sentence
	printf("Your sentence in reverse order:\n");
	for (int i = 0; i < sizeof(words)/sizeof(words[0]); i++) {
		if (words[i] != NULL) {
			printf("%s ", words[i]);
		}
	}
	printf("\n");

	// Count the number of vowels in the sentence
	int vowel_count = 0;
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u' || sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U') {
			vowel_count++;
		}
	}

	// Print the vowel count
	printf("\nYour sentence has %d vowels.\n", vowel_count);

	return 0;
}