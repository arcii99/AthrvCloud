//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_START "@#"
#define WATERMARK_END "#@"

char* paranoid_watermark(char* data, char* watermark, char* secret_key) {
  char* modified_data = malloc(sizeof(char) * strlen(data) * 2 + 1); // Allocate enough space for the modified data
  char* start = strstr(data, WATERMARK_START);
  char* end = strstr(data, WATERMARK_END);
  
  // If the watermark is already present, remove it
  if (start && end) {
    int length_to_remove = end - start + strlen(WATERMARK_END);
    strncpy(modified_data, data, start - data);
    strcpy(modified_data + (start - data), end + strlen(WATERMARK_END));
    strcat(modified_data, "\0");
  } else {
    strcpy(modified_data, data);
  }
  
  // Add the watermark with the secret key
  char secret_watermark[strlen(watermark) + strlen(secret_key) + 1];
  sprintf(secret_watermark, "%s%s", watermark, secret_key);
  char* random_position = modified_data + rand() % (strlen(modified_data) - strlen(secret_watermark));
  char* modified_position = malloc(sizeof(char) * strlen(secret_watermark) * 2 + 1); // Allocate enough space for the modified watermark
  strcpy(modified_position, "");
  for (int i = 0; i < strlen(secret_watermark); i++) {
    char random_char = *(random_position + i);
    char secret_char = *(secret_watermark + i);
    int random_int = (int) random_char;
    int secret_int = (int) secret_char;
    int modified_int = (random_int + secret_int) % 256;
    char modified_char = (char) modified_int;
    char modified_str[2];
    sprintf(modified_str, "%c", modified_char);
    strcat(modified_position, modified_str);
  }
  
  // Replace the random string with the modified watermark
  strncpy(random_position, modified_position, strlen(secret_watermark));
  
  return modified_data;
}

int main() {
  char* original_data = "This is the original data";
  char* watermark = "@#DIGITAL_WATERMARK#@";
  char* secret_key = "p4r4n01d";
  srand(time(NULL)); // Initialize the random seed
  
  char* paranoid_data = paranoid_watermark(original_data, watermark, secret_key);
  printf("Paranoid data: %s\n", paranoid_data);
  
  char* unparanoid_data = paranoid_watermark(paranoid_data, watermark, secret_key);
  printf("Unparanoid data: %s\n", unparanoid_data);
  
  return 0;
}