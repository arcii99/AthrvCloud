//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int n, int binary[8]) {
   // Storing remainder in binary array
   int i, j = 7;
   for (i = 0; i < 8; i++) {
      binary[i] = 0;
   }
   while (n > 0) {
      binary[j--] = n % 2;
      n /= 2;
   }
}

// Function to convert binary to decimal
int binaryToDecimal(int binary[8]) {
   int i, decimal = 0;
   for (i = 0; i < 8; i++) {
      decimal += binary[i] * pow(2, 7 - i);
   }
   return decimal;
}

// Function to embed watermark into image
void embedWatermark(char filePath[], char watermark[], char outputFilePath[]) {
   FILE *fileptr = fopen(filePath, "rb");
   if (fileptr == NULL) {
      printf("Failed to read file!\n");
      exit(EXIT_FAILURE);
   }

   FILE *newFileptr = fopen(outputFilePath, "wb");
   if (newFileptr == NULL) {
      printf("Failed to write file!\n");
      exit(EXIT_FAILURE);
   }

   char ch;
   int count = 0, binary[8];
   while ((ch = getc(fileptr)) != EOF) {
      decimalToBinary(ch, binary);
      if (count < strlen(watermark)) {
         decimalToBinary(watermark[count], binary);
      }
      fputc(binaryToDecimal(binary), newFileptr);
      count++;
   }

   fclose(fileptr);
   fclose(newFileptr);

   printf("Watermark embedding completed successfully!\n");
}

// Function to extract watermark from image
void extractWatermark(char filePath[], int watermarkSize) {
   FILE *fileptr = fopen(filePath, "rb");
   if (fileptr == NULL) {
      printf("Failed to read file!\n");
      exit(EXIT_FAILURE);
   }

   char *watermark = (char*)malloc(watermarkSize * sizeof(char));
   int count = 0, binary[8];
   while (!feof(fileptr)) {
      char ch = getc(fileptr);
      decimalToBinary(ch, binary);
      watermark[count] = binaryToDecimal(binary);
      count++;
      if (count >= watermarkSize) {
         break;
      }
   }

   fclose(fileptr);

   printf("Extracted watermark: %s\n", watermark);
}

int main() {
   char filePath[] = "image.bmp";
   char watermark[] = "This is a sample watermark message.";
   char outputFilePath[] = "watermarked_image.bmp";
   int watermarkSize = strlen(watermark);

   embedWatermark(filePath, watermark, outputFilePath);
   extractWatermark(outputFilePath, watermarkSize);

   return 0;
}