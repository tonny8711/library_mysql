#include "Manage_book.h"
#include   "iostream"
using namespace std;




CManage_book::CManage_book()
{
	cout << "添加书籍输入1\t删除书籍输入2\t修改书籍输入3" << endl;
	int import_num = 0;
	cin >> import_num;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1)
	{
		if (import_num != 1 && import_num != 2 && import_num != 3)
		{
			cout << "输入有误，请重新输入" << endl;
			cin >> import_num;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}
	if (import_num == 1)
	{
		create_book();
		book_name = "\0";
	}
	if (import_num == 2)
	{
		delete_book();
		book_name = "\0";
	}
	if (import_num == 3)
	{
		delete_book();
		book_name = "\0";
	}
}


CManage_book::~CManage_book()
{
}

void CManage_book::create_book()
{
	cout << "请输出书名" << endl;
	cin >> book_name;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command;
	snprintf(command, "select book_name from library where book_name = '%s'", book_name);
	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"library", //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //通常是0
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
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < field_count; i++)
		{
			bookname[i] = row[i];
			printf("%s\t", row[i]);
		}
		printf("\n");
	}
	if (bookname[1] != "\0")
	{
		cout << "该书已存在" << endl;
	}
	else
	{
		cout << "请输入该书的编号" << endl;
		cin >> book_id;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入该书的作者" << endl;
		cin >> book_author;
		cout << "请输入该书的出版社" << endl;
		cin >> book_press;
		cout << "请输入该书的出版时间" << endl;
		cin >> book_time;
		cout << "请输出书名" << endl;
		cin >> book_name;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//初始化MySQL连接句柄
		MYSQL *mysql = NULL;
		mysql = mysql_init((MYSQL *)0);
		snprintf(command, "insert into library (book_name,book_id,book_author,book_press,book_time) values (%s,%s,%s,%s,%s)", book_name,book_id, book_author, book_press, book_time);
		mysql_real_connect
		(
			mysql,
			"localhost", //数据库地址
			"root", //数据库用户名
			"123456", //数据库密码
			"library", //数据库名称
			0, //数据库端口，0表示默认端口（即3306）
			NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
			0 //通常是0
		);

		if (!mysql) //连接失败
		{
			printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		}
		int flag = mysql_real_query(mysql, command, strlen(command));

		if (flag)
		{
			printf("Create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			exit(-1);
		}
	}
}

void CManage_book::alter_book() 
{
	cout << "请输出书名" << endl;
	cin >> book_name;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command;
	snprintf(command, "select book_name,book_id,book_author,book_press,book_time from library where book_name = '%s'", book_name);
	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"library", //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //通常是0
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
	row = mysql_fetch_row(res);
	int i = 0;
	while (i < field_count)
	{
		bookname[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		bookid[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		bookauthor[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		bookpress[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		booktime[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		printf("\n");
	}
	if (bookname[0] == "\0")
	{
		cout << "书库中没有该书" << endl;
	}
	else
	{
		cout << "是（1）否（0）修改？" << endl;
		int choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			cout << "请输入该书的书名" << endl;
			cin >> book_name;
			cout << "请输入该书的编号" << endl;
			cin >> book_id;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "请输入该书的作者" << endl;
			cin >> book_author;
			cout << "请输入该书的出版社" << endl;
			cin >> book_press;
			cout << "请输入该书的出版时间" << endl;
			cin >> book_time;
			cout << "请输出书名" << endl;
			cin >> book_name;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//初始化MySQL连接句柄
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			snprintf(command, "updata library set book_name = '%s',book_id = '%s',book_author = '%s',book_press = '%s',book_time = '%s')", book_name, book_id, book_author, book_press, book_time);
			mysql_real_connect
			(
				mysql,
				"localhost", //数据库地址
				"root", //数据库用户名
				"123456", //数据库密码
				"library", //数据库名称
				0, //数据库端口，0表示默认端口（即3306）
				NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
				0 //通常是0
			);

			if (!mysql) //连接失败
			{
				printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			}
			int flag = mysql_real_query(mysql, command, strlen(command));

			if (flag)
			{
				printf("Create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
	}
}

void CManage_book::delete_book()
{
	cout << "请输出书名" << endl;
	cin >> book_name;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command;
	snprintf(command, "select book_name,book_id,book_author,book_press,book_time from library where book_name = '%s'", book_name);
	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"library", //数据库名称
		0, //数据库端口，0表示默认端口（即3306）
		NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
		0 //通常是0
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
	row = mysql_fetch_row(res);
	int i = 0;
	while (i < field_count)
	{
		bookname[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		bookid[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		bookauthor[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		bookpress[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		booktime[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		printf("\n");
	}
	if (bookname[0] == "\0")
	{
		cout << "书库中没有该书" << endl;
	}
	else
	{
		cout << "是（1）否（0）删除？" << endl;
		int choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			//初始化MySQL连接句柄
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			snprintf(command, "delete * from library where book_name = '%s'", book_name);
			mysql_real_connect
			(
				mysql,
				"localhost", //数据库地址
				"root", //数据库用户名
				"123456", //数据库密码
				"library", //数据库名称
				0, //数据库端口，0表示默认端口（即3306）
				NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
				0 //通常是0
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
		}
	}

}
