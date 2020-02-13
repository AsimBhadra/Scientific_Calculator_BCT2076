#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
int initmouse();
void showptr();
void starting();
void ending();
void hideptr();
void getmousepos(int *,int*,int*);
void restrictptr(int,int,int,int);
int button,x,y,x1,y1,x2,y2,s;
long double num=0,get,num1=0,result=0;
long double addnum(int);
char opr;
int a,b,r,i1,count,c,sq,newnum=1,d=0;
union REGS i,o;
int main()
{
  int driver=DETECT,mode;
  int q,p[12];
  char input;
   char *inpu[4][4]={"1","2","3","4",
	  "5","6","7","8",
	  "9","0","+","-" ,
	  "*","/","clr","="};
  char inp[4][4]={'1','2','3','4',
	  '5','6','7','8',
	  '9','0','+','-' ,
	  '*','/','l','='};
  initgraph(&driver,&mode,"C:\\Turboc3\\BGI");

  if(initmouse()==0)
  {
    printf("not");
    getch();
    return(0);
  }
  starting();
  getch();
  cleardevice();
  settextstyle(1,0,2);
  setfillstyle(1,LIGHTGRAY);
  bar(236,82,432,300);
  setcolor(WHITE);
  rectangle(236,48,432,82);
  d=100;
  s=0;
   for(a=0;a<4;a++)
   {
	c=240;
	for(b=0;b<4;b++)
	{
	   setfillstyle(1,DARKGRAY);
	   bar(c,d,c+40,d+40);
	   setcolor(YELLOW);
	   outtextxy(c+10,d+14,inpu[a][b]);
	   c+=50;
	   }
    d+=50;
    }
  showptr();
  num=0;
  gotoxy(36,5);
  printf("%18.2Lf",num);

  count=0;

while(!kbhit())
{

  outtextxy(30,400,"Press any key to exit..");
  i1=0;
  c=240;
  d=100;
  rectangle(0,0,638,478);
  getmousepos(&button,&x,&y);
  for(a=0;a<4;a++)
  {
    c=240;
    for(b=0;b<4;b++)
    {
      if((x>=c&&x<=c+40)&&(y>=d&&y<=d+40))
      {
       if((button&1)==1)
       {
	while((button&1)==1)
	{
	 setcolor(10);
	 rectangle(c,d,c+40,d+40);
	 rectangle(c-1,d-1,c+41,d+41);
	 rectangle(c-2,d-2,c+42,d+42);
	 break;
	 }
     delay(100);
     setcolor(GREEN);
     rectangle(c,d,c+40,d+40);
     rectangle(c-1,d-1,c+41,d+41);
     rectangle(c-2,d-2,c+42,d+42);
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

     case 'l':
	 num=0;
	 num1=0;
	 result=0;
	 count=0;
	 gotoxy(36,5);
	 printf("%18.2Lf",num);
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

      c+=50;
    }

    d+=50;
  }
  setcolor(YELLOW);
  delay(150);
}
  getch();
  ending();
  getch();
  return 0;
}
long double addnum(int getnum)
{
    num=num*10+getnum;
    return(num);
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
void starting()
{
    int aa,bb,cc,dd,maxx,maxy,i=10;
    maxx=getmaxx();
    maxy=getmaxy();
    rectangle(0,0,maxx,maxy);
    setcolor(i);
    setcolor(4);
    settextstyle(1,0,5);
    outtextxy(200,20,"WELCOME");
    setcolor(5);
    outtextxy(200,70,"Kalculator");
    setcolor(2);
    outtextxy(120,120,"Team Members:");
    setcolor(3);
    outtextxy(200,160,"ANKIT");
    outtextxy(200,200,"ASIM");
    outtextxy(200,240,"BIKESH");
    outtextxy(200,280,"RAHUL");
}
void ending()
{
  int k;
  cleardevice();
  rectangle(0,0,638,478);
  k=0;
  while(!kbhit())
  {
  setcolor(k);
  settextstyle(1,0,8);
  outtextxy(100,150,"THANK YOU");
  line(90,250,580,250);
  settextstyle(1,0,5);
  outtextxy(100,270,"FOR USING KALCULATOR");
  delay(200);
  k++;
  }
}
