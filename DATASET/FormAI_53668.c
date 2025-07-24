//FormAI DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf(RED "Usage: ./recover image\n" RESET);
    return 1;
  }

  char *infile = argv[1];

  FILE *inptr = fopen(infile, "r");

  if (inptr == NULL)
  {
    printf(RED "Unable to open file.\n" RESET);
    return 1;
  }

  unsigned char buffer[BLOCK_SIZE];

  int jpeg_count = 0;

  FILE *outptr = NULL;

  while (fread(buffer, BLOCK_SIZE, 1, inptr))
  {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
      char filename[8];

      sprintf(filename, "%03i.jpg", jpeg_count);

      if (outptr != NULL)
      {
        fclose(outptr);
      }

      outptr = fopen(filename, "w");

      if (outptr == NULL)
      {
        printf(RED "Unable to create file.\n" RESET);
        fclose(inptr);
        return 2;
      }

      jpeg_count++;
    }

    if (outptr != NULL)
    {
      fwrite(buffer, BLOCK_SIZE, 1, outptr);
    }
  }

  if (outptr != NULL)
  {
    fclose(outptr);
  }

  fclose(inptr);

  printf(GREEN "Done! %i files recovered.\n" RESET, jpeg_count);

  return 0;
}