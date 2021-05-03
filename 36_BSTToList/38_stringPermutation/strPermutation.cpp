/*offer  38 
  输入一个字符串，打印出该字符串中字符的所有排列
  你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 */
// 有重复的元素
vector<string>res;

viod backtrack(string s,string path,vector<bool>& used)
{
	if(path.size() == s.size()){
		res.push_back(path);
		return;
	}
	for(int i=0;i<s.size();i++)
	{
		if(!used[i]){
			if(i>=1&&s[i-1]==s[i]&&!used[i-1]) continue;
			path.push_back(s[i]);//做选择
			used[i]=true;
			backtrack(s,path,used); //回溯
			path.pop_back();      //撤销选选
			used[i]=false;
		}
	}
}

vector<string> permutation(string s) {
	if(s.size() == 0) return {};
	string path;
	sort(s.begin(),s.end());  //先排序  
	vector<bool>used(s.size(),false);

	backtrack(s,path,used);
	return res;
}







