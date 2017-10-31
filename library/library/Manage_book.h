#pragma once
#include "Library.h"
class CManage_book :
	public CLibrary
{
public:
	CManage_book();
	~CManage_book();
	void create_book();
	void alter_book();
	void delete_book();
};

