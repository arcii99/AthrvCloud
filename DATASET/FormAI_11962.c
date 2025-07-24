//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>

int main(void) {
    char input_string[100];
    printf("Enter your string: ");
    fgets(input_string, sizeof(input_string), stdin);

    printf("\nHere is your string in ASCII art:\n");

    int index = 0;
    while (input_string[index] != '\0') {
        switch (input_string[index]) {
            case 'A':
                printf("###  \n#  # \n#  # \n#### \n#  # \n#  # \n#  # \n\n");
                break;

            case 'B':
                printf("###  \n#  # \n#  # \n#### \n#  # \n#  # \n###  \n\n");
                break;

            case 'C':
                printf(" ### \n#    \n#    \n#    \n#    \n#    \n ### \n\n");
                break;

            case 'D':
                printf("###  \n#  # \n#  # \n#  # \n#  # \n#  # \n###  \n\n");
                break;

            case 'E':
                printf("#### \n#    \n#    \n#### \n#    \n#    \n#### \n\n");
                break;

            case 'F':
                printf("#### \n#    \n#    \n#### \n#    \n#    \n#    \n\n");
                break;

            case 'G':
                printf(" ### \n#    \n#    \n#  ##\n#  # \n#  # \n ## #\n\n");
                break;

            case 'H':
                printf("#  # \n#  # \n#  # \n#### \n#  # \n#  # \n#  # \n\n");
                break;

            case 'I':
                printf("###  \n ##  \n ##  \n ##  \n ##  \n ##  \n###  \n\n");
                break;

            case 'J':
                printf("    #\n    #\n    #\n    #\n    #\n#   #\n ### \n\n");
                break;

            case 'K':
                printf("#  # \n# #  \n##   \n# #  \n#  # \n#  # \n#  # \n\n");
                break;

            case 'L':
                printf("#    \n#    \n#    \n#    \n#    \n#    \n#### \n\n");
                break;

            case 'M':
                printf("#  # \n## ##\n# ## \n#    \n#    \n#    \n#    \n\n");
                break;

            case 'N':
                printf("#  # \n## # \n# ## \n#  # \n#  # \n#  # \n#  # \n\n");
                break;

            case 'O':
                printf(" ### \n#  # \n#  # \n#  # \n#  # \n#  # \n ### \n\n");
                break;

            case 'P':
                printf("###  \n#  # \n#  # \n###  \n#    \n#    \n#    \n\n");
                break;

            case 'Q':
                printf(" ### \n#  # \n#  # \n#  # \n#  # \n# #  \n ## #\n\n");
                break;

            case 'R':
                printf("###  \n#  # \n#  # \n###  \n# #  \n#  # \n#  # \n\n");
                break;

            case 'S':
                printf(" ### \n#    \n#    \n ### \n    #\n    #\n ### \n\n");
                break;

            case 'T':
                printf("#####\n  #  \n  #  \n  #  \n  #  \n  #  \n  #  \n\n");
                break;

            case 'U':
                printf("#  # \n#  # \n#  # \n#  # \n#  # \n#  # \n ### \n\n");
                break;

            case 'V':
                printf("#  # \n#  # \n#  # \n#  # \n# #  \n##   \n#    \n\n");
                break;

            case 'W':
                printf("#    \n#    \n#    \n#    \n# ## \n## ##\n#  # \n\n");
                break;

            case 'X':
                printf("#  # \n#  # \n#  # \n ##  \n#  # \n#  # \n#  # \n\n");
                break;

            case 'Y':
                printf("#  # \n#  # \n#  # \n ##  \n  #  \n  #  \n  #  \n\n");
                break;

            case 'Z':
                printf("#####\n    #\n   # \n  #  \n #   \n#    \n#####\n\n");
                break;

            case ' ':
                printf("    \n    \n    \n    \n    \n    \n    \n\n");
                break;

            default:
                printf("INVALID CHARACTER\n");
        }

        index++;
    }

    return 0;
}