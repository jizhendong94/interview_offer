#include<iostream>
#include<string>
using namespace std;
string replacespace(string s)
{
	int begin = -1;
	while((begin = s.find(' ',begin+1)) != string::npos)
	{
		s.replace(begin,1,"%20");
	}
	return s;
}

string replacespace1(string s)
{
	string res;
	for(auto &c:s)
	{
		if(c == ' ' )
		{
			res +="%20";
		}
		else
			res +=c;
	}
	return res;
}
string replacespace2(string s)
{
	int count = 0,len=s.size();
	for(char &c:s)
	{
		if(c == ' ')
			count++;
	}
	s.resize(s.size()+2*count);
	int originindex = len;
	int newindex = s.size();
	while(originindex>=0 && newindex>originindex)
	{
		if(s[originindex]==' ')
		{
			s[newindex--]='0';
			s[newindex--]='2';
			s[newindex--]='%';
		}
		else
			s[newindex--] = s[originindex];
		originindex--;
	}
	return s;
}
int main()
{
	string s = "wo are happy";
	cout<<replacespace(s)<<endl;
	cout<<replacespace1(s)<<endl;
	cout<<replacespace2(s)<<endl;
	return 0;
}
