#include<iostream>


/* offer  21 
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

*/

vector<int> exchange(vector<int>& nums)
{
	int n = nums.size();
	if(0 == n) return {};
	int left = 0,right = n-1;
	while(left < right)
	{
		while(left<right && nums[left]%2!=0)
			left++;
		while(left<right && nums[right]%2==0)
			rihgt--;
		swap(nums[left++],nums[right--]);
	}
	return nums;
}
