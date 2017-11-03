#include "Manage_book.h"
#include   "iostream"
using namespace std;




CManage_book::CManage_book()
{
	cout << "添加书籍输入1\t删除书籍输入2\t修改书籍输入3" << endl;
	int import_num = 0;
	cin >> import_num;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1)
	{
		if (import_num != 1 && import_num != 2 && import_num != 3)
		{
			cout << "输入有误，请重新输入" << endl;
			cin >> import_num;
			//cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
		alter_book();
		book_name = "\0";
	}
}


CManage_book::~CManage_book()
{
}

void CManage_book::create_book()
{
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	char* readerid[100] = { "\0" };
	char* readername[100] = { "\0" };
	char *bookamount[100] = { "\0" };
	cout << "请输出书名" << endl;
	cin >> book_name;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char strsql[1000] = "select book_name from library where book_name = '";
	strcat_s(strsql, sizeof(strsql), book_name);
	strcat_s(strsql, sizeof(strsql), "'");
	char* command = strsql;
	cout << command << endl;
	
	//sprintf_s(command,sizeof(command), "select book_name from library where book_name = '%s'", book_name);
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
	bookname[0] = "0";
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < field_count; i++)
		{
			bookname[i] = row[i];
			//cout << bookname[i];
			printf("%s\t", row[i]);
		}
		printf("\n");
	}
	mysql_close(mysql); //关闭连接  

	system("pause");
	if (bookname[0] != "0")
	{
		cout << "该书已存在" << endl;
	}
	else
	{
		cout << "请输入该书的编号" << endl;
		cin >> book_id;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "请输入该书的作者" << endl;
		cin >> book_author;
		cout << "请输入该书的出版社" << endl;
		cin >> book_press;
		cout << "请输入该书的出版时间" << endl;
		cin >> book_time;
		/*cout << "请输出书名" << endl;
		cin >> book_name;*/
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//初始化MySQL连接句柄
		MYSQL *mysql = NULL;
		mysql = mysql_init((MYSQL *)0);
		strcpy_s(strsql, sizeof(strsql), "insert into library (book_amount,book_name,book_id,book_author,book_press,book_time) values (");
		strcat_s(strsql, sizeof(strsql), "1,'");
		strcat_s(strsql, sizeof(strsql), book_name);
		strcat_s(strsql, sizeof(strsql), "','");
		strcat_s(strsql, sizeof(strsql), book_id);
		strcat_s(strsql, sizeof(strsql), "','");
		strcat_s(strsql, sizeof(strsql), book_author);
		strcat_s(strsql, sizeof(strsql), "','");
		strcat_s(strsql, sizeof(strsql), book_press);
		strcat_s(strsql, sizeof(strsql), "','");
		strcat_s(strsql, sizeof(strsql), book_time);
		strcat_s(strsql, sizeof(strsql), "')");
		cout << command << endl;
		//sprintf_s(command,sizeof(command), "insert into library (book_name,book_id,book_author,book_press,book_time) values (%s,%s,%s,%s,%s)", book_name,book_id, book_author, book_press, book_time);
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
			printf("Create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			exit(-1);
		}
		mysql_close(mysql); //关闭连接  

		system("pause");
	}
}

