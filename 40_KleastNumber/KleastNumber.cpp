/*  40 offer
	输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，
	则最小的4个数字是1、2、3、4。

 */


//快速排序
vector<int>res;

void quicksort(vector<int>& arr,int left,int right,int k)
{
	int temp = arr[left];
	int i=left,j = right;
	while(i<j){
		while(i<j&&arr[j]>temp) j--;
		arr[i]=arr[j];
		while(i<j&&arr[i]<=temp) i++;
		arr[j]=arr[i];
	}
	arr[i]=temp;
	if(i+1 == k){
		res.assign(arr.begin(),arr.begin()+k);
		return;
	}
	else if(i+1>k){
		quicksort(arr,left,i-1,k);
	}
	else{
		quicksort(arr,i+1,right,k);
	}
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
	if(k == 0 ) return {};
	quicksort(arr,0,arr.size()-1,k);
	return res;
}











