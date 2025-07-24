//FormAI DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Program to implement Lempel–Ziv–Welch (LZW) Compression Algorithm.*/
/*LZW is a universal lossless data compression algorithm.•*/
/*It is an adaptive algorithm i.e it adapts itself to the data being compressed.*/

#define MAX_TABLE_SIZE 4096  //Maximum table size defined.

int dictionary[MAX_TABLE_SIZE][2]; //Declared a table to store dictionary of strings.
int dictSize = 256;    //Initial dictionary size predefined with single character strings of ASCII.

/*Function to search for a pattern in the table*/
int search(int prefix, int character)
{
    int i;
    for(i=0; i<dictSize; i++)
    {
        if(dictionary[i][0] == prefix && dictionary[i][1] == character)
        {
            return i;   //If pattern found in the table return the index.
        }
    }
    return -1;  //If not found return -1.
}

/*Function to add an entry to the dictionary*/
void addToDict(int prefix, int character)
{
    dictionary[dictSize][0] = prefix;
    dictionary[dictSize][1] = character;
    dictSize++;
}

/*LZW Compression Algorithm*/
int* LZW_Compress(char* input)
{
    int* output = (int*)malloc( strlen(input)*sizeof(int)); //Allocate memory for the output.

    /*Initial table set with ASCII character strings*/
    int i, prefix = input[0], ch, code;
    for(i=1; i<strlen(input); i++)
    {
        ch = input[i];
        code = search(prefix, ch);  //Pattern search in the table.
        if(code != -1) //If pattern found, add next character.
        {
            prefix = code;
        }
        else 
        {
            output[i-1] = prefix;
            addToDict(prefix, ch);  //Add a new entry to dictionary.
            prefix = ch;    //Move the pattern search to next character.
        }
    }
    output[i-1] = prefix;

    return output;
}

/*Main Function*/
int main()
{
    //Input string to be compressed.
    char input[] = "Hello World! This is a test sentence.";
    printf("\nInput String : %s",input);

    //LZW Compression.
    int* output = LZW_Compress(input);

    //Displaying compressed output.
    printf("\nCompressed Output : ");
    for(int i=0; i<strlen(input); i++)
    {
        printf("%d ", output[i]);    //Display the compressed output.
    }

    printf("\n");
    return 0;
}