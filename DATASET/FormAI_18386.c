//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
/*Cryptic Pixel Art Generator*/
#include<stdio.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int i,j,k,l,t,m,n,o,x,y,a,b,c,d,e,f,g,h;
    char pixel[16][16];
    printf("Welcome to the Cryptic Pixel Art Generator!\n");
    printf("Generating Pixel Art...\n");
    for(i=0;i<16;i++){
        for(j=0;j<16;j++){
            pixel[i][j] = '.';
        }
    }
    for(k=0;k<4;k++){
        t = rand()%16;
        m = rand()%16;
        n = rand()%16;
        o = rand()%16;
        for(l=0;l<16;l++){
            pixel[l][t] = '=';
            pixel[t][l] = '=';
            pixel[l][m] = '?';
            pixel[m][l] = '?';
            pixel[l][n] = '*';
            pixel[n][l] = '*';
            pixel[l][o] = '#';
            pixel[o][l] = '#';
        }
    }
    for(x=0;x<2;x++){
        a = rand()%16;
        b = rand()%16;
        c = rand()%16;
        d = rand()%16;
        for(y=0;y<16;y++){
            pixel[y][a] = '|';
            pixel[a][y] = '|';
            pixel[y][b] = '.';
            pixel[b][y] = '.';
            pixel[y][c] = '+';
            pixel[c][y] = '+';
            pixel[y][d] = '-';
            pixel[d][y] = '-';
        }
    }
    printf("Your Cryptic Pixel Art:\n\n");
    for(e=0;e<16;e++){
        for(f=0;f<16;f++){
            printf("%c ", pixel[e][f]);
        }
        printf("\n");
    }
    printf("\nHave fun deciphering the art!\n");
    return 0;
}