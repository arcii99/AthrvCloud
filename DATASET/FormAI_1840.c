//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>

int main() {
   FILE *fp;
   char ch;
   int count = 0;

   fp = fopen("image.bmp", "rb"); // open image file in read-binary mode

   if(fp == NULL) {
      printf("Error. Unable to open the image.\n");
      return 0;
   }

   fseek(fp, 54, SEEK_SET); // set file pointer to image pixel data position

   while((ch = fgetc(fp)) != EOF) { 
      if(count % 3 == 0) { // apply ASCII mapping to pixel RGB value
         if(ch >= 230)
            printf("@");
         else if(ch >= 200)
            printf("8");
         else if(ch >= 180)
            printf("&");
         else if(ch >= 160)
            printf("$");
         else if(ch >= 130)
            printf("#");
         else if(ch >= 100)
            printf("*");
         else if(ch >= 70)
            printf("o");
         else
            printf(".");
      }
      count++;
   }

   fclose(fp); // close image file
   return 0;
}