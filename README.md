# Kreslení TGA Obrázků
Jedná se o konzolovou aplikaci, sloužící k zakreslování, jednoduchých geometrických obrázců do TGA obrázku. Uživatel zakresluje tvary do obrázku pomocí funkcí s parametry.

## spuštění programu
1. přesunout v konzoli do adresáře, kde jou uloženy soubory main.c, drawing.h, drawing.c, Makefile
2. pomocí příkazu make se program přeloží na spustitelný soubor projekt
(předpokladem je, že máte nainstalovaný překladač gcc)
3. pomocí příkazu ./projekt spustíte program
### parametry programu
- tyto parametry je nutno uvést při spuštění programu
--output zde uveďte kde chcete výstupní TGA soubor uložit a jeho název
--width zde uveďte šířku obrázku v pixelech
--height zde uveďte výšku programu v pixelech

ukázka spuštění programu s parametry:
`
./projekt --output output.tga --width 400 --height 400==
`
## Popis příkazů
- Všechny příkazy, až na "save" a "exit" mají 4 stejné parametry r, g, b, a.
- r,g,b určují barvu vykresleného obrazce a parametr a určuje průhlednost 
tyto parametry mají rozsah 0 až 255
- veškeré parametry musí být odděleny čárkami
### save
uloží obrázek
### exit
uloží obrázek a ukončí program
### line
Vykreslí čáru z bodu x1, y1 do bodu x2, y2
##### Pořadí parametrů
- x1,y1,x2,y2,r,g,b,a
### rectangle
Vykreslí obdelník s levým horním rohem v bodě x, y o sířce width a výšce height
##### Pořadí parametrů
- x,y,width,height,r,g,b,a
### circle
Vykreslí kruh se středem v bodě x, y o poloměru radius
##### Pořadí parametrů
- x,y,radius,r,g,b,a
### triangle
Vykreslí rovnostranný trojuhelník se středem v bodě x, y o poloměru width
##### Pořadí parametrů
- x,y,width,r,g,b,a
### rotated-rectangle
Vykreslí orotovaný obdelník s levým horním rohem v bodě x, y o sířce width, výšce height a rotací angle
##### Pořadí parametrů
- angle,x,y,width,height,r,g,b,a
## ukázkové použití
```sh
line 10,10,50,40,255,255,0,255
rectangle 10,10,100,100,255,0,0,255
circle 20,20,40,120,120,120,128
triangle 50,50,20,0,255,0,255
rotated-rectangle 45,80,80,50,50,255,0,255,128
save
exit
```
