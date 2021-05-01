#include<iostream>
using namespace std;

int Fabinic(int n)
{
	if(n<=0)
		return -1;
	if(1 == n) return 1;
	if(2 == n) return 1;

	int fn_2 = 1;
	int fn_1 = 1;
	int res = 0;
	for(int i = 3;i<=n;i++)
	{
		res = fn_2 + fn_1;
		fn_2 = fn_1;
		fn_1 = res;
	}
	return res;
}


int Fabinic_digui(int n)
{
	if(n<=0){
		cout<<"input ERROR"<<endl;
		return -1;
	}
	if(1 == n) return 1;
	if(2 == n) return 1;

	return Fabinic_digui(n-1)+Fabinic_digui(n-2);
}

int main(int argc,const char* argv[])
{
	int n;
	cout<<"intput : "<<endl;
	cin>>n;
	cout<<Fabinic(n)<<endl;

	cout<<"res2 : "<<Fabinic_digui(n)<<endl;
	return 0;
}
