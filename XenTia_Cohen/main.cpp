#include<graphics.h>//thu vien do hoa
#include<stdio.h>//printf scanf
#include<limits.h>//MAX MIN INTEGER

//khai bao bien
int xwmin = 100;
int xwmax = 300;
int ywmin = 100;
int ywmax = 300;
float m;//he so goc
int xgd, ygd;//luu tru hoanh do va tung do cua giao diem
int x0,y0,x1,y1;//toa do giao diem cua duong thang voi cua so cat
void khoitaocuaso(){
	setcolor(15);//white color
	setlinestyle(1,1,2);//width = 2
	rectangle(xwmin, ywmax, xwmax, ywmin);
}
int mahoa(int x, int y){//ma hoa 1 diem (x,y)
	if(x>=xwmin && x<=xwmax && y>=ywmin && y<=ywmax){
		return 0;//0000 => ma thap phan = 0
	}
	if(x>=xwmin && x<=xwmax && y<ywmin){
		return 4;//0100 => ma thap phan = 4
	}
	if(x>=xwmin && x<=xwmax && y>ywmax){
		return 8;//1000 => ma thap phan = 8
	}
	if(x<xwmin && y>=ywmin && y<=ywmax){
		return 1;//0001 => ma thap phan = 1
	}
	if(x>xwmax && y>=ywmin && y<=ywmax){
		return 2;//0010 => ma thap phan = 2
	}
	if(x<xwmin && y<ywmin){
		return 5;//0101 => ma thap phan = 5
	}
	if(x<xwmin && y>ywmax){
		return 9;//1001 => ma thap phan = 9
	}
	if(x>xwmax && y>ywmax){
		return 10;//1010 => ma thap phan = 10
	}
	if(x>xwmax && y<ywmin){
		return 6;//0110 => ma thap phan = 6
	}		
}
void timgiaodiem(int x, int y){//tim giao diem cua diem dang xet
	switch(mahoa(x,y)){
		case 0:{
			//diem nam trong cua so cat
			xgd=x; ygd=y;
			break;
		}
		case 2:{
			xgd=xwmax;
			ygd=y+(xgd-x)*m;
			break;
		}
		case 1:{
			xgd=xwmin;
			ygd=y+(xgd-x)*m;
			break;
		}
		case 4:{
			ygd=ywmin;
			xgd=x+(ygd-y)/m;
			break;
		}
		case 8:{
			ygd=ywmax;
			xgd=x+(ygd-y)/m;
			break;
		}
		case 5:{//B==L==1
			//xet bit B=1
			ygd=ywmin;
			xgd=x+(ygd-y)/m;
			if(xgd<xwmin){
				//xet bit L=1
				xgd=xwmin;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 6:{//B==R==1
			//xet bit B=1
			ygd=ywmin;
			xgd=x+(ygd-y)/m;
			if(xgd>xwmax){
				//xet bit R=1
				xgd=xwmax;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 9:{//A==L==1
			//xet bit A=1
			ygd=ywmax;
			xgd=x+(ygd-y)/m;
			if(xgd<xwmin){
				//xet bit L=1
				xgd=xwmin;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		case 10:{//A==R==1
			//xet bit A=1
			ygd=ywmax;
			xgd=x+(ygd-y)/m;
			if(xgd>xwmax){
				//xet bit R=1
				xgd=xwmax;
				ygd=y+(xgd-x)*m;
			}
			break;
		}
		
	}
}
void Cohen(int xa, int ya, int xb, int yb){
	//tim he so goc
	if(xa==xb){
		m=INT_MAX;
	}
	if(ya==yb){
		m=0;
	}
	else{//xa!=xb va ya!=yb
		m=(float)(yb-ya)/(xb-xa);
	}
	printf("\nDoan thang di qua XA = %d, YA= %d, XB=%d, YB=%d",xa,ya,xb,yb);
	//ve doan thang noi 2 diem A(xa,ya) va B(xb,yb)
	setcolor(2);
	line(xa,ya,xb,yb);
	//in kqua ma hoa 2diem A va B
	printf("\nMa hoa (A) = %d, Ma hoa (B) = %d", mahoa(xa,ya),mahoa(xb,yb));
	//lap luan tim giao diem
	if(mahoa(xa,ya)!=0 && mahoa(xb,yb)!=0 && (mahoa(xa,ya) & mahoa(xb,yb))!=0){
		printf("\nDoan thang khong bi gioi han boi cua so cat");
		return;
	}
	//nguoc lai, doan thang co 1 hoac 2 giao diem voi cua so cat
	timgiaodiem(xa,ya);
	x0=xgd;
	y0=ygd;
	timgiaodiem(xb,yb);
	x1=xgd;
	y1=ygd;
	//in ra man hinh 2 diem moi sau khi xen tia
	if(x0<xwmin || y0<ywmin || x0>xwmax || y0>ywmax || x1<xwmin || y1<ywmin || x1>xwmax || y1>ywmax ){
		printf("\nDoan thang khong bi gioi han boi cua so cat");
	}
	else{
		setcolor(4);
		printf("\nToa do X0 = %d, Y0= %d, X1=%d, Y1=%d",x0,y0,x1,y1);
		line(x0,y0,x1,y1);
	}
}
int main(){
	initwindow(400,400);
	khoitaocuaso();
	//A trong+ B ngoai
	//Cohen(150,280,260,150);//AB nam trong
	
//	Cohen(150,280,360,150);//A trong, B phai
//	Cohen(150,140,150,450);//A trong, B tren
//	Cohen(200,140,60,140);//A trong, B trai
//	Cohen(200,140,200,70);//A trong, B duoi
	//A ngoai + B trong
//	Cohen(360,150,150,280);//B trong, A phai
//	Cohen(150,450,150,140);//B trong, A tren
//	Cohen(60,140,200,140);//B trong, A trai
//	Cohen(200,70,200,140);//B trong, A phai
	//A trai + B phai
	//Cohen(70,200,350,200);//A trai, B phai
	
	//A tren + B duoi
	//Cohen(200,40,200,360);//A tren, B duoi
	
	//A trai + B tren
	//Cohen(70,200,240,400);//A trai, B tren
	
	//A trai + B duoi
	//Cohen(70,200,240,35);//A trai, B duoi
	
	//A phai + B tren
	//Cohen(370,200,140,320);//A phai, B tren
	
	//A phai + B duoi
	//Cohen(370,200,160,400);//A phai, B duoi
	
	//A goc tren, trai + B ben trong
	Cohen(50,30,150,140);//B trong, A tren, trai
	Cohen(10,80,150,140);//B trong, A tren, trai
	
	//A goc duoi, trai + B ben trong
	Cohen(80,430,150,140);//B trong, A duoi, trai
	Cohen(10,430,150,140);//B trong, A duoi, trai
	
	//A goc tren, phai + B ben trong
	Cohen(450,30,200,170);//B trong, A tren, phai
	Cohen(330,10,200,170);//B trong, A tren, phai
	
	//A goc duoi, phai + B ben trong
	Cohen(450,430,200,170);//B trong, A duoi, phai
	Cohen(330,410,200,170);//B trong, A duoi, phai

	Cohen(90,90,90,90);
//	A ngoai + B trong
//	Cohen(50,150,50,250);
//	Cohen(150,150,250,250);
//	Cohen(150,150,350,250);
//	Cohen(150,150,50,250);
	getch();//press any key
}
