//FormAI DATASET v1.0 Category: Image compression ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000                 //maximum size of the array
#define BYTE_SIZE 8                     //1 byte consists of 8 bits

//Compression function
int compress(unsigned char* arr, int size, unsigned char* output)
{
    unsigned char mask = 1;             //mask used to set bits in the compressed byte
    int compressedSize = 0;             //size of the compressed output
    unsigned char compressed[MAX_SIZE]; //compressed output array
    int index = 0;                      //index used to iterate through the output array
    int count = 0;                      //count used to keep track of number of consecutive 1s or 0s

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            count++;
        }
        else
        {
            //set first bit to 1 if there are consecutive 1s, 0 otherwise
            if (arr[i] == 1)
            {
                compressed[index] |= mask;
            }
            mask <<= 1;

            //set second bit to 1 if there are more than 2 consecutive 1s or 0s
            if (count > 1)
            {
                compressed[index] |= mask;
            }
            mask <<= 1;

            //set remaining 6 bits to the count value
            compressed[index] |= count;
            count = 0;
            mask = 1;

            index++;
        }

        //if the compressed array reaches max size, break out of loop
        if (index >= MAX_SIZE)
        {
            break;
        }
    }

    //copy compressed array to output array and return compressed size
    memcpy(output, compressed, index + 1);
    compressedSize = index + 1;

    return compressedSize;
}

//Decompression function
int decompress(unsigned char* arr, int size, unsigned char* output)
{
    int decompressedSize = 0;                   //size of the decompressed output
    unsigned char decompressed[MAX_SIZE];       //decompressed output array
    int index = 0;                              //index used to iterate through the output array
    int count = 0;                              //count used to keep track of number of consecutive 1s or 0s

    for (int i = 0; i < size; i++)
    {
        //check first bit to see if there are consecutive 1s or 0s
        if (arr[i] & 1)
        {
            count = 1;
        }
        else
        {
            count = 0;
        }

        //check second bit to see if there are more than 2 consecutive 1s or 0s
        if (arr[i] & 2)
        {
            count += 2;
        }

        //set bits in decompressed array based on count and bit values
        for (int j = 0; j < count; j++)
        {
            decompressed[index++] = arr[i] & (1 << (BYTE_SIZE - j - 1)) ? 1 : 0;
        }
    }

    //copy decompressed array to output array and return decompressed size
    memcpy(output, decompressed, index + 1);
    decompressedSize = index + 1;

    return decompressedSize;
}

int main()
{
    unsigned char arr[MAX_SIZE] = { 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0 };  //example input array
    unsigned char compressed[MAX_SIZE];                                 //compressed output array
    unsigned char decompressed[MAX_SIZE];                               //decompressed output array
    int size = sizeof(arr) / sizeof(arr[0]);                            //size of input array

    printf("Input array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int compressedSize = compress(arr, size, compressed);
    printf("Compressed array:\n");
    for (int i = 0; i < compressedSize; i++)
    {
        printf("%d ", compressed[i]);
    }
    printf("\n");

    int decompressedSize = decompress(compressed, compressedSize, decompressed);
    printf("Decompressed array:\n");
    for (int i = 0; i < decompressedSize; i++)
    {
        printf("%d ", decompressed[i]);
    }
    printf("\n");

    return 0;
}