#include "stdafx.h"

#include "HeaderIdzika.h"

#include <iostream>
#include <windows.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main()
{
	BOOL b = CopyFile((LPCWSTR)"C:/kupa.txt", (LPCWSTR)"C:\\Users\\Michał\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2", true);
	if (!b) {
		cout << "Error: " << GetLastError() << endl;
	}
	else {
		cout << "Okay " << endl;
	}
	//CopyFile((LPCWSTR)"C:\\kod_visio.jpg", (LPCWSTR)"C:\\Users\\Michał\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2",false);
	//CopyFileA("C:\\kod_visio.jpg", "C:\\Users\\Michał\\Documents\\Visual Studio 2017\\Projects\\ConsoleApplication2", true);
	//cin.get();
	system("pause");
	return 0;
}
