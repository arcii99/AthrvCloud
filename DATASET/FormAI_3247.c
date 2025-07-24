//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store elements
typedef struct {
    int key;
    char *value;
} Element;

// Define a struct to represent a bucket
typedef struct {
    int count;
    int size;
    Element *elements;
} Bucket;

// Define the bucket sort function
void bucket_sort(Element array[], int n, int max_value) {
    int i, j;
    Bucket *buckets = (Bucket*)malloc(sizeof(Bucket) * max_value);

    // Initialize buckets
    for (i = 0; i < max_value; i++) {
        buckets[i].count = 0;
        buckets[i].size = 10;
        buckets[i].elements = (Element*)malloc(sizeof(Element) * buckets[i].size);
    }

    // Insert elements into buckets
    for (i = 0; i < n; i++) {
        Element element = array[i];
        int bucket_index = element.key - 1;
        if (buckets[bucket_index].count == buckets[bucket_index].size) {
            // Double the size of the bucket's elements array
            buckets[bucket_index].size *= 2;
            buckets[bucket_index].elements = (Element*)realloc(buckets[bucket_index].elements, sizeof(Element) * buckets[bucket_index].size);
        }
        buckets[bucket_index].elements[buckets[bucket_index].count++] = element;
    }

    // Sort elements within each bucket using insertion sort
    for (i = 0; i < max_value; i++) {
        for (j = 1; j < buckets[i].count; j++) {
            Element key = buckets[i].elements[j];
            int k = j - 1;
            while (k >= 0 && buckets[i].elements[k].key > key.key) {
                buckets[i].elements[k+1] = buckets[i].elements[k];
                k--;
            }
            buckets[i].elements[k+1] = key;
        }
    }

    // Copy elements back to original array
    int index = 0;
    for (i = 0; i < max_value; i++) {
        for (j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].elements[j];
        }
        free(buckets[i].elements);
    }

    free(buckets);
}

// Define a helper function to generate random strings
char *get_random_string(int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    char *random_string = (char*)malloc(sizeof(char) * (length + 1));
    int i;
    for (i = 0; i < length; i++) {
        int index = rand() % strlen(charset);
        random_string[i] = charset[index];
    }
    random_string[length] = '\0';
    return random_string;
}

int main() {
    int i, n = 100;
    Element *array = (Element*)malloc(sizeof(Element) * n);

    // Generate random keys and values for elements
    for (i = 0; i < n; i++) {
        int key = rand() % n + 1;
        char *value = get_random_string(10);
        array[i].key = key;
        array[i].value = value;
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s\n", array[i].key, array[i].value);
    }
    printf("\n");

    // Sort array using bucket sort
    bucket_sort(array, n, n);

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %s\n", array[i].key, array[i].value);
    }
    printf("\n");

    // Free memory
    for (i = 0; i < n; i++) {
        free(array[i].value);
    }
    free(array);

    return 0;
}