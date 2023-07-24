#include <bits/stdc++.h> 
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k){
    // Write your code here.
 int n1 = arr1.size();    
 int n2 = arr2.size();

   int c=0;    
   int ans;    
   int i = 0;    
   int j =0;

   while(c<k){        
       if(i==n1 || j==n2)
       break;        
       if(arr1[i]<=arr2[j]){            
           ans = arr1[i];            
           c++;            
           i++;        
           }else{            
               ans = arr2[j];            
               c++;            
               j++;        
            }    
        }

   while(c<k && i<n1){        
       ans = arr1[i];        
       i++;        
       c++;    
       }

   while(c<k && j<n2){        
       ans = arr2[j];        
       j++;        
       c++;    
       }

   return ans;
}
