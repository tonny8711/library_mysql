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
		alter_reader();
	}
}


CReader::~CReader()
{
}

void CReader::create_reader()
{
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	char* readerid[100] = { "\0" };
	char* readername[100] = { "\0" };
	char *bookamount[100] = { "\0" };
	cout << "��������ߵ�ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	strcpy_s(strsql, sizeof(strsql), "select reader_id from reader where reader_id = '");
	strcat_s(strsql, sizeof(strsql), reader_id);
	strcat_s(strsql, sizeof(strsql), "'");
	cout << command << endl;
	//mysqlcreate(command, "library");
	/*char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command),"select reader_id from reader where reader_id = '%s'", reader_id);*/
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
	mysql_close(mysql); //�ر�����  

	system("pause");
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
		strcpy_s(strsql, sizeof(strsql), "insert into reader (reader_id,reader_name) values ('");
		strcat_s(strsql, sizeof(strsql), reader_id);
		strcat_s(strsql, sizeof(strsql), "','");
		strcat_s(strsql, sizeof(strsql), reader_name);
		strcat_s(strsql, sizeof(strsql), "')");
		cout << command << endl;
		//sprintf_s(command,sizeof(command), "insert into reader (reader_id,reader_name) values (%s,%s)", reader_id,reader_name);
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
			printf("Create reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			exit(-1);
		}
	}
}


void CReader::alter_reader()
{
	char* bookname[100] = { "\0" };
	char* bookid[100] = { "\0" };
	char* bookauthor[100] = { "\0" };
	char* bookpress[100] = { "\0" };
	char* booktime[100] = { "\0" };
	char* readerid[100] = { "\0" };
	char* readername[100] = { "\0" };
	char *bookamount[100] = { "\0" };
	cout << "��������ߵ�ID" << endl;
	cin >> reader_id;
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	strcpy_s(strsql, sizeof(strsql), "select reader_id ,reader_name from reader where reader_id = '");
	strcat_s(strsql, sizeof(strsql), reader_id);
	strcat_s(strsql, sizeof(strsql), "'");
	cout << command << endl;
	/*char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);*/
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
	MYSQL_ROW row ;
	int i = 0;
	int j = 0;
	readerid[0] = "\0";
	while (row = mysql_fetch_row(res))
	{
		i = 0;
		readerid[j] = row[i];
		printf("%s\t", row[i]);
		i++;
		readername[j] = row[i];
		printf("%s\t", row[i]);
		printf("\n");
		j++;
	}
	mysql_close(mysql); //�ر�����  

	system("pause");
	if (readerid[0] == "\0")
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
			char* readerid_ = readerid[0];
			while (1)
			{
				cout << "�������µ�ID" << endl;
				cin >> reader_id;
				MYSQL *mysql = NULL;
				mysql = mysql_init((MYSQL *)0);
				strcpy_s(strsql, sizeof(strsql), "select reader_id ,reader_name from reader where reader_id = '");
				strcat_s(strsql, sizeof(strsql), reader_id);
				strcat_s(strsql, sizeof(strsql), "'");
				cout << command << endl;
				/*char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
				sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);*/
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
					printf("Select error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
					exit(-1);
				}
				MYSQL_RES *res = mysql_store_result(mysql); //��ȡ����ѯ���   
				MYSQL_FIELD *field = mysql_fetch_fields(res); //��ȡ��������
				int field_count = mysql_field_count(mysql); //��ȡ����

															//�����������
				/*for (int i = 0; i < field_count; i++)
				{
					printf("%s\t", field[i].name);
				}*/

				printf("\n");

				//�������ÿһ������  
				MYSQL_ROW row;
				int i = 0;
				int j = 0;
				readerid[0] = "\0";
				while (row = mysql_fetch_row(res))
				{
					i = 0;
					readerid[j] = row[i];
					//printf("%s\t", row[i]);
					i++;
					readername[j] = row[i];
					/*printf("%s\t", row[i]);
					printf("\n");*/
					j++;
				}
				mysql_close(mysql); //�ر�����  

				system("pause");
				if (readerid[0] == "\0")
				{
					break;
				}
				else
				{
					cout << "�ö���ID�Ѵ��ڣ����������룡" << endl;
				}
			}
			cout << "�������µ�����" << endl;
			cin >> reader_name;
			MYSQL *mysql = NULL;
			strcpy_s(strsql, sizeof(strsql), "delete from reader where reader_id = '");
			strcat_s(strsql, sizeof(strsql), readerid_);
			strcat_s(strsql, sizeof(strsql), "'");
			cout << command << endl;
			mysqlalter(command);
			strcpy_s(strsql, sizeof(strsql), "insert into reader values ('");
			strcat_s(strsql, sizeof(strsql), reader_id);
			strcat_s(strsql, sizeof(strsql), "','");
			strcat_s(strsql, sizeof(strsql), reader_name);
			strcat_s(strsql, sizeof(strsql), "')");
			cout << command << endl;
			mysqlcreate(command);
			/*mysql = mysql_init((MYSQL *)0);
			sprintf_s(command,sizeof(command), "updata reader set reader_id = '%s',reader_name = '%s' where reader_name = '%s')", reader_id, reader_name, readername[0]);*/
			//mysql_real_connect
			//(
			//	mysql,
			//	"localhost", //���ݿ��ַ
			//	"root", //���ݿ��û���
			//	"123456", //���ݿ�����
			//	"library", //���ݿ�����
			//	0, //���ݿ�˿ڣ�0��ʾĬ�϶˿ڣ���3306��
			//	NULL, //���unix_socket����NULL���ַ���ָ���׽��ֻ�Ӧ�ñ�ʹ�õ������ܵ���ע��host�����������ӵ�����
			//	0 //CLIENT_MULTI_STATEMENTS  //0 //ͨ����0
			//);

			//if (!mysql) //����ʧ��
			//{
			//	printf("Connection error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			//}
			//int flag = mysql_real_query(mysql, command, strlen(command));

			//if (flag)
			//{
			//	printf("Create reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			//	exit(-1);
			//}
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
	strcpy_s(strsql, sizeof(strsql),"select reader_id,reader_name from reader where reader_id = '" );
	strcat_s(strsql, sizeof(strsql), reader_id );
	strcat_s(strsql, sizeof(strsql), "'");
	cout << command << endl;
	/*char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select reader_id,reader_name from reader where reader_id = '%s'", reader_id);*/
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
	MYSQL_ROW row ;
	int i = 0;
	int j = 0;
	readerid[0] = "\0";
	while (row = mysql_fetch_row(res))
	{
		i = 0;
		readerid[j] = row[i];
		printf("%s\t", row[i]);
		i++;
		readername[j] = row[i];
		printf("%s\t", row[i]);
		printf("\n");
		j++;
	}
	if (readerid[0] == "\0")
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
			strcpy_s(strsql, sizeof(strsql), "delete from reader where reader_id = '");
			strcat_s(strsql, sizeof(strsql), reader_id);
			strcat_s(strsql, sizeof(strsql), "'");
			cout << command << endl;
			//sprintf_s(command,sizeof(command), "delete * from reader where reader_id = '%s')", reader_id);
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
				printf("delete reader reader error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
		else if (choice != "0")
			cout << "��������" << endl;
	}
}
