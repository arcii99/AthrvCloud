//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct compressed_data {
    int size;
    unsigned char *data;
} c_data;

c_data* compress(unsigned char *data, int size) {
    int i, j, k, len = 0;
    unsigned char *compressed = NULL;
    c_data *result = (c_data*)malloc(sizeof(c_data));
    if(!result) return NULL;

    for(i=0; i<size; i++) {
        j = i+1;
        while(j<size && data[j] == data[i]) j++;
        len += snprintf(NULL, 0, "%d%c", j-i, data[i]) + 1;
        i = j-1;
    }

    compressed = (unsigned char*)malloc(len*sizeof(unsigned char));
    if(!compressed) { free(result); return NULL; }

    for(i=0, k=0; i<size; i++) {
        j = i+1;
        while(j<size && data[j] == data[i]) j++;
        k += sprintf((char*)compressed+k, "%d%c", j-i, data[i]);
        compressed[k++] = '|';
        i = j-1;
    }

    result->data = compressed;
    result->size = len-1;
    return result;
}

void decompress(c_data *cdata) {
    int i, j, k, count = 0;
    for(i=0; i<cdata->size; i++) {
        if(cdata->data[i] == '|') {
            count++;
        }
    }
    unsigned char *decompressed = (unsigned char*)malloc(count*sizeof(unsigned char));
    if(!decompressed) { fprintf(stderr, "Memory allocation failed.\n"); return; }
    for(i=0, j=0, k=0; i<cdata->size; i++) {
        count = 0;
        while(cdata->data[i] != '|') {
            j = (j*10) + (cdata->data[i]-'0');
            i++;
        }
        i++;
        while(count<j) {
            decompressed[k++] = cdata->data[i];
            count++;
        }
    }
    printf("Decompressed Data: %s\n", decompressed);
    free(decompressed);
}

int main() {
    unsigned char data[] = "aaabbccddddhh";
    c_data *compressed_data;
    compressed_data = compress(data, strlen(data));
    printf("Compressed Data: %s\n", compressed_data->data);
    decompress(compressed_data);
    free(compressed_data->data);
    free(compressed_data);

    return 0;
}