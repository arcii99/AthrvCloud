//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: peaceful
#include<stdio.h>
#include<string.h>
int main()
{
    char input[100],morse[100];
    int i,j;
    printf("Enter text to convert to Morse code:\n");
    fgets(input,100,stdin);
    input[strcspn(input,"\n")]=0; //To remove trailing '\n' from input
    for(i=0;i<strlen(input);i++)
    {
        if(input[i]==' ')
            strcpy(morse+i*5,"       "); //Space between words is 7 dots in Morse code
        else
        {
            switch(input[i])
            {
                case 'A': strcpy(morse+i*5,".--   "); break;
                case 'B': strcpy(morse+i*5,"-...  "); break;
                case 'C': strcpy(morse+i*5,"-.-.  "); break;
                case 'D': strcpy(morse+i*5,"-..   "); break;
                case 'E': strcpy(morse+i*5,".     "); break;
                case 'F': strcpy(morse+i*5,"..-.  "); break;
                case 'G': strcpy(morse+i*5,"--.   "); break;
                case 'H': strcpy(morse+i*5,"....  "); break;
                case 'I': strcpy(morse+i*5,"..    "); break;
                case 'J': strcpy(morse+i*5,".---  "); break;
                case 'K': strcpy(morse+i*5,"-.-   "); break;
                case 'L': strcpy(morse+i*5,".-..  "); break;
                case 'M': strcpy(morse+i*5,"--    "); break;
                case 'N': strcpy(morse+i*5,"-.    "); break;
                case 'O': strcpy(morse+i*5,"---   "); break;
                case 'P': strcpy(morse+i*5,".--.  "); break;
                case 'Q': strcpy(morse+i*5,"--.-  "); break;
                case 'R': strcpy(morse+i*5,".-.   "); break;
                case 'S': strcpy(morse+i*5,"...   "); break;
                case 'T': strcpy(morse+i*5,"-     "); break;
                case 'U': strcpy(morse+i*5,"..-   "); break;
                case 'V': strcpy(morse+i*5,"...-  "); break;
                case 'W': strcpy(morse+i*5,".--   "); break;
                case 'X': strcpy(morse+i*5,"-..-  "); break;
                case 'Y': strcpy(morse+i*5,"-.--  "); break;
                case 'Z': strcpy(morse+i*5,"--..  "); break;
                case '0': strcpy(morse+i*5,"----- "); break;
                case '1': strcpy(morse+i*5,".---- "); break;
                case '2': strcpy(morse+i*5,"..--- "); break;
                case '3': strcpy(morse+i*5,"...-- "); break;
                case '4': strcpy(morse+i*5,"....- "); break;
                case '5': strcpy(morse+i*5,"..... "); break;
                case '6': strcpy(morse+i*5,"-.... "); break;
                case '7': strcpy(morse+i*5,"--... "); break;
                case '8': strcpy(morse+i*5,"---.. "); break;
                case '9': strcpy(morse+i*5,"----. "); break;
                default: strcpy(morse+i*5,"/?/   "); //For unsupported characters
            }
        }
    }
    printf("\nMorse code:\n%s\n",morse);
    return 0;
}