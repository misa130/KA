﻿// ka1_signed_integers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum states {
	S, A, B, E
}state = S;

int SA(string str);

int main() {
	setlocale(LC_ALL, "rus");

	int value_error = 0;
	string str = " gg +12 23 -34 45 + - ++ 2z";
	
	//while
	cout << "введите целое число со знаком\n";
	//getline(cin, str);
	cout << "вы ввели " << str << "\n";
	value_error = SA(str);
	if (value_error > 0) { cout << "в введенной строке " << value_error << " ошибок\n"; }
	else cout << "ошибок нет\n";
	system("pause");
	return 0;
}

int SA(string str) {
	int value_error = 0;
	char c;
	string buffer;
	for (int i = 0; i < str.size(); i++) {
		c = str.at(i);
		switch (state) {
		case S: {
			buffer = "";
			if (((c == '+') || (c == '-'))&&(i !=(str.size() -1))) { state = A; buffer = c; }else
			if ((c >= '0') && (c <= '9')) { state = B; buffer = c;}else
			if ((c == ' ') || (c == '\0') || (c == '\n')) { state = S; }else
			{buffer += c; value_error++; state = S; cout << "\tS error : " <<buffer<< endl;}
			break;
		}
		case A: {
			if ((c >= '0') && (c <= '9')) { state = B; buffer += c;}else
			{buffer += c; value_error++; state = S; cout << "\tA error : " << buffer << endl;}
			break;
		}
		case B: {
			if ((c >= '0') && (c <= '9')) { state = B; buffer += c;}else
			if ((c == ' ') || (c == '\0') || (c == '\n')) { state = S; cout << buffer << endl;}else
			{buffer += c; value_error++; state = S; cout << "\tB error : " << buffer << endl;}
			break;
		}
		//E не используется, потому что пропускается символ c, находясь в этом состоянии (проще написать функцию обработки ошибок чем кейс)
		case E: {
			state = S;
			break;
		}
		default: {}
		}

	}
	return value_error;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
