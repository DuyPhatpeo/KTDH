#include<winbgim.h>
#include<stdio.h>
#include<math.h>
void circle (int xc ,int yc,int x,int y,int color){
	putpixel(xc+x,yc+y,color);
	putpixel(xc+x,yc-y,color);
	putpixel(xc-x,yc+y,color);
	putpixel(xc-x,yc-y,color);
	putpixel(xc+y,yc+x,color);
	putpixel(xc+y,yc-x,color);
	putpixel(xc-y,yc+x,color);
	putpixel(xc-y,yc-x,color);
}
void bre(int xc,int yc,int r){
	int x=0;
	int y=r;
	int d=3-2*r;
	while(x<y){
		circle(xc,yc,x,y,4);
		if(d<0){
			d=d+4*x+6;
		}
		else{
			d=d+4*x-4*y+10;
			y--;
		}
		circle(xc,yc,x,y,4);
		x++;
	}
}



int main(){
	initwindow(400,400);
	bre(100,100,90);
	getch();
}
