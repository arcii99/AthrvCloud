//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include<stdio.h>

void main()
{
    int height, width, maxcolor;
    int r,g,b,i,j;//for RGB value
    int newr,newg,newb;

    FILE * fp;
    FILE * fp1;

    fp=fopen("input_image.ppm","r");//open input image file
    fp1=fopen("output_image.ppm","w+");//open output image file

    fscanf(fp,"%*[^\n]%*c");
    fscanf(fp,"%*[^\n]%*c");
    fscanf(fp,"%d %d",&height, &width);
    fscanf(fp,"%d",&maxcolor);

    fprintf(fp1,"%s","P3\n"); //To write on Output ppm file.
    fprintf(fp1,"%d ",height);
    fprintf(fp1,"%d\n",width);
    fprintf(fp1,"%d\n",maxcolor);
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            fscanf(fp,"%d %d %d",&r,&g,&b);
            //setting brightness, contrast anything like that
            newr=r-50;
            newg=g-45;
            newb=b-40;
            
            if(newr<0 || newg<0 || newb<0)//if RGB goes negative
            {
            newr=0;
            newg=0;
            newg=0;
            }
            fprintf(fp1,"%d ",newr);
            fprintf(fp1,"%d ",newg);
            fprintf(fp1,"%d\n",newb);
        }
    }
    fclose(fp);
    fclose(fp1);
    printf("Your image has been processed successfully!!!\n");

}