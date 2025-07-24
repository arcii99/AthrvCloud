//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: authentic
#include <stdio.h>
#include <stdint.h>

void print_hex(uint32_t num){
  printf("0x");
  for(int i=sizeof(num);i>0;i--){
    uint8_t hex_digit = (num >> ((i - 1) * 4)) & 0xF;
    printf("%X", hex_digit);
  }
  printf("\n");
}

int main(){
  uint32_t num = 0xDEADBEEF;
  
  printf("Decimal: %d\n", num);
  print_hex(num);
  
  return 0;
}