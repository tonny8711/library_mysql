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






void CLibrary::mysqlselect(char *command)
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
		0 //ͨ����0
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
	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < field_count; i++)
		{
			printf("%s\t", row[i]);
		}
		printf("\n");
	}
	//sqlselect(mysql, command); //��ѯ����   
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
		0 //ͨ����0
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
		0 //ͨ����0
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
		0 //ͨ����0
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
}

