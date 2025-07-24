//FormAI DATASET v1.0 Category: Image Editor ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

// Function to read Image Pixels and dimensions of the image
void readImg(int *img, int *height, int *width){
    FILE *file;
    char filename[100];
    printf("Enter the image file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fscanf(file, "%d", height);
    fscanf(file, "%d", width);
    for(int i=0; i<(*height)*(*width); i++){
        fscanf(file, "%d", &img[i]);
    }
    fclose(file);
}

// Function to save Image Pixels and dimensions of the image
void saveImg(int *img, int height, int width){
    FILE *file;
    char filename[100];
    printf("Enter the name of file to save the image: ");
    scanf("%s", filename);
    file = fopen(filename, "w");
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%d\n", height);
    fprintf(file, "%d\n", width);
    for(int i=0; i<height*width; i++){
        fprintf(file, "%d ", img[i]);
    }
    fclose(file);
}

int main(){
    int height, width;
    int *img;
    int choice, x1, y1, x2, y2, color;
    int maxval;
    int r, g, b;
    printf("*****IMAGE EDITOR*****\n");
    printf("\nChoose one option among below:-\n");
    printf("\n1. Create a Blank Image\n2. Read an Image from the File\n");
    scanf("%d", &choice);

    if(choice==1){ // Create a Blank Image
        printf("Enter the height and width of the image:\n");
        scanf("%d%d", &height, &width);
        img = (int*) calloc (height*width, sizeof(int)); // Allocating memory to a pointer
    }
    else if(choice==2){ // Read an Image from the File
        readImg(img, &height, &width);
    }
    else{
        printf("Invalid choice, Please choose either 1 or 2.\n");
        return 0;
    }

    // Maximum Gray scale value of the Image Pixels
    printf("\nEnter the maximum gray scale value of the image: ");
    scanf("%d", &maxval);

    do{
        printf("\nChoose an option:\n");
        printf("1. Display the Image\n");
        printf("2. Draw a line on the Image\n");
        printf("3. Fill a Color in the Image\n");
        printf("4. Save the Image as a File\n");
        printf("5. Exit\n\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("The image is:\n");
                for(int i=0; i<height*width; i++){
                    printf("%d ", img[i]);
                    if((i+1)%width == 0){
                        printf("\n");
                    }
                }
                printf("\n");
                break;

            case 2: // Draw a line on the Image
                printf("Enter the starting pixel coordinates of the line:\n");
                scanf("%d%d", &x1, &y1);
                printf("Enter the ending pixel coordinates of the line:\n");
                scanf("%d%d", &x2, &y2);
                printf("Enter the Gray Scale Value of the line: ");
                scanf("%d", &color);

                // Creating a line on Image
                for(int i=x1; i<=x2; i++){
                    int j = y1+((i-x1)*(y2-y1))/(x2-x1); // Formula to get corresponding y-coordinate value
                    img[i*width+j] = color;
                }
                break;

            case 3: // Fill a Color in the Image
                printf("Enter the pixel coordinates for the starting point of the fill operation:\n");
                scanf("%d%d", &x1, &y1);
                printf("Enter the RGB values (in the range of 0-255) to fill in the Image:\n");
                scanf("%d%d%d", &r, &g, &b);
                color = (r<<16) + (g<<8) + b; // Packing RGB values into a single 24bit number

                // Checking if the given coordinates are within the image boundary
                if(x1<0 || x1>=height || y1<0 || y1>=width){
                    printf("Invalid pixel coordinate value!\n");
                    break;
                }

                int oldColor = img[x1*width+y1]; // Storing the old pixel value

                // Pointer to store the points in the boundary
                int *boundary = (int*) calloc (height*width, sizeof(int)); 
                int top = 0, bottom = 0;

                if(oldColor != color){ // If the given color is different from the old color
                    boundary[bottom++] = x1*width+y1; // Adding the starting point to the boundary

                    // Boundary filling algorithm
                    while(top != bottom){
                        int currentPixel = boundary[top++];
                        if(img[currentPixel] == oldColor){
                            img[currentPixel] = color;
                            int x = currentPixel/width, y = currentPixel%width;
                            if(x>0 && img[(x-1)*width+y]==oldColor){
                                boundary[bottom++] = (x-1)*width+y;
                            }
                            if(x<height-1 && img[(x+1)*width+y]==oldColor){
                                boundary[bottom++] = (x+1)*width+y;
                            }
                            if(y>0 && img[x*width+y-1]==oldColor){
                                boundary[bottom++] = x*width+y-1;
                            }
                            if(y<width-1 && img[x*width+y+1]==oldColor){
                                boundary[bottom++] = x*width+y+1;
                            }
                        }
                    }
                }
                free(boundary);
                break;

            case 4: // Save the Image as a File
                saveImg(img, height, width);
                break;

            case 5: // Exit
                printf("Exiting the program!\n");
                free(img); // Freeing up the memory
                return 0;

            default:
                printf("Invalid choice, Please Choose a valid option.\n");
        }

    }while(choice != 5);
}