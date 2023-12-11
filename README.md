# Kreslení TGA Obrázků
Jedná se o konzolovou aplikaci, sloužící k zakreslování jednoduchých geometrických obrázců do TGA obrázku. Uživatel zakresluje tvary do obrázku pomocí funkcí s parametry.

## spuštění programu
1. přesunout se v konzoli do adresáře, kde jou uloženy soubory main.c, drawing.h, drawing.c, Makefile
2. pomocí příkazu make se všechny nezbytné soubory přeloží na spustitelný soubor "kresleni"
(předpokladem je, že máte nainstalovaný překladač gcc)
3. pomocí příkazu ./kresleni spustíte program
### parametry programu
- tyto parametry je nutno uvést při spuštění programu
 
<b>--output vystupni.tga</b><br>
na místo "vystupni.tga" zadejte název vašeho výstupního TGA soboru

  
<b>--width sirka</b><br>
na místo "sirka" zadejte vámi požadovanou šířku obrázku v pixelech

<b>--height vyska</b><br> 
na místo "vyska" zadejte šířku obrázku v pixelech
projekt

ukázka spuštění programu s parametry:

`
./kresleni --output output.tga --width 400 --height 400
`
## Popis jednotlivých příkazů
- Všechny příkazy, až na "save", "exit" a "clear" mají 4 stejné parametry r, g, b, a.
- r,g,b určují barvu vykresleného obrazce ve formátu RGB a parametr a určuje průhlednost<br>
<b>tyto 4 parametry mají rozsah 0 až 255</b>
- veškeré parametry musí být odděleny čárkami
### save
uloží obrázek do souboru
### exit
uloží obrázek do souboru a ukončí program
### clear
vyčistí plátno
### line
Vykreslí čáru z bodu x1, y1 do bodu x2, y2
<br><b>Pořadí parametrů: x1,y1,x2,y2,r,g,b,a</b>
### rectangle
Vykreslí obdelník s levým horním rohem v bodě x, y o sířce width a výšce height
<br><b>Pořadí parametrů: x,y,width,height,r,g,b,a</b>
### circle
Vykreslí kruh se středem v bodě x, y o poloměru radius
<br><b>Pořadí parametrů: x,y,radius,r,g,b,a</b>
### triangle
Vykreslí rovnostranný trojuhelník se středem v bodě x, y o poloměru width
<br><b>Pořadí parametrů: x,y,width,r,g,b,a</b>
### rotated-rectangle
Vykreslí orotovaný obdelník se středem v bodě x, y o sířce width, výšce height a rotací angle
<br><b>Pořadí parametrů: angle,x,y,width,height,r,g,b,a</b>
## ukázkové použití
```
./kresleni --output out.tga --width 900 --height 450
line 10,10,50,40,255,255,0,255
clear
rectangle 10,10,100,100,255,0,0,255
save
circle 20,20,40,120,120,120,128
triangle 50,50,20,0,255,0,255
rotated-rectangle 45,80,80,50,50,255,0,255,128
exit
```

- ./kresleni je samotné spuštění programu, soubor o šířce 900 a výšce 450 se bude ukládat do souboru out.tga
- line vykreslí čáru z bodu 10,10 do bodu 50,40 o barvě 255,255,0 a hodnotě alpha 255
- vyčistí plátno (černou barvou)
- rectangle vykreslí obdelník s levým horním rohem v bodě 10,10 šířce 100, výšce 100 o barvě 255,0,0 a hodnotě alpha 255
- save uloží obrázek na disk do souboru na adrese zadané při spuštění programu
- circle vykreslí kruh se středem v bodě 20,20 s poloměrem 40 o barvě 120,120,120 a hodnotě alpha 128
- triangle vykreslí rovnostranný trojúhelník se středem v bodě 50,50 o délce strany 20 o barvě 0,255,0 a hodnotě alpha 255
- rotated-rectangle vykreslí obdelník se středem na pozici 80,80 s rotací 45 stupňů o šířce 50, výšce 50, barvě 255,0,255 a hodnotě alpha 128
- exit uloží obrázek na disk do souboru na adrese zadané při spuštění programu a ukončí probram