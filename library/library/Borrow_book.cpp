#include "Borrow_book.h"



CBorrow_book::CBorrow_book()
{
		cout << "�����������������" << endl;
		cin >> book_name;
		MYSQL *mysql = NULL;
		mysql = mysql_init((MYSQL *)0);
		char strsql[1000] = "select * from library where book_name = '";
		strcat_s(strsql, sizeof(strsql), book_name);
		strcat_s(strsql, sizeof(strsql), "'or book_id = '");
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
			0 //CLIENT_MULTI_STATEMENTS  //0 //ͨ����0
		);
		cout << command << endl;
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
		
		for(int j = 0; bookname[j] != NULL ; j++ )
		{ 
			booknum[j] = strtod(bookamount[j], &ptr);
		}
		
		if (bookname[0] == NULL )
		{
			cout << "�����û�и���" << endl;
		}
		else if (booknum[0] < 1)
		{
			cout << "�����Ѿ�������������û�д��" << endl;
		}
		else
		{
			for (int j = 0; bookname[j] != NULL; j++)
			{
				booknum[j] --;
				bookamount[j] = number_change_string(booknum[j]);
				cout << bookamount[j] << endl;
			}
			
			cout << "���������ID" << endl;
			cin >> reader_id;
			
			MYSQL *mysql = NULL;
			mysql = mysql_init((MYSQL *)0);
			strcpy_s(strsql, sizeof(strsql), "select reader_id ,reader_name from reader where reader_id = '");
			strcat_s(strsql, sizeof(strsql), reader_id);
			strcat_s(strsql, sizeof(strsql), "'");
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
				j++;
				printf("\n");
			}
			if (readerid[0] != "\0")
			{
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
				cout << "����ɹ�" << endl;
			}
			else
				cout << "�ö���ID�����ڣ�" << endl;
		}
}





CBorrow_book::~CBorrow_book()
{
}
