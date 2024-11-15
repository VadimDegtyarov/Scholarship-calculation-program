	#pragma once
	#include <iostream>
	#include <string>
	#include <fstream>
	#include<windows.h>
	#include<vector>
	#include<stdlib.h>
	#include<conio.h>
	#include <iomanip>
	#include <algorithm>


	#define UP 72
	#define DOWN 80
	#define ESC 27
	#define ENTER 13

	using namespace std;
	struct users
	{
		string login;
		string changelogin;
		bool isadmin = false;
	};
	struct students
	{
	
		string Name;
		string group;
		bool FormOfEducation;
	
		string scores;
	};


	extern int NUMOFUSER;
	extern HANDLE hStdOut;

	extern vector<users>user;
	extern vector<students>info;
	extern vector<string> student;
	extern users userinstruct;
	extern students infoinstruct;
	extern fstream DataF;
	extern fstream fs;
	extern vector<string> infstud;
	void GoToXY(short x, short y);
	void ConsoleCursorVisible(bool show, short size);
	void registration();
	void autorization();
	int wherey();
	void Mainmenu();
	void menuuser();

	void OutputInfo();
	void InputInfo();

	void Sort();
	void Search();

	void Schship();
	void ChangeStud();