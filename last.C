#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#define PI 3.141516
int initmouse();
void showptr();
void starting();
void ending();
void hideptr();
void getmousepos(int *,int*,int*);
void restrictptr(int,int,int,int);
int button,x,y,x1,y1,x2,y2,s,n;
long double num=0,get,num1=0,result=0;
long double addnum(int);
char opr;
int a,b,r,i1,count,c,sq,newnum=1,d=0,power;
union REGS i,o;
int main()
{
	int gd=DETECT,gm,errCode;
	char *inpu[6][5]={"sqrt","mat","x^3","x^2","log",
			"sin","cos","tan","DEL","AC",
			"7","8","9","+","-",
			  "4","5","6","*","/",
			   "1","2","3","","",
			  "0",".","","Ans","="};
	char inp[6][5]={'s','m','r','t','l',
			  'S','C','T','D','A',
			  '7','8','9','+','-',
			  '4','5','6','*','/',
			   '1','2','3','z','p',
			   '0','.','o','N','='};
	int q,p[12];
	char input;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	errCode=graphresult();

	if (errCode!=grOk)

	{

		printf("Graphics error %s",grapherrormsg(errCode));

		getch();

	}

	rectangle(150,20,450,400);//outline

	outtextxy(220,27,"Scientific Kalculator");

	rectangle(160,43,440,83); //screen bar

	d=100;
	for(a=0;a<6;a++){
	c=160;
		for(b=0;b<5;b++){

	rectangle(c,d,c+40,d+40);
	outtextxy(c+8,d+12,inpu[a][b]);
	c=c+60;
	}
	d=d+50;
	}
	 showptr();
  num=0;

  gotoxy(36,5);
  printf("%18.2Lf",num);
  count=0;

  d=100;
  getmousepos(&button,&x,&y);
  showptr();
	num=0;
	gotoxy(36,5);
	printf("%18.2Lf",num);
	count=0;
	while(!kbhit())
	{
		d=100;
		getmousepos(&button,&x,&y);
		for(a=0;a<6;a++)
		{
			c=160;
			for(b=0;b<5;b++)
			{
				if((x>=c && x<=c+40) && (y>=d && y<=d+40))
				{
					if((button&1)==1)
					{
						delay(2);
						setcolor(RED);
						rectangle(c,d,c+40,d+40);
						input=inp[a][b];
						switch(input)
     {
     case '1':

	 get=addnum(1);

	 gotoxy(36,5);
	 printf("%18.2Lf",get);


	 break;

     case '2':

	 get=addnum(2);

	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;

      case '3':

	 get=addnum(3);
	 gotoxy(36,5);

	 printf("%18.2Lf",get);
	 break;
       case '4':
	 get=addnum(4);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
     case '5':
	 get=addnum(5);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
     case '6':
	 get=addnum(6);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
     case '7':
	 get=addnum(7);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
   case '8':
	 get=addnum(8);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
   case '9':
	 get=addnum(9);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
   case '0':
	 get=addnum(0);
	 gotoxy(36,5);
	 printf("%18.2Lf",get);
	 break;
    case '+':
	 num1=num;
	 num=0;
	 opr='+';
	 gotoxy(36,5);
	 printf("%18.2Lf",num);
	 break;

  case '-':
	 num1=num;
	 num=0;
	 opr='-';
	 gotoxy(36,5);
	 printf("%18.2Lf",num);
	break;

  case '*':
	 num1=num;
	 num=0;
	 opr='*';
	 gotoxy(36,5);
	 printf("%18.2Lf",num);
	break;

  case '/':
	 num1=num;
	 num=0;
	 opr='/';
	 gotoxy(36,5);
	 printf("%18.2Lf",num);
	break;

     case 'D':
	 num=0;
	 num1=0;
	 result=0;
	 count=0;
	 gotoxy(36,5);
	 printf("%18.2Lf",num);
	 break;
      case 'S':
	num=num*PI/180;
	result=sin(num);
	gotoxy(36,5);
	printf("%18.2Lf",result);
	num=result;
	break;

      case 'C':
	num=num*PI/180;
	result=cos(num);
	gotoxy(36,5);
	printf("%18.2Lf",result);
	num=result;
	break;

      case 'T':
	num=num*PI/180;
	result=tan(num);
	gotoxy(36,5);
	printf("%18.2Lf",result);
	num=result;
	break;

	case 's':
		result=sqrt(num);
		gotoxy(36,5);
		printf("%18.2Lf",result);
		num=result;
		break;

	case 'r':
		result=num*num*num;
		gotoxy(36,5);
		printf("%18.2Lf",result);
		num=result;
		break;

	case 't':
		result=num*num;
		gotoxy(36,5);
		printf("%18.2Lf",result);
		num=result;
		break;
	case 'l':
		result=log(num);
		gotoxy(36,5);
		printf("%18.2f",result);
		num=result;
		break;
	case 'n':
		gotoxy(36,5);
		printf("Enter n?:");
		scanf("%d",&n);
		result=pow(num,n);
		gotoxy(36,5);
		printf("%18.2f",result);
		num=result;
		break;

     case '=':
	 switch(opr)
	 {
	   case '+':
		 if(count<1)
		 {
		   result=num+num1;
		 }
		 else
		 {
		   result=result+num;
		 }
		 gotoxy(36,5);
		 printf("%18.2Lf",result);
		 count+=1;
		 break;

	   case '-':

		 if(count<1)
		 {
		   result=num1-num;
		 }
		 else
		 {
		   result=result-num;
		 }
		 gotoxy(36,5);
		 printf("%18.2Lf",result);
		 count+=1;
		 break;
	   case '*':
		 if(count<1)
		 {
		  result=num1*num;
		 }
		 else
		 {
		  result=result*num;
		 }
		 gotoxy(36,5);
		 printf("%18.2Lf",result);
		 count+=1;
		 break;

	   case '/':
		 if(count<1)
		 {
		  result=num1/num;
		 }
		 else
		 {
		  result=result/num;
		 }
		 gotoxy(36,5);
		 printf("%18.2Lf",result);
		 count+=1;
		 break;



	 }
     }
       }
      }
			 c+=60;   }

      d+=50; }
	delay(150);
	}
	getch();
	return 0;
	}
int initmouse()
{
    i.x.ax=0;
    int86(0x33,&i,&o);
    return(o.x.ax);
}
void showptr()
{
   i.x.ax=1;
   int86(0x33,&i,&o);
}
void hideptr()
{
   i.x.ax=2;
   int86(0x33,&i,&o);
}
void restrictptr(int x1,int y1,int x2,int y2)
{
    i.x.ax=7;
    o.x.cx=x1;
    o.x.dx=x2;
    int86(0x33,&i,&o);
    i.x.ax=8;
    o.x.cx=y1;
    o.x.dx=y2;
    int86(0x33,&i,&o);
}
void getmousepos(int *button,int *x,int *y)
{
  i.x.ax=3;
  int86(0x33,&i,&o);
  *button=o.x.bx;
  *x=o.x.cx;
  *y=o.x.dx;
}
long double addnum(int getnum)
{
    num=num*10+getnum;
    return(num);
}

