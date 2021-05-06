/*
   数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，
   第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

   请写一个函数，求任意第n位对应的数字。

 */

int findNthDigit(int n) {
	int digit = 1;
	long start = 1;
	long count = 9;
	while(n>count){
		n-=count;
		digit+=1;
		start*=10;
		count = 9*start*digit;
	}
	long num = start+(n-1)/digit;
	string str = to_string(num);
	return str[(n-1)%digit]-'0';
}



