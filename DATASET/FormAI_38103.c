//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100], output[100];
    printf("Enter the text: ");
    fgets(input, 100, stdin);

    int length = 0;
    while (input[length] != '\n') {
        length++;
    }

    int i, j;
    for (i = 0; i < length; i++) {
        char ch = input[i];
        switch(ch) {
            case 'a': printf(",%%%%%%%%,\n%%/\033[1;32ma\033[0m%%%%%%/\n%/   \033[1;32ma\033[0m   %%\n'%%%%%%%%%%'\n");
                      break;
            case 'b': printf("%%%%%%%%\n%  \033[1;32mb\033[0m  %%\n%%%%%%%%\n%  \033[1;32mb\033[0m  %%\n%%%%%%%%\n");
                      break;
            case 'c': printf(" ,%%%%%%, \n%%C    %%\n%%     \n%%C    %%\n '%%%%%%'\n");
                      break;
            case 'd': printf("%%%%%%%\n%  \033[1;32md\033[0m  %%\n%  \033[1;32md\033[0m  %%\n%%%%%%%\n");
                      break;
            case 'e': printf("%%%%%%%%\n%  \033[1;32me\033[0m  \n%%%%%%%%\n%  \033[1;32me\033[0m  \n%%%%%%%%\n");
                      break;
            case 'f': printf("%%%%%%%%\n%  \033[1;32mf\033[0m  \n%%%%%%%%\n%  \n%\n");
                      break;
            case 'g': printf(" ,%%%%%%, \n%%G    %%\n%%  %%%%%\n%%    %%%\n '%%%%%%o'\n");
                      break;
            case 'h': printf("%%%   %%\n%  \033[1;32mh\033[0m  %%\n%%%%%%%%\n%  \033[1;32mh\033[0m  %%\n%%%   %%\n");
                      break;
            case 'i': printf("%%%%%%\n  %\033[1;32mi\033[0m  \n  %\033[1;32mi\033[0m  \n%%%%%%\n");
                      break;
            case 'j': printf("%%%%%%o\n    %\n%%%%%%%\n%   \033[1;32mj\033[0m  %%\n '%%%%%%'\n");
                      break;
            case 'k': printf("%%%  \n%  \033[1;32mk\033[0m   \n%%%%%%\n%  \033[1;32mk\033[0m  %%\n%%%   %%\n");
                      break;
            case 'l': printf("%\n%  \n%  \n%  \n%%%%%%%%\n");
                      break;
            case 'm': printf("MMMMMMMM\n%%%%%%  %%\n%% @@ %% %%\n%%_@@_%%%_\n%%     %%\n");
                      break;
            case 'n': printf("N     %%\n%  \\% \033[1;32mn\033[0m%%\n%%%%%%%%\n%  \\%%%\033[1;32mn\033[0m\n%    N%%\n");
                      break;
            case 'o': printf(" ,%%%%%%, \n%%O    %%\n%%    %%\n%%O   %% \n '%%%%%%'\n");
                      break;
            case 'p': printf("%%%%%%%\n%  \033[1;32mp\033[0m  %%\n%%%%%%%\n%     \n%\n");
                      break;
            case 'q': printf(" ,%%%%%%, \n%%Q    %%\n%%    %%\n%%Q   %% \n '%%%%%%%\\_\n");
                      break;
            case 'r': printf("%%%%%%%\n%  \033[1;32mr\033[0m  %%\n%%%%%%%\n%   \\%%\n%    \\%\n");
                      break;
            case 's': printf("%%%%%%%%\n%  \033[1;32ms\033[0m  \n%%%%%%%%\n       %\n%%%%%%%%\n");
                      break;
            case 't': printf("%%%%%%%\n  %\n  %\033[1;32mt\033[0m  \n  %\n  %\n");
                      break;
            case 'u': printf("UU    UU\nUU    UU\nUU    UU\nUUuuuuUU\n '%%%%%%'\n");
                      break;
            case 'v': printf("VV    VV\nVV    VV\n  VV VV \n   VVV  \n    V   \n");
                      break;
            case 'w': printf("WWWWWWWWWW\nWW    WW  \nWW @@ WW %% \nWW @@ WW %% \n WWWWWWWW  \n");
                      break;
            case 'x': printf("XX    XX\n XX  XX \n   XX   \n XX  XX \nXX    XX\n");
                      break;
            case 'y': printf("YY    YY\nYY    YY\n YYYYYY  \n    YY  \nYYYYYY  \n");
                      break;
            case 'z': printf("ZZZZZZZZ\n      %\033[1;32mz\033[0m\n    %%  \n  %%    \n%%%%%%%%\n");
                      break;
            case ' ': printf("\n");
                      break;
            default: printf("Invalid character\n");
                     exit(0);
        }
    }

    return 0;
}