/*
   在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
   s 只包含小写字母。

 */

char firstUniqChar(string s) {
	unordered_map<int,int>mp;
	for(char c:s)
		mp[c]++;
	for(char c:s){
		if(mp[c]==1)
			return c;
	}
	return ' ';
}






