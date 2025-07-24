//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

void to_lower_case(char *word);
int is_valid_character(char c);
int is_word_end(char c);

int main() {
	char input[MAX_LENGTH];
	int count = 0;

	printf("Enter a sentence: ");
	fgets(input, MAX_LENGTH, stdin);

	for (int i = 0; i < strlen(input); i++) {
		char current_char = input[i];

		if (is_valid_character(current_char)) {
			int start_index = i;
			while (!is_word_end(input[i])) {
				i++;
			}

			char word[MAX_LENGTH];
			int word_length = i - start_index;
			strncpy(word, input + start_index, word_length);
			word[word_length] = '\0';

			to_lower_case(word);

			printf("%s ", word);
			count++;
		}
	}

	printf("\nTotal words: %d\n", count);

	return 0;
}

void to_lower_case(char *word) {
	for (int i = 0; i < strlen(word); i++) {
		word[i] = tolower(word[i]);
	}
}

int is_valid_character(char c) {
	if (isalpha(c) || isspace(c)) {
		return 1;
	}

	return 0;
}

int is_word_end(char c) {
	if (isspace(c) || ispunct(c) || c == '\0') {
		return 1;
	}

	return 0;
}