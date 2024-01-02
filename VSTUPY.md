# Testovací vstupy
<b>Spuštění programu</b>
```
./kresleni --output output.tga --width 1920 --height 1080
```
## Stromeček, domeček a sluníčko
```
rectangle 0,0,1920,1080,0,204,255,255
rectangle 0,900,1920,280,0,204,0,255
rectangle 1000,850,15,50,102,51,0,255
triangle 1007,800,150,0,102,0,255
triangle 1007,750,140,0,102,0,255
triangle 1007,690,120,0,102,0,255
circle 1920,0,500,255,255,0,255
rotated-rectangle 45,500,500,300,300,255,0,0,255
rectangle 300,500,400,400,204,255,102,255
rectangle 350,700,100,200,153,120,0,255
line 420,800,440,800,0,0,0,255
rectangle 500,730,80,80,153,51,0,255
rectangle 510,740,60,60,0,0,255,255
save
```

## Pěkný vzor
(je použita alpha)
```
rectangle 0,0,1920,1080,0,255,0,128
circle 0,0,150,255,0,0,255
circle 0,1080,150,255,0,0,255
circle 1920,0,150,255,0,0,255
circle 1920,1080,150,255,0,0,255
rotated-rectangle 45,960,540,600,600,0,0,255,255
triangle 960,540,900,0,255,0,128
line 0,0,1920,1080,255,0,255,255
line 1920,0,0,1080,255,0,255,255
save
```
