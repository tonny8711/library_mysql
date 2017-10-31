#include "Reader.h"



CReader::CReader()
{
	cout << "添加读者输入1\t删除读者输入2\t修改读者输入3" << endl;
	int import_num = 0;
	cin >> import_num;
	//cin.clear();
	////cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
		create_reader();
	}
	if (import_num == 2)
	{
		delete_reader();
	}
	if (import_num == 3)
	{
		delete_reader();
	}
}


CReader::~CReader()
{
}

void CReader::create_reader()
{
	cout << "请输入读者的ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command),"select reader_id from reader where reader_id = '%s'", reader_id);
	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"reader", //数据库名称
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
			readerid[i] = row[i];
			printf("%s\t", row[i]);
		}
		printf("\n");
	}
	if (readerid[0] != "\0")
	{
		cout << "该读者ID已存在" << endl;
	}
	else
	{
		cout << "请输入读者名字" << endl;
		cin >> reader_name;
		MYSQL *mysql = NULL;
		mysql = mysql_init((MYSQL *)0);
		sprintf_s(command,sizeof(command), "insert into reader (reader_id,reader_name) values (%s,%s)", reader_id,reader_name);
		mysql_real_connect
		(
			mysql,
			"localhost", //数据库地址
			"root", //数据库用户名
			"123456", //数据库密码
			"reader", //数据库名称
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
			printf("Create reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			exit(-1);
		}
	}
}


void CReader::alter_reader()
{
	cout << "请输入读者的ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);
	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"reader", //数据库名称
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
	MYSQL_ROW row = mysql_fetch_row(res);
	int i = 0;
	int j = 0;
	while (j < field_count)
	{
		i = 0;
		readerid[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		readername[i] = row[i];
		printf("%s\t", row[i]);
		printf("\n");
		j++;
		i++;
	}
	if (reader_id == "\0")
	{
		cout << "该ID不存在" << endl;
	}
	else
	{
		cout << "是（1）否（0）要修改？" << endl;
		string choice = "-1";
		cin >> choice;
		if (choice == "1")
		{
			cout << "请输入新的ID" << endl;
			cin >> reader_id;
			cout << "请输入新的姓名" << endl;
			cin >> reader_name;
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			sprintf_s(command,sizeof(command), "updata reader set reader_id = '%s',reader_name = '%s' where reader_name = '%s')", reader_id, reader_name, readername[0]);
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
				printf("Create reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
		else if (choice != "0")
			cout << "输入有误" << endl;
	}
}


void CReader::delete_reader()
{
	cout << "请输入读者的ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);
	mysql_real_connect
	(
		mysql,
		"localhost", //数据库地址
		"root", //数据库用户名
		"123456", //数据库密码
		"reader", //数据库名称
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
	MYSQL_ROW row = mysql_fetch_row(res);
	int i = 0;
	int j = 0;
	while (j < field_count)
	{
		i = 0;
		readerid[i] = row[i];
		printf("%s\t", row[i]);
		i++;
		readername[i] = row[i];
		printf("%s\t", row[i]);
		printf("\n");
		j++;
		i++;
	}
	if (reader_id == "\0")
	{
		cout << "该ID不存在" << endl;
	}
	else
	{
		cout << "是（1）否（0）删除？" << endl;
		string choice = "-1";
		cin >> choice;
		if (choice == "1")
		{
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			sprintf_s(command,sizeof(command), "delete * from reader where reader_id = '%s')", reader_id);
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
				printf("delete reader reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
		else if (choice != "0")
			cout << "输入有误" << endl;
	}
}
