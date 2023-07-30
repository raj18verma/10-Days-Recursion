#include <bits/stdc++.h> 

vector<string> helper(string &s,int index) {
    if(index==s.length()) {
        return {};
    }
    vector<string> later = helper(s,index+1);
    if(later.empty()) {
        string tmp="";
        tmp+=s[index];
        return {tmp,"1"};
    }
    else {
        vector<string>ans;
        for(auto it:later) {
            string tmp=it;
            it = s[index]+it;
            ans.push_back(it);
            int num=0,i=0;
            for(i=0;i<tmp.length() && tmp[i]>='0' && tmp[i]<='9';i++) {
                num = (num*10)+(tmp[i]-'0');
            }
            if(num>0) {
                num++;
                tmp=to_string(num)+tmp.substr(i);
                ans.push_back(tmp);
            }
            else {
                tmp="1"+tmp;
                ans.push_back(tmp);
            }
        }
        return ans;
    }
}

vector < string > findAbbr(string & str) {
    vector<string>ans = helper(str,0);
    sort(ans.begin(),ans.end());
    return ans;
}
