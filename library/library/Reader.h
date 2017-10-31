#pragma once
#include "Library.h"
class CReader :
	public CLibrary
{
public:
	CReader();
	~CReader();
	void create_reader();
	void alter_reader();
	void delete_reader();
};

