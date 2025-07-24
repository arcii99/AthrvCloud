//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert integer to binary string
char* intToBin(int num, int bit) 
{
    char *binary = (char *) malloc(bit+1);
    binary[bit] = '\0';

    int i;
    for (i = bit-1; i >= 0; i--) {
        binary[i] = (num & (1 << i)) ? '1' : '0';
    }

    return binary;
}

//Function to convert binary string to integer
int binToInt(char *binary) 
{
  int decimal = 0, i = 0;
  while (*binary != '\0') {
      if (*binary != '0' && *binary != '1') {
          return -1;
      }
      decimal = (decimal << 1) + (*binary - '0');
      binary++;
      i++;
  }
  return decimal;
}

//Function to perform digital watermark embedding
void embedDigitalWatermark(char *source, char *watermark) 
{
    int sourceLength = strlen(source);
    int watermarkLength = strlen(watermark);

    int i, j = 0;    
    for (i = 0; i < sourceLength; i++) {
        if (j < watermarkLength) {
            char *binarySrcChar = intToBin((int)source[i], 8);
            char *binaryWmChar = intToBin((int)watermark[j], 8);
            binarySrcChar[7] = binaryWmChar[0];
            source[i] = (char)binToInt(binarySrcChar);
            j++;
        }
        if (j == watermarkLength) {
            break;
        }
    }
}

//Function to extract digital watermark from the source
char* extractDigitalWatermark(char *source, int watermarkLength) 
{
    int sourceLength = strlen(source);
    char *watermark = (char *) malloc(watermarkLength+1);
    watermark[watermarkLength] = '\0';

    int i, j = 0;    
    for (i = 0; i < sourceLength; i++) {
        if (j < watermarkLength) {
            char *binarySrcChar = intToBin((int)source[i], 8);
            watermark[j] = binarySrcChar[7];
            j++;
        }
        if (j == watermarkLength) {
            break;
        }
    }
    return watermark;
}

int main() {
    char source[] = "This is a text message";
    char watermark[] = "Secret message";

    printf("Original Message: %s\n", source);

    embedDigitalWatermark(source, watermark);

    printf("Watermarked Message: %s\n", source);

    char *extractedWatermark = extractDigitalWatermark(source, strlen(watermark));
    printf("Extracted Watermark: %s\n", extractedWatermark);

    return 0;
}