//FormAI DATASET v1.0 Category: QR code reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_SIZE 1000

int main() {
   char qrCode[MAX_QR_SIZE]; // declare a char array to hold the QR code
   printf("Please enter a QR code to read: ");
   scanf("%s", qrCode); // user inputs the QR code
   
   // validate the QR code
   if (strlen(qrCode)%2 != 0 && strlen(qrCode) > MAX_QR_SIZE) {
      printf("Invalid QR code\n"); // if the QR code length is odd or greater than MAX_QR_SIZE, it's invalid
      return 0;
   }
   
   // assume the QR code is valid, now decode it
   int i = 0;
   char hex[3] = ""; // because each hex number is two digits long (e.g. 0A), we need three characters (two digits plus null terminator) for each hex number
   unsigned char decodedQR[MAX_QR_SIZE]; // declare an unsigned char array to hold the decoded QR code
   while(i < strlen(qrCode)) {
      strncpy(hex, qrCode+i, 2); // extract two characters from the QR code at a time (i.e. a hex number)
      int decimal = strtol(hex, NULL, 16); // convert the hex number to decimal
      decodedQR[i/2] = decimal; // assign the decimal value to the corresponding byte in the decodedQR array
      i += 2; // advance the index by two to move to the next hex number in the QR code
   }
   
   // print the decoded QR code
   printf("Decoded QR code:\n");
   for (int j = 0; j < strlen(decodedQR); j++) {
      printf("%c", decodedQR[j]);
   }
   printf("\n");
   
   return 0;
}