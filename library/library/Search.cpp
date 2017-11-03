#include "Search.h"



CSearch::CSearch()
{

	cout << "书号搜索（1）、书名搜索（2）、作者搜索（3）、出版社搜索（4）、出版时间搜索（5）、多项搜索（6）" << endl;
	string choice = "-1";
	cin >> choice;
	if (choice == "1")
	{
		cout << "请输入书号" << endl;
		cin >> book_id;
		strcpy_s(strsql, sizeof(strsql), "select * from library where book_id = '");
		strcat_s(strsql, sizeof(strsql), book_id);
		strcat_s(strsql, sizeof(strsql), "'");
		cout << command << endl;
		mysqlselect(command, "library");
	}
	else if (choice == "2")
	{
		cout << "请输入书名" << endl;
		cin >> book_name;
		strcpy_s(strsql, sizeof(strsql), "select * from library where book_name = '");
		strcat_s(strsql, sizeof(strsql), book_name);
		strcat_s(strsql, sizeof(strsql), "'");
		cout << command << endl;
		mysqlselect(command, "library");
	}
	else if (choice == "3")
	{
		cout << "请输入书的作者" << endl;
		cin >> book_author;
		strcpy_s(strsql, sizeof(strsql), "select * from library where book_author = '");
		strcat_s(strsql, sizeof(strsql), book_author);
		strcat_s(strsql, sizeof(strsql), "'");
		cout << command << endl;
		mysqlselect(command, "library");
	}
	else if (choice == "4")
	{
		cout << "请输入书的出版社" << endl;
		cin >> book_press;
		strcpy_s(strsql, sizeof(strsql), "select * from library where book_press = '");
		strcat_s(strsql, sizeof(strsql), book_press);
		strcat_s(strsql, sizeof(strsql), "'");
		cout << command << endl;
		mysqlselect(command, "library");
	}
	else if (choice == "5")
	{
		cout << "请输入书的出版时间" << endl;
		cin >> book_time;
		strcpy_s(strsql, sizeof(strsql), "select * from library where book_time = '");
		strcat_s(strsql, sizeof(strsql), book_time);
		strcat_s(strsql, sizeof(strsql), "'");
		cout << command << endl;
		mysqlselect(command, "library");
	}
	else if (choice == "6")
	{
		strcpy_s(strsql, sizeof(strsql), "select * from library where ");
		

		while (1)
		{
			cout << "选择搜索选项" << endl;
			cout << "书号（1）、书名（2）、作者（3）、出版社（4）、出版时间（5）、结束（6）" << endl;
			cin >> choice;
			if (choice == "1")
			{
				cout << "请输入书号" << endl;
				cin >> book_id;
				strcat_s(strsql, sizeof(strsql), " and book_id = '");
				strcat_s(strsql, sizeof(strsql), book_id);
				strcat_s(strsql, sizeof(strsql), "' ");
			}
			else if (choice == "2")
			{
				cout << "请输入书名" << endl;
				cin >> book_name;
				strcat_s(strsql, sizeof(strsql), " and book_name = '");
				strcat_s(strsql, sizeof(strsql), book_name);
				strcat_s(strsql, sizeof(strsql), "' ");
			}
			else if (choice == "3")
			{
				cout << "请输入书的作者" << endl;
				cin >> book_author;
				strcat_s(strsql, sizeof(strsql), " and book_author ='");
				strcat_s(strsql, sizeof(strsql), book_author);
				strcat_s(strsql, sizeof(strsql), "' ");
			}
			else if (choice == "4")
			{
				cout << "请输入书的出版社" << endl;
				cin >> book_press;
				strcat_s(strsql, sizeof(strsql), " and book_press ='");
				strcat_s(strsql, sizeof(strsql), book_press);
				strcat_s(strsql, sizeof(strsql), "' ");
			}
			else if (choice == "5")
			{
				cout << "请输入书的出版时间" << endl;
				cin >> book_time;
				strcat_s(strsql, sizeof(strsql), " and book_time ='");
				strcat_s(strsql, sizeof(strsql), book_time);
				strcat_s(strsql, sizeof(strsql), "' ");
			}
			else if (choice == "6")
			{
				strncpy_s(strsql, sizeof(strsql), strsql, strlen(strsql) - 1);
				char cpy_str[1000] = {"\0"};
				char* pfound1 = NULL;
				
				pfound1 = strstr(strsql, " and");
				cout << pfound1 << endl;
				int pnum = strlen(strsql) - strlen(pfound1) + 4;
				int j = 0;
				for (int i = pnum; i < strlen(strsql); i++, j++)
				{
					cpy_str[j] = strsql[i];
				}
				cpy_str[j] = '\0';
				cout << cpy_str << endl;
				strncpy_s(strsql, sizeof(strsql), strsql, strlen(strsql) - strlen(pfound1));
				strcat_s(strsql, sizeof(strsql), cpy_str);
				cout << command << endl;
				mysqlselect(command, "library");
				break;
			}
			else
			{
				cout << "输入有误！请重新输入" << endl;
			}

		}
	}
	else 
	{
		cout << "输入有误！请重新输入" << endl;
	}
}


void CSearch::search_bookid()
{

}

void search_bookname()
{

}

void search_bookauthor()
{

}

void search_bookpress()
{

}

void search_booktime()
{

}

CSearch::~CSearch()
{
}
