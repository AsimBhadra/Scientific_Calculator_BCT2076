#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>


void main()
{
	int gd=DETECT,gm,errCode;
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

	//1st row
	rectangle(160,400,200,440);//numbers
	rectangle(220,400,260,440);
	rectangle(280,400,320,440);
	rectangle(340,400,380,440);
	rectangle(400,400,440,440);

	//2nd row
	rectangle(160,350,200,390);
	rectangle(220,350,260,390);
	rectangle(280,350,320,390);
	rectangle(340,350,380,390);
	rectangle(400,350,440,390);

	//3rd row
	rectangle(160,300,200,340);
	rectangle(220,300,260,340);
	rectangle(280,300,320,340);
	rectangle(340,300,380,340);
	rectangle(400,300,440,340);

	//4th row
	rectangle(160,250,200,290);
	rectangle(220,250,260,290);
	rectangle(280,250,320,290);
	rectangle(340,250,380,290);
	rectangle(400,250,440,290);

	//5th row
	rectangle(160,200,200,240);
	rectangle(220,200,260,240);
	rectangle(280,200,320,240);
	rectangle(340,200,380,240);
	rectangle(400,200,440,240);

	//6th row
	rectangle(160,150,200,190);
	rectangle(220,150,260,190);
	rectangle(280,150,320,190);
	rectangle(340,150,380,190);
	rectangle(400,150,440,190);

	//7th row
	rectangle(160,100,200,140);
	rectangle(220,100,260,140);
	rectangle(280,100,320,140);
	rectangle(340,100,380,140);
	rectangle(400,100,440,140);

	//placing texts
	outtextxy(177,420,"0");
	outtextxy(237,420,".");
	outtextxy(285,420,"10^x");
	outtextxy(350,420,"Ans");
	outtextxy(417,420,"=");

	outtextxy(177,370,"1");
	outtextxy(237,370,"2");
	outtextxy(297,370,"3");
	outtextxy(350,370,"+");
	outtextxy(417,370,"-");

	outtextxy(177,320,"4");
	outtextxy(237,320,"5");
	outtextxy(297,320,"6");
	outtextxy(350,320,"X");
	outtextxy(417,320,"/");

	outtextxy(177,270,"7");
	outtextxy(237,270,"8");
	outtextxy(297,270,"9");
	outtextxy(350,270,"DEL");
	outtextxy(413,270,"AC");

	outtextxy(170,220,"sin");
	outtextxy(230,220,"cos");
	outtextxy(290,220,"tan");
	outtextxy(350,220,"(");
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
