#include <iostream>
#include "console.h"
#include <ctime>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define ROW 25
#define COLUMN 30
class SnakeGame {
	private:
		typedef struct Fruit{
			int xHQ, yHQ;
			char hq = 'X';
		};
		
		typedef struct Snake{
			int x;
			int y; // toa do cac dot cua con snake		
			char ch; // ki tu cua dot	
		};
		Fruit fruit;
		char ctrl, tmp;
		int snakeLength; //
		Snake snake[12];
		int score, checkLost;
	public:
		SnakeGame(){//khoi tao con snake
			snake[0] = {3,5,(char)1};
			snake[1] = {2,5,'*'};
			snake[2] = {1,5,'*'};
			snake[3] = {0,5,'*'};
			snakeLength = 4;
			ctrl = 'd';
			tmp = ctrl;
			fruit.xHQ = snaked()%30 + 3;
			fruit.yHQ = snaked()%20 + 3;
			score = 0;
			checkLost = 0;
		}
		
		void control() {
			while(1) {
				clrscr1();
				showScreen(2);
				if (snake[0].x == fruit.xHQ && snake[0].y == fruit.yHQ) {
					fruit.xHQ = snaked()%25 + 2;
					fruit.yHQ = snaked()%20 + 2;
					score ++;
					snakeLength ++;
					snake[snakeLength - 1].ch = '*';
				}
				if (_kbhit()) {
					ctrl = _getch();
					if (ctrl == 'w' && tmp == 's')
						ctrl = 's';
					if (ctrl == 'd' && tmp == 'a')
						ctrl = 'a';
					if (ctrl == 'a' && tmp == 'd')
						ctrl = 'd';
					if (ctrl == 's' && tmp == 'w')
						ctrl = 'w';
					tmp = ctrl;
				}
				for (int i = snakeLength - 1; i >= 1; i --) {
					snake[i].y = snake[i-1].y;
					snake[i].x = snake[i-1].x;
				}
				if (ctrl == 'd') {
					snake[0].x ++;
					
				}
					
				if (ctrl == 'a') {
					snake[0].x --;
				}		
				if (ctrl == 's') {
					snake[0].y ++;
				}
				if (ctrl == 'w') {
					snake[0].y--;
				}
				for (int i = 1; i < snakeLength; i++) {
					if (snake[0].x == snake[i].x && snake[0].y == snake[i].y ) {
						clrscr1();
						cout << "thua";
						checkLost = 1;
						break;
					}
				}
				if (checkLost == 1)
					break;
				Sleep(200);
			}
			
		}
		
		void showScreen(int n) {

			for (int i = snakeLength - 1; i >= 0; i--) {
				gotoXY(snake[i].x, snake[i].y);
				cout << snake[i].ch;
			}
			if (n != 1) {
				gotoXY(30,0);
				cout << "score cua ban : " << score;
				gotoXY(fruit.xHQ,fruit.yHQ);
				cout << fruit.hq;
			}
			
		}
};

int main(int argc, char** argv) {
	SnakeGame snake;
	char str;
	int cot = 0;
	while(cot < 80) {
		clrscr1();
		gotoXY(cot, 5);
		snake.showScreen(1);
		Sleep(20);
		cot ++;
		if (cot == 76) {
			clrscr1();
			gotoXY(20, 5);
			TextColor(14);
			cout << "WELCOME TO GAME RAN SAN MOI II" << endl << endl << "\t\t\t  " << "Code by Que Cui";
			break;
		}	
	}
	
	cout << endl << endl << endl << endl;
	int sign = 0;
	do {
		if (sign == 1)
			break;
		cout << "\t\t\t1.Bat dau tro choi" << endl << endl;
		cout << "\t\t\t2.Xem score cao" << endl << endl;
		cout << "\t\t\t3.Huong dan choi" << endl << endl;
		cout << "\t\t\t4.Thoat" << endl;
		str = _getch();
		switch (str) {
			case '1': clrscr1(); snake.control(); sign = 1; break;
			case '2': break;
			case '3': clrscr1(); cout << "Dung 4 phim de dieu khien : W A S D" << endl << "Phim A : sang trai" << endl;
				cout << "Phim W : len tren" << endl << "Phim S : xuong duoi" << endl << "Phim D : sang phai"; Sleep(1900); clrscr1(); break;
			case '4': return 0; 
		}
	}while(1);
	
	TextColor(0);
}