void CManage_book::alter_book() 
{
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	char* readerid[100] = { "\0" };
	char* readername[100] = { "\0" };
	char *bookamount[100] = { "\0" };
	cout << "请输出书名" << endl;
	cin >> book_name;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	strcpy_s(strsql,sizeof(strsql), "select book_name,book_id,book_author,book_press,book_time ,reader_id,reader_name ,book_amount from library where book_name = '");
	strcat_s(strsql, sizeof(strsql), book_name);
	strcat_s(strsql, sizeof(strsql), "'");
	cout << command << endl;
	/*char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select book_name,book_id,book_author,book_press,book_time from library where book_name = '%s'", book_name);*/
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
	bookname[0] = "\0";
	readername[0] = "\0";
	while (row = mysql_fetch_row(res))
	{
		i = 0;
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
		bookamount[j] =  row[i];
		printf("%s\t", row[i]);
		i++;
		j++;
		printf("\n");
	}
	mysql_close(mysql); //关闭连接  
	system("pause");

	if (bookname[0] == "\0")
	{
		cout << "书库中没有该书" << endl;
	}
	else if (readername[0] != NULL)
	{
		cout << "该书已借出！现无法修改" << endl;
	}
	else
	{
		cout << "是（1）否（0）修改？" << endl;
		int choice = -1;
		cin >> choice;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			cout << "请输入该书的书名" << endl;
			cin >> book_name;
			cout << "请输入该书的编号" << endl;
			cin >> book_id;
			//cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "请输入该书的作者" << endl;
			cin >> book_author;
			cout << "请输入该书的出版社" << endl;
			cin >> book_press;
			cout << "请输入该书的出版时间" << endl;
			cin >> book_time;
			//cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//初始化MySQL连接句柄
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			strcpy_s(strsql, sizeof(strsql), "delete from library where book_name = '");
			strcat_s(strsql, sizeof(strsql), bookname[0]);
			strcat_s(strsql, sizeof(strsql), "'");
			cout << command << endl;
			mysqldelete(command);
			strcpy_s(strsql, sizeof(strsql), "insert into library (book_name,book_id,book_author,book_press,book_time) values ('");
			strcat_s(strsql, sizeof(strsql), book_name);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), book_id);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), book_author);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), book_press);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), book_time);
			strcat_s(strsql, sizeof(strsql), "')");
			cout << command << endl;
			//sprintf_s(command,sizeof(command), "updata library set book_name = '%s',book_id = '%s',book_author = '%s',book_press = '%s',book_time = '%s'where book_name = '%s')", book_name, book_id, book_author, book_press, book_time,bookname[0]);
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
				printf("Create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
			mysql_close(mysql); //关闭连接  

			system("pause");
		}
		else if (choice != 0)
			cout << "输入有误" << endl;
	}
}

void CManage_book::delete_book()
{
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	char* readerid[100] = { "\0" };
	char* readername[100] = { "\0" };
	char *bookamount[100] = { "\0" };
	cout << "请输出书名" << endl;
	cin >> book_name;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//初始化MySQL连接句柄
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	strcpy_s(strsql, sizeof(strsql), "select book_name,book_id,book_author,book_press,book_time from library where book_name = '");
	strcat_s(strsql, sizeof(strsql), book_name);
	strcat_s(strsql, sizeof(strsql), "'");
	cout << command << endl;
	/*char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select book_name,book_id,book_author,book_press,book_time from library where book_name = '%s'", book_name);*/
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
	//row ;
	int i = 0;
	int j = 0;
	bookname[0] = "\0";
	while (row = mysql_fetch_row(res))
	{
		i = 0;
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
		j++;
		printf("\n");
	}
	mysql_close(mysql); //关闭连接  

	system("pause");
	if (bookname[0] == "\0")
	{
		cout << "书库中没有该书" << endl;
	}
	else
	{
		cout << "是（1）否（0）删除？" << endl;
		int choice = -1;
		cin >> choice;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			//初始化MySQL连接句柄
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			strcpy_s(strsql, sizeof(strsql), "delete from library where book_name = '");
			strcat_s(strsql, sizeof(strsql), book_name);
			strcat_s(strsql, sizeof(strsql), "'");
			cout << command << endl;
			mysqldelete(command);
			///*sprintf_s(command,sizeof(command), "delete * from library where book_name = '%s'", book_name);
			//mysql_real_connect*/
			//(
			//	mysql,
			//	"localhost", //数据库地址
			//	"root", //数据库用户名
			//	"123456", //数据库密码
			//	"library", //数据库名称
			//	0, //数据库端口，0表示默认端口（即3306）
			//	NULL, //如果unix_socket不是NULL，字符串指定套接字或应该被使用的命名管道。注意host参数决定连接的类型
			//	0 //CLIENT_MULTI_STATEMENTS  //0 //通常是0
			//);

			//if (!mysql) //连接失败
			//{
			//	printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			//}
			//int flag = mysql_real_query(mysql, command, strlen(command));

			//if (flag)
			//{
			//	printf("delete error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			//	exit(-1);
			//}
			//mysql_close(mysql); //关闭连接  

			//system("pause");
		}
	}

}
