// Normal approach

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


// Recursive approach
string removeDuplicate(string &s)
{
    // Write your code here
 if(s.length()==1)   
 return s;
else{      
    char c = s[s.length()-1];      
 s.pop_back();      
 removeDuplicate(s);      

 if(s[s.length()-1]!=c){    
s.push_back(c);}           
return s;
   }    
}
