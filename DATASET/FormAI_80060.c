//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char sentence[1000], clean_sentence[1000], vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	int sentence_length, clean_length = 0, i, j, is_vowel;
	
	printf("Enter a sentence: ");
	fgets(sentence, 1000, stdin);
	sentence_length = strlen(sentence);
	
	for (i = 0; i < sentence_length; ++i) {
		// Removes non-letter characters
		if (isalpha(sentence[i])) {
			clean_sentence[clean_length] = tolower(sentence[i]);
			clean_length++;
		}
	}
	
	printf("Cleaned sentence: %s\n", clean_sentence);
	
	// Counts frequency of each vowel
	int vowel_count[5] = {0};
	for (i = 0; i < clean_length; ++i) {
		is_vowel = 0;
		for (j = 0; j < 10; ++j) {
			if (clean_sentence[i] == vowels[j]) {
				is_vowel = 1;
				if (j < 5) // Lowercase vowels
					vowel_count[j]++;
				else // Uppercase vowels
					vowel_count[j-5]++;
			}
		}
	}
	
	// Outputs vowel frequency
	printf("\nVowel frequency:\n");
	for (i = 0; i < 5; ++i) {
		printf("%c: %d\n", vowels[i], vowel_count[i]);
	}
	for (i = 0; i < 5; ++i) {
		printf("%c: %d\n", vowels[i+5], vowel_count[i+5]);
	}
	
	return 0;
}