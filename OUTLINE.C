#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
void main()

{
	int a,b,c,d;
	int gd=DETECT,gm,errCode;
	char *inpu[7][5]={"sqrt","cbrt","base","eq","mat",
			  "x^n","x^3","x^2","log","ln",
			  "sin","cos","tan","","",
			  "7","8","9","DEL","AC",
			  "4","5","6","X","/",
			   "1","2","3","+","-",
			  "0",".","10^x","Ans","=",};
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	errCode=graphresult();

	if (errCode!=grOk)

	{

		printf("Graphics error %s",grapherrormsg(errCode));

		getch();

	}

	rectangle(150,20,450,450);//outline

	outtextxy(220,27,"Scientific Kalculator");

	rectangle(160,43,440,83); //screen bar

	d=100;
	for(a=0;a<7;a++){
	c=160;
		for(b=0;b<5;b++){

	rectangle(c,d,c+40,d+40);
	outtextxy(c+8,d+12,inpu[a][b]);
	c=c+60;
	}
	d=d+50;
	}



	getch();
