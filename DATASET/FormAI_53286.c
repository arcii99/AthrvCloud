//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char value : 1;
    unsigned char frequency : 7;
} bitFrequency;

char *compress(char *input) {
    // Initialize a 256 byte frequency table for each ASCII character
    int frequency[256];
    memset(frequency, 0, sizeof frequency);

    // Count the frequency of each ASCII character in the input string
    int i = 0;
    while (input[i] != '\0') {
        frequency[(unsigned char)input[i]]++;
        i++;
    }
    
    // Calculate the number of unique characters found in the input string
    int uniqueChars = 0;
    for (int j = 0; j < 256; ++j) {
        if (frequency[j]) {
            ++uniqueChars;
        }
    }

    // Create an array of bitFrequency structs with the number of unique characters
    bitFrequency *freqTable = (bitFrequency*)calloc(uniqueChars, sizeof(bitFrequency));
    int k = 0;
    for (int j = 0; j < 256; ++j) {
        if (frequency[j]) {
            freqTable[k].value = j;
            freqTable[k++].frequency = frequency[j];
        }
    }

    // Sort the freqTable in ascending order based on the frequency of the characters
    for (int j = 0; j < uniqueChars - 1; ++j) {
        for (int l = j + 1; l < uniqueChars; ++l) {
            if (freqTable[j].frequency > freqTable[l].frequency) {
                bitFrequency temp = freqTable[j];
                freqTable[j] = freqTable[l];
                freqTable[l] = temp;
            }
        }
    }

    // Calculate the max and min range for each character
    float maxRange[uniqueChars];
    float minRange[uniqueChars];
    maxRange[0] = (((float)freqTable[0].frequency) / i);
    minRange[0] = 0;
    for (int j = 1; j < uniqueChars; ++j) {
        maxRange[j] = maxRange[j-1] + (((float)freqTable[j].frequency) / i);
        minRange[j] = maxRange[j-1];
    }

    // Encode the input string
    float lowerBound = 0;
    float upperBound = 1;
    float range = 1;
    int encodedLength = 0;
    for (int j = 0; j < i; ++j) {
        char c = input[j];
        int index = 0;
        while (freqTable[index].value != c) {
            index++;
        }
        float newLowerBound = lowerBound + (range * minRange[index]);
        float newUpperBound = lowerBound + (range * maxRange[index]);
        while (((newLowerBound > 0.5) && (newUpperBound > 0.5)) || ((newLowerBound < 0.5) && (newUpperBound < 0.5))) {
            if (newLowerBound > 0.5) {
                putchar('0');
                while (encodedLength > 0) {
                    putchar('1');
                    encodedLength--;
                }
                newLowerBound -= 0.5;
                newUpperBound -= 0.5;
            } else {
                putchar('1');
                while (encodedLength > 0) {
                    putchar('0');
                    encodedLength--;
                }
                newLowerBound *= 2;
                newUpperBound *= 2;
            }
        }
        range = newUpperBound - newLowerBound;
        lowerBound = newLowerBound;
        upperBound = newUpperBound;
        encodedLength++;
    }

    // Output the encoded data as a string
    putchar('0');
    while (encodedLength > 0) {
        putchar('1');
        encodedLength--;
    }
    return input;
}

int main() {
    char *testString = "This is a test string for compression!";
    printf("Original string: %s\n", testString);
    char *compressedString = compress(testString);
    printf("Compressed string: %s\n", compressedString);
    return 0;
}