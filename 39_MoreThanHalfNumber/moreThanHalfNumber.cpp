/*offer  39 
  数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
  你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 */



//解法一：排序取中位数
//时间O(nlogn)，空间O(1)
int majorityElement(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	return nums[nums.size()/2];
}


//解法二：建立哈希表法
//时间O(n)，空间O(n/2)
int majorityElement(vector<int>& nums) {
	unordered_map<int,int>hash;
	int len = nums.size();
	for(int i=0;i<len;i++){
		hash[nums[i]]++;
		if(hash[nums[i]]>len/2)
			return nums[i];
	}
	return -1;
}


//解法三：摩尔投票法
//也可以理解成混战极限一换一，不同的两者一旦遇见就同归于尽，最后活下来的值都是相同的，即要求的结果
//时间O(n)，空间O(1)
int majorityElement(vector<int>& nums) {
	int res = 0,count = 0;
	for(int i=0;i<nums.size();i++)
	{
		if(0 == count){
			res = nums[i];
			count++;
		}
		else{
			res == nums[i]?count++:count--;
		}
	}
	return res;
}
