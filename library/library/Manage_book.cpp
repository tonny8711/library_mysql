#include "Manage_book.h"
#include   "iostream"
using namespace std;




CManage_book::CManage_book()
{
	cout << "����鼮����1\tɾ���鼮����2\t�޸��鼮����3" << endl;
	int import_num = 0;
	cin >> import_num;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	cout << "���������" << endl;
	cin >> book_name;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char strsql[1000] = "select book_name from library where book_name = '";
	strcat_s(strsql, sizeof(strsql), book_name);
	strcat_s(strsql, sizeof(strsql), "'");
	char* command = strsql;
	
	//sprintf_s(command,sizeof(command), "select book_name from library where book_name = '%s'", book_name);
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
			bookname[i] = row[i];
			printf("%s\t", row[i]);
		}
		printf("\n");
	}
	if (bookname[1] != NULL)
	{
		cout << "�����Ѵ���" << endl;
	}
	else
	{
		cout << "���������ı��" << endl;
		cin >> book_id;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "��������������" << endl;
		cin >> book_author;
		cout << "���������ĳ�����" << endl;
		cin >> book_press;
		cout << "���������ĳ���ʱ��" << endl;
		cin >> book_time;
		/*cout << "���������" << endl;
		cin >> book_name;*/
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//��ʼ��MySQL���Ӿ��
		MYSQL *mysql = NULL;
		mysql = mysql_init((MYSQL *)0);
		strcpy_s(strsql, sizeof(strsql), "insert into library (id,book_amount,book_name,book_id,book_author,book_press,book_time) values (");
		strcat_s(strsql, sizeof(strsql), "2,1,'");
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
			printf("Create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
			exit(-1);
		}
	}
}

void CManage_book::alter_book() 
{
	cout << "���������" << endl;
	cin >> book_name;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select book_name,book_id,book_author,book_press,book_time from library where book_name = '%s'", book_name);
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
	row = mysql_fetch_row(res);
	int i = 0;
	int j = 0;
	while (j < field_count)
	{
		i = 0;
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
		j++;
		printf("\n");
	}
	if (bookname[0] == "\0")
	{
		cout << "�����û�и���" << endl;
	}
	else
	{
		cout << "�ǣ�1����0���޸ģ�" << endl;
		int choice = -1;
		cin >> choice;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			cout << "��������������" << endl;
			cin >> book_name;
			cout << "���������ı��" << endl;
			cin >> book_id;
			//cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "��������������" << endl;
			cin >> book_author;
			cout << "���������ĳ�����" << endl;
			cin >> book_press;
			cout << "���������ĳ���ʱ��" << endl;
			cin >> book_time;
			cout << "���������" << endl;
			cin >> book_name;
			//cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			//��ʼ��MySQL���Ӿ��
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			sprintf_s(command,sizeof(command), "updata library set book_name = '%s',book_id = '%s',book_author = '%s',book_press = '%s',book_time = '%s'where book_name = '%s')", book_name, book_id, book_author, book_press, book_time,bookname[0]);
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
				printf("Create error:%d, %s\n", mysql_errno(mysql), mysql_error(mysql));
				exit(-1);
			}
		}
		else if (choice != 0)
			cout << "��������" << endl;
	}
}

void CManage_book::delete_book()
{
	cout << "���������" << endl;
	cin >> book_name;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//��ʼ��MySQL���Ӿ��
	MYSQL *mysql = NULL;
	mysql = mysql_init((MYSQL *)0);
	char* command = "qwerwqerasdfasdfasdfasdfasdfzxcvsadfasdfasdfasdfasdfasdfasdfasdf";
	sprintf_s(command,sizeof(command), "select book_name,book_id,book_author,book_press,book_time from library where book_name = '%s'", book_name);
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
		cout << "�����û�и���" << endl;
	}
	else
	{
		cout << "�ǣ�1����0��ɾ����" << endl;
		int choice = -1;
		cin >> choice;
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (choice == 1)
		{
			//��ʼ��MySQL���Ӿ��
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			sprintf_s(command,sizeof(command), "delete * from library where book_name = '%s'", book_name);
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
	}

}
