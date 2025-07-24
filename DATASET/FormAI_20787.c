//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert RGB color code to HEX color code
char* rgbToHex(int r, int g, int b) {
	char* hex = (char*)malloc(sizeof(char) * 7);
	sprintf(hex, "#%02X%02X%02X", r, g, b);
	return hex;
}

// Function to convert HEX color code to RGB color code
void hexToRgb(char* hex, int* r, int* g, int* b) {
	sscanf(hex, "#%02X%02X%02X", r, g, b);
}

int main() {
	// Variables to store RGB values
	int r, g, b;

	// Prompt user for RGB values
	printf("Enter the RGB color code (separated by space): ");
	scanf("%d %d %d", &r, &g, &b);

	// Convert RGB to HEX and print result
	char* hex = rgbToHex(r, g, b);
	printf("The HEX color code is %s\n", hex);

	// Prompt user for HEX value
	printf("Enter the HEX color code: ");
	char input[7];
	scanf("%s", input);

	// Convert HEX to RGB and print result
	hexToRgb(input, &r, &g, &b);
	printf("The RGB color code is (%d, %d, %d)\n", r, g, b);

	// Free allocated memory
	free(hex);

	return 0;
}