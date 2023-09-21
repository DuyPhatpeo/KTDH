#include<stdio.h>
#include<graphics.h>
#include<math.h>

//m<1 va xa<xb
void TH1(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 int x; float y; y=ya;
 for(x=xa;x<=xb;x++)
 {
  y+=m;
  printf("\nx=%d,y=%.0f",x,round(y));
  putpixel(x,round(y),color);
  delay(10);
 }
}

void TH2(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 int x; float y; y=ya;
 for(x=xa;x>=xb;x--)
 {
  y-=m;
  printf("\nx=%d,y=%.0f",x,round(y));
  putpixel(x,round(y),color);
  delay(10);
 }
}

void TH3(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 float x=xa; int y;
 for(y=ya;y<=yb;y++)
 {
  x+=1/m;
  printf("\nx=%.0f,y=%d",round(x),y);
  putpixel(round(x),y,color);
  delay(10);
 }
}

void TH4(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 float x=xa; int y;
 for(y=ya;y>=yb;y--)
 {
  x-=1/m;
  printf("\nx=%.0f,y=%d",round(x),y);
  putpixel(round(x),y,color);
  delay(10);
 }
}

void TH5(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 int x; float y; y=yb;
 for(x=xb;x<=xa;x++)
 {
  y+=m;
  printf("\nx=%d,y=%.0f",x,round(y));
  putpixel(x,round(y),color);
  delay(10);
 }
}

void TH6(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 int x; float y; y=yb;
 for(x=xb;x>=xa;x--)
 {
  y-=m;
  printf("\nx=%d,y=%.0f",x,round(y));
  putpixel(x,round(y),color);
  delay(10);
 }
}

void TH7(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 float x=xb; int y;
 for(y=ya;y>=yb;y--)
 {
  x-=1/m;
  printf("\nx=%.0f,y=%d",round(x),y);
  putpixel(round(x),y,color);
  delay(10);
 }
}

void TH8(int xa, int ya, int xb, int yb, int color)
{
 float m=(float)(yb-ya)/(xb-xa);
 float x=xb; int y;
 for(y=ya;y<=yb;y++)
 {
  x+=1/m;
  printf("\nx=%.0f,y=%d",round(x),y);
  putpixel(round(x),y,color);
  delay(10);
 }
}


int main()
{
 initwindow(400,400);
 TH1(20,30,120,80,10);
 TH2(120,80,20,30,15);
 TH3(30,20,80,120,4);
 TH4(80,120,30,20,5);
 TH5(120,30,20,80,6);
 TH6(20,80,120,30,3);
 TH7(30,120,80,20,1);
 TH8(80,20,30,120,2);
 getch();
}
