#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>visited;

int sum(int x,int y){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	while(y){
		res+=y%10;
		y/=10;
	}	
	return res;
}
int dfs(int x,int y,int m,int n,int k)
{
	if(x<0||y<0||x>=m||y>=n||visited[x][y]||sum(x,y)>k) return 0;
	visited[x][y]=1;
	return 1+dfs(x-1,y,m,n,k)+dfs(x,y-1,m,n,k)+
			dfs(x+1,y,m,n,k)+dfs(x,y+1,m,n,k);
}
int movintCount(int m,int n,int k)
{
	visited=vector<vector<int>>(m,vector<int>(n,0));
	return dfs(0,0,m,n,k);
}


int main(){
	return 0;
}


/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
