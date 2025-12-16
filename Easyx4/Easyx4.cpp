#include<easyx.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14
int main() {
	initgraph(800,600);
	//背景色为棕色
	setbkcolor(RGB(169,92,10));
	cleardevice();
	//耳朵及阴影
	setfillcolor(RGB(130, 69, 4));
	solidcircle(200, 130, 90);
	solidcircle(600, 130, 90);
	setfillcolor(RGB(255, 178, 50));
	solidcircle(200, 120, 90);
	solidcircle(600, 120, 90);
	//高光（剪切）
	HRGN leftEarClip = CreateEllipticRgn(110, 30, 290, 210);
	HRGN rightEarClip = CreateEllipticRgn(510, 30, 690, 210);
	HRGN earsClip = CreateRectRgn(0, 0, 0, 0);
	CombineRgn(earsClip, leftEarClip, rightEarClip, RGN_OR);
	setcliprgn(earsClip);

	setfillcolor(RGB(243, 154, 2));
	solidcircle(200, 130, 90);
	solidcircle(600, 130, 90);

	//耳朵里面
	setfillcolor(RGB(255, 178, 50));
	solidcircle(200, 210, 90);
	solidcircle(600, 210, 90);

	DeleteObject(leftEarClip);
	DeleteObject(rightEarClip);
	DeleteObject(earsClip);
	setcliprgn(NULL);

	//头部及高光
	setfillcolor(RGB(255, 178, 50));
	solidcircle(400, 300, 250);

	HRGN headClip(CreateEllipticRgn(150, 50, 650, 550));
	setcliprgn(headClip);

	setfillcolor(RGB(243, 154, 2));
	solidcircle(400, 320, 250);

	DeleteObject(headClip);
	setcliprgn(NULL);

	//眼睛
	setfillcolor(RGB(51, 34, 8));
	solidcircle(275, 300, 25);
	solidcircle(525, 300, 25);

	//嘴部
	setfillcolor(RGB(130, 69, 4));
	solidellipse(310, 385, 490, 485);

	setfillcolor(WHITE);
	solidellipse(310, 380, 490, 480);

	//鼻子及胡须
	setfillcolor(RGB(51, 34, 8));
	solidcircle(400, 420, 15);

	setlinestyle(PS_SOLID, 5);
	setlinecolor(RGB(51, 34, 8));
	line(400,420,370,450);
	line(400,420,430,450);

	getchar();
	closegraph();
	return 0;
	//用于git使用学习的测试注释
}