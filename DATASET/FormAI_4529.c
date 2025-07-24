//FormAI DATASET v1.0 Category: Data recovery tool ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

// Function prototypes
bool is_jpeg(BYTE block[BLOCK_SIZE]);
void write_jpeg(FILE* recover_file, BYTE block[BLOCK_SIZE]);

int main(int argc, char* argv[])
{
	// Ensure proper usage
	if (argc != 2)
	{
		fprintf(stderr, "Usage: ./recover image\n");
		return 1;
	}
	
	// Open file for reading
	FILE* file = fopen(argv[1], "r");
	
	if (file == NULL)
	{
		fprintf(stderr, "Could not open file.\n");
		return 2;
	}
	
	// Initialize variables
	BYTE buffer[BLOCK_SIZE];
	bool jpeg_found = false;
	int count = 0;
	FILE* recover_file = NULL;
	
	// Look for JPEGs until end of file
	while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
	{
		// Check if block is a JPEG
		if (is_jpeg(buffer))
		{
			// Close previous file if one is open
			if (jpeg_found)
			{
				fclose(recover_file);
			}
			else
			{
				jpeg_found = true;
			}
			
			// Create new file
			char filename[8];
			sprintf(filename, "%03i.jpg", count);
			recover_file = fopen(filename, "w");
			if (recover_file == NULL)
			{
				fclose(file);
				fprintf(stderr, "Could not create file.\n");
				return 3;
			}
			
			count++;
		}
		
		// If JPEG has been found, write to file
		if (jpeg_found)
		{
			write_jpeg(recover_file, buffer);
		}
	}
	
	// Close files
	fclose(recover_file);
	fclose(file);
	
	return 0;
}

/**
 * Checks if a block of memory is a JPEG by checking its first four
 * bytes.
 */
bool is_jpeg(BYTE block[BLOCK_SIZE])
{
	return block[0] == 0xff
	  && block[1] == 0xd8
	  && block[2] == 0xff
	  && (block[3] & 0xf0) == 0xe0;
}

/**
 * Writes a block of memory to a file.
 */
void write_jpeg(FILE* recover_file, BYTE block[BLOCK_SIZE])
{
	fwrite(block, BLOCK_SIZE, 1, recover_file);
}