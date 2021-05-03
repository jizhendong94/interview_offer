/*offer 30  
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。

思路：数据栈 AA ： 栈 AA 用于存储所有元素，保证入栈 push() 函数、出栈 pop() 函数、获取栈顶 top() 函数的正常逻辑。
辅助栈 BB ： 栈 BB 中存储栈 AA 中所有 非严格降序 的元素，则栈 AA 中的最小元素始终对应栈 BB 的栈顶元素，
即 min() 函数只需返回栈 BB 的栈顶元素即可。

push(x) 函数： 重点为保持栈 BB 的元素是 非严格降序 的。
				将 xx 压入栈 AA （即 A.add(x) ）；
				若 ① 栈 BB 为空 或 ② xx 小于等于 栈 BB 的栈顶元素，则将 xx 压入栈 BB （即 B.add(x) ）。
pop() 函数： 重点为保持栈 A, BA,B 的 元素一致性 。
			执行栈 AA 出栈（即 A.pop() ），将出栈元素记为 yy ；
			若 yy 等于栈 BB 的栈顶元素，则执行栈 B 出栈（即 B.pop() ）。
top() 函数： 直接返回栈 AA 的栈顶元素即可，即返回 A.peek() 。

min() 函数： 直接返回栈 BB 的栈顶元素即可，即返回 B.peek() 。

*/
class MinStack {
	stack<int>stack1;
	stack<int>stack2;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
		stack1.push(x);
		if(stack2.empty()||x<=stack2.top()) //必须<=  
			stack2.push(x);
    }
    
    void pop() {
		if(stack1.top() == stack2.top()) 
			stack2.pop();
		stack1.pop();
    }
    
    int top() {
		return stack1.top();

    }
    
    int min() {
		return stack2.top();
    }
};








































