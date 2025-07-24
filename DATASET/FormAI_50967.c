//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char message[] = "Hello, World!";
  char watermark[] = "Watermark";
  
  int message_length = strlen(message);
  int watermark_length = strlen(watermark);
  
  char encoded_message[1000];
  
  // Encoding the message with the watermark
  for(int i = 0; i < message_length; i++) {
    // Taking each character of the message
    char m = message[i];
    
    // Taking the character from watermark at i modulo watermark_length
    char w = watermark[i % watermark_length];
    
    // Combining the characters
    char c = (m + w) % 128;
    
    encoded_message[i] = c;
  }
  
  printf("Encoded message: %s\n", encoded_message);
  
  // Decoding the message to check if watermark is present
  char decoded_message[1000];
  
  for(int i = 0; i < message_length; i++) {
    // Taking each character of the encoded message
    char c = encoded_message[i];
    
    // Taking the character from watermark at i modulo watermark_length
    char w = watermark[i % watermark_length];
    
    // Subtracting the watermark character from the encoded character
    // to get back the original character
    char m = (c - w + 128) % 128;
    
    decoded_message[i] = m;
  }
  
  printf("Decoded message: %s\n", decoded_message);
  
  // Checking if watermark is present in decoded message
  int watermark_found = 0;
  
  for(int i = 0; i < message_length; i++) {
    // Taking each character of the decoded message
    char m = decoded_message[i];
    
    // Taking the character from watermark at i modulo watermark_length
    char w = watermark[i % watermark_length];
    
    // Checking if characters match
    if(m == w) {
      watermark_found = 1;
      break;
    }
  }
  
  if(watermark_found) {
    printf("Watermark found!\n");
  } else {
    printf("Watermark not found.\n");
  }
  
  return 0;
}