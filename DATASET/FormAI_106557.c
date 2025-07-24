//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IMG_WIDTH 256
#define IMG_HEIGHT 256
#define MAX_PIXELS 65536

// Define the image object
typedef struct {
    int width, height;
    unsigned char data[IMG_WIDTH*IMG_HEIGHT];
} image;

// Reads in a PGM file
void read_pgm(image *img, char *filename){
    FILE *fp = fopen(filename, "r");
    char ch, type;
    int i = 0, width, height, max_gray;
    while((ch = fgetc(fp)) != EOF){
        if(ch == '#'){
            while(fgetc(fp) != '\n');
        }else if(ch == 'P'){
            type = fgetc(fp);
            if(type != '5' && type != '6'){
                printf("Error: unsupported PGM type %c\n", type);
                exit(1);
            }
        }else if(ch == '\n' && i == 1){
            fscanf(fp, "%d %d", &img->width, &img->height);
            i++;
        }else if(ch == '\n' && i == 2){
            fscanf(fp, "%d", &max_gray);
            if(max_gray > 255){
                printf("Error: max value must be less than or equal to 255\n");
                exit(1);
            }
            i++;
        }else if(i == 3){
            img->data[img->width*img->height-1] = ch;
            img->data[img->width*img->height-2] = fgetc(fp);
            for(int j = img->width*img->height-3; j >= 0; j--){
                img->data[j] = fgetc(fp);
            }
        }else{
            i++;
        }
    }
    fclose(fp);
}

// Writes out a PGM file
void write_pgm(image *img, char *filename){
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P5\n%d %d\n255\n", img->width, img->height);
    for(int i = 0; i < img->width*img->height; i++){
        fputc(img->data[i], fp);
    }
    fclose(fp);
}

// Flips an image horizontally
void flip_horizontal(image *img){
    unsigned char temp;
    for(int i = 0; i < img->height; i++){
        for(int j = 0; j < img->width/2; j++){
            temp = img->data[i*img->width+j];
            img->data[i*img->width+j] = img->data[i*img->width+img->width-j-1];
            img->data[i*img->width+img->width-j-1] = temp;
        }
    }
}

// Flips an image vertically
void flip_vertical(image *img){
    unsigned char temp;
    for(int i = 0; i < img->width; i++){
        for(int j = 0; j < img->height/2; j++){
            temp = img->data[j*img->width+i];
            img->data[j*img->width+i] = img->data[(img->height-j-1)*img->width+i];
            img->data[(img->height-j-1)*img->width+i] = temp;
        }
    }
}

// Changes the brightness of an image
void change_brightness(image *img, int brightness){
    for(int i = 0; i < img->width*img->height; i++){
        int value = img->data[i] + brightness;
        img->data[i] = fmin(fmax(value, 0), 255);
    }
}

// Changes the contrast of an image
void change_contrast(image *img, float contrast){
    float factor = (259.0*(contrast+255.0))/(255.0*(259.0-contrast));
    for(int i = 0; i < img->width*img->height; i++){
        float value = factor*(img->data[i]-128.0)+128.0;
        img->data[i] = fmin(fmax(value, 0), 255);
    }
}

int main(){
    image img;
    read_pgm(&img, "input.pgm");
    
    printf("Enter task to perform [1: Flip horizontally, 2: Flip vertically, 3: Change brightness, 4: Change contrast]: ");
    int task;
    scanf("%d", &task);
    
    switch(task){
        case 1:
            flip_horizontal(&img);
            printf("Image flipped horizontally!\n");
            write_pgm(&img, "output.pgm");
            break;
        case 2:
            flip_vertical(&img);
            printf("Image flipped vertically!\n");
            write_pgm(&img, "output.pgm");
            break;
        case 3:
            printf("Enter brightness adjustment (-255 to 255): ");
            int brightness;
            scanf("%d", &brightness);
            change_brightness(&img, brightness);
            printf("Brightness changed!\n");
            write_pgm(&img, "output.pgm");
            break;
        case 4:
            printf("Enter contrast adjustment (0.0 to 2.0): ");
            float contrast;
            scanf("%f", &contrast);
            change_contrast(&img, contrast);
            printf("Contrast changed!\n");
            write_pgm(&img, "output.pgm");
            break;
        default:
            printf("Error: invalid task selected\n");
            break;
    }
    
    return 0;
}