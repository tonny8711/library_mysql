#pragma once
#include "map"
#include "vector"
#include "string"
#include "iostream"
#include <stdio.h>  
#include <mysql.h>  
#include   <functional> 
#include   <algorithm> 
using namespace std;

class CLibrary
{
public:
	CLibrary();
	~CLibrary(); 
	void mysqlselect(char *command);
	void mysqlalter(char *command);
	void mysqlcreate(char *command);
	void mysqldelete(char *command);
	char ch1[100];
	char ch2[100];
	char ch3[100];
	char ch4[100];
	char ch5[100];
	char ch6[100];

	char ch7[100];
	char ch8[100];
	char* book_name = ch1;
	char* book_id = ch2;
	char* book_author = ch3;
	char* book_press = ch4;
	char* book_time = ch5;
	int book_acount = 1;
	char* reader_id = ch6;
	char* reader_name = ch7;
	char* strsql = ch8;
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	char* readerid[100] = { "\0" };
	char* readername[100] = { "\0" };
	int bookacount[100] = { 0 };
	/*char strsql[200];
	char* command = strsql;*/
};

