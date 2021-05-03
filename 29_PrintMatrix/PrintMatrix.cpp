/*offer  29 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

*/

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int>res;
	if(0 == matrix.size()) return res;
	int up=0,left=0,down=matrix.size()-1,right=matrix[0].size()-1;

	while(true){
		for(int i=left;i<=right;i++) res.push_back(matrix[up][i]);
		if(++up>down) break;
		for(int i=up;i<=down;i++) res.push_back(matrix[i][right]);
		if(--right<left) break;
		for(int i=right;i>=left;i--) res.push_back(matrix[down][i]);
		if(--down<up) break;
		for(int i=down;i>=up;i--) res.push_back(matrix[i][left]);
		if(++left>right) break;
	}
	return res;
}







