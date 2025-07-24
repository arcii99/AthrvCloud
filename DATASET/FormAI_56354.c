//FormAI DATASET v1.0 Category: QR code reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Define variables
  int size = 0;
  char* code = NULL;
  int i, j, k, l, m, n;
  
  // Read in QR code data
  printf("Please enter the QR code: ");
  scanf("%ms", &code);
  size = strlen(code);
  
  // Check if code is valid and calculate dimensions
  int dim = 0;
  int valid = 1;
  for (i = 0; i < size; i += 2) {
    if (i+1 >= size || code[i] != '1' || code[i+1] != '0') {
      valid = 0;
      break;
    }
    dim++;
  }
  if (valid == 0 || dim*dim*2 != size) {
    printf("Error: Invalid QR code\n");
    return 1;
  }
  
  // Calculate error correction data
  int p1[dim], p2[dim], p3[dim], p4[dim];
  for (i = 0; i < dim; i++) {
    p1[i] = ((i+1)*7) % dim;
    p2[i] = ((i+1)*8) % dim;
    p3[i] = ((i+1)*9) % dim;
    p4[i] = ((i+1)*10) % dim;
  }
  
  // Extract module data and calculate data polynomial
  int module[dim][dim];
  int poly_data[dim*dim];
  k = 0;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      module[i][j] = (code[k] == '1') ? 1 : 0;
      if ((i+j) % 2 == 0) {
        poly_data[k/2] = module[i][j];
      }
      k++;
    }
  }
  int size_data = dim*dim/2;
  
  // Calculate generator polynomial
  int poly_gen[dim+1];
  memset(poly_gen, 0, sizeof(poly_gen));
  poly_gen[0] = 1;
  for (i = 0; i < dim; i++) {
    int temp_gen[dim+1];
    memcpy(temp_gen, poly_gen, sizeof(temp_gen));
    for (j = 0; j < dim; j++) {
      temp_gen[j+1] = (temp_gen[j+1] + temp_gen[j]*p1[i]) % 2;
    }
    memcpy(poly_gen, temp_gen, sizeof(poly_gen));
  }
  for (i = 0; i < dim; i++) {
    int temp_gen[dim+1];
    memcpy(temp_gen, poly_gen, sizeof(temp_gen));
    for (j = 0; j < dim; j++) {
      temp_gen[j+1] = (temp_gen[j+1] + temp_gen[j]*p2[i]) % 2;
    }
    memcpy(poly_gen, temp_gen, sizeof(poly_gen));
  }
  for (i = 0; i < dim; i++) {
    int temp_gen[dim+1];
    memcpy(temp_gen, poly_gen, sizeof(temp_gen));
    for (j = 0; j < dim; j++) {
      temp_gen[j+1] = (temp_gen[j+1] + temp_gen[j]*p3[i]) % 2;
    }
    memcpy(poly_gen, temp_gen, sizeof(poly_gen));
  }
  for (i = 0; i < dim; i++) {
    int temp_gen[dim+1];
    memcpy(temp_gen, poly_gen, sizeof(temp_gen));
    for (j = 0; j < dim; j++) {
      temp_gen[j+1] = (temp_gen[j+1] + temp_gen[j]*p4[i]) % 2;
    }
    memcpy(poly_gen, temp_gen, sizeof(poly_gen));
  }
  int size_gen = dim+1;
  
  // Calculate message polynomial
  int poly_msg[size_data+size_gen-1];
  memcpy(poly_msg, poly_data, sizeof(poly_data));
  for (i = size_data; i < size_data+size_gen-1; i++) {
    poly_msg[i] = 0;
  }
  for (i = 0; i < size_data; i++) {
    int temp_msg[size_gen];
    memcpy(temp_msg, poly_msg+i, sizeof(temp_msg));
    for (j = 0; j < size_gen; j++) {
      temp_msg[j] = (temp_msg[j] + poly_gen[j]) % 2;
    }
    memcpy(poly_msg+i, temp_msg, sizeof(temp_msg));
  }
  
  // Calculate error polynomial
  int poly_err[size_gen-1];
  memset(poly_err, 0, sizeof(poly_err));
  for (i = 0; i < size_data+size_gen-1; i++) {
    int temp_err[size_gen];
    memcpy(temp_err, poly_gen, sizeof(temp_err));
    for (j = 0; j < size_gen; j++) {
      temp_err[j] = (temp_err[j] + poly_msg[i]*(((i+j)%2 == 0) ? 1 : 0)) % 2;
    }
    for (j = 0; j < size_gen-1; j++) {
      temp_err[j] = temp_err[j+1];
    }
    temp_err[size_gen-1] = 0;
    memcpy(poly_err, temp_err, sizeof(poly_err));
  }
  
  // Calculate corrected message polynomial
  int poly_corr[size_data];
  memcpy(poly_corr, poly_data, sizeof(poly_data));
  for (i = 0; i < size_data; i++) {
    int temp_corr[size_gen];
    memcpy(temp_corr, poly_corr+i, sizeof(temp_corr));
    for (j = 0; j < size_gen; j++) {
      temp_corr[j] = (temp_corr[j] + poly_err[j]) % 2;
    }
    memcpy(poly_corr+i, temp_corr, sizeof(temp_corr));
  }
  
  // Extract final message data and print
  char final[size_data+1];
  final[size_data] = '\0';
  k = 0;
  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      if ((i+j) % 2 == 0) {
        final[k++] = '0' + poly_corr[k/2];
      }
    }
  }
  printf("The message in the QR code is: %s\n", final);
  
  // Free dynamically allocated memory
  free(code);
  
  return 0;
}