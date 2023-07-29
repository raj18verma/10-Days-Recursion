//Problem Link:- https://www.codingninjas.com/studio/problems/ip-address_992846?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_recursion_roadmap&leftPanelTab=1

#include <bits/stdc++.h> 

void rec(int ind,string &str,string &cur,vector<string>&ans,int n,int cnt)
{
	if (ind==n)
    {
		if (cnt==0)
		{
			cur.pop_back();
			ans.push_back(cur);
		}
		return;
	}
	if (str[ind]=='0')
	{
		string t2=cur+"0"+".";
		rec(ind+1,str,t2,ans,n,cnt-1);
		return;
	}
	string temp="";
	for (int i=ind;i<n;i++)
	{
       temp+=str[i];
	   if  (temp.size()==3 && temp>"255") break;
	   if (temp.size()>3) break;
	   string temp2=cur+temp+".";
       rec(i+1,str,temp2,ans,n,cnt-1);
	}
}
vector<string> generateIPAddress(string s)
{
	vector<string>ans;
	int n=s.size();
	string cur="";
	rec(0,s,cur,ans,n,4);
	return ans;
}
