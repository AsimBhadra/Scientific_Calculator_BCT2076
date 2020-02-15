	#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

long double addnum(int);

int mouse();
void show_mouse_ptr();
void show_mouse_pos();

struct{
		int x0;
		int y0;
		int x1;
		int y1;
	} coordinates[7][5] = {
		{{160, 100, 200, 140},{220, 100, 260, 140},{280, 100, 320, 140},{340, 100, 380, 140},{400, 100, 440, 140}},
		{{160, 150, 200, 190},{220, 150, 260, 190},{280, 150, 320, 190},{340, 150, 380, 190},{400, 150, 440, 190}},
		{{160, 200, 200, 240},{220, 200, 260, 240},{280, 200, 320, 240},{340, 200, 380, 240},{400, 200, 440, 240}},
		{{160, 250, 200, 290},{220, 250, 260, 290},{280, 250, 320, 290},{340, 250, 380, 290},{400, 250, 440, 290}},
		{{160, 300, 200, 340},{220, 300, 260, 340},{280, 300, 320, 340},{340, 300, 380, 340},{400, 300, 440, 340}},
		{{160, 350, 200, 390},{220, 350, 260, 390},{280, 350, 320, 390},{340, 350, 380, 390},{400, 350, 440, 390}},
		{{160, 400, 200, 440},{220, 400, 260, 440},{280, 400, 320, 440},{340, 400, 380, 440},{400, 400, 440, 440}}
	};

int x, y, button;
union REGS in, out;

void main(){
	int status , a, b, c, d, i, j;
	int gd = DETECT, gm, errCode;
	char num;
	char input[7][5][5] = {
				{"sqrt", "cbrt", "base", "eq", "mat"},
			  	{"x^n", "x^3", "x^2", "log", "ln"},
			  	{"sin", "cos", "tan", "(", ")"},
			  	{"7", "8", "9", "DEL", "AC"},
			  	{"4", "5", "6", "X", "/"},
			   	{"1", "2", "3", "+", "-"},
			  	{"0", ".", "10^x", "Ans", "="}
				};

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	errCode = graphresult();
	if (errCode != grOk) {
		printf("Graphics error %s", grapherrormsg(errCode));
		getch();
	}
	
	rectangle(150, 20, 450, 450);//outline
	outtextxy(220, 27, "Scientific Kalculator");
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(160, 43, 440, 83); //screen bar
	floodfill(162, 45, BLUE);
	
	status = mouse();
	if(status == 0) {
		printf("mouse not initialized");
	} else {
		show_mouse_ptr();
		d = 100;
		for(a=0;a<7;a++){
			c=160;
			for(b=0;b<5;b++){
				setcolor(BLUE);
				setfillstyle(SOLID_FILL, BLUE);
				bar3d(coordinates[a][b].x0,coordinates[a][b].y0,coordinates[a][b].x1,coordinates[a][b].y1, 5, 1);
				floodfill(c, d,BLUE);
				setcolor(WHITE);
				outtextxy(c+8,d+12,input[a][b]);
				c=c+60;
			}
			d=d+50;
		}
		while(!kbhit()) {
			show_mouse_pos();
			if(button == 1) {
				for(a = 0; a < 7; a++) {
					for(b = 0; b < 5; b++) {
						 if(coordinates[a][b].x0 < x && x < coordinates[a][b].x1 && coordinates[a][b].y0 < y && y < coordinates[a][b].y1) {
							setfillstyle(SOLID_FILL, BLUE);
							bar(162, 43, 440, 83);
							floodfill(162, 45,BLUE);
							setcolor(WHITE);
							outtextxy(170, 70, input[a][b]);
							setcolor(BLUE);

							delay(100);


						}
					}
				}
			}
	}
	getch();
	closegraph();
	}
}
int mouse(){
	in.x.ax = 0;
	int86(0x33, &in, &out);
	return (out.x.ax);
}
void show_mouse_ptr() {
	in.x.ax = 1;

	int86(0x33, &in, &out);
}
void show_mouse_pos() {
	in.x.ax = 3;
	int86(0x33, &in, &out);
	button = out.x.bx;
	x = out.x.cx;
	y = out.x.dx;
}
