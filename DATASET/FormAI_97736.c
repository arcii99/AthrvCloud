//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: grateful
// Thank you for choosing our digital watermarking program!
// We are grateful for your trust in our programming skills.
// Below is an example code to demonstrate our unique digital watermarking process.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void embedWatermark(char *originalText, char *watermark) {
   int j = 0;
   for(int i=0; i<strlen(originalText); i++) {
      if(originalText[i] != ' ') {
         if(j<strlen(watermark)) {
            originalText[i] = watermark[j++];
         }
      }
   }
}

void extractWatermark(char *watermarkedText, char *extractedWatermark) {
   int j = 0;
   for(int i=0; i<strlen(watermarkedText); i++) {
      if(watermarkedText[i] != ' ') {
         if(j<strlen(extractedWatermark)) {
            extractedWatermark[j++] = watermarkedText[i];
         }
      }
   }
}

int main() {
   char originalText[100], watermarkedText[100], watermark[20], extractedWatermark[20];
   printf("Enter the original text:\n");
   fgets(originalText, sizeof(originalText), stdin);
   printf("Enter the watermark to embed:\n");
   fgets(watermark, sizeof(watermark), stdin);
   strcpy(watermarkedText, originalText);
   embedWatermark(watermarkedText, watermark);
   printf("The watermarked text is: %s\n", watermarkedText);
   extractWatermark(watermarkedText, extractedWatermark);
   printf("The extracted watermark is: %s\n", extractedWatermark);
   return 0;
}

// We hope that this program meets your expectations.
// If you have any feedback or suggestions, please let us know.
// Thank you again for your trust and support.