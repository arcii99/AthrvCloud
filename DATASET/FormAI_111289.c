//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include<stdio.h>
#include<string.h>

typedef struct metadata          //Custom data type for metadata structure
{
    char author[30];
    char date[20];
    char version[10];
    char description[50];
} metadata;

void extract_metadata(FILE* file);      //Function prototypes
void print_metadata(metadata* md);

int main()
{
    FILE* file = fopen("file.txt", "r");    //Opening the text file
    if(file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Extracting metadata...\n\n");
    extract_metadata(file);                //Calling function to extract metadata
    fclose(file);                           //Closing the file
    return 0;
}

void extract_metadata(FILE* file)
{
    metadata md;                            //Creating metadata struct
    char line[150], temp[50];               //Temp variables to store strings
    int i;

    fgets(line, sizeof(line), file);        //Reading first line
    while(strncmp(line, "/*", 2) != 0)      //Loop to skip lines without metadata
    {
        if(fgets(line, sizeof(line), file) == NULL)
        {
            printf("No metadata found!\n"); //If no metadata is found
            return;
        }
    }
    while(strncmp(line, "*/", 2) != 0)      //Loop to extract metadata
    {
        if(strstr(line, "Author: "))        //Extracting author data
        {
            i = 0;
            while(line[i+8] != '\n')        //Copying author name to metadata struct
            {
                md.author[i] = line[i+8];
                i++;
            }
            md.author[i] = '\0';
        }
        else if(strstr(line, "Date: "))    //Extracting date data
        {
            i = 0;
            while(line[i+6] != '\n')        //Copying date to metadata struct
            {
                md.date[i] = line[i+6];
                i++;
            }
            md.date[i] = '\0';
        }
        else if(strstr(line, "Version: ")) //Extracting version data
        {
            i = 0;
            while(line[i+9] != '\n')        //Copying version number to metadata struct
            {
                md.version[i] = line[i+9];
                i++;
            }
            md.version[i] = '\0';
        }
        else if(strstr(line, "Description: "))  //Extracting description data
        {
            i = 0;
            while(line[i+13] != '\n')       //Copying description to metadata struct
            {
                md.description[i] = line[i+13];
                i++;
            }
            md.description[i] = '\0';
        }
        if(fgets(line, sizeof(line), file) == NULL)  //Reading next line
        {
            break;
        }
    }
    print_metadata(&md);                    //Calling function to print metadata
}

void print_metadata(metadata* md)           //Function to print extracted metadata
{
    printf("Author: %s\n", md->author);
    printf("Date: %s\n", md->date);
    printf("Version: %s\n", md->version);
    printf("Description: %s\n", md->description);
}