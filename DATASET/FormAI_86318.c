//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
	char sentence[100];
	char* words[20] = {"meow", "purr", "hiss", "scratch", "lick", "pounce", "yowl", "nip", "chase", "play", "sleep", "eat", "drink", "sniff", "roll", "bat",
			"claw", "groom", "hunt", "snarl"};

	char* translations[20] = {"Hello human", "I am happy", "Stay away", "I need attention", "I am cleaning myself", "Let's play", "I am in pain",
			"Stop that", "Let's run", "I am bored", "I'm tired", "I am hungry", "I'm thirsty", "What's that smell?", "That feels good", "Leave me alone",
			"That's mine", "Cleaning myself", "I am hunting", "I am angry"};

	printf("Enter a sentence in cat language (separated by spaces):\n");
	fgets(sentence, 100, stdin);

	char* word = strtok(sentence, " ");
	while (word != NULL) {
		for (int i = 0; i < 20; i++) {
			if (strcmp(word, words[i]) == 0) {
				printf("%s ", translations[i]);
				break;
			}
		}
		word = strtok(NULL, " ");
	}

	return 0;
}