//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_MAX_SIZE 64   // Maximum size of the watermark

/*
* Function Name: embed_watermark
* Input Params:
* 1. char* orig_data - Original data
* 2. char* watermark - Watermark to be embedded in the data
* Output: char* - Data with watermark embedded
* Description: The function takes in original data and a watermark and embeds the watermark in the least
* significant bits of each byte of the data. It then returns the data with the watermark embedded.
*/
char* embed_watermark(char* orig_data, char* watermark) {
    int orig_len = strlen(orig_data);              // Length of original data
    int watermark_len = strlen(watermark);          // Length of watermark
    char* watermarked_data = malloc(orig_len + 1);  // Allocating memory for watermarked data

    if (!watermarked_data) {                        // Error handling for memory allocation
        printf("ERROR: Unable to allocate memory\n");
        return NULL;
    }

    memcpy(watermarked_data, orig_data, orig_len + 1);  // Copying original data to watermarked data
    int watermark_ptr = 0;                             // Pointer to current character in the watermark

    for (int i = 0; i < orig_len; i++) {
        if (watermark_ptr == watermark_len) {    // Check if all characters of the watermark have been embedded
            break;
        }

        unsigned char curr_byte = watermarked_data[i];   // Current byte of data
        unsigned char watermark_byte = watermark[watermark_ptr];  // Current byte of watermark

        for (int j = 0; j < 8; j++) {   // Embedding the watermark in 8 bits of the byte
            if (watermark_ptr == watermark_len) {
                break;
            }

            unsigned char watermark_bit = (watermark_byte >> (7 - j)) & 1;  // Current bit of watermark
            curr_byte = (curr_byte & ~1) | watermark_bit;  // Embedding the bit in the LSB of the byte
            watermark_ptr++;
        }

        watermarked_data[i] = curr_byte;  // Setting the modified byte in the watermarked data
    }

    return watermarked_data;
}

/*
* Function Name: extract_watermark
* Input Params:
* 1. char* watermarked_data - Data with watermark embedded
* Output: char* - Extracted watermark
* Description: The function takes in watermarked data and extracts the watermark by retrieving the least
* significant bits of each byte in the data. It then returns the extracted watermark.
*/
char* extract_watermark(char* watermarked_data) {
    int watermarked_len = strlen(watermarked_data);  // Length of watermarked data
    char* extracted_watermark = malloc(WATERMARK_MAX_SIZE + 1);  // Allocating memory for extracted watermark

    if (!extracted_watermark) {   // Error handling for memory allocation
        printf("ERROR: Unable to allocate memory\n");
        return NULL;
    }

    int watermark_ptr = 0;     // Pointer to current character in the extracted watermark
    int watermark_len = 0;     // Length of extracted watermark

    for (int i = 0; i < watermarked_len; i++) {
        if (watermark_ptr == WATERMARK_MAX_SIZE) {   // Check if maximum size of watermark has been reached
            break;
        }

        unsigned char curr_byte = watermarked_data[i];   // Current byte of watermarked data
        unsigned char watermark_byte = 0;                // Byte to store extracted bits

        for (int j = 0; j < 8; j++) {   // Extracting 8 bits of watermark from the byte
            unsigned char watermark_bit = curr_byte & 1;    // Current bit of watermark
            watermark_byte = (watermark_byte << 1) | watermark_bit; //Storing the bit in the byte
            curr_byte = curr_byte >> 1;   // Moving to next bit

            if (watermark_len == 0 && watermark_bit == 0) {   // Starting delimiter for watermark
                continue;
            }

            if (watermark_len > 0 && watermark_bit == 1) {    // Ending delimiter for watermark
                extracted_watermark[watermark_ptr++] = '\0';
                return extracted_watermark;
            }

            if (watermark_ptr == WATERMARK_MAX_SIZE) {        // Check if maximum size of watermark has been reached
                break;
            }

            extracted_watermark[watermark_ptr++] = watermark_bit + '0';  // Adding bit to extracted watermark
            watermark_len++;    //Updating the length of extracted watermark
        }
    }

    extracted_watermark[watermark_ptr] = '\0';    // Adding delimiter at end of watermark
    return extracted_watermark;
}

int main() {
    char orig_data[] = "Hello, world!";   // Original data
    char watermark[] = "SecretCode123";   // Watermark to be embedded

    printf("Original data: %s\n", orig_data);
    printf("Watermark to be embedded: %s\n", watermark);

    char* watermarked_data = embed_watermark(orig_data, watermark);  // Embedding watermark in data

    if (!watermarked_data) {   // Error handling for failed watermark embedding
        printf("ERROR: Watermark embedding failed\n");
        return 1;
    }

    printf("Watermark embedded data: %s\n", watermarked_data);

    char* extracted_watermark = extract_watermark(watermarked_data);  // Extracting watermark from data

    if (!extracted_watermark) {  // Error handling for failed watermark extraction
        printf("ERROR: Watermark extraction failed\n");
        return 1;
    }

    printf("Extracted watermark: %s\n", extracted_watermark);

    free(watermarked_data);   // Freeing allocated memory
    free(extracted_watermark);

    return 0;   //Returning success
}