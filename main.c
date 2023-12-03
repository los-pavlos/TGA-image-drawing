#include "drawing.h"
#define MAX_ARGUMENT_COUNT 9

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
            printf("Chybné či nadbytečné parametry.\n");
            printf("Použití: %s --output <cesta k souboru> --width <cislo> --height <cislo>\n", argv[0]);
            return 1;
        }
    }

    if (outputFilename == NULL || width == -1 || height == -1)
    {
        printf("Chybějící nebo chybně zadávající parametry.\n");
        printf("Použití: %s --output <cesta k souboru> --width <cislo> --height <cislo>\n", argv[0]);
        return 1;
    }

    if (width <= 0 || height <= 0)
    {
        printf("Neplatné rozměry. Šířka a výška musí být kladná celá čísla.\n");
        return 1;
    }
    //                                                                    pixely + default cerna....
    Pixel *pixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    clear(width,height,pixels);
    char command[101] = {};
    char *token;
    while (1)
    {
        fgets(command, 101, stdin);
        //                                                                 exit, save
        if (strcmp(command, "exit\n") == 0)
        {
            saveTGA(outputFilename, width, height, pixels);
            free(pixels);
            return 0;
        }
        else if (strcmp(command, "save\n") == 0)
        {
            saveTGA(outputFilename, width, height, pixels);
        }else{
        //      strtok tvaru
        char* tvar;
        tvar = strtok(command, " ");
        //      nacteni parametru tvaru
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
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawLine(par[0], par[1], par[2], par[3], width, height, pixels, par[4], par[5], par[6], par[7]);
            }
        }else if(strcmp(tvar, "rectangle") == 0){
             if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[7]<0||par[4]>255||par[5]>255||par[6]>255||par[7]>255){
                printf("\033[91mNeplatné argumeny funkce rectangle!\tPoužití viz. README. soubor\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawRectangle(par[0], par[1], par[2], par[3], width, height, pixels, par[4], par[5], par[6], par[7]);
            }
        }else if(strcmp(tvar, "circle")==0){
            if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[3]>255||par[4]>255||par[5]>255||par[6]>255){
                printf("\033[91mNeplatné argumeny funkce circle!\tPoužití viz. README soubor\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawCircle(par[0], par[1], par[2], width, height, pixels, par[3], par[4], par[5], par[6]);
            }
        }else if(strcmp(tvar, "triangle")==0){
            if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[3]>255||par[4]>255||par[5]>255||par[6]>255){
                printf("\033[91mNeplatné argumeny funkce triangle!\tPoužití viz. README soubor\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawTriangle(par[0], par[1], par[2], width, height, pixels, par[3], par[4], par[5], par[6]);
            }
        }else if(strcmp(tvar, "rotated-rectangle") == 0){
            if(par[0]<0|| par[1]<0|| par[2]<0|| par[3]<0|| par[4]<0|| par[5]<0|| par[6]<0||par[7]<0||par[8]<0||par[5]>255||par[6]>255||par[7]>255||par[8]>255){
                printf("\033[91mNeplatné argumeny funkce rotated-rectangle!\tPoužití viz. README soubor\n");
                printf("Příkaz nebyl vykonán.\033[39m\n");  
            }else{
                drawRotatedRectangle(par[0], par[1], par[2], par[3], par[4], width, height, pixels, par[5], par[6], par[7], par[8]);
            }
        }else {
            printf("\033[91mNesprávný příkaz!\n");
            printf("Použití viz. README soubor\033[39m\n");
        }
        }
    }
}