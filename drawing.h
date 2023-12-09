#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define M_PI 3.14159265358979323846


typedef unsigned char byte;

typedef struct
{
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
} TGAHeader;

typedef struct
{
    byte blue;
    byte green;
    byte red;
    byte alpha;
} Pixel;
void vykreslovani(Pixel* pixels, int width, int height, char *command);
void swapInt(int *a, int *b);
void saveTGA(const char *filename, int width, int height, Pixel *pixels);
void clear(int width, int height, Pixel *pixels);
void drawLine(int x1, int y1, int x2, int y2, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a);
void drawRectangle(int x, int y, int width, int height, int imgWidth, int imgHeight, Pixel *pixels, byte r, byte g, byte b, byte a);
void drawCircle(int centerX, int centerY, int radius, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a);
void drawTriangle(int centerX, int centerY, int sideLength, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a);
void drawFilledEquilateralTriangle(int centerX, int centerY, int sideLength, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a);
void drawRotatedRectangle(float angle, int x, int y, int width, int height, int imgWidth, int imgHeight, Pixel *pixels, byte r, byte g, byte b, byte a);


