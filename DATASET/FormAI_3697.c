//FormAI DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>

int main() {
	char string[100], encrypted[100];
	int i, key;

	printf("Enter the string to encrypt: ");
	scanf("%s", string);

	printf("Enter the key: ");
	scanf("%d", &key);

	// Encryption
	for(i = 0; i < strlen(string); i++) {
		encrypted[i] = string[i] + key;
	}

	printf("The encrypted string is: %s\n", encrypted);

	return 0;
}