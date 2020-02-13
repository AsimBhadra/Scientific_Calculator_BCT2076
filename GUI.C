#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>


void main()
{

	int gd=DETECT,gm,errCode;
	int user,i,j;
	int a,b,c,d;

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	errCode=graphresult();
	if (errCode!=grOk)
	{
		printf("Graphics error %s",grapherrormsg(errCode));
		getch();
	}
	//setfillstyle(1,4);
	rectangle(150,20,450,450);//outlined
	outtextxy(220,27,"Scientific Kalculator");
	rectangle(160,43,440,83); //screen bar
	setcolor(9);
	for(j=0;j<7;j++)
	{
		for(i=0;i<5;i++)
		{
			a=160+60*i;
			b=400-50*j;
			c=200+60*i;
			d=440-50*j;
			setfillstyle(1,9);
			rectangle(a,b,c,d);
			floodfill(a+5,b+5,9);

		}
	}

	//placing texts
	setcolor(WHITE);
	outtextxy(177,420,"0");
	outtextxy(237,420,".");
	outtextxy(285,420,"10^x");
	outtextxy(350,420,"Ans");
	outtextxy(417,420,"=");

	outtextxy(177,370,"1");
	outtextxy(237,370,"2");
	outtextxy(297,370,"3");
	outtextxy(357,370,"+");
	outtextxy(417,370,"-");

	outtextxy(177,320,"4");
	outtextxy(237,320,"5");
	outtextxy(297,320,"6");
	outtextxy(357,320,"X");
	outtextxy(417,320,"/");

	outtextxy(177,270,"7");
	outtextxy(237,270,"8");
	outtextxy(297,270,"9");
	outtextxy(350,270,"DEL");
	outtextxy(413,270,"AC");

	outtextxy(170,220,"sin");
	outtextxy(230,220,"cos");
	outtextxy(290,220,"tan");
	outtextxy(355,220,"(");
	outtextxy(417,220,")");

	outtextxy(170,170,"x^n");
	outtextxy(230,170,"x^3");
	outtextxy(290,170,"x^2");
	outtextxy(347,170,"log");
	outtextxy(413,170,"ln");

	outtextxy(167,120,"sqrt");
	outtextxy(225,120,"cbrt");
	outtextxy(285,120,"base");
	outtextxy(353,120,"eq");
	outtextxy(410,120,"mat");

	getch();



}
