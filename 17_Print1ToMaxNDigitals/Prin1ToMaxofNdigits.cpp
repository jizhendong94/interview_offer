#include<iostream>
using namespace std;

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。
// 考虑大数溢出问题 使用全排列  转化成字符串问题求解


vector<int>res;

void dfs(int n,int idx,string path)
{
	if(idx == n){               //填满n位时记录当前值
		int val = stoi(path);   //stoi会自动去除前导0
		if(0!=val){
			res.push_back(val);
		}
		return;
	}

	for(int i=0;i<10;i++){       //每一位有十个值可选
		path[idx] = i + '0';
		dfs(n,idx+1,path);
	}
}

vector<int> PrintNumbers(int n)
{
	string path(n,'0');
	dfs(n,0,path);
	return res;
}


