
/*offer  33
  输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，
  否则返回 false。假设输入的数组的任意两个数字都互不相同。

递归解法：

-终止条件：当i>=j 说明此子树节点数量<=1,无需判别正确性，直接返回true
-递推工作：1. 划分左右子树：遍历[i,j]区间的元素，寻找第一个大于根节点的节点，标记为m
			此时，划分出左区间[i,m-1],右区间[m,j-1],根节点j。
		   2. 判断是否是二叉搜索树：左子树区间[i,m-1]内的的所有节点都应<postorder[j],第一步的
				区间划分已经保证了左区间的正确性，因此只需判断右子树区间即可。
				右子树区间：[m,j-1]内的所有节点都应>postorder[j],实现方式为遍历，当遇到<=postorder[j]
				的节点则跳出，可以通过p=j判断是否为二叉搜索树。


返回值： 所有子树都需正确才可判定正确，因此使用 与逻辑符&& 连接。
p = j    ： 判断 此树 是否正确。
recur(i, m - 1)recur(i,m−1) ： 判断 此树的左子树 是否正确。
recur(m, j - 1)recur(m,j−1) ： 判断 此树的右子树 是否正确。

*/

bool recur(vector<int>& postorder,int i,int j)
{
	if(i>=j) return true;
	int p = i;
	while(postorder[p]<postorder[j]) p++;
	int m = p;
	while(postorder[p]>postorder[j]) p++;

	return (p==j)&&recur(postorder,i,m-1)&&recur(m,j-1);
}

bool verifyPostorder(vector<int>& postorder) {
	return recur(postorder,0,postorder.size()-1);
}





