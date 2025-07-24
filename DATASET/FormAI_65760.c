//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define CHAR_SIZ 7
#define CHAR_NUM 95

char ascii_art[CHAR_NUM][CHAR_SIZ][MAX_LEN] =
{
   "   \n   \n   \n   \n   \n   \n   \n", // space
   "   #   \n  # #  \n #   # \n#######\n#     #\n       \n       \n", // A
   " ####  \n#    # \n###### \n#    # \n###### \n       \n       \n", // B
   " ##### \n#     #\n#      \n#     #\n ##### \n       \n       \n", // C
   "####   \n#   #  \n#    # \n#   #  \n####   \n       \n       \n", // D
   "#######\n#      \n#####  \n#      \n#######\n       \n       \n", // E
   "#######\n#      \n#####  \n#      \n#      \n       \n       \n", // F
   " ######\n#      \n#  ### \n#    # \n ##### \n       \n       \n", // G
   "#     #\n#     #\n#######\n#     #\n#     #\n       \n       \n", // H
   " ##### \n   #   \n   #   \n   #   \n ##### \n       \n       \n", // I
   "   ### \n     # \n     # \n#    # \n ####  \n       \n       \n", // J
   "#     #\n#   #  \n###    \n#   #  \n#     #\n       \n       \n", // K
   "#      \n#      \n#      \n#      \n#######\n       \n       \n", // L
   "#     #\n##   ##\n# # # #\n#  #  #\n#     #\n       \n       \n", // M
   "#     #\n##    #\n# #   #\n#  #  #\n#   ## \n       \n       \n", // N
   " ##### \n#     #\n#     #\n#     #\n ##### \n       \n       \n", // O
   "###### \n#     #\n###### \n#      \n#      \n       \n       \n", // P
   " ##### \n#     #\n#  #  #\n#   # \n ## ## \n       \n       \n", // Q
   "###### \n#     #\n###### \n#   #  \n#    # \n       \n       \n", // R
   " ######\n#      \n ##### \n      #\n###### \n       \n       \n", // S
   "#######\n   #   \n   #   \n   #   \n   #   \n       \n       \n", // T
   "#     #\n#     #\n#     #\n#     #\n ##### \n       \n       \n", // U
   "#     #\n#     #\n #   # \n  # #  \n   #   \n       \n       \n", // V
   "#     #\n#     #\n#  #  #\n#     #\n ## ## \n       \n       \n", // W
   "#     #\n #   # \n  # #  \n #   # \n#     #\n       \n       \n", // X
   "#     #\n #   # \n  # #  \n   #   \n   #   \n       \n       \n", // Y
   "#######\n     # \n   #   \n #     \n#######\n       \n       \n", // Z
   "  ##   \n #  #  \n    #  \n   #   \n ##    \n       \n       \n", // [
   " #     \n  #    \n   #   \n  #    \n #     \n       \n       \n", // '\'
   "##     \n  #    \n   #   \n    #  \n##     \n       \n       \n", // ]
   "  #    \n   #   \n ##### \n   #   \n  #    \n       \n       \n", // ^
   "       \n       \n       \n       \n###### \n       \n       \n", // _
   "   #   \n  #    \n #     \n#      \n#      \n       \n       \n", // `
   "       \n ####  \n     # \n ##### \n#     #\n       \n       \n", // a
   "      #\n ####  \n#    # \n#    # \n ####  \n       \n       \n", // b
   "       \n ####  \n#      \n#      \n ####  \n       \n       \n", // c
   "     # \n ####  \n#    # \n#    # \n ####  \n       \n       \n", // d
   "       \n ##### \n# #### \n##     \n ##### \n       \n       \n", // e
   "  ###  \n #  #  \n#####  \n #     \n #     \n       \n       \n", // f
   "       \n ##### \n#    # \n ##### \n     # \n####   \n       \n", // g
   "#      \n ####  \n#    # \n#    # \n#    # \n       \n       \n", // h
   "   #   \n       \n  #    \n  #    \n  #    \n       \n       \n", // i
   "    #  \n       \n   #   \n   #   \n####   \n       \n       \n", // j
   "#      \n#   #  \n###    \n#   #  \n#    # \n       \n       \n", // k
   "  #    \n  #    \n  #    \n  #    \n   ##  \n       \n       \n", // l
   "       \n ## ## \n# # # #\n# # # #\n# # # #\n       \n       \n", // m
   "       \n ####  \n#    # \n#    # \n#    # \n       \n       \n", // n
   "       \n ####  \n#    # \n#    # \n ####  \n       \n       \n", // o
   "       \n ####  \n#    # \n#    # \n ####  \n#      \n#      \n", // p
   "       \n ##### \n#    # \n#    # \n ##### \n     # \n     # \n", // q
   "       \n # ##  \n##  #  \n#      \n#      \n       \n       \n", // r
   "       \n ##### \n#      \n ##### \n     # \n#####  \n       \n", // s
   "   #   \n ##### \n   #   \n   #   \n ###   \n       \n       \n", // t
   "       \n#    # \n#    # \n#    # \n ####  \n       \n       \n", // u
   "       \n#    # \n #  #  \n  ##   \n  #    \n       \n       \n", // v
   "       \n#     #\n#     #\n #   # \n  ###  \n       \n       \n", // w
   "       \n#    # \n ## #  \n   #   \n##   # \n       \n       \n", // x
   "       \n#    # \n #  #  \n  ##   \n  #    \n  #    \n #     \n", // y
   "       \n#######\n    #  \n   #   \n#######\n       \n       \n", // z
   "  ##   \n #     \n #     \n#      \n #     \n  ##   \n       \n", // {
   "  #    \n  #    \n  #    \n       \n  #    \n  #    \n  #    \n", // |
   "##     \n  #    \n  #    \n   #   \n  #    \n##     \n       \n", // }
   "  ##   \n ##    \n# ##   \n    ## \n   ##  \n       \n       \n", // ~
};

