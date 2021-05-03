/*offer 42	

输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。

*/

int maxSubArray(vector<int>& nums)
{
	if(0 == nums.size()) return 0;
	vector<int>dp(nums.size());
	dp[0] = nums[0];
	for(int i=1;i<nums.size();i++){
		dp[i]=max(nums[i],dp[i-1]+nums[i]);
	}	
	int res = INT_MIN;
	for(int i = 0;i<dp.size();i++)
		res = max(res,dp[i]);

	return res;
}





