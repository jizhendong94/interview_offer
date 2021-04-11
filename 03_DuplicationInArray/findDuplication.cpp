#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//方式1  hash 表 存储是否出现过，时间复杂度O(N)  空间复杂度O(N)
int findRepeatNumber(vector<int>& nums){
	unordered_map<int,int>mp;
	for(int i=0;i<nums.size();i++)
	{
		if(mp.find(nums[i])!=mp.end())
			return nums[i];
		else
			mp[nums[i]]++;
	}
	return -1;
}

//鸽巢原理 如果没有重复的数字，那么数字i将出现在下标i的位置
int FindRepeatNumber1(vector<int>& nums)
{
	if(nums.size()!=0)
	{
		for(int i=0;i<nums.size();i++)
		{
			if(i != nums[i])
			{
				if(nums[i] == nums[nums[i]])
					return nums[i];
				swap(nums[i],nums[nums[i]]);
			}
		}
	}
	return -1;
}


int main()
{
	vector<int> V1={2,3,1,0,2,5,3};
	cout<<"0:: "<<findRepeatNumber(V1)<<endl;
	cout<<"1:: "<<FindRepeatNumber1(V1)<<endl;
	return 0;
}


