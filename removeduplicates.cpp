string removeDuplicate(string &s)
{
    // Write your code here
    int n=s.length();
    string ans="";
    for(int i=0; i<n; i++){
        if(i<n-1 && s[i]==s[i+1]){
            continue;
        }else{
            ans+=s[i];
        }
    }
    return ans;
}
