//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the message 
char message[] = "Hello, world!";
// Define the watermark 
char watermark[] = "012345678901234567890123456789012345678901234567890123456789";

// Function to embed the watermark in the message
void embedWatermark(char *msg, char *wm) {
  // Set the starting position for the watermark
  int wmPos = 0;
  // For each character in the message
  for (int i = 0; i < strlen(msg); i++) {
    // If the current character is a letter
    if (msg[i] >= 'a' && msg[i] <= 'z') {
      // Convert the letter to uppercase
      msg[i] = msg[i] - 'a' + 'A';
      // Add the next character of the watermark
      msg[i] = msg[i] + wm[wmPos++] - '0';
      // If we have reached the end of the watermark
      if (wmPos >= strlen(wm)) {
        // Reset the watermark position
        wmPos = 0;
      }
    }
  }
}

// Function to extract the watermark from the message
void extractWatermark(char *msg, char *wm) {
  // Set the starting position for the watermark
  int wmPos = 0;
  // For each character in the message
  for (int i = 0; i < strlen(msg); i++) {
    // If the current character is a letter
    if (msg[i] >= 'a' && msg[i] <= 'z') {
      // Convert the letter to uppercase
      msg[i] = msg[i] - 'a' + 'A';
      // Subtract the next character of the watermark
      msg[i] = msg[i] - wm[wmPos++] + '0';
      // If we have reached the end of the watermark
      if (wmPos >= strlen(wm)) {
        // Reset the watermark position
        wmPos = 0;
      }
    }
  }
}

// Main function
int main() {
  // Define the message and watermark buffers
  char plaintext[100] = {0};
  char extractedWatermark[100] = {0};
  char *wm = watermark;
  
  // Prompt user to enter a message 
  printf("Enter a message: ");
  fgets(plaintext, sizeof plaintext, stdin);
  
  // Embed the watermark in the message 
  embedWatermark(plaintext, wm);
  
  // Print the watermarked message 
  printf("\nWatermarked message: %s", plaintext);
  
  // Extract the watermark from the message 
  extractWatermark(plaintext, extractedWatermark);
  
  // Print the extracted watermark 
  printf("\nExtracted watermark: %s\n", extractedWatermark);
  
  return 0;
}