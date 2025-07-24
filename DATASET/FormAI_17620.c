//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    strcpy(input, "ASCII art");

    int height = 10;
    int width = strlen(input) * 5;

    char *output = (char *)malloc((height * width + height + 1) * sizeof(char));
    output[0] = '\0';

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
            {
                strcat(output, "#");
            }
            else
            {
                int index = (j - 1) / 5;
                if (index < strlen(input))
                {
                    char c = input[index];
                    switch (i % 5)
                    {
                        case 0:
                        case 4:
                            strcat(output, "#####");
                            break;
                        case 1:
                            strcat(output, "#   #");
                            break;
                        case 2:
                            switch (j % 5)
                            {
                                case 1:
                                case 3:
                                    strcat(output, "#   #");
                                    break;
                                case 2:
                                    strcat(output, "  ");
                                    strcat(output, &c);
                                    strcat(output, "  ");
                                    break;
                                default:
                                    strcat(output, "     ");
                                    break;
                            }
                            break;
                        case 3:
                            switch (j % 5)
                            {
                                case 1:
                                    strcat(output, "#   #");
                                    break;
                                case 2:
                                    strcat(output, "  ");
                                    strcat(output, &c);
                                    strcat(output, "  ");
                                    break;
                                case 3:
                                    strcat(output, "#   #");
                                    break;
                                default:
                                    strcat(output, "     ");
                                    break;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        strcat(output, "\n");
    }

    printf("%s", output);
    free(output);

    return 0;
}