#include <graphics.h>
#include<stdio.h>
#include<math.h>
#define INPUT "chopnhon_v2.inp.txt"
#define MATRANKE "chopnhon_v2.mtk.txt"
#define maxdinh 20 
int dinh[maxdinh][maxdinh];
int mtk[maxdinh][maxdinh];
int n; //sodinh
FILE *fp;
//ma tran ket qua cua phep chieu xien
int Pnew[maxdinh][maxdinh];
void inmatran(int a[][maxdinh], int hang, int cot){
	for(int i=0;i<hang;i++){
		for(int j = 0;j<cot;j++){
			printf("%5d",a[i][j]);
		}
		printf("\n");
	}
}
void readfile(){
	//tap tin toa do dinh
	fp = fopen(INPUT,"r");
	if(fp == NULL){
		printf("File not found");
		return;
	}
	else{
		//doc so dinh cua da giac
		fscanf(fp,"%d",&n);
		printf("\nSo dinh cua da giac : %d",n);
		//doc toa do cac dinh cua da giac 
		for(int i =0;i<n;i++){
			for(int j=0;j<3;j++){ //x,y,z
				fscanf(fp,"%d",&dinh[i][j]);
			}
		}
		//hien thi noi dung cua cac dinh da giac
		printf("\nToa do cac dinh cua da giac:\n ");
		inmatran(dinh,n,3);
		fclose(fp);
	}
	fp = fopen(MATRANKE,"r");
	if(fp == NULL){
		printf("File not found");
		return;
	}
	else{
		//doc so dinh cua da giac
		fscanf(fp,"%d",&n);
		printf("So dinh cua da giac : %d",n);
		//doc toa do cac dinh cua da giac 
		for(int i =0;i<n;i++){
			for(int j=0;j<n;j++){ //x,y,z
				fscanf(fp,"%d",&mtk[i][j]);
			}
		}
		//hien thi noi dung cua cac dinh da giac
		printf("\nMa tran ke cac dinh cua da giac:\n ");
		inmatran(mtk,n,n);
		fclose(fp);
	}
}
void oxy(){
	setcolor(2);
	for(int i = 0;i<n-1;i++){// cac dinh cua da giac
		for(int j =i+1;j<n;j++){// j = i+1
			if(mtk[i][j] ==1 ){//2 dinh co noi voi nhau
			line(dinh[i][0],dinh[i][1],dinh[j][0], dinh[j][1]);//x0, y0 -> x1, y1;
			}
		}
	}
}
void oxz(){
	setcolor(4);
	for(int i = 0;i<n-1;i++){// cac dinh cua da giac
		for(int j =i+1;j<n;j++){// j = i+1
			if(mtk[i][j] ==1 ){//2 dinh co noi voi nhau
			line(dinh[i][0],dinh[i][2],dinh[j][0], dinh[j][2]);//x0, z0 -> x1, z1;
			}
		}
	}
}
void oyz(){
	setcolor(13);
	for(int i = 0;i<n-1;i++){// cac dinh cua da giac
		for(int j =i+1;j<n;j++){// j = i+1
			if(mtk[i][j] ==1 ){//2 dinh co noi voi nhau
			line(dinh[i][1],dinh[i][2],dinh[j][1], dinh[j][2]);//y0, z0 -> y1, z1;
			}
		}
	}
}


void chieuxien(float L,int theta){
	//khai bao ma tran T
	float T[3][3]={{1,0,0},{0,1,0},{L*cos(theta*3.1416/180),L*sin(theta*3.1416/180)}};
	//khoi tao ma tran Pnew=0
	for(int i=0;i <n;i++)
		for(int j=0;j<n;j++)
			Pnew[i][j]=0;
	//nhan 2 ma tran dinh[n][3]*T[3][n]
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++){
				Pnew[i][j]=round(Pnew[i][j]+dinh[i][k]*T[k][j]);
		}
	printf("\nMa tran Pnew:\n");
	inmatran(Pnew,n,3);
	setcolor(2);
	for(int i = 0;i<n-1;i++){// cac dinh cua da giac
		for(int j =i+1;j<n;j++){// j = i+1
			if(mtk[i][j] ==1 ){//2 dinh co noi voi nhau
			line(Pnew[i][0],Pnew[i][1],Pnew[j][0], Pnew[j][1]);//x0, y0 -> x1, y1;
			}
		}
	}
}

int main()
{
	initwindow(1000,1000);
	readfile();
//	oxy();
//	oxz();
//	oyz();
	char buffer[10];
	for(int i=0;i <180 ;i++){
		sprintf(buffer,"%d",i);
		settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
		outtextxy(0,0,buffer);
		chieuxien(0.5,i);
		delay(100);
		cleardevice();
	}
	getch();
}
