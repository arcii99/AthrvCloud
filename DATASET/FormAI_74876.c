//FormAI DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
   // check that the arguments are valid
   if(argc != 4) 
   {
      printf("Usage: %s [input file] [output file] [key]\n", argv[0]);
      return 1;
   }

   // open the input and output files
   FILE *input = fopen(argv[1], "rb");
   FILE *output = fopen(argv[2], "wb");

   // make sure files were opened successfully
   if(input == NULL || output == NULL) 
   {
      printf("Error: failed to open file(s)\n");
      return 1;
   }

   // get the encryption key and calculate its length
   char *key = argv[3];
   int keyLength = strlen(key);

   // read and encrypt each byte in the input file
   int c;
   int i = 0;
   while((c = fgetc(input)) != EOF) 
   {
      // XOR each byte with a corresponding byte in the key
      fputc(c ^ key[i % keyLength], output);
      i++;
   }

   // close the files
   fclose(input);
   fclose(output);

   return 0;
}