//FormAI DATASET v1.0 Category: Image Steganography ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Function to convert an integer to binary*/
char* int_to_binary(int num)
{
   int bits = sizeof(int) * 8; /*Number of bits in int*/
   char* binary = malloc(bits + 1); /*Allocate memory for binary string*/
   binary[bits] = '\0'; /*Null terminate string*/

   int i;
   for (i = bits - 1; i >= 0; i--)
   {
      binary[i] = (num & 1) + '0'; /*Set the bit to 0 or 1*/
      num >>= 1; /*Shift right by 1 position*/
   }

   return binary;
}

/*Function to convert a binary string to integer*/
int binary_to_int(char* binary)
{
   int decimal = 0, base = 1;
   int len = strlen(binary);
   int i;
   for (i = len - 1; i >= 0; i--)
   {
      if (binary[i] == '1')
         decimal += base;
      base *= 2;
   }

   return decimal;
}

/*Function to read a BMP image file and return the pixel array*/
unsigned char* read_bmp(char* filename, int* width, int* height)
{
   unsigned char header[54];
   FILE* file = fopen(filename, "rb"); /*Open the file in binary read mode*/

   /*Check if file could be opened*/
   if (file == NULL) 
   {
       printf("Error: Could not open file %s", filename);
       return NULL;
   }

   /*Read the header of BMP file*/
   if (fread(header, 1, 54, file) != 54) 
   { 
       printf("Error: Invalid BMP file %s", filename);
       fclose(file);
       return NULL;
   }

   /*Check if BMP file format is correct*/
   if (header[0] != 'B' || header[1] != 'M') 
   {
       printf("Error: Invalid BMP file format %s", filename);
       fclose(file);
       return NULL;
   }

   /*Extract image dimensions and pixel array*/
   *width = *(int*)&header[18];
   *height = *(int*)&header[22];
   int bit_count = *(short*)&header[28]; /*Number of bits per pixel*/
   if (bit_count != 24) 
   {
       printf("Error: Invalid BMP file format %s", filename);
       fclose(file);
       return NULL;
   }

   int padding = 0;
   while ((*width * 3 + padding) % 4 != 0)
       padding++; /*Calculate row padding in bytes*/

   int row_size = *width * 3 + padding;
   int data_size = row_size * *height;
   
   unsigned char* data = (unsigned char*)malloc(data_size); /*Allocate memory for pixel array*/
   if (data == NULL) 
   {
      printf("Error: Out of memory");
      fclose(file);
      return NULL;
   }

   if (fread(data, 1, data_size, file) != data_size) 
   {
      printf("Error: Invalid BMP file %s", filename);
      fclose(file);
      free(data);
      return NULL;
   }

   fclose(file);
   return data;
}

/*Function to write a BMP image file from a pixel array*/
int write_bmp(char* filename, unsigned char* data, int width, int height)
{
   unsigned char header[54] = {0}; /*Initialise header with zeros*/
   
   header[0] = 'B'; header[1] = 'M'; /*BMP file format*/
   *(int*)&header[2] = 54 + width * height * 3; /*Size of file*/
   *(int*)&header[10] = 54; /*Pixel data location*/
   *(int*)&header[14] = 40; /*Size of BITMAPINFOHEADER*/
   *(int*)&header[18] = width; /*Image width*/
   *(int*)&header[22] = height; /*Image height*/
   *(short*)&header[26] = 1; /*Number of color planes*/
   *(short*)&header[28] = 24; /*Number of bits per pixel*/

   int padding = 0;
   while ((width * 3 + padding) % 4 != 0)
       padding++; /*Calculate row padding in bytes*/

   int row_size = width * 3 + padding;
   int data_size = row_size * height;

   unsigned char* file_data = (unsigned char*)malloc(54 + data_size); /*Allocate memory for file data*/
   if (file_data == NULL)
   {
      printf("Error: Out of memory");
      return 0;
   }

   memcpy(file_data, header, 54); /*Copy header to file data*/
   int i;
   for (i = 0; i < height; i++)
   {
      memcpy(file_data + 54 + i * row_size, data + i * width * 3, width * 3); /*Copy row to file data*/
      int j;
      for (j = 0; j < padding; j++)
         file_data[54 + i * row_size + width * 3 + j] = 0; /*Fill padding with zeros*/
   }

   FILE* file = fopen(filename, "wb"); /*Open the file in binary write mode*/
   fwrite(file_data, 1, 54 + data_size, file); /*Write file data to file*/
   fclose(file);
   free(file_data);

   return 1;
}

