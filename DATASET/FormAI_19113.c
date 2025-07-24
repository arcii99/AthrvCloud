//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void watermark(int pixel_value, int watermark_value) {
  int i,j,k,l,m,n;
  int array2[8][8]={{0}};
  int array3[8][8]={{0}};
  int array4[8][8]={{0}};
  int array5[8][8]={{0}};
  
  // Creating 8x8 block
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
        array2[i][j] = pixel_value; // Copying the original pixel value to array2
    }
  }

  // Generating random numbers and hashing them to get values between 0-255
  int random_number[64]={201, 51, 187, 141, 98, 100, 115, 120, 94, 206,
                          110, 223, 126, 123, 252, 166, 4, 132, 74, 129,
                          209, 67, 185, 141, 16, 58, 130, 166, 106, 87,
                          135, 80, 85, 248, 193, 205, 209, 196, 212, 183,
                          10, 42, 193, 217, 119, 170, 82, 35, 0, 153,
                          40, 60, 82, 50, 23, 83, 198, 48, 155, 141};
  int hashed_random_number[64]={0};
  
  for(k=0; k<64; k++) {
    hashed_random_number[k] = ((random_number[k] * 67) % 169) + 86;
  }

  // Converting values of array2 to binary
  int binary_array[8][8][8] = {0};
  for(l=0; l<8; l++) {
    for(m=0; m<8; m++) {
        int r = array2[l][m];
        
        for(n=7; n>=0; n--) {
            int x = r % 2;
            binary_array[l][m][n] = x;
            r = r / 2;
        }
    }
  }

  // Embedding the watermark
  for(l=0; l<8; l++) {
    for(m=0; m<8; m++) {
        int watermark_bit = 0;

        if(watermark_value & (1 << (l * 8 + m))) {
            watermark_bit = 1;
        } else {
            watermark_bit = 0;
        }

        for(n=0; n<8; n++) {
            if((binary_array[l][m][n] == 0) && (hashed_random_number[n] > 127) && (watermark_bit == 1)) {
                binary_array[l][m][n] = 1;
            } else if((binary_array[l][m][n] == 1) && (hashed_random_number[n] <= 127) && (watermark_bit == 0)) {
                binary_array[l][m][n] = 0;
            }
        }
    }
  }

  // Converting binary values to decimal
  for(l=0; l<8; l++) {
    for(m=0; m<8; m++) {
        int decimal_value = 0;
        
        for(n=7; n>=0; n--) {
            decimal_value += pow(2, n) * binary_array[l][m][n];
        }

        array3[l][m] = decimal_value;
    }
  }

  // Applying DCT
  for(l=0; l<8; l++) {
    for(m=0; m<8; m++) {
        float ci, cj, sum = 0;
        float dct_value = 0;

        if(l == 0) {
            ci = 1 / sqrt(2);
        } else {
            ci = 1;
        }

        if(m == 0) {
            cj = 1 / sqrt(2);
        } else {
            cj = 1;
        }
        
        for(i=0; i<8; i++) {
            for(j=0; j<8; j++) {
                sum += array3[i][j] * cos((2 * i + 1) * l * M_PI / 16) * cos((2 * j + 1) * m * M_PI / 16);
            }
        }
        
        dct_value = 0.25 * ci * cj * sum;
        array4[l][m] = dct_value;
    }
  }

  // Applying inverse DCT
  for(l=0; l<8; l++) {
    for(m=0; m<8; m++) {
        float ci, cj, sum = 0;
        float idct_value = 0;

        for(i=0; i<8; i++) {
            for(j=0; j<8; j++) {
                if(i == 0) {
                    ci = 1 / sqrt(2);
                } else {
                    ci = 1;
                }

                if(j == 0) {
                    cj = 1 / sqrt(2);
                } else {
                    cj = 1;
                }

                sum += ci * cj * array4[i][j] * cos((2 * l + 1) * i * M_PI / 16) * cos((2 * m + 1) * j * M_PI / 16);
            }
        }

        idct_value = 0.25 * sum;
        array5[l][m] = idct_value;
    }
  }

  // Updating the pixel value with watermark
  for(l=0; l<8; l++) {
    for(m=0; m<8; m++) {
        pixel_value = array5[l][m];
    }
  }

  printf("Original Pixel Value: %d\n", pixel_value);
  printf("Watermark Value: %d\n", watermark_value);
  printf("Updated Pixel Value: %d\n", pixel_value);
}

int main() {
    int pixel_value = 56;
    int watermark_value = 953;

    watermark(pixel_value, watermark_value);

    return 0;
}