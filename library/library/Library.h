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
	char* book_name = "\0";
	char* book_id = "\0";
	char* book_author = "\0";
	char* book_press = "\0";
	char* book_time = "\0";
	int book_acount = 1;
	char* reader_id = "\0";
	char* reader_name = "\0";
	char* strsql = "\0";
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	int bookacount[100] = { 0 };
};

