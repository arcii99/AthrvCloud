//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Romeo and Juliet
// Romeo and Juliet Fractal Generation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int i, j, n = 800, color;
    double xmin = -2.0, xmax = 1.0, ymin = -1.5, ymax = 1.5, cre, cim, zre, zim, new_zre;
    double x, y, scalex, scaley;

    printf("Oh Romeo, shall we generate a beautiful fractal image?\n");
    printf("Aye my Juliet, let us begin!\n");

    FILE *fp;
    fp = fopen("romeo_juliet_fractal.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n255\n", n, n);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cre = xmin + (xmax-xmin)*i/n;
            cim = ymin + (ymax-ymin)*j/n;
            zre = zim = 0.0;
            color = 0;

            while(color < 256 && zre*zre + zim*zim < 4.0)
            {
                new_zre = zre*zre - zim*zim + cre;
                zim = 2.0*zre*zim + cim;
                zre = new_zre;
                color += 3;
            }

            unsigned char rgb[3];
            rgb[0] = color % 256;
            rgb[1] = (color+80) % 256;
            rgb[2] = (color+200) % 256;

            scalex = (xmax - xmin)/n;
            scaley = (ymax - ymin)/n;

            x = xmin + i*scalex;
            y = ymin + j*scaley;

            if(rand()%5 == 0)
            {
                rgb[0] = 255;
                rgb[1] = 0;
                rgb[2] = 0;
                fprintf(fp, "%c%c%c", rgb[0], rgb[1], rgb[2]);
                continue;
            }

            if(x < -0.5 && x > -1.0 && y < 0.0 && y > -0.5)
            {
                rgb[0] = 255;
                rgb[1] = 0;
                rgb[2] = 0;
            }

            if(x > 0.5 && x < 1.0 && y < 0.0 && y > -0.5)
            {
                rgb[0] = 255;
                rgb[1] = 0;
                rgb[2] = 0;
            }

            if(y > 0.5 && y < 1.0 && x < 0.0 && x > -0.5)
            {
                rgb[0] = 255;
                rgb[1] = 0;
                rgb[2] = 0;
            }

            if(y < -0.5 && y > -1.0 && x < 0.0 && x > -0.5)
            {
                rgb[0] = 255;
                rgb[1] = 0;
                rgb[2] = 0;
            }

            fprintf(fp, "%c%c%c", rgb[0], rgb[1], rgb[2]);
        }
    }

    fclose(fp);

    printf("Oh Romeo, the image is complete!\n");
    printf("My Juliet, let us view it together!\n");

    return 0;
}