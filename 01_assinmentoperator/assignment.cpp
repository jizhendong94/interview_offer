//为Cmystring类型添加赋值运算符

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class Cmystring{
public:
	Cmystring(const char* pdata=nullptr);
	Cmystring(const Cmystring& str);
	~Cmystring(void);

	Cmystring& operator = (const Cmystring& str);
	void Print();
private:
	char* my_data;
};

Cmystring::Cmystring(const char* pdata)
{
	if(nullptr == pdata)
	{
		my_data = new char[1];
		my_data[0] = '\0';
	}
	else
	{
		my_data = new char[strlen(pdata)+1];
		strcpy(my_data,pdata);
	}
}

Cmystring::Cmystring(const Cmystring& str)
{
	my_data = new char[strlen(str.my_data)+1];
	strcpy(my_data,str.my_data);
}

Cmystring::~Cmystring()
{
	delete[] my_data;
}

Cmystring& Cmystring::operator = (const Cmystring& str)
{
	if(this != &str)
	{
		delete[] my_data;
		my_data = nullptr;

		my_data = new char[strlen(str.my_data)+1];
		strcpy(my_data,str.my_data);
	}
	return *this;
}

void Cmystring::Print()
{
	printf("%s",my_data);
}

void Test1()
{
	cout<<"Test1 begin:  "<<endl;
	string text  = "hello world\n";
	//const char* text = "hello world";

	Cmystring str1(text.c_str());
	Cmystring str2 = str1;

	str2.Print();
	cout<<"Test1 end:  "<<endl;
}

int main()
{
	Test1();
	return 0;
}





