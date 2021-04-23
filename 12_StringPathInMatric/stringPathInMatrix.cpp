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




int main()
{
	return 0;
}
