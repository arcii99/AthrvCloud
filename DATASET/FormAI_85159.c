//FormAI DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define a struct to store the frequency table for each character
typedef struct {
    char character;
    int frequency;
} frequencyTable;

//Function to calculate the frequency table for the given text
frequencyTable* createFrequencyTable(char *text, int length) {
    frequencyTable* table = (frequencyTable*)malloc(sizeof(frequencyTable)*length);
    for(int i=0; i<length; i++) {
        table[i].character = text[i];
        table[i].frequency = 1;
        for(int j=i+1; j<length; j++) {
            if(text[j] == table[i].character) {
                table[i].frequency++;
                text[j] = '\0';
            }
        }
    }
    return table;
}

//Function to sort the frequency table in descending order
void sortFrequencyTable(frequencyTable *table, int length) {
    for(int i=0; i<length-1; i++) {
        for(int j=i+1; j<length; j++) {
            if(table[i].frequency < table[j].frequency) {
                frequencyTable temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }
}

//Function to print the frequency table for debugging purposes
void printFrequencyTable(frequencyTable *table, int length) {
    for(int i=0; i<length; i++) {
        printf("%c: %d\n", table[i].character, table[i].frequency);
    }
}

//Function to compress the given text using the frequency table
void compress(char *text, int length, frequencyTable *table, int tableLength) {
    for(int i=0; i<length; i++) {
        for(int j=0; j<tableLength; j++) {
            if(text[i] == table[j].character) {
                printf("%d", j);
                break;
            }
        }
    }
}

//Main function to test the compression algorithm
int main() {
    char text[] = "this is a test message for compression algorithm";
    int length = strlen(text);
    
    frequencyTable *table = createFrequencyTable(text, length);
    sortFrequencyTable(table, length);
    
    printFrequencyTable(table, length);
    compress(text, length, table, length);
    
    return 0;
}