//FormAI DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_FILE_NAME 100

struct file
{
    char file_name[MAX_FILE_NAME];
    char data[MAX_SIZE];
    int size;
};

struct message
{
    char data[MAX_SIZE];
    int size;
};

// Function to read file contents into file structure
int read_file(char file_name[], struct file *f)
{
    FILE *fp;
    fp = fopen(file_name, "rb");
    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return -1;
    }
    fseek(fp, 0, SEEK_END);
    f->size = ftell(fp);
    rewind(fp);
    fread(f->data, f->size, 1, fp);
    fclose(fp);
    strcpy(f->file_name, file_name);
    return 0;
}

// Function to write file contents from file structure
int write_file(struct file *f)
{
    FILE *fp;
    fp = fopen(f->file_name, "wb");
    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return -1;
    }
    fwrite(f->data, f->size, 1, fp);
    fclose(fp);
    return 0;
}

// Function to read message contents into message structure
int read_message(char message[], struct message *m)
{
    int len = strlen(message);
    if(len > MAX_SIZE)
    {
        printf("Error: Message is too long.\n");
        return -1;
    }
    strcpy(m->data, message);
    m->size = len;
    return 0;
}

// Function to hide message data in file data using LSB technique
void hide_message(struct file *f, struct message *m)
{
    int len = strlen(m->data);
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j=i; j<f->size; j+=8)
        {
            if(j+7 < f->size)
            {
                f->data[j+7] &= ~(1 << i);
                if(m->data[(j/8)%len] & (1 << i))
                {
                    f->data[j+7] |= (1 << i);
                }
            }
        }
    }
    strcpy(f->file_name, strcat(f->file_name, ".steg"));
}

// Function to extract message data from file data using LSB technique
void extract_message(struct file *f, struct message *m)
{
    int i, j;
    for(i=0; i<8; i++)
    {
        for(j=i; j<f->size; j+=8)
        {
            if(j+7 < f->size)
            {
                if(f->data[j+7] & (1 << i))
                {
                    m->data[(j/8)%m->size] |= (1 << i);
                }
            }
        }
    }
}

int main()
{
    struct file f;
    struct message m;
    char inp_file[MAX_FILE_NAME], out_file[MAX_FILE_NAME], message[MAX_SIZE];
    int input;

    // Input file and message
    printf("Enter the name of a file to hide message in: ");
    scanf("%s", inp_file);
    input = read_file(inp_file, &f);
    if(input == -1)
    {
        return -1;
    }
    printf("Enter the message to hide: ");
    scanf(" %[^\n]", message);

    // Hide message in file
    input = read_message(message, &m);
    if(input == -1)
    {
        return -1;
    }
    hide_message(&f, &m);
    printf("Message has been hidden in file.\n");

    // Write steg file
    input = write_file(&f);
    if(input == -1)
    {
        return -1;
    }
    printf("Steganography file has been written as %s.\n", f.file_name);

    // Extract message from steg file
    printf("Do you want to extract message from file? (1/0): ");
    scanf("%d", &input);
    if(input == 1)
    {
        read_file(f.file_name, &f);
        extract_message(&f, &m);
        printf("Extracted message is: %s\n", m.data);
    }

    return 0;
}