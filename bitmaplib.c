#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



struct Color {
    char red;
    char green;
    char blue;
};

struct Picture {
    int width;
    int height;
    struct Color * pixels;
};

struct Picture new_pic(int width, int height) {
    struct Picture figure;
    figure.pixels = malloc(sizeof(struct Color)*width*height);
    figure.width = width;
    figure.height = height;
    return figure;
}

void save_pic(struct Picture figure, char nom_fichier[]) {
    FILE * fichier = fopen(nom_fichier,"w");
    fprintf(fichier, "P6\n%d %d\n255\n", figure.width, figure.height);
    int i,j;
    struct Color col;
    for (j = 0; j < figure.height; j++) {
        for (i = 0; i < figure.width; i++) {
            col = figure.pixels[i+j*figure.width];            
        }
    }
    fwrite(figure.pixels,figure.height*figure.width,sizeof(col),fichier);
    fclose(fichier);
}

void set_pixel(struct Picture figure, int x, int y, struct Color col) {
    figure.pixels[x+y*figure.width] = col;
}

void drawLine(struct Picture p, int x1, int y1, int x2, int y2, struct Color c)
{
  int dir,i,x,y,n, delta;
  
  if (abs(x1-x2) >= abs(y1-y2))
    {
      dir=0; // tracé horizontal
      delta= x1<x2 ? 1 : -1;
      n=abs(x1-x2);
    }
  else
    {
      dir =1; // tracé vertical
      delta= y1<y2 ? 1 : -1;
      n=abs(y1-y2);
    }
  if (dir==0)
    {
      x=x1;
      for (i=0;i<n;i++, x+=delta)
        {
	  
          y=(y2-y1)*(x-x1)/(x2-x1)+y1;
	  set_pixel(p,x,y,c);
	}
    }
  else
    {
      y=y1;
      for (i=0;i<n;i++, y+=delta)
        {
          x=(x2-x1)*(y-y1)/(y2-y1)+x1;
	  set_pixel(p,x,y,c);
	}
    }

}

