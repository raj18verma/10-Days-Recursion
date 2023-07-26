#include <bits/stdc++.h> 
using namespace std;

void helper(vector<int>&factors,int index,vector<vector<int>>&ans,vector<int>&curr,int n) {
	if(index==factors.size()) {
		if(n==1) {
			ans.push_back(curr);
		}
		return;
	}
	if(n%factors[index]==0) {
		curr.push_back(factors[index]);
		helper(factors,index,ans,curr,n/factors[index]);
		curr.pop_back();
		helper(factors,index+1,ans,curr,n);
	}
	else {
		helper(factors,index+1,ans,curr,n);
	}
}

vector<vector<int>> factorCombinations(int n) {
	vector<vector<int>>ans;
	vector<int>factors;
	for(int i=2;i<n;i++) {
		if(n%i==0) {
			factors.push_back(i);
		}
	}
	vector<int>curr;
	helper(factors,0,ans,curr,n);
	return ans;
}
