//FormAI DATASET v1.0 Category: Image Classification system ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int score;
} Image;

int compare_scores(const void *a, const void *b) {
    Image *Ia = (Image*)a;
    Image *Ib = (Image*)b;
    return (Ib->score - Ia->score);
}

int main() {
    int num_images = 5;
    Image images[num_images];
    images[0].name = "image1.jpg";
    images[0].score = 98;
    images[1].name = "image2.jpg";
    images[1].score = 83;
    images[2].name = "image3.jpg";
    images[2].score = 76;
    images[3].name = "image4.jpg";
    images[3].score = 92;
    images[4].name = "image5.jpg";
    images[4].score = 68;

    // print unsorted list
    printf("Unsorted list:\n");
    for (int i=0; i<num_images; i++) {
        printf("%s - Score: %d\n", images[i].name, images[i].score);
    }
    printf("\n");

    // sort by score (descending order)
    qsort(images, num_images, sizeof(Image), compare_scores);

    // print sorted list
    printf("Sorted list:\n");
    for (int i=0; i<num_images; i++) {
        printf("%s - Score: %d\n", images[i].name, images[i].score);
    }

    return 0;
}