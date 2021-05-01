#include<iostream>
using namespace std;

/*
dp[i]代表绳子长度为i时，绳子可能的最大长度乘积
对于绳长为i的绳子，我们选择在j位置将绳子剪断，此时绳子被分成长度为j和长度为i - j的两部分，此时剪断之后绳子可能的最大长度乘积，为绳长为j和绳长i - j时候结果的积。而dp状态更新为max(result[i],result[j] × result[i - j])。

为什么n = 1,2,3的返回值不等于result[n]：同第2点所述，当作为结果返回时，必须要切一段，不能不切。但是作为子问题被引用时，可以作为一整段出现，也就是不切，因此最大值有区别

*/


int cuttingrope(int n)
{
	if(n<=1) return 0;
	if(n==2) return 1;
	if(n==3) return 2;
	vector<int>dp(n+1,0);
	dp[1]=1;
	dp[2]=2;
	dp[3]=3;
	for(int i=4;i<=n;i++){
		for(int j=1;j<=i/2;j++){
			dp[i]=max(dp[i],dp[j]*dp[i-j]);
		}
	}
	return dp[n];
}

int main()
{
	return 0;
}

