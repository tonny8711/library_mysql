#include "Library.h"



CLibrary::CLibrary()
{
}


CLibrary::~CLibrary()
{
}

//// mysql_test.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		table, //���ݿ�����
		0, //���ݿ�˿ڣ�0��ʾĬ�϶˿ڣ���3306��
		NULL, //���unix_socket����NULL���ַ���ָ���׽��ֻ�Ӧ�ñ�ʹ�õ������ܵ���ע��host�����������ӵ�����
		0 //CLIENT_MULTI_STATEMENTS  //0 //ͨ����0
	);

	if (!mysql) //����ʧ��
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("Select error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}

	MYSQL_RES *res = mysql_store_result(mysql); //��ȡ����ѯ���   
	MYSQL_FIELD *field = mysql_fetch_fields(res); //��ȡ��������
	int field_count = mysql_field_count(mysql); //��ȡ����

												//�����������
	for (int i = 0; i < field_count; i++)
	{
		printf("%s\t", field[i].name);
	}

	printf("\n");

	//�������ÿһ������  
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
	mysql_close(mysql); //�ر�����  

	system("pause");
	//return 0;
}

void CLibrary::mysqlalter(char *command)
{
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		"library", //���ݿ�����
		0, //���ݿ�˿ڣ�0��ʾĬ�϶˿ڣ���3306��
		NULL, //���unix_socket����NULL���ַ���ָ���׽��ֻ�Ӧ�ñ�ʹ�õ������ܵ���ע��host�����������ӵ�����
		0 //CLIENT_MULTI_STATEMENTS  //0 //ͨ����0
	);

	if (!mysql) //����ʧ��
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("alter error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}
	mysql_close(mysql); //�ر�����  

	system("pause");
}

void CLibrary::mysqlcreate(char *command)
{
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		"library", //���ݿ�����
		0, //���ݿ�˿ڣ�0��ʾĬ�϶˿ڣ���3306��
		NULL, //���unix_socket����NULL���ַ���ָ���׽��ֻ�Ӧ�ñ�ʹ�õ������ܵ���ע��host�����������ӵ�����
		0 //CLIENT_MULTI_STATEMENTS  //0 //ͨ����0
	);

	if (!mysql) //����ʧ��
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}
	mysql_close(mysql); //�ر�����  

	system("pause");
}

void CLibrary::mysqldelete(char *command)
{
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);

	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		"library", //���ݿ�����
		0, //���ݿ�˿ڣ�0��ʾĬ�϶˿ڣ���3306��
		NULL, //���unix_socket����NULL���ַ���ָ���׽��ֻ�Ӧ�ñ�ʹ�õ������ܵ���ע��host�����������ӵ�����
		0 //CLIENT_MULTI_STATEMENTS  //0 //ͨ����0
	);

	if (!mysql) //����ʧ��
	{
		printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
	}
	int flag = mysql_real_query(mysql, command, strlen(command));

	if (flag)
	{
		printf("delete error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
		exit(-1);
	}
	mysql_close(mysql); //�ر�����  

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