#pragma once
#include "Library.h"
class CSearch :
	public CLibrary
{
public:
	CSearch();
	~CSearch();
	void search_bookid();
	void search_bookname();
	void search_bookauthor();
	void search_bookpress();
	void search_booktime();
};

