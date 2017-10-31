#include"Reader.h"
#include"Manage_book.h"
#include"Borrow_book.h"
#include"Return.h"
#include"Search.h"


int main()
{
	while (1)
	{
		cout << "************************************************************************" << endl;
		cout << "书籍管理（1）\t读者管理（2）\t借书（3）\t还书（4）\t搜索（5）\t退出（6）" << endl;
		string choice = "-1";
		cin >> choice;
		if (choice == "1")
			CManage_book();
		else if (choice == "2")
			CReader();
		else if (choice == "3")
			CBorrow_book();
		else if (choice == "4")
			CReturn();
		else if (choice == "5")
			CSearch();
		else if (choice == "6")
			break;
		else
			cout << "输入有误！" << endl;
	}
	return 0;
}