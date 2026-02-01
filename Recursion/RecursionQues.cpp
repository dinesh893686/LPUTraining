// 1. 
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int lft=maxDepth(root->left);
        int rght=maxDepth(root->right);
        return 1+max(lft,rght);
    }
};

//2.
https://leetcode.com/problems/sort-an-array/description/
//Sort an array using recursion

class Solution {
public:
    void Solve(vector<int> &nums,int t)
    {
        if(nums.size()==0||t>=nums[nums.size()-1])
        {
            nums.push_back(t);
            return;
        }
        
        int to=nums[nums.size()-1];
        nums.pop_back();
        Solve(nums,t);
        nums.push_back(to);
            
    }
    void getSorted(vector<int> &nums)
    {
        if(nums.size()==0)
            return;
        
        int t=nums[nums.size()-1];
        nums.pop_back();
        getSorted(nums);
        Solve(nums,t);
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return nums;
        
        getSorted(nums);
        return nums;
    }
};

//3. Sort a stack
https://www.geeksforgeeks.org/problems/sort-a-stack/1
void GetStack(stack<int> &s,int to)
{
    if(s.empty()||to>=s.top())
    {
        s.push(to);
        return;
    }
    
    int t=s.top();
    s.pop();
    GetStack(s,to);
    s.push(t);
    return;
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   return;
   
   int to=s.top();
   s.pop();
   sort();
   GetStack(s,to);
   return;
}

//4. Delete middle element of stack
https://www.geeksforgeeks.org/delete-middle-element-stack/
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void getDeleted(stack<int> &s,int k)
    {
        if(k==1)
        {
            s.pop();
            return;
        }
        int t=s.top();
        s.pop();
        getDeleted(s,k-1);
        s.push(t);
        return;
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        int k=ceil(sizeOfStack/2);
        getDeleted(s,k);
        return;
        
    }
};


//5. 
https://www.geeksforgeeks.org/problems/reverse-a-stack/1

#include<bits/stdc++.h>
using namespace std;
void getSolve(stack<int> &st,int t)
{
    if(st.size()==0)
    {
        st.push(t);
        return;
    }
    
    int to=st.top();
    st.pop();
    getSolve(st,t);
    st.push(to);
    return;
}
void solve(stack<int> &st)
{
    if(st.size()==0)
    return;
    
    int t=st.top();
    st.pop();
    solve(st);
    getSolve(st,t);
  return;
}
int main() {
    int n;
    cin>>n;
    stack<int> st;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        st.push(a);
    }
    solve(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
	return 0;
}

// 6. kth symbol in grammar
https://leetcode.com/problems/k-th-symbol-in-grammar/description/
class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1&&k==1)
        {
            return 0;
        }
        int mid=pow(2,n-1)/2;
        if(k<=mid)
        {
            return kthGrammar(n-1,k);
        }
        else
            return !kthGrammar(n-1,k-mid);
    }
};


// Print Subsets | Print PowerSets | Print all Subsequences

https://www.geeksforgeeks.org/print-subsequences-string/

//7. Print all subsets
https://leetcode.com/problems/subsets/description/
class Solution {
public:
    void getSorted(vector<int> op,vector<int> nums,vector<vector<int>> &result)
    {
        if(nums.size()==0)
        {
            result.push_back(op);
            return;
        }
        
        vector<int> op1=op;
        vector<int> op2=op;
        op1.push_back(nums[0]);
        nums.erase(nums.begin());
        getSorted(op1,nums,result);
        getSorted(op2,nums,result);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        vector<vector<int>> result;
        getSorted(op,nums,result);
        return result;
    }
};


//9.Print Unique Subsets




// 10. Permutations with spaces
https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1
class Solution
{
public:
    void getSorted(string op,string S,vector<string> &result)
    {
        if(S.length()==0)
        {
            result.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        op1.push_back(' ');
        op1.push_back(S[0]);
        op2.push_back(S[0]);
        S.erase(S.begin());
        getSorted(op1,S,result);
        getSorted(op2,S,result);
        return;
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string> result;
        string op;
        op.push_back(S[0]);
        S.erase(S.begin());
        getSorted(op,S,result);
        return result;
    }
};

//11. Permutation with case changes
https://www.geeksforgeeks.org/permute-string-changing-case/
class Solution {
public:
    void getSolved(string s,string op,vector<string> &result)
    {
        if(s.length()==0)
        {
            result.push_back(op);
            return;
        }

        if(is digit(s[0]))
        {
            string op1=op;
            op1.push_back(s[0]);
            s.erase(s.begin());
            getSolved(s,op1,result);
        }
        else
        {
            string op1=op;
            string op2=op;
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin());
            getSolved(s,op1,result);
            getSolved(s,op2,result);
        }

        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string op;
        getSolved(s,op,result);
        return result;
    }
};



//12.Letter case Permutation
https://leetcode.com/problems/letter-case-permutation/description/
class Solution {
public:
    void getSolved(string s,string op,vector<string> &result)
    {
        if(s.length()==0)
        {
            result.push_back(op);
            return;
        }
        
        if(isdigit(s[0]))
        {
            string op1=op;
            op1.push_back(s[0]);
            s.erase(s.begin());
            getSolved(s,op1,result);
        }
        else
        {
            string op1=op;
            string op2=op;
            op1.push_back(tolower(s[0]));
            op2.push_back(toupper(s[0]));
            s.erase(s.begin());
            getSolved(s,op1,result);
            getSolved(s,op2,result);
        }
        
        return;
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        string op;
        getSolved(s,op,result);
        return result;
    }
};

// 13.Generate all balanced parantheses
https://www.interviewbit.com/problems/generate-all-parentheses-ii/

class Solution {
public:
    void getSolved(string opt,int op,int cl,vector<string> &result)
    {
        if(op==0&&cl==0)
        {
            result.push_back(opt);
            return;
        }
        
        if(op!=0)
        {
            string op1=opt;
            op1.push_back('(');
            getSolved(op1,op-1,cl,result);
        }
        
        if(cl>op)
        {
            string op1=opt;
            op1.push_back(')');
            getSolved(op1,op,cl-1,result);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        int op=n,cl=n;
        vector<string> result;
        string opt;
        getSolved(opt,op,cl,result);
        return result;
    }
};

//14. Print n-bits having more 1s than 0s
https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

class Solution{
public:	
    void getSorted(string op,int one,int zero,int N,vector<string> &result)
    {
        if(N==0)
        {
            result.push_back(op);
            return;
        }
        
        string op1=op;
        op1.push_back('1');
        getSorted(op1,one+1,zero,N-1,result);
        
        if(one>zero)
        {
            string op1=op;
            op1.push_back('0');
            getSorted(op1,one,zero+1,N-1,result);
        }
        
        return;
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes 
	    string op;
	    op.push_back('1');
	    N-=1;
	    vector<string> result;
	    int one=1,zero=0;
	    getSorted(op,one,zero,N,result);
	    return result;
	}
};

// Josephus Problem