/*Function to hide a message in the least significant bit of pixel values*/
int hide_message(unsigned char* data, int width, int height, char* message)
{
   int message_length = strlen(message);
   if (message_length > (width * height * 3) / 8) /*Check if message fits in image*/
   {
      printf("Error: Message too long to hide in image");
      return 0;
   }

   char* binary_message = (char*)malloc(message_length * 8 + 1); /*Allocate memory for binary message*/
   if (binary_message == NULL)
   {
      printf("Error: Out of memory");
      return 0;
   }

   int i, j, k = 0;
   for (i = 0; i < message_length; i++)
   {
      char* binary = int_to_binary((int)message[i]); /*Convert each character to binary*/
      for (j = 0; j < 8; j++)
         binary_message[k++] = binary[j]; /*Append binary characters to message*/
      free(binary);
   }

   binary_message[k] = '\0'; /*Null terminate message*/

   k = 0;
   for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
      {
         int index = i * width * 3 + j * 3; /*Calculate index of pixel*/
         int pixel_value = data[index]; /*Get the value of the least significant bit of the pixel*/
         char* binary = int_to_binary(pixel_value);
         binary[7] = binary_message[k++];
         data[index] = (unsigned char)binary_to_int(binary); /*Set the value of the least significant bit of the pixel*/
         free(binary);
         if (k == strlen(binary_message)) /*If entire message has been hidden, stop*/
            break;
      }
      if (k == strlen(binary_message)) /*If entire message has been hidden, stop*/
         break;
   }

   free(binary_message);
   return 1;
}

/*Function to retrieve a message hidden in the least significant bit of pixel values*/
char* retrieve_message(unsigned char* data, int width, int height)
{
   char* binary_message = (char*)malloc(width * height * 3 + 1); /*Allocate memory for binary message*/
   if (binary_message == NULL)
   {
      printf("Error: Out of memory");
      return NULL;
   }

   int i, j, k = 0;
   for (i = 0; i < height; i++)
   {
      for (j = 0; j < width; j++)
      {
         int index = i * width * 3 + j * 3; /*Calculate index of pixel*/
         int pixel_value = data[index]; /*Get the value of the least significant bit of the pixel*/
         char* binary = int_to_binary(pixel_value);
         binary_message[k++] = binary[7]; /*Append the least significant bit of the pixel to the message*/
         free(binary);
      }
   }

   binary_message[k] = '\0'; /*Null terminate message*/

   char* message = (char*)malloc(k / 8 + 1); /*Allocate memory for retrieved message*/
   if (message == NULL)
   {
      printf("Error: Out of memory");
      free(binary_message);
      return NULL;
   }

   k = 0;
   for (i = 0; i < strlen(binary_message); i += 8)
   {
      char binary[9]; /*Extract 8 bits at a time*/
      strncpy(binary, binary_message + i, 8);
      binary[8] = '\0';
      message[k++] = (char)binary_to_int(binary); /*Convert 8 bits to a character*/
   }

   message[k] = '\0'; /*Null terminate message*/

   free(binary_message);
   return message;
}

int main()
{
   int width, height;
   char* message = "Hello World!"; /*Message to be hidden*/
   char* filename = "lena.bmp"; /*Input BMP image file*/
   char* output_filename = "steganography.bmp"; /*Output BMP image file*/

   /*Read BMP image file*/
   unsigned char* data = read_bmp(filename, &width, &height);
   if (data == NULL)
      return 1;

   /*Hide message in image*/
   if (!hide_message(data, width, height, message))
   {
      free(data);
      return 1;
   }

   /*Write steganography BMP image file with hidden message*/
   if (!write_bmp(output_filename, data, width, height))
   {
      free(data);
      return 1;
   }

   /*Free memory*/
   free(data);

   /*Read steganography BMP image file with hidden message*/
   data = read_bmp(output_filename, &width, &height);
   if (data == NULL)
      return 1;

   /*Retrieve message from image*/
   char* retrieved_message = retrieve_message(data, width, height);
   if (retrieved_message == NULL)
   {
      free(data);
      return 1;
   }

   printf("Original message: %s\n", message);
   printf("Message retrieved from steganography image: %s\n", retrieved_message);

   /*Free memory*/
   free(data);
   free(retrieved_message);

   return 0;
}