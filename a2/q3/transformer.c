#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int r, g, b;
} Pixel;

typedef struct {
    int width, height, max;
    Pixel **pixels;
} Image;

Image *read_image() {
    Image *img = malloc(sizeof(Image));
    char magic[3];
    scanf("%s", magic);
    scanf("%d %d", &img->width, &img->height);
    scanf("%d", &img->max);
    
    img->pixels = malloc(img->height * sizeof(Pixel *));
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = malloc(img->width * sizeof(Pixel));
        for (int j = 0; j < img->width; j++) {
            scanf("%d %d %d", &img->pixels[i][j].r,
                              &img->pixels[i][j].g,
                              &img->pixels[i][j].b);
        }
    }
    return img;
}

void apply_sepia(Image *img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int r = img->pixels[i][j].r;
            int g = img->pixels[i][j].g;
            int b = img->pixels[i][j].b;
            
            int newR = (int)(r * 0.393 + g * 0.769 + b * 0.189);
            int newG = (int)(r * 0.349 + g * 0.686 + b * 0.168);
            int newB = (int)(r * 0.272 + g * 0.534 + b * 0.131);
            
            img->pixels[i][j].r = newR > 255 ? 255 : newR;
            img->pixels[i][j].g = newG > 255 ? 255 : newG;
            img->pixels[i][j].b = newB > 255 ? 255 : newB;
        }
    }
}

void flip_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        int left = 0, right = img->width - 1;
        while (left < right) {
            Pixel temp = img->pixels[i][left];
            img->pixels[i][left] = img->pixels[i][right];
            img->pixels[i][right] = temp;
            left++;
            right--;
        }
    }
}

void print_image(Image *img) {
    printf("P3\n");
    printf("%d %d\n", img->width, img->height);
    printf("%d\n", img->max);
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            printf("%d %d %d ", img->pixels[i][j].r,
                               img->pixels[i][j].g,
                               img->pixels[i][j].b);
        }
        printf("\n");
    }
}

void free_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

int main(int argc, char *argv[]) {
    int do_flip = 0, do_sepia = 0;
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            do_flip = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            do_sepia = 1;
        }
    }
    
    Image *img = read_image();
    
    if (do_flip) flip_image(img);
    if (do_sepia) apply_sepia(img);
    
    print_image(img);
    free_image(img);
    
    return 0;
}