/* Shifts the output vertically based on the user input */
void vshift(char* string, int col_offset)
{
    int i = 0, j = 0;
    char res[MAX_LEN] = { 0 };
    while (i < strlen(string))
    {
        if (string[i] == '\n')
            j = 0;
        else
            j++;
        if (j + col_offset >= 0 && j + col_offset < MAX_LEN)
            res[i] = string[i + col_offset];
        else
            res[i] = ' ';
        i++;
    }
    strcpy(string, res);
}

/* Shifts the output horizontally based on the user input */
void hshift(char* string, int row_offset)
{
    char arr[MAX_LEN][MAX_LEN] = { !0 };
    int i = 0, j = 0, k = 0;
    while (i < strlen(string))
    {
        if (string[i] == '\n')
        {
            arr[j][k] = 0;
            j++;
            k = 0;
        }
        else
        {
            arr[j][k] = string[i];
            k++;
        }
        i++;
    }

    char res[MAX_LEN] = { 0 };
    for (int i = 0; i < strlen(string); i++)
    {
        int diff = i / CHAR_SIZ;
        int row = i % CHAR_SIZ;
        if (res[i] == '\n' || arr[row][diff + row_offset] == 0 || diff + row_offset >= MAX_LEN || diff + row_offset < 0)
            res[i] = '\n';
        else
            res[i] = arr[row][diff + row_offset];
    }

    strcpy(string, res);
}

/* Outputs the specified string in ASCII art */
void print_ascii(char* str)
{
    int len = strlen(str);
    int size = len * CHAR_SIZ + len - 1;

    char result[MAX_LEN] = { 0 };
    for (int i = 0; i < len; i++)
    {
        if (!isprint(str[i]))
            str[i] = ' ';
        if (!islower(str[i]))
            str[i] = tolower(str[i]);
        if (i == 0)
            strcpy(result, ascii_art[(int)str[i] - 32][0]);
        else
            strcat(result, ascii_art[(int)str[i] - 32][0]);
        if (i < len - 1)
            strcat(result, "\n");
    }

    vshift(result, -1 * size / 2);
    hshift(result, size / 2);

    printf("%s\n", result);
}

/* Main program */
int main()
{
    char input[MAX_LEN];
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);
    printf("\nASCII ART:\n\n");
    print_ascii(input);
    return 0;
}