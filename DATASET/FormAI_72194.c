//FormAI DATASET v1.0 Category: modern Encryption ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {

	printf("Welcome to the exciting world of modern encryption!\n");

	char message[50];
	
	printf("Please enter a message to encrypt:\n");

	fgets(message, 50, stdin);

	int key = 15;
	
	// Encryption process
	for (int i = 0; i < strlen(message); i++) {
		if (message[i] >= 'a' && message[i] <= 'z') {
			message[i] = (char)(((int)message[i] - 97 + key) % 26 + 97);
		}
		else if (message[i] >= 'A' && message[i] <= 'Z') {
			message[i] = (char)(((int)message[i] - 65 + key) % 26 + 65);
		}
	}

	printf("Your encrypted message is:\n%s", message);

	// Decryption process
	for (int i = 0; i < strlen(message); i++) {
		if (message[i] >= 'a' && message[i] <= 'z') {
			message[i] = (char)(((int)message[i] - 97 - key + 26) % 26 + 97);
		}
		else if (message[i] >= 'A' && message[i] <= 'Z') {
			message[i] = (char)(((int)message[i] - 65 - key + 26) % 26 + 65);
		}
	}

	printf("\nYour decrypted message is:\n%s", message);

	return 0;
}