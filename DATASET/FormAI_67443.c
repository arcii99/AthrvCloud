//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Function to calculate mean
float mean(float arr[], int n)
{
    float sum = 0, mean;
    int i;

    for (i = 0; i < n; i++)
        sum += arr[i];

    mean = sum / n;
    return mean;
}

//Function to calculate standard deviation
float standard_deviation(float arr[], int n, float mean)
{
    float sum = 0, std_dev;
    int i;

    for (i = 0; i < n; i++)
        sum += pow(arr[i] - mean, 2);

    std_dev = sqrt(sum / n);
    return std_dev;
}

//Function to embed watermark
void embed_watermark(float *arr, char *watermark)
{
    int i, j, k = 0;
    float mean_val = mean(arr, 10);
    float std_dev_val = standard_deviation(arr, 10, mean_val);
    int watermark_len = strlen(watermark);

    //Loop through array and embed watermark
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < watermark_len; j++)
        {
            if (k < watermark_len)
            {
                if (watermark[k] == '0')
                    arr[i] = arr[i] - ((1 / 3) * std_dev_val);
                else if (watermark[k] == '1')
                    arr[i] = arr[i] + ((1 / 3) * std_dev_val);
            }
            k++;
        }
    }
}

//Function to extract watermark
char *extract_watermark(float *arr)
{
    int i, j, k = 0;
    float mean_val = mean(arr, 10);
    float std_dev_val = standard_deviation(arr, 10, mean_val);
    char *watermark = (char *)malloc(sizeof(char) * 9);

    //Loop through array and extract watermark
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (k < 9)
            {
                if (arr[i] > (mean_val + std_dev_val / 3))
                    watermark[k] = '1';
                else if (arr[i] < (mean_val - std_dev_val / 3))
                    watermark[k] = '0';
            }
            k++;
        }
    }

    watermark[k] = '\0';
    return watermark;
}

int main()
{
    float arr[10] = {2.4, 3.1, 2.8, 3.5, 4.2, 2.2, 3.6, 3.4, 2.7, 3.9};

    //Embed watermark
    char watermark[] = "101010101";
    embed_watermark(arr, watermark);

    //Extract watermark and print
    char *extracted_watermark = extract_watermark(arr);
    printf("Extracted Watermark: %s\n", extracted_watermark);

    return 0;
}