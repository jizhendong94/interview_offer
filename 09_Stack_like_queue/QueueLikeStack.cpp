#include<iostream>
#include<queue>
using namespace std;

class Cstack{
private:
	queue<int>q1,q2;
public:
	Cstack() {}
	void appendTail(int val)
	{
		if(q1.size()==0 && q2.size()==0)
			q1.push(val);
		else if(q1.size()>0)
			q1.push(val);
		else if(q2.size()>0)
			q2.push(val);
	}

	int delTail()
	{
		if(q2.size()==0)
		{
			if(q1.size()==0)
				return -1;
			while(q1.size()!=1)
			{
				q2.push(q1.front());
				q1.pop();
			}
			int res = q1.front();
			q1.pop();
			return res;
		}
		else
		{
			while(q2.size()!=1)
			{
				q1.push(q2.front());
				q2.pop();
			}
			int res = q2.front();
			q2.pop();
			return res;
		}
	}

};
