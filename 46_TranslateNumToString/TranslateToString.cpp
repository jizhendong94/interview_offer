/*
   给定一个数字，我们按照如下规则把它翻译为字符串：
   0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……
   ，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，
   用来计算一个数字有多少种不同的翻译方法
 */

//递归
int translateNum(int num) {
	if(num<=9) return 1;
	//取输入数字的余数，然后递归计算
	int ba = num%100;
	//如果<=9或者>=26 余数不能按照2位数字组合
	if(ba<=9 || ba>=26) return translateNum(num/10);
	//[10,25]既可以当做一个字符，也可以当做两个字符
	else return (translateNum(num/10)+translateNum(num/100));
}

//DP 

bool helper(const char& a,const char&b)
{
	return (a=='1'||a=='2'&&b<='5');
}
int translateNum(int num) {
	string str = to_string(num);
	int n = str.size();
	if(n<=1) return n;
	vector<int>dp(n,0);
	dp[0] = 1;
	dp[1] = helper(str[0],str[1])?2:1;
	for(int i=2;i<n;i++)
	{
		dp[i]=helper(str[i-1],str[i])?dp[i-2]+dp[i-1]:dp[i-1];
	}
	return dp[n-1];
}









