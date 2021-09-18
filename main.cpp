#include<iostream>
using namespace std;

#define TRIANGLE_4
//#define DIAMOND
//#define CHESS_1
//#define CHESS_3

void main()
{
	setlocale(LC_ALL, "Russian");
	int num;
	cout << "¬ведите размер фигуры: ";
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