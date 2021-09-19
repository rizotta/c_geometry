#include<iostream>
using namespace std;

//#define TRIANGLE_4
//#define DIAMOND
//#define CHESS_1
#define CHESS_2
//#define CHESS_3

#define UPPER_LEFT_ANGLE	(char)218
#define UPPER_RIGHT_ANGLE	(char)191
#define LOWER_RIGHT_ANGLE	(char)217
#define LOWER_LEFT_ANGLE	(char)192
#define VERT_LINE			(char)179
#define HORIZ_LINE			"\xC4\xC4" //(char)196
#define WHITE_BOX			"\xDB\xDB" //(char)219
#define BLACK_BOX			"  "

void main()
{
	setlocale(LC_ALL, "Russian");
	int num;
	cout << "Введите размер фигуры: ";
	cin >> num;

#ifdef TRIANGLE_4
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num - 1; j++) {
			cout << "  ";
		}
		for (int j = 0; j <= i; j++) {
			cout << "* ";
		}
		cout << endl;
	}
#endif

#ifdef DIAMOND
	for (int i = 0; i < num; i++) {
		for (int j = i; j < num - 1; j++) {
			cout << " ";
		}
		cout << "/";

		for (int j = 0; j < i * 2; j++) {
			cout << " ";
		}

		cout << "\\";
		for (int j = i; j < num - 1; j++) {
			cout << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << "\\";

		for (int j = 0; j < (num - i - 1) * 2; j++) {
			cout << " ";
		}
		cout << "/";

		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		cout << endl;
	}
#endif

#ifdef CHESS_1 
	bool flag;
	for (int i = 0; i < num; i++)
	{
		if (i % 2) {
			flag = false;
		}
		else {
			flag = true;
		}
		for (int i = 0; i < num; i++)
		{
			if (i % 2 == flag) {
				cout << "- ";
			}
			else {
				cout << "+ ";
			}
		}
		cout << endl;
	}
#endif

#ifdef CHESS_2
	setlocale(LC_ALL, "C");
	num++;
	for (int i = 0; i <= num; i++)
	{
		for (int j = 0; j <= num; j++)
		{
			if (i == 0 && j == 0) cout << UPPER_LEFT_ANGLE;
			else if (i == 0 && j == num) cout << UPPER_RIGHT_ANGLE;
			else if (i == num && j == 0) cout << LOWER_LEFT_ANGLE;
			else if (i == num && j == num) cout << LOWER_RIGHT_ANGLE;
			else if (i == 0 || i == num) cout << HORIZ_LINE;
			else if (j == 0 || j == num) cout << VERT_LINE;
			else cout << ((i + j) % 2 == 0 ? WHITE_BOX : BLACK_BOX);
		}
		cout << endl;
	}
#endif

#ifdef CHESS_3 
	bool flag = 0;
	for (int i = 1; i <= num * num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			for (int k = 0; k < num; k++)
			{
				if ((j % 2 && flag == false) || (j % 2 == false && flag)) {
					cout << "  ";
				}
				else {
					cout << "* ";
				}
			}
		}
		cout << endl;
		if (i % num == false) {
			flag = !flag;
		}
	}
#endif

}