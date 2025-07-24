//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DATA_SIZE 1000

bool isPowerOfTwo(int num)
{
    if (num == 0)
        return false;

    while (num != 1)
    {
        if (num % 2 != 0)
            return false;
        num = num / 2;
    }
    return true;
}

char* dataRecovery(char *corruptedData)
{
    int size = sizeof(corruptedData) / sizeof(corruptedData[0]);
    if (!isPowerOfTwo(size))
    {
        printf("Oops! Corrupted data size is not a power of 2, cannot recover data!\n");
        return NULL;
    }

    int binaryCounter = 0;
    for (int i = 0; i < size; i++)
    {
        if (corruptedData[i] == '1')
            binaryCounter++;
    }

    if (!isPowerOfTwo(binaryCounter))
    {
        printf("Oops! Corrupted data contains non-uniform binary values, cannot recover data!\n");
        return NULL;
    }

    char* recoveredData = (char*)malloc(MAX_DATA_SIZE * sizeof(char));

    for (int i = 0; i < size; i += binaryCounter)
    {
        for (int j = 0; j < binaryCounter; j++)
        {
            if (corruptedData[i + j] == '1')
                recoveredData[j] = '1';
            else
                recoveredData[j] = '0';
        }
    }
    printf("Hurray! Recovered data is: %s\n", recoveredData);
    return recoveredData;
}

int main()
{
    char* corruptedData = "0100101011010010";
    char* recoveredData = dataRecovery(corruptedData);
    free(recoveredData);
    return 0;
}