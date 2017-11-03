#include "Library.h"



CLibrary::CLibrary()
{
}


CLibrary::~CLibrary()
{
}

//// mysql_test.cpp : 定义控制台应用程序的入口点。
////
//
//#include "stdafx.h"
//
//
//int main()
//{
//    return 0;
//}
//






void CLibrary::mysqlselect(char *command,char *table)
{
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		table, //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //CLIENT_MULTI_STATEMENTS  //0 //通常是0
	);

	if (!mysql) //连接失败
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("Select error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}

	MYSQL_RES *res = mysql_store_result(mysql); //读取将查询结果   
	MYSQL_FIELD *field = mysql_fetch_fields(res); //获取所有列名
	int field_count = mysql_field_count(mysql); //获取列数

												//输出所有列名
	for (int i = 0; i < field_count; i++)
	{
		printf("%s\t", field[i].name);
	}

	printf("\n");

	//遍历输出每一行数据  
	MYSQL_ROW row;
	int i = 0;
	int j = 0;
	char *ch_num[10] = { "\0" };
	if (table == "library")
	{
		while (row = mysql_fetch_row(res))
		{
			i = 0;
			ch_num[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			bookname[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			bookid[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			bookauthor[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			bookpress[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			booktime[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			readerid[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			readername[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			bookamount[j] = row[i];
			printf("%s\t", row[i]);
			j++;
			printf("\n");
		}
	}
	else
	{
		while (row = mysql_fetch_row(res))
		{
			i = 0;
			readerid[j] = row[i];
			printf("%s\t", row[i]);
			i++;
			readername[j] = row[i];
			printf("%s\t", row[i]);
			i++;
		}
	}
	mysql_close(mysql); //关闭连接  

	system("pause");
	//return 0;
}

void CLibrary::mysqlalter(char *command)
{
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"library", //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //CLIENT_MULTI_STATEMENTS  //0 //通常是0
	);

	if (!mysql) //连接失败
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("alter error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}
	mysql_close(mysql); //关闭连接  

	system("pause");
}

void CLibrary::mysqlcreate(char *command)
{
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"library", //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //CLIENT_MULTI_STATEMENTS  //0 //通常是0
	);

	if (!mysql) //连接失败
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}
	mysql_close(mysql); //关闭连接  

	system("pause");
}

void CLibrary::mysqldelete(char *command)
{
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"library", //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //CLIENT_MULTI_STATEMENTS  //0 //通常是0
	);

	if (!mysql) //连接失败
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("delete error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}
	mysql_close(mysql); //关闭连接  

	system("pause");
}


char* CLibrary::number_change_string(int num )
{
	int i[100];
	int j = 0;
	for (; num >= 10; j++)
	{
		i[j] = num % 10;
		num = num / 10;
	}
	i[j] = num;
	ch[j + 1] = '\0';
	for (; j >= 0; j--)
	{
		ch[j] = (char)(i[j] + 48);
		cout << ch[j] << endl;
	}
	return ch;
}