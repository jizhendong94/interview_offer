#include<iostream>
#include<vector>
using namespace std;

int rows=0;
int cols=0;


int dfs(vector<vector<char>>& board,string word,int i,int j,int k)
{
	if(i>=rows||i<0||j>=cols||j<0||board[i][j]!=word[k]) return false;
	if(k==word.size()-1) return true;

	board[i][j]='\0';
	bool res = dfs(board,word,i+1,j,k+1)||dfs(board,word,i-1,j,k+1)||
				dfs(board,word,i,j+1,k+1)||dfs(board,word,i,j-1,k+1);
	board[i][j]=word[k];
	return res;
}
bool exist(vector<vector<char>>& board,string word)
{
	rows = board.size();  
	cols = board[0].size(); //全局变量，或者类私有变量
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(dfs(board,word,i,j,0))
				return true;
		}
	}
	return false;
}

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


int main()
{
	return 0;
}
