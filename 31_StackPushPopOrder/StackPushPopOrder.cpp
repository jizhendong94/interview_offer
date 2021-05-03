
/*剑指offer 31  
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

题解：

算法流程：

1    初始化： 辅助栈 stack ，弹出序列的索引i ；
2    遍历压栈序列： 各元素记为 num ；
	 元素 num 入栈；
     循环出栈：若 stack的栈顶元素= 弹出序列元素popped[i] ，则执行出栈与 i++；
3    返回值： 若 stackstack 为空，则此弹出序列合法。


*/




bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	stack<int>S;
	int i = 0;
	for(int num:pushed){
		S.push(num);
		while(!S.empty() && S.top() == popped[i]){
			S.pop();
			i++;
		}
	}
	return S.empty();
}

















