/*
   输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

此题求拼接起来的最小数字，本质上是一个排序问题。设数组 numsnums 中任意两数字的字符串为 xx 和 yy ，则规定 排序判断规则 为：

若拼接字符串 x + y > y + x，则 xx “大于” yy ；
反之，若 x + y < y + xx ，则 xx “小于” yy ；
xx “小于” yy 代表：排序完成后，数组中 xx 应在 yy 左边；“大于” 则反之。

 */


//排序处
string minNumber(vector<int>& nums) {
	vector<string>strs;
	string res;
	for(int i=0;i<nums.size();i++)
		strs.push_back(to_string(nums[i]));
	sort(strs.begin(),strs.end(),[](string& s1,string& s2){return s1+s2<s2+s1;});
	for(int i=0;i<strs.size();i++)
		res.append(strs[i]);
	return res;
}

