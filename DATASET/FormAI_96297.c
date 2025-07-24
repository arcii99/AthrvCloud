//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
  int i;
  char input[1000], output[1000];

  printf("Enter C Cat Language: ");
  fgets(input, 1000, stdin);

  for (i = 0; i < strlen(input); i++)
  {
    switch (input[i])
    {
      case 'M':
        strcat(output, "Microchip detected, ");
        break;
      case 'P':
        strcat(output, "Purring detected, ");
        break;
      case 'V':
        strcat(output, "Vicious detected, ");
        break;
      case 'S':
        strcat(output, "Scratching detected, ");
        break;
      case 'E':
        strcat(output, "Escape plan detected, ");
        break;
      case 'H':
        strcat(output, "Hissing detected, ");
        break;
      case 'T':
        strcat(output, "Tailing detected, ");
        break;
      case 'C':
        strcat(output, "Clawing detected, ");
        break;
      case 'A':
        if (input[i+1] == 'T')
        {
          strcat(output, "Attacking detected, ");
          i++;
        }
        else if (input[i+1] == 'U')
        {
          strcat(output, "Auburn detected, ");
          i++;
        }
        else
        {
          strcat(output, "Adorable detected, ");
        }
        break;
      case 'R':
        strcat(output, "Relaxing detected, ");
        break;
      case 'N':
        strcat(output, "Napping detected, ");
        break;
      default:
        break;
    }
  }

  printf("Converted to English: %s\n", output);

  return 0;
}