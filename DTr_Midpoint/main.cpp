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
void mid (int xc,int yc,int r){
	int x=0;
	int y=r;
	circle(xc,yc,x,y,4);
	int p=1-r;
	while(x<y){
		if(p<0){
			p+=2*x+3;
		}
		else{
			p+=2*(x-y)+5;
			y--;
		}
		x++;
		circle(xc,yc,x,y,4);
	}
}
int main(){
	initwindow(400,400);
	mid(100,100,90);
	getch();
}
