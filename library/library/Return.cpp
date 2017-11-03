#include "Return.h"



CReturn::CReturn()
{
	cout << "请输入读者ID" << endl;
	cin >> reader_id;
	cout << "请输入要还的书名字或者编号" << endl;
	cin >> book_name;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char strsql[1000] = "select * from library where reader_id = '";
	strcat_s(strsql, sizeof(strsql), reader_id);
	strcat_s(strsql, sizeof(strsql), "' and (");
	strcat_s(strsql, sizeof(strsql), "book_name = '");
	strcat_s(strsql, sizeof(strsql), book_name);
	strcat_s(strsql, sizeof(strsql), "' or ");
	strcat_s(strsql, sizeof(strsql), "book_id = '");
	strcat_s(strsql, sizeof(strsql), book_name);
	strcat_s(strsql, sizeof(strsql), "')");
	char* command = strsql;

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
	cout << command << endl;
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
		printf("%s\t", row[i]);
		i++;
		printf("%s\t", row[i]);
		i++;
		bookamount[j] = row[i];
		printf("%s\t", row[i]);
		j++;
		printf("\n");
	}

	for (int j = 0; bookname[j] != NULL; j++)
	{
		booknum[j] = strtod(bookamount[j], &ptr);
	}

	if (bookname[0] == NULL)
	{
		cout << "当前你还没有借该书！" << endl;
	}
	else
	{
		for (int j = 0; bookname[j] != NULL; j++)
		{
			booknum[j] ++;
			bookamount[j] = number_change_string(booknum[j]);
			cout << bookamount[j] << endl;
		}
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);

			strcpy_s(strsql, sizeof(strsql), "delete from library where book_name = '");
			strcat_s(strsql, sizeof(strsql), bookname[0]);
			strcat_s(strsql, sizeof(strsql), "'");
			cout << command << endl;
			mysqldelete(command);
			strcpy_s(strsql, sizeof(strsql), "insert into library (book_amount,reader_name,reader_id,book_name,book_id,book_author,book_press,book_time) values ( ");
			strcat_s(strsql, sizeof(strsql), bookamount[0]);
			strcat_s(strsql, sizeof(strsql), ", '");
			strcat_s(strsql, sizeof(strsql), readername[0]);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), readerid[0]);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), bookname[0]);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), bookid[0]);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), bookauthor[0]);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), bookpress[0]);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), booktime[0]);
			strcat_s(strsql, sizeof(strsql), "')");
			cout << command << endl;
			mysqlcreate(command);
			cout << "还书成功" << endl;
	}
}


CReturn::~CReturn()
{
}
