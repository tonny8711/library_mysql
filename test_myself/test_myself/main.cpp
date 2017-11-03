#include "iostream"
#include "string"

using namespace std;

void main()
{
	char str[20] = "123456789";
	char* command = str;
	strncpy_s(str, sizeof(str), str, strlen(str) - 1);
	cout << command << endl;
}