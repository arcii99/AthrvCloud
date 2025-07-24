//FormAI DATASET v1.0 Category: QR code generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char** argv) {
   // user input string
   char input_string[1024];
   printf("Enter input string to generate QR code: ");
   scanf("%s", input_string);

   // create QR code
   QRcode* qr = QRcode_encodeString(input_string, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);

   // print QR code
   int size = qr->width;
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         if (qr->data[i * size + j] & 1) {
            printf("  ");
         } else {
            printf("\u2588\u2588");
         }
      }
      printf("\n");
   }

   // cleanup
   QRcode_free(qr);
   return 0;
}