/*offer 38 

  输入一个字符串，打印出该字符串中字符的所有排列

  字符串中可能有重复元素
 */

vector<string>res;
void backtrack(string s,string path,vector<bool>& visited)
{
	if(s.size() == path.size()){
		res.push_back(path);
		return;
	}
	for(int i=0;i<s.size();i++){
		if(!visited[i]){
			if(i>=1&&s[i-1]==s[i]&&!visited[i-1]) continue;
			path.push_back(s[i]);
			visited[i]=true;
			backtrack(s,path,visited);
			path.pop_back();
			visited[i]=false;
		}
	}
}
vector<string> Permutation(string s)
{
	if(s.size() == 0 ) return {};
	string path;
	vector<bool>visited(s.size(),false);
	backtrack(s,path,visited);
	return res;
}










