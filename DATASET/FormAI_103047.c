//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n = 0, spaces = 10, asterisks = 1;

	// create an apocalyptic feel by printing red color
	system("color 0c");

	// loop for the top half of the "C" pattern
	for (i = 1; i <= 11; i++) {
		if (i == 1) {
			printf("\n");
		} else if (i == 2) {
			printf("\t   * * * * *\n");
		} else if (i <= 6) {
			printf("\t*\n");
		} else if (i == 7) {
			printf("\t* * * * * * *\n");
		} else if (i >= 8 && i <= 10) {
			printf("\t*\n");
		} else {
			printf("\t   * * * * *\n\n");
		}
	}

	printf("\t\t\t     ");

	// loop for the bottom half of the "C" pattern
	for (j = 1; j <= 17; j++) {
		if (j == 1 || j == 17) {
			printf("*");
		} else if (j <= 8) {
			printf(" ");
		} else if (j == 9) {
			printf("*\n");
		} else {
			printf(" ");
		}
	}

	printf("\n");
	system("pause");
	return 0;
}