#include<graphics.h>
#include<stdio.h>

//20,30,120,80
void bre1(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x;
	int y=ya;
	for(x=xa;x<=xb;x++){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q<0){
			y++;
			q=q+2*dx-2*dy;
		}
		else{
			q=q-2*dy;
		}
	}
}
//120,80,20,30
void bre2(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = 2*dy-dx;
	int x;
	int y=ya;
	for(x=xa;x>=xb;x--){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q<0){
			y--;
			q=q-2*dx+2*dy;
		}
		else{
			q=q+2*dy;
		}
	}
}
//20,80,120,30
void bre3(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x;
	int y=ya;
	for(x=xa;x<=xb;x++){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			y--;
			q=q-2*dx-2*dy;
		}
		else{
			q=q-2*dy;
		}
	}
}
//120,30,20,80
void bre4(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x;
	int y=ya;
	for(x=xa;x>=xb;x--){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			y++;
			q=q+2*dx+2*dy;
		}
		else{
			q=q+2*dy;
		}
	}
}
//30,20,80,120
void bre5(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x=xa;
	int y;
	for(y=ya;y<=yb;y++){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			x++;
			q=q+2*dx-2*dy;
		}
		else{
			q=q+2*dx;
		}
	}
}
//80,120,30,20
void bre6(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x=xa;
	int y;
	for(y=ya;y>=yb;y--){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			x--;
			q=q-2*dx+2*dy;
		}
		else{
			q=q-2*dx;
		}
	}
}
//30,120,80,20

void bre7(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x=xa;
	int y=ya;
	for(y=ya;y >=yb;y--){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			x++;
			q=q+2*dx+2*dy;
		}
		else{
			q=q+2*dx;
		}
	}
}
//80,20,30,120
void bre8(int xa,int ya, int xb, int yb, int color){
	int dx=xb-xa;
	int dy=yb-ya;
	int q = dx-2*dy;
	int x=xa;
	int y;
	for(y=ya;y <=yb;y++){
		printf("\nx = %d ,y = %d, Q = %d",x,y,q);
		putpixel(x,y,color);
		delay(10);
		if(q>0){
			x--;
			q=q-2*dx-2*dy;
		}
		else{
			q=q-2*dx;
		}
	}
}

int main(){
	initwindow(200,200);
	bre1(20,30,120,80,1);
	bre2(120,80,20,30,3);
	bre3(20,80,120,30,2);
	bre4(120,30,20,80,5);
	bre5(30,20,80,120,1);
	bre6(80,120,30,20,3);
	bre7(30,120,80,20,2);
	bre8(80,20,30,120,5);
	getch();
}
