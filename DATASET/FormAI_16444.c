//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

void extract_metadata(char* filename);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: metadataextractor filename\n");
        return 1;
    }

    char* filename = argv[1];
    extract_metadata(filename);

    return 0;
}

void extract_metadata(char* filename)
{
    char line[MAX_LINE_LENGTH];
    char title[MAX_LINE_LENGTH];
    char artist[MAX_LINE_LENGTH];
    char album[MAX_LINE_LENGTH];
    int year = 0;
    int track = 0;

    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    while(fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        if(strncmp(line, "Title:", 6) == 0)
        {
            strncpy(title, line + 7, MAX_LINE_LENGTH - 7);
            title[strcspn(title, "\n")] = 0;
        }
        else if(strncmp(line, "Artist:", 7) == 0)
        {
            strncpy(artist, line + 8, MAX_LINE_LENGTH - 8);
            artist[strcspn(artist, "\n")] = 0;
        }
        else if(strncmp(line, "Album:", 6) == 0)
        {
            strncpy(album, line + 7, MAX_LINE_LENGTH - 7);
            album[strcspn(album, "\n")] = 0;
        }
        else if(strncmp(line, "Year:", 5) == 0)
        {
            year = atoi(line + 6);
        }
        else if(strncmp(line, "Track:", 6) == 0)
        {
            track = atoi(line + 7);
        }
    }

    fclose(file);

    printf("Title: %s\n", title);
    printf("Artist: %s\n", artist);
    printf("Album: %s\n", album);
    printf("Year: %d\n", year);
    printf("Track: %d\n", track);
}