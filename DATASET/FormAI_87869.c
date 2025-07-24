//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encode(char *image_filename, char *secret_message, char *output_filename);
void decode(char *image_filename);

int main() {
  printf("Welcome to the Image Steganography Puzzle Game!\n");
  printf("To play, enter a secret message to hide in an image.\n");
  printf("Then, choose an image file to hide the message in.\n");
  printf("Finally, enter the output file name for the encoded image.\n\n");

  char secret_message[256];
  char image_filename[256];
  char output_filename[256];

  // Get user input for secret message
  printf("Enter your secret message: ");
  fgets(secret_message, 256, stdin);

  // Remove newline character from end of input
  secret_message[strcspn(secret_message, "\n")] = 0;

  // Get user input for image file name
  printf("Enter the name of the image file you want to encode the message in: ");
  fgets(image_filename, 256, stdin);

  // Remove newline character from end of input
  image_filename[strcspn(image_filename, "\n")] = 0;

  // Get user input for output file name
  printf("Enter the name of the output file: ");
  fgets(output_filename, 256, stdin);

  // Remove newline character from end of input
  output_filename[strcspn(output_filename, "\n")] = 0;

  printf("\nEncoding secret message in image...\n");

  encode(image_filename, secret_message, output_filename);

  printf("\nDone! Your message has been successfully encoded in the image.\n");
  printf("Now, it's time to solve the puzzle!\n");
  printf("Decode the secret message from the image to complete the game.\n");
  
  printf("\nPress enter to continue...");
  getchar();

  printf("\nHere is a new challenge!\n");
  printf("Decode the following image to reveal the secret message: \n\n");

  // Display encoded image
  system("open encoded_image.bmp"); // For Mac OS X
  // system("start encoded_image.bmp"); // For Windows
  
  printf("\nDecoding image...\n");

  decode("encoded_image.bmp");

  printf("\nCongratulations! You have solved the puzzle!\n");
  printf("The secret message was: %s\n", secret_message);
  
  return 0;
}

void encode(char *image_filename, char *secret_message, char *output_filename) {
  // Open original image
  FILE *image_file = fopen(image_filename, "rb");
  
  // Check if file was opened successfully
  if (image_file == NULL) {
    printf("Error: Could not open image file %s.\n", image_filename);
    exit(1);
  }

  // Open or create output file
  FILE *output_file = fopen(output_filename, "wb");
  
  // Check if file was opened successfully
  if (output_file == NULL) {
    printf("Error: Could not create output file %s.\n", output_filename);
    exit(1);
  }

  // Write header of image file to output file
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, image_file);
  fwrite(header, sizeof(unsigned char), 54, output_file);

  // Get size of message to encode
  int message_size = strlen(secret_message);

  // Convert message size to a 32-bit binary string
  char message_size_binary[32];
  for (int i = 0; i < 32; i++) {
    message_size_binary[i] = '0' + ((message_size >> (31 - i)) & 1);
  }

  // Encode message size in image file
  unsigned char byte;
  int byte_index = 0;
  for (int i = 0; i < 54; i++) {
    fread(&byte, sizeof(unsigned char), 1, image_file);
    byte = (byte & 0xFE) | ((message_size_binary[byte_index] == '1') ? 1 : 0);
    fwrite(&byte, sizeof(unsigned char), 1, output_file);
    byte_index++;
  }

  // Encode secret message in image file
  char message_binary[message_size * 8 + 1];
  memset(message_binary, 0, sizeof(message_binary));
  for (int i = 0; i < message_size; i++) {
    for (int j = 0; j < 8; j++) {
      message_binary[i * 8 + j] = '0' + ((secret_message[i] >> (7 - j)) & 1);
    }
  }

  byte_index = 0;
  while (fread(&byte, sizeof(unsigned char), 1, image_file) == 1) {
    if (byte_index < message_size * 8) {
      byte = (byte & 0xFE) | ((message_binary[byte_index] == '1') ? 1 : 0);
      byte_index++;
    }
    fwrite(&byte, sizeof(unsigned char), 1, output_file);
  }

  fclose(image_file);
  fclose(output_file);
}

void decode(char *image_filename) {
  // Open encoded image
  FILE *image_file = fopen(image_filename, "rb");

  // Check if file was opened successfully
  if (image_file == NULL) {
    printf("Error: Could not open image file %s.\n", image_filename);
    exit(1);
  }

  // Read header of image file
  unsigned char header[54];
  fread(header, sizeof(unsigned char), 54, image_file);

  // Get size of message from image file
  char message_size_binary[32];
  int byte_index = 0;
  for (int i = 0; i < 54; i++) {
    unsigned char byte;
    fread(&byte, sizeof(unsigned char), 1, image_file);
    message_size_binary[byte_index] = ((byte & 1) == 1) ? '1' : '0';
    byte_index++;
  }

  int message_size = 0;
  for (int i = 0; i < 32; i++) {
    message_size = (message_size << 1) | (message_size_binary[i] - '0');
  }

  // Decompress secret message from image file
  char *secret_message = (char *) malloc(sizeof(char) * (message_size + 1));
  memset(secret_message, 0, sizeof(secret_message));
  char message_byte_binary[9];
  byte_index = 0;
  for (int i = 0; i < message_size; i++) {
    memset(message_byte_binary, 0, sizeof(message_byte_binary));
    for (int j = 0; j < 8; j++) {
      unsigned char byte;
      fread(&byte, sizeof(unsigned char), 1, image_file);
      message_byte_binary[j] = ((byte & 1) == 1) ? '1' : '0';
      byte_index++;
    }
    secret_message[i] = 0;
    for (int j = 0; j < 8; j++) {
      secret_message[i] |= (message_byte_binary[j] - '0') << (7 - j);
    }
  }

  printf("The secret message is: %s\n", secret_message);

  fclose(image_file);
}