# Drawing TGA Pictures
It is a console application used to draw simple geometric figures into a TGA image. The user draws shapes into the image using functions with parameters.

## start the program
1. move in the console to the directory where the files main.c, drawing.h, drawing.c, Makefile are stored
2. using the make command, all necessary files are translated into an executable file "drawing"
(assuming you have the gcc compiler installed)
3. use the command ./kresleni to run the program
### program parameters
- these parameters must be specified when starting the program
 
<b>--output "output.tga"</b><br>
enter the name of your output TGA file instead of "output.tga".

  
<b>--width "width"</b><br>
enter the desired width of the image in pixels instead of "sirka".

<b>--height "height"</b><br>
enter the width of the image in pixels instead of "height".
project

example of running the program with parameters:

`
./kresleni --output output.tga --width 400 --height 400
`
## Description of individual commands
- All commands, except for "save", "exit" and "clear" have the same 4 parameters r, g, b, a.
- r,g,b determine the color of the rendered image in RGB format and the a parameter determines the transparency<br>
<b>these 4 parameters range from 0 to 255</b>
- all parameters must be separated by commas
### save
saves the image to a file
### exit
saves the image to a file and exits the program
### clear
cleans the canvas
### line
Draws a line from x1, y1 to x2, y2
<br><b>Order of parameters: x1,y1,x2,y2,r,g,b,a</b>
### rectangle
Draws a rectangle with the upper left corner at point x, y with width width and height height
<br><b>Order of parameters: x,y,width,height,r,g,b,a</b>
### circle
Draws a circle centered at x, y with radius radius
<br><b>Parameter order: x,y,radius,r,g,b,a</b>
### triangle
Draws an equilateral triangle centered at x, y with a radius of width
<br><b>Parameter order: x,y,width,r,g,b,a</b>
### rotated-rectangle
Draws a rotated rectangle centered at x, y with width, height and rotation angle
<br><b>Order of parameters: angle,x,y,width,height,r,g,b,a</b>
## sample usage
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

- ./kresleni run the program, a file with a width of 900 and a height of 450 will be saved in the out.tga file
- line draws a line from point 10,10 to point 50,40 with color 255,255.0 and alpha value 255
- cleans the canvas (with black paint)
- rectangle renders a rectangle with the upper left corner at point 10,10, width 100, height 100, color 255,0,0 and alpha value 255
- save saves the image on disk to a file at the address specified when the program is started
- circle will draw a circle centered at point 20,20 with a radius of 40 with a color of 120,120,120 and an alpha value of 128
- triangle renders an equilateral triangle centered at 50.50, side length 20, color 0.255.0, and alpha 255
- rotated-rectangle renders a rectangle centered at position 80,80 rotated 45 degrees with width 50, height 50, color 255,0,255 and alpha 128
- exit saves the image on disk to a file at the address specified when the program is started and exits program
