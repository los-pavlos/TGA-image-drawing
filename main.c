#include "drawing.h"

int main(int argc, char *argv[])
{
    const char *outputFilename = NULL;
    int width = -1;
    int height = -1;
    //                                                      Zpracovani parametru funkce main
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--output") == 0 && i + 1 < argc)
        {
            outputFilename = argv[i + 1];
            i++;
        }
        else if (strcmp(argv[i], "--width") == 0 && i + 1 < argc)
        {
            width = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "--height") == 0 && i + 1 < argc)
        {
            height = atoi(argv[i + 1]);
            i++;
        }
        else
        {
            printf("\033[91mChybné či nadbytečné parametry.\n");
            printf("Použití: %s --output <cesta k souboru> --width <cislo> --height <cislo>\033[39m\n", argv[0]);
            return 1;
        }
    }

    if (outputFilename == NULL || width == -1 || height == -1)
    {
        printf("\033[91mChybějící nebo chybně zadávající parametry.\n");
        printf("Použití: %s --output <cesta k souboru> --width <cislo> --height <cislo>\033[39m\n", argv[0]);
        return 1;
    }

    if (width <= 0 || height <= 0)
    {
        printf("Neplatné rozměry. Šířka a výška musí být kladná celá čísla.\n");
        return 1;
    }
    //  vytvoreni pixelů
    Pixel *pixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    //  default color - black
    clear(width,height,pixels);
    //  prikazy od uzivatele
    char command[101] = {};
    char *token;
    while (1)
    {
        fgets(command, 101, stdin);
        //  exit, save, clear
        if (strcmp(command, "exit\n") == 0)
        {
            saveTGA(outputFilename, width, height, pixels);
            free(pixels);     
            return 0;
        }
        else if (strcmp(command, "save\n") == 0)    
        {
            saveTGA(outputFilename, width, height, pixels);
        }else if (strcmp(command, "clear\n") == 0){
            clear(width,height,pixels);
        }else{
            //  vykreslovani tvarů
            vykreslovani(pixels,width,height,command);
        }
    }
}