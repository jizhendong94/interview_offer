#include<iostream>
#include<vector>

using namespace std;

int findrepeate(vector<int>& nums)
{
	int start = 1;
	int end = nums.size()-1;
	while(start<=end)
	{
		int mid = ((end-start)>>1)+start;
		int count=coutrange(nums,start,mid);
		if(start == end)
		{
			if(count>1)
				return start;
			else
				break;
		}
		if(count>(mid-start)+1)
			end=mid;
		else
			start =mid+1;
	}
	return -1;
}

int coutrange(vector<int>& nums,int start,int end)
{

}
int main()
{
	vector<int>V1(10);

	V1[2] = 2;

	for(auto iter= V1.begin();iter!=V1.end();iter++)
	{
		cout<<*iter<<" "<<endl;
	}
	cout<<endl;
}
