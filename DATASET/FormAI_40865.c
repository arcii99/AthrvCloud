//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: invasive
#include<stdio.h>
#include<string.h>

char Translate(char words[], int i);

int main() {

	char words[1000];
	printf("Enter the text you want to translate to C Cat Language: ");
	fgets(words, 1000, stdin);
	printf("\nTranslated text in C Cat Language: ");

	for (int i = 0; i < strlen(words); i++) {
		Translate(words, i);
	}

	return 0;
}

char Translate(char words[], int i) {

	if (words[i] == 'a' || words[i] == 'A') {
		printf("meow ");
	} else if (words[i] == 'b' || words[i] == 'B') {
		printf("purr ");
	} else if (words[i] == 'c' || words[i] == 'C') {
		printf("hiss ");
	} else if (words[i] == 'd' || words[i] == 'D') {
		printf("scratch ");
	} else if (words[i] == 'e' || words[i] == 'E') {
		printf("paw ");
	} else if (words[i] == 'f' || words[i] == 'F') {
		printf("tail ");
	} else if (words[i] == 'g' || words[i] == 'G') {
		printf("whisker ");
	} else if (words[i] == 'h' || words[i] == 'H') {
		printf("nap ");
	} else if (words[i] == 'i' || words[i] == 'I') {
		printf("mouse ");
	} else if (words[i] == 'j' || words[i] == 'J') {
		printf("yawn ");
	} else if (words[i] == 'k' || words[i] == 'K') {
		printf("claw ");
	} else if (words[i] == 'l' || words[i] == 'L') {
		printf("lick ");
	} else if (words[i] == 'm' || words[i] == 'M') {
		printf("stretch ");
	} else if (words[i] == 'n' || words[i] == 'N') {
		printf("sniff ");
	} else if (words[i] == 'o' || words[i] == 'O') {
		printf("pounce ");
	} else if (words[i] == 'p' || words[i] == 'P') {
		printf("hunt ");
	} else if (words[i] == 'q' || words[i] == 'Q') {
		printf("hungr ");
	} else if (words[i] == 'r' || words[i] == 'R') {
		printf("stal ");
	} else if (words[i] == 's' || words[i] == 'S') {
		printf("pe");
		printf("rr ");
	} else if (words[i] == 't' || words[i] == 'T') {
		printf("pet ");
	} else if (words[i] == 'u' || words[i] == 'U') {
		printf("scratch ");
	} else if (words[i] == 'v' || words[i] == 'V') {
		printf("groom ");
	} else if (words[i] == 'w' || words[i] == 'W') {
		printf("strol ");
	} else if (words[i] == 'x' || words[i] == 'X') {
		printf("purr ");
	} else if (words[i] == 'y' || words[i] == 'Y') {
		printf("nap ");
	} else if (words[i] == 'z' || words[i] == 'Z') {
		printf("paw ");
	} 

}