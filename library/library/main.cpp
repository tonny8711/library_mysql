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
		cout << "�鼮����1��\t���߹���2��\t���飨3��\t���飨4��\t������5��\t�˳���6��" << endl;
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
			cout << "��������" << endl;
	}
	return 0;
}