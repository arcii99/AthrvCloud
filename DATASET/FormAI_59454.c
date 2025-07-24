//FormAI DATASET v1.0 Category: Image Steganography ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define BYTESIZE 8
#define FILE_SUFFIX "_stego"

typedef unsigned char byte; // 1 Byte
typedef unsigned short int word; // 2 bytes

word getBitNo(word x,int n) {
    return (x>>n) & 0b1; 
}

word setBitNo(word x,int n,word v) {
    word mask = ~(1<<n);
    v = ((v & 0b1) << n);
    return (x & mask) | v;
}

word setByteLSB(word x, byte v,int i) {
    int offset = i*BYTESIZE;
    for(int n = 0; n < BYTESIZE; n++) {
        x = setBitNo(x,offset+n,v);
        v >>= 1;
    }
    return x;
}

byte getByteLSB(word x,int i) {
    int offset = i*BYTESIZE;
    byte v = 0;
    for(int n = 0; n < BYTESIZE; n++) {
        v |= (byte)getBitNo(x,offset+n) << n;
    }
    return v;
}

void hideDataInImage(FILE* f, byte* data, size_t sz, char* save_as) {
    word* buffer = malloc(sizeof(word)*sz);
    if (buffer == NULL) {
        perror("Failed to allocate data buffer");
        return;
    }
    size_t bytesRead = fread(buffer,sizeof(buffer[0]),sz,f);
    size_t bitsProcessed = 0;
    for(unsigned long i = 0; i < sz; i++) {
        for(int ch = 0; ch < BYTESIZE; ch++) {
            if (bitsProcessed >= sz*BYTESIZE) {
                // no more data to hide
                break;
            }
            buffer[i] = setByteLSB(buffer[i],data[bitsProcessed/BYTESIZE],ch);
            bitsProcessed++;
        }
    }

    // write stego-image /w suffix
    int len = strlen(save_as);
    char* name = malloc(sizeof(char) * (len + strlen(FILE_SUFFIX) + 1));
    if (name == NULL) {
        perror("Failed to allocate memory for filename");
        return;
    }
    strncpy(name,save_as,len);
    strncpy(name+len,FILE_SUFFIX,strlen(FILE_SUFFIX)+1); // ensure null-terminator
    FILE* f_out = fopen(name,"wb");
    fwrite(buffer,sizeof(buffer[0]),sz,f_out);
    fclose(f_out);

    free(buffer);
    free(name);
}

byte* retriveDataFromImage(FILE* f, size_t sz) {
    byte* buffer = malloc(sz);
    if (buffer == NULL) {
        perror("Failed to allocate data buffer");
        return NULL;
    }
    memset(buffer,0,sz);

    word* imageBuffer = malloc(sizeof(word)*sz);
    if (imageBuffer == NULL) {
        perror("Failed to allocate image buffer");
        free(buffer);
        return NULL;
    }
    size_t bytesRead = fread(imageBuffer,sizeof(imageBuffer[0]),sz,f);
    size_t bitsProcessed = 0;
    for(unsigned long i = 0; i < sz; i++) {
        for(int ch = 0; ch < BYTESIZE; ch++) {
            if (bitsProcessed >= sz*BYTESIZE) {
                // no more data to retrieve
                break;
            }
            buffer[bitsProcessed/BYTESIZE] |= getByteLSB(imageBuffer[i],ch) << (bitsProcessed%BYTESIZE);
            bitsProcessed++;
        }
    }
    free(imageBuffer);
    return buffer;
}

int main() {
    FILE* f = fopen("test.png","rb");
    if(f==NULL) {
        printf("error opening file.");
        return 1;
    }
    fseek(f,0L,SEEK_END);
    size_t sz = ftell(f)/sizeof(word); // assume 2byte words
    fseek(f,0L,SEEK_SET);

    byte* dataToHide = (byte*)"Hello, world!";
    size_t dataSz = sizeof(dataToHide);

    hideDataInImage(f,dataToHide,dataSz,"test.png");

    fclose(f);

    // retrieve hidden data from image
    f = fopen("test_stego.png","rb");
    if(f==NULL) {
        printf("error opening file.");
        return 1;
    }
    fseek(f,0L,SEEK_END);
    sz = ftell(f)/sizeof(word); // assume 2byte words
    fseek(f,0L,SEEK_SET);
    byte* data = retriveDataFromImage(f,sz);
    printf("Retrieved data: %s\n",data);
    fclose(f);
    free(data);

    return 0;
}