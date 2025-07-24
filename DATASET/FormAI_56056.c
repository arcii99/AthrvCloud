//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

void printNextRow(int rowNum, int n) {
	// Base case
	if (rowNum == n) {
		return;
	}

	// Print spaces at the beginning of each row
	for (int i = rowNum; i < n; i++) {
		printf(" ");
	}

	// Print stars for the first half of the row
	for (int i = 0; i < rowNum; i++) {
		printf("* ");
	}

	// Print stars for the second half of the row
	for (int i = 0; i < rowNum - 1; i++) {
		printf("* ");
	}

	printf("\n");

	// Recursive call to print the next row
	printNextRow(rowNum + 1, n);
}

void printRows(int rowNum, int n) {
	// Base case
	if (rowNum == 0) {
		return;
	}

	// Print spaces at the beginning of each row
	for (int i = rowNum; i < n; i++) {
		printf(" ");
	}

	// Print stars for the first half of the row
	for (int i = 0; i < rowNum; i++) {
		printf("* ");
	}

	// Print stars for the second half of the row
	for (int i = 0; i < rowNum - 1; i++) {
		printf("* ");
	}

	printf("\n");

	// Recursive call to print the next rows
	printNextRow(rowNum + 1, n);
	printRows(rowNum - 1, n);
}

int main() {
	int n = 7;

	// Print the first half of the pattern
	printRows(n, n);

	// Print the second half of the pattern
	printNextRow(1, n);

	return 0;
}