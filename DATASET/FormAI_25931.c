//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char input[1000];
	printf("Enter a sentence for sentiment analysis: ");
	fgets(input, sizeof(input), stdin);

	int sentiment = 0;
	char* token = strtok(input, " .\n");

	while (token != NULL) {
		if (strlen(token) % 2 == 0) {
			sentiment++;
		} else {
			sentiment--;
		}
		token = strtok(NULL, " .\n");
	}

	if (sentiment > 0) {
		printf("Your sentence is quite positive!\n");
	} else if (sentiment < 0) {
		printf("Your sentence is quite negative :(\n");
	} else {
		printf("Your sentence is rather neutral.\n");
	}

	return 0;
}