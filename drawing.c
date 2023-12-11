#include "drawing.h"
#define MAX_ARGUMENT_COUNT 9

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// ukladani TGA souboru
void saveTGA(const char *filename, int width, int height, Pixel *pixels)
{

    FILE *tgaFile = fopen(filename, "wb");
    if (tgaFile == NULL) {
        printf("Chyba při otevírání souboru.\n");
        exit(1);
    }

    TGAHeader header = {
        .id_length = 0,
        .color_map_type = 0,
        .image_type = 2,
        .color_map = {0, 0, 0, 0, 0},
        .x_origin = {0, 0},
        .y_origin = {0, 0},
        .width = {width & 0xFF, (width >> 8) & 0xFF},
        .height = {height & 0xFF, (height >> 8) & 0xFF},
        .depth = 32,
        .descriptor = 8};

    fwrite(&header, sizeof(TGAHeader), 1, tgaFile);

    for (int i = 0; i < width * height; ++i)
    {
        fwrite(&pixels[i].blue, sizeof(byte), 1, tgaFile);
        fwrite(&pixels[i].green, sizeof(byte), 1, tgaFile);
        fwrite(&pixels[i].red, sizeof(byte), 1, tgaFile);
        fwrite(&pixels[i].alpha, sizeof(byte), 1, tgaFile);
    }

    fclose(tgaFile);
}
// vycisteni platna
void clear(int width, int height, Pixel *pixels){
     for (int i = 0; i < width * height; ++i)
    {
        pixels[i].red = 0;
        pixels[i].green = 0;
        pixels[i].blue = 0;
        pixels[i].alpha = 255;
    }
}

void vykreslovani(Pixel* pixels, int width, int height, char *command){
    char* tvar;
        tvar = strtok(command, " ");
        //          nacteni parametru tvaru
        int par[MAX_ARGUMENT_COUNT];
        for(int i=0;i<MAX_ARGUMENT_COUNT;i++){
            par[i]=-1;
        }
        //          nacitani argumentu jednotlivych tvaru
        char *token; 
        for(int i=0;i<MAX_ARGUMENT_COUNT;i++){
            token=strtok(NULL, ",");
            if(token!=NULL){
                par[i]=atoi(token);
            }
        }
        //          kontrola parametru a vykonani funkce
        if(strcmp(tvar, "line")==0){
             if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[7]<0||par[4]>255||par[5]>255||par[6]>255||par[7]>255){
                printf("\033[91mNeplatné argumeny funkce line!\tPoužití viz. README soubor\n");
                printf("\033[36mline x1,y1,x2,y2,r,g,b,a\033[91m\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawLine(par[0], par[1], par[2], par[3], width, height, pixels, par[4], par[5], par[6], par[7]);
            }
        }else if(strcmp(tvar, "rectangle") == 0){
             if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[7]<0||par[4]>255||par[5]>255||par[6]>255||par[7]>255){
                printf("\033[91mNeplatné argumeny funkce rectangle!\tPoužití viz. README. soubor\n");
                printf("\033[36mrectangle x,y,width,height,r,g,b,a\033[91m\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawRectangle(par[0], par[1], par[2], par[3], width, height, pixels, par[4], par[5], par[6], par[7]);
            }
        }else if(strcmp(tvar, "circle")==0){
            if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[3]>255||par[4]>255||par[5]>255||par[6]>255){
                printf("\033[91mNeplatné argumeny funkce circle!\tPoužití viz. README soubor\n");
                printf("\033[36mcircle x,y,radius,r,g,b,a\033[91m\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawCircle(par[0], par[1], par[2], width, height, pixels, par[3], par[4], par[5], par[6]);
            }
        }else if(strcmp(tvar, "triangle")==0){
            if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[3]>255||par[4]>255||par[5]>255||par[6]>255){
                printf("\033[91mNeplatné argumeny funkce triangle!\tPoužití viz. README soubor\n");
                printf("\033[36mtriangle x,y,width,r,g,b,a\033[91m\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawTriangle(par[0], par[1], par[2], width, height, pixels, par[3], par[4], par[5], par[6]);
            }
        }else if(strcmp(tvar, "rotated-rectangle") == 0){
            if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[7]<0||par[8]<0||par[5]>255||par[6]>255||par[7]>255||par[8]>255){
                printf("\033[91mNeplatné argumeny funkce rotated-rectangle!\tPoužití viz. README soubor\n");
                printf("\033[36mrotated-rectangle angle,x,y,width,height,r,g,b,a\033[91m\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawRotatedRectangle(par[0], par[1], par[2], par[3], par[4], width, height, pixels, par[5], par[6], par[7], par[8]);
            }
        }else {
            printf("\033[91mNesprávný příkaz!\n");
            printf("Použití viz. README soubor\033[39m\n");
        }
}

