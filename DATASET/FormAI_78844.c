//FormAI DATASET v1.0 Category: Text processing ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main()
{
	char current_word[MAX_LINE_SIZE];
	char longest_word[MAX_LINE_SIZE];
	int current_word_length = 0, longest_word_length = 0;
	char line[MAX_LINE_SIZE];

	printf("Input some text. Press Ctrl+D to exit.\n");

	while (fgets(line, MAX_LINE_SIZE, stdin))
	{
		char *word = strtok(line, " ");

		while (word != NULL)
		{
			current_word_length = strlen(word);

			if (current_word_length > longest_word_length)
			{
				strcpy(longest_word, word);
				longest_word_length = current_word_length;
			}

			word = strtok(NULL, " ");
		}
	}

	printf("The longest word in the text is: %s\n", longest_word);

	return 0;
}