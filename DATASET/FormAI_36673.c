//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "sample.jpg"
#define WATERMARK_SIZE 64

void generate_random_key(char key[])
{
    int i;
    for (i = 0; i < WATERMARK_SIZE; i++)
    {
        key[i] = rand() % 256;
    }
}

void embed_watermark(char watermark[], char *filename)
{
    FILE *f;
    f = fopen(filename, "rb+");
    if (f == NULL)
    {
        printf("Could not open file!\n");
        return;
    }

    // move to end of file
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);

    // move back to beginning of file
    fseek(f, 0, SEEK_SET);

    // generate random key
    char key[WATERMARK_SIZE];
    generate_random_key(key);

    // write key to file
    fwrite(key, sizeof(char), WATERMARK_SIZE, f);

    // embed watermark
    int i;
    char c;
    for (i = 0; i < WATERMARK_SIZE; i++)
    {
        c = watermark[i] ^ key[i];
        fseek(f, file_size - WATERMARK_SIZE + i, SEEK_SET);
        fwrite(&c, sizeof(char), 1, f);
    }

    printf("Watermark embedded successfully!\n");

    fclose(f);
}

void extract_watermark(char *filename, char watermark[])
{
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL)
    {
        printf("Could not open file!\n");
        return;
    }

    // move to end of file
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);

    // move back to beginning of file
    fseek(f, 0, SEEK_SET);

    // read key from file
    char key[WATERMARK_SIZE];
    fread(key, sizeof(char), WATERMARK_SIZE, f);

    // extract watermark
    int i;
    char c;
    for (i = 0; i < WATERMARK_SIZE; i++)
    {
        fseek(f, file_size - WATERMARK_SIZE + i, SEEK_SET);
        fread(&c, sizeof(char), 1, f);
        watermark[i] = c ^ key[i];
    }

    printf("Watermark extracted successfully!\n");

    fclose(f);
}

int main()
{
    char watermark[WATERMARK_SIZE] = "This is a sample watermark.";

    // seed random number generator
    srand(time(NULL));

    // embed watermark in file
    embed_watermark(watermark, FILENAME);

    // extract watermark from file
    char extracted_watermark[WATERMARK_SIZE];
    extract_watermark(FILENAME, extracted_watermark);

    printf("Extracted watermark: %s\n", extracted_watermark);

    return 0;
}