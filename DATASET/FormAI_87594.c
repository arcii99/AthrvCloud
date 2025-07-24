//FormAI DATASET v1.0 Category: QR code reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <qrencode.h>

int main()
{
  char qr_code_data[1000];
  printf("Please input the QR code data:\n");
  scanf("%s", qr_code_data);

  QRcode *qr_code = QRcode_encodeString(qr_code_data, 0, QR_ECLEVEL_M, QR_MODE_8, 1);

  if (qr_code == NULL)
  {
    printf("QR code encoding failed!");
    return 1;
  }

  int qr_code_width = qr_code->width;
  int *qr_code_data_matrix = qr_code->data;

  printf("QR code width: %d\n", qr_code_width);

  printf("QR code data bits:\n");

  for (int i = 0; i < qr_code_width; i++)
  {

    for (int j = 0; j < qr_code_width; j++)
    {
      int index = i * qr_code_width + j;
      printf("%d", *(qr_code_data_matrix + index));
    }

    printf("\n");
  }

  QRcode_free(qr_code);

  return 0;
}