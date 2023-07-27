void rec(int open,int close,string &cur,vector<string>&ans)
{
    if (open==0 && close==0)
    {
        ans.push_back(cur);
        return ;
    }
    if (open<close)
    {
        cur.push_back(')');
        rec(open,close-1,cur,ans);
        cur.pop_back();
    }
    if (open>0)
    {
        cur.push_back('(');
        rec(open-1,close,cur,ans);
        cur.pop_back();
    }

}

vector<string> validParenthesis(int n){
    // Write your code here.
    vector<string>ans;
    string cur="";
    rec(n,n,cur,ans);
    return ans;
}
