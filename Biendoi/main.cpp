#include<graphics.h>
#include<stdio.h>
#include<math.h>
#define maxdinh 20
#define INPUT "biendoi.txt"

//khai bao bien
int td[maxdinh][2];//x:0 y:1
int n;
FILE *fp;//con tro tap tin

void readfile(){
	fp=fopen(INPUT,"r");//r: ready only
	if(fp==NULL){
		printf("File not found");
	}
	else{
		//doc so dinh cua da giac
		fscanf(fp,"%d",&n);
		printf("\n So dinh cua da giac: %d",n);
		//doc toa do tung dinh cua da giac
		for(int i=0;i<n;i++){
			for(int j=0;j<2;j++){
				fscanf(fp,"%d",&td[i][j]);
			}
		}
	}
	fclose(fp);
	td[n][0] = td[0][0];
	td[n][1] = td[1][0];
 }


void vedagiac(){
	td[n][0]=td[0][0];
	td[n][1]=td[0][1];
	for(int i=0;i<n;i++)//Hang: so dinh
	{
		for(int j=0;j<2;j++){//cot: toa do x va y
			setcolor(4);
			setlinestyle(1,0,3);
			line(td[i][0],td[i][1],td[i+1][0],td[i+1][1]);
		}
	}	
}

void tinhtien(int dx, int dy){
	//x'=x+dx; y'=y+dy
	for(int i=0;i<n;i++){//duyet qua cac dinh
		td[i][0] += dx;
		td[i][1] += dy;
	}	
	vedagiac();
}

void around(int xr, int yr, float theta){
	//x' = xr + (x-xr)cos(theta) - (y-yr)sin(theta)
 	//y' = xr + (x-xr)sin(theta) + (y-yr)cos(theta)
 	//theta co don vi la gradian: 0-3,141592
 	int rad= theta*M_PI/180;
	for(int i=0;i<n;i++){
		int x=td[i][0];
		int y=td[i][1];
		td[i][0] = round(xr + (x - xr)*cos(rad) - (y - yr)*sin(rad));
		td[i][1] = round(xr + (x - xr)*sin(rad) + (y - yr)*cos(rad));
	}
	vedagiac();
}
 
int main(){
	readfile();
	initwindow(800,800);
	vedagiac();
//	for(int tam=0;tam<10;tam++){
//		tinhtien(tam,00);
//		delay(100);
//	}
	for(int goc = 0; goc<180;goc++){
		around(500,500,goc);
		delay(5);
	}
	getch();
	
}
