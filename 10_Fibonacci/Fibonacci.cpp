#include<iostream>
#include<vector>

using namespace std;

int Fibonacci(int n)
{
	vector<int>res={0,1};
	if(n<2)
		return res[n];
	int FN_2 = 0;
	int FN_1 = 1;
	int FN = 0;
	for(int i=2;i<=n;i++)
	{
		FN = FN_1 + FN_2; //防止溢出  可能要取余数 ();
		FN_2 = FN_1;
		FN_1 = FN;
	}
	return FN;
}

int main(int argc,const char *argv[])
{
	cout<<"FN(10):  "<<Fibonacci(10)<<endl;
	return 0;
}
