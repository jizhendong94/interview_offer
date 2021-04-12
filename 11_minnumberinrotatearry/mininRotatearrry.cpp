#include<iostrem>
#include<vector>
using namespace std;

int minInRatoteArray(vector<int>& num)
{
	int left = 0;
	int right = num.size()-1;
	int pivot = left + (right-left)/2;
	while(left < right)
	{
		if(num[pivot]<num[right])
			right=pivot;
		else if(num[pivot]>num[right])
			left = pivot+1;
		else
			right -=1;
	}
	return num[left];
}
int main()
{
	return 0;
}
