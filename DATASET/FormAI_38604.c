//FormAI DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
	char juliet[] = "O Romeo, Romeo! wherefore art thou Romeo?";
	char romeo[] = "Here's my fumble footed attempt at a love sonnet for thee,";

	// Counting the number of characters in both strings using strlen() function
	int juliet_length = strlen(juliet);
	int romeo_length = strlen(romeo);

	printf("Juliet: %s\n", juliet);
	printf("Romeo: %s\n\n", romeo);

	// Swapping the first 5 characters of Juliet's string with Romeo's string
	for(int i = 0; i < 5; i++)
	{
		char temp = juliet[i];
		juliet[i] = romeo[i];
		romeo[i] = temp;
	}

	printf("After swapping first 5 characters:\n");
	printf("Juliet: %s\n", juliet);
	printf("Romeo: %s\n\n", romeo);

	// Reversing the last 10 characters of Romeo's string
	for(int i = romeo_length - 11, j = romeo_length - 1; i < j; i++, j--)
	{
		char temp = romeo[i];
		romeo[i] = romeo[j];
		romeo[j] = temp;
	}

	printf("After reversing last 10 characters of Romeo's string:\n");
	printf("Juliet: %s\n", juliet);
	printf("Romeo: %s\n\n", romeo);

	// Concatenating both strings in Romeo's string
	strcat(romeo, juliet);

	printf("After concatenating:\n");
	printf("%s\n", romeo);

	return 0;
}