#include<stdio.h>
#include<graphics.h>

//khai bao bien
int xwmin = 100;
int ywmin = 100;
int xwmax = 300;
int ywmax = 300;

float MIN(float a,float b){
	return (a<b)?a:b;
}

float MAX(float a,float b){
	return (a>b)?a:b;
}
void LiangBasky(int xa,int ya,int xb,int yb){
	setcolor(2);
	line(xa,ya,xb,yb);
	int dx = xb-xa;
	int dy = yb-ya;
	int x0, y0, x1, y1;
	int p[4] = {-dx, dx, -dy, dy};
	int q[4] = {xa-xwmin,xwmax-xa,ya-ywmin,ywmax-ya};
	//in ra man hinh gia tri cua p va q
	printf("pk[]");
	for(int i=0;i<4;i++){
		printf("%5d",p[i]);
	}
	printf("\nqk[]");
	for(int i=0;i<4;i++){
		printf("%5d",q[i]);
	}
	float t1 =0.0 ;
	float t2= 1.0;
	//xet truong hop pk< 0
	for(int i=0;i<4;i++){
		if(p[i]<0){
			//tim max t1 voi q[i]/p[i]
			t1 = MAX(t1,(float)q[i]/p[i]);
		}
	}
	//in ra t1 =?
	printf("\nt1 = %f",t1);
	//xet truong hop pk> 0
	for(int i=0;i<4;i++){
		if(p[i]>0){
			//tim max t1 voi q[i]/p[i]
			t2 = MIN(t2,(float)q[i]/p[i]);
		}
	}
	//in ra t2 =?
	printf("\nt2 = %f",t2);
	//tim x0 ,y0
	x0 = xa+t1*dx;
	y0= ya+ t1*dy;
	//tim x1 ,y1
	x1 = xa+t2*dx;
	y1= ya+ t2*dy;
	printf("\nGiao diem cua doan thang cua cua so cat : (%d,%d) ,(%d,%d)",x0,y0,x1,y1);
	if(x0<xwmin || x0> xwmax || y0 < ywmin || y0> ywmax||x1<xwmin || x1> xwmax || y1 < ywmin || y1> ywmax){
		printf("nam ngoai cua so cat");
	}
	else{
		//ve duong thang sau khi xen tia
		setcolor(13);
		line(x0,y0,x1,y1);	
	}
}

int main(){
	initwindow(500,500);
	rectangle(xwmin,ywmin,ywmax,xwmax);
	//AB nam trong
	LiangBasky(150,280,260,150);
	
	//AB nam trong
	LiangBasky(150,280,260,150);
	
	//A trong + B ngoai
	LiangBasky(150,280,360,150);//A trong, B phai
	LiangBasky(150,140,150,450);//A trong, B tren
	LiangBasky(200,140,60,140);//A trong, B trai
	LiangBasky(200,140,200,70);//A trong, B duoi
	
	//A ngoai + B trong
	//LiangBasky(360,150,150,280);//B trong, A phai
	//LiangBasky(150,450,150,140);//B trong, A tren
	//LiangBasky(60,140,200,140);//B trong, A trai
	//LiangBasky(200,70,200,140);//B trong, A duoi
	
	//A trai + B phai
	//LiangBasky(70,200,350,200);//A trai, B phai
	//A tren + B duoi
	//LiangBasky(200,40,200,360);//A tren, B duoi
	//A trai + B tren
	//LiangBasky(70,200,240,400);//A trai, B tren
	//A trai + B duoi
	//LiangBasky(70,200,240,35);//A trai, B duoi
	
	//A phai + B tren
	//LiangBasky(370,200,140,320);//A phai, B tren
	
	//A phai + B duoi
	//LiangBasky(370,200,140,35);//A phai, B duoi
	
	//A goc tren, trai + B ben trong
	//LiangBasky(50,30,150,140);//B trong, A tren, trai
	//LiangBasky(10,80,150,140);//B trong, A tren, trai
	
	//A goc duoi, trai + B ben trong
	//LiangBasky(80,430,150,140);//B trong, A duoi, trai
	//LiangBasky(10,430,150,140);//B trong, A duoi, trai
	//A goc tren, phai + B ben trong
	//LiangBasky(450,30,200,170);//B trong, A tren, phai
	//LiangBasky(330,10,200,170);//B trong, A tren, phai
	
	//A goc duoi, phai + B ben trong
	//LiangBasky(450,430,200,170);//B trong, A duoi, phai
	//LiangBasky(330,410,200,170);//B trong, A duoi, phai
	getch();
}