void drawLine(int x1, int y1, int x2, int y2, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a)
{   
    
    float alpha = a / 255.0;
    // Bresenhamův algoritmus.
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        // osetreni kresleni mimo platno
        if (x1 >= 0 && x1 < width && height - 1 - y1 >= 0 && height - 1 - y1 < height) // Změna zde
        {
            int index = (height - 1 - y1) * width + x1;
            pixels[index].red = alpha * r + (1.0 - alpha) * pixels[index].red;
            pixels[index].green = alpha * g + (1.0 - alpha) * pixels[index].green;
            pixels[index].blue = alpha * b + (1.0 - alpha) * pixels[index].blue;
            pixels[index].alpha = 255;
        }

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
  
}

void drawRectangle(int x, int y, int width, int height, int imgWidth, int imgHeight, Pixel *pixels, byte r, byte g, byte b, byte a)
{
    for (int i = 0; i < height; i++)
    {
        drawLine(x, y + i, x + width - 1, y + i, imgWidth, imgHeight, pixels, r, g, b, a);
    }   
}

void drawCircle(int centerX, int centerY, int radius, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a)
{   
    float alpha = a / 255.0;
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int dx = x - centerX;
            int dy = centerY - y; // Změna zde

            if (dx * dx + dy * dy <= radius * radius)
            {
                int index = (height - 1 - y) * width + x; // Změna zde
                pixels[index].red = alpha * r + (1.0 - alpha) * pixels[index].red;
                pixels[index].green = alpha * g + (1.0 - alpha) * pixels[index].green;
                pixels[index].blue = alpha * b + (1.0 - alpha) * pixels[index].blue;
                pixels[index].alpha = 255;
            }
        }
    }
}

void drawTriangle(int centerX, int centerY, int sideLength, int width, int height, Pixel *pixels, byte r, byte g, byte b, byte a)
{
    float alpha = a / 255.0;
    float halfHeight = sideLength * sqrt(3) / 2.0;
    float halfSide = sideLength / 2.0;
    
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // Transform pixel coordinates to triangle coordinates
            float tx = x - centerX;
            float ty = centerY - y +(halfHeight/2.5);

            // Check if the pixel is inside the equilateral triangle
            if (tx >= -halfSide && tx <= halfSide &&
                ty >= 0 && ty <= halfHeight &&
                ty <= -sqrt(3) * tx + sideLength * sqrt(3) / 2.0 &&
                ty <= sqrt(3) * tx + sideLength * sqrt(3) / 2.0)
            {
                int index = (height - 1 - y) * width + x;
                pixels[index].red = alpha * r + (1.0 - alpha) * pixels[index].red;
                pixels[index].green = alpha * g + (1.0 - alpha) * pixels[index].green;
                pixels[index].blue = alpha * b + (1.0 - alpha) * pixels[index].blue;
                pixels[index].alpha = 255;
            }
        }
    }
}

void drawRotatedRectangle(float angle, int x, int y, int width, int height, int imgWidth, int imgHeight, Pixel *pixels, byte r, byte g, byte b, byte a)
{   

    float alpha = a / 255.0;

    // prevod na radiany
    angle=(int)angle%360;
    angle=360-angle;
    float radians = angle * M_PI / 180.0;

    float centerX = x + (width / 2.0);
    float centerY = y + (height / 2.0);

    
    for (int i = x; i < x + width; ++i)
    {
        for (int j = y; j < y + height; ++j)
        {
            // rotace...
            float translatedX = i - centerX;
            float translatedY = centerY - j;

            
            float rotatedX = translatedX * cos(radians) - translatedY * sin(radians);
            float rotatedY = translatedX * sin(radians) + translatedY * cos(radians);

            
            int rotatedPixelX = rotatedX + centerX - (width / 2.0);
            int rotatedPixelY = rotatedY + centerY - (height / 2.0);

            // Kontrola zapisu mimo obrazek...
            if (rotatedPixelX >= 0 && rotatedPixelX < imgWidth && rotatedPixelY >= 0 && rotatedPixelY < imgHeight)
            {
                // Update the pixel color
                int index = (imgHeight - 1 - rotatedPixelY) * imgWidth + rotatedPixelX;
                pixels[index].red = alpha * r + (1.0 - alpha) * pixels[index].red;
                pixels[index].green = alpha * g + (1.0 - alpha) * pixels[index].green;
                pixels[index].blue = alpha * b + (1.0 - alpha) * pixels[index].blue;
                pixels[index].alpha = 255;
            }
        }
    }
}
