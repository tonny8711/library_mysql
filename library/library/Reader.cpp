#include "Reader.h"



CReader::CReader()
{
	cout << "��Ӷ�������1\tɾ����������2\t�޸Ķ�������3" << endl;
	int import_num = 0;
	cin >> import_num;
	//cin.clear();
	////cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1)
	{
		if (import_num != 1 && import_num != 2 && import_num != 3)
		{
			cout << "������������������" << endl;
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
	cout << "��������ߵ�ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command),"select reader_id from reader where reader_id = '%s'", reader_id);
	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		"reader", //���ݿ�����
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
			readerid[i] = row[i];
			printf("%s\t", row[i]);
		}
		printf("\n");
	}
	if (readerid[0] != "\0")
	{
		cout << "�ö���ID�Ѵ���" << endl;
	}
	else
	{
		cout << "�������������" << endl;
		cin >> reader_name;
		MYSQL *mysql = NULL;
		mysql = mysql_init((MYSQL *)0);
		sprintf_s(command,sizeof(command), "insert into reader (reader_id,reader_name) values (%s,%s)", reader_id,reader_name);
		mysql_real_connect
		(
			mysql,
			"localhost", //���ݿ��ַ
			"root", //���ݿ��û���
			"123456", //���ݿ�����
			"reader", //���ݿ�����
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
			printf("Create reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			exit(-1);
		}
	}
}


void CReader::alter_reader()
{
	cout << "��������ߵ�ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);
	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		"reader", //���ݿ�����
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
		cout << "��ID������" << endl;
	}
	else
	{
		cout << "�ǣ�1����0��Ҫ�޸ģ�" << endl;
		string choice = "-1";
		cin >> choice;
		if (choice == "1")
		{
			cout << "�������µ�ID" << endl;
			cin >> reader_id;
			cout << "�������µ�����" << endl;
			cin >> reader_name;
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			sprintf_s(command,sizeof(command), "updata reader set reader_id = '%s',reader_name = '%s' where reader_name = '%s')", reader_id, reader_name, readername[0]);
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
				printf("Create reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
		else if (choice != "0")
			cout << "��������" << endl;
	}
}


void CReader::delete_reader()
{
	cout << "��������ߵ�ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);
	mysql_real_connect
	(
		mysql,
		"localhost", //���ݿ��ַ
		"root", //���ݿ��û���
		"123456", //���ݿ�����
		"reader", //���ݿ�����
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
		cout << "��ID������" << endl;
	}
	else
	{
		cout << "�ǣ�1����0��ɾ����" << endl;
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
				printf("delete reader reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
		else if (choice != "0")
			cout << "��������" << endl;
	}
}
