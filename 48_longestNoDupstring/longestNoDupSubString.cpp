/*offer 48 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

*/

int lengoflongestSubString(string s)
{
    int map[256]={0},len=0,start=0;
    for(int i=0;i<s.size();i++)
    {
        map[s[i]]++;
        while(map[s[i]]==2){
            map[s[start]]--;
            start++;
        }
        len=max(len,i-start+1);
    }   
    return len;
}










