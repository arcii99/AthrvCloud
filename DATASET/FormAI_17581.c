//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX 5000
#define BLOCK_SIZE 8
#define MESSAGE_SIZE 100

char message[MAX];
char encrypted_image[MAX];
char decrypted_image[MAX];

struct pixel{
    unsigned char r,g,b;
};

struct image{
    int width;
    int height;
    struct pixel *data;
};

struct watermark{
    char message[MESSAGE_SIZE];
    int message_length;
};

unsigned char* stob(unsigned char* s,int bits){
    unsigned char *binary = malloc(bits);
    int i, j;
    for(i=0; i < bits; i++){
        binary[i] = 0;
    }
    for(j=0; j<strlen(s); j++){
        int ch = (int) s[j];
        for(i=7; i>=0; i--){
            if(ch & (1 << i)){
                binary[j*8+(7-i)] = 1;
            }
        }
    }
    return binary;
}

unsigned char* btos(unsigned char *b,int bits){
    unsigned char *str = malloc(bits/8);
    int i, j;
    for(i=0; i< bits/8; i++){
        str[i] = 0;
    }
    for(j=0; j<bits/8; j++){
        int ch = 0;
        for(i=0; i<8; i++){
            if(b[j*8+i] == 1){
                ch += pow(2,7-i);
            }
        }
        str[j] = (unsigned char) ch;
    }
    return str;
}

void encode(struct image *img, struct watermark *wm){
    int i,j,kp,bp;
    unsigned char *message_bit = stob(wm->message, wm->message_length*8);

    kp=0;
    bp=0;
    for(i=0;i<img->height;i++){
        for(j=0;j<img->width;j++){
            struct pixel *pxl = img->data + (i*img->width + j);
            unsigned char r = pxl->r;
            unsigned char g = pxl->g;
            unsigned char b = pxl->b;

            if(kp<wm->message_length*8){
                if(bp<=7){
                    int lsb = message_bit[kp];
                    kp++;
                    r = (r & 0xFE) | lsb;
                    bp++;
                }
                if(bp<=7){
                    int lsb = message_bit[kp];
                    kp++;
                    g = (g & 0xFE) | lsb;
                    bp++;
                }
                if(bp<=7){
                    int lsb = message_bit[kp];
                    kp++;
                    b = (b & 0xFE) | lsb;
                    bp++;
                }
            } 
            pxl->r = r;
            pxl->g = g;
            pxl->b = b;
            if(bp==8){
                bp=0;
            }
        }
    }
}

struct watermark* decode(struct image *img){
    int i,j,kp,bp;
    struct watermark *wm = malloc(sizeof(struct watermark));
    wm->message_length = 0;

    unsigned char *message_bit = malloc(img->height*img->width*3);
    kp=0;
    bp=0;
    for(i=0;i<img->height;i++){
        for(j=0;j<img->width;j++){
            struct pixel *pxl = img->data + (i*img->width + j);
            unsigned char r = pxl->r;
            unsigned char g = pxl->g;
            unsigned char b = pxl->b;

            if(bp<=7){
                int lsb = r & 0x01;
                message_bit[kp] = lsb;
                bp++;
                kp++;
            }
            if(bp<=7){
                int lsb = g & 0x01;
                message_bit[kp] = lsb;
                bp++;
                kp++;
            }
            if(bp<=7){
                int lsb = b & 0x01;
                message_bit[kp] = lsb;
                bp++;
                kp++;
            }
            if(bp==8){
                bp=0;
                unsigned char *msg_byte = btos(message_bit+(kp-8),8);
                wm->message[wm->message_length] = *msg_byte;
                wm->message_length++;
            }
        }
    }
    unsigned char *msg_byte = btos(message_bit+(kp-bp),bp);
    wm->message[wm->message_length] = *msg_byte;
    wm->message_length++;
    return wm;
}

int main(int argc, char** argv){
    if(argc != 3){
        fprintf(stderr,"usage: %s <source-image> <target-image>\n", argv[0]);
        exit(1);
    }
    char *src_file = argv[1];
    char *dst_file = argv[2];

    FILE *src = fopen(src_file, "rb");
    if(!src){
        fprintf(stderr,"Unable to read file %s\n", src_file);
        exit(1);
    }
    FILE *dst = fopen(dst_file, "wb");
    if(!dst){
        fprintf(stderr,"Unable to write file %s\n", dst_file);
        exit(1);
    }

    struct image img;
    fread(&img.width, sizeof(int), 1, src);
    fread(&img.height, sizeof(int), 1, src);
    img.data = malloc(img.width * img.height * sizeof(struct pixel));

    size_t elements_read = fread(img.data, sizeof(struct pixel), img.width*img.height, src);
    if(elements_read != img.width * img.height){
        fprintf(stderr,"Unable to read file %s\n", src_file);
        exit(1);
    }

    struct watermark *wm = malloc(sizeof(struct watermark));
    printf("Enter message: ");
    fgets(wm->message, MESSAGE_SIZE, stdin);
    wm->message_length=strlen(wm->message)-1;

    encode(&img, wm);

    fwrite(&img.width, sizeof(int), 1, dst);
    fwrite(&img.height, sizeof(int), 1, dst);
    fwrite(img.data, sizeof(struct pixel), img.width * img.height, dst);

    fclose(src);
    fclose(dst);

    struct image img2;
    src = fopen(dst_file, "rb");
    fread(&img2.width, sizeof(int), 1, src);
    fread(&img2.height, sizeof(int), 1, src);
    img2.data = malloc(img2.width * img2.height * sizeof(struct pixel));
    elements_read = fread(img2.data, sizeof(struct pixel), img2.width*img2.height, src);
    if(elements_read != img2.width * img2.height){
        fprintf(stderr,"Unable to read file %s\n", dst_file);
        exit(1);
    }

    struct watermark *wm2 = decode(&img2);
    printf("%s\n", wm2->message);
    fclose(src);
    return 0;
}