//1.> Next Greater Element
https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class
{
    public:
  vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v; // creating a vector for storing result 
    stack <long long> s; // creating a stack for temp. hold the values from array
    for (int i=n-1;i>=0;i--){
      if(s.size() ==0) // when stack size is empty there is no element in stack return output as -1;
        v.push_back(-1);
      else if (s.size()>0 && s.top()>arr[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top()); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top()<=arr[i]) // when there is element in stack and that element is less then array element 
      {
        while(s.size()>0 && s.top()<=arr[i]) // upto when there is element and stack top is less then array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if (s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top()); // else push stack top in the vector 
        }
      }
      s.push(arr[i]); // push array in stack
    }
    reverse(v.begin(),v.end()); // while returning reverse the vector and return it.
    return v;
  }
};
     

// Time Complexity: O(N)
// Auxiliary Space: O(N)

//2. Next Greater to Left
https://www.geeksforgeeks.org/previous-greater-element/

class
{
    public:
  vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v; // creating a vector for storing result 
    stack <long long> s; // creating a stack for temp. hold the values from array
    for (int i=0;i<n;i++){ 
      if(s.size() ==0) // when stack size is empty there is no element in stack return output as -1;
        v.push_back(-1);
      else if (s.size()>0 && s.top()>arr[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top()); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top()<=arr[i]) // when there is element in stack and that element is less then array element 
      {
        while(s.size()>0 && s.top()<=arr[i]) // upto when there is element and stack top is less then array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if (s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top()); // else push stack top in the vector 
        }
      }
      s.push(arr[i]); // push array in stack
    }
    return v;
  }
};
     

// Time Complexity: O(N)
// Auxiliary Space: O(N)

//3.Nearest smaller element on left
https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=
class
{
    public:
  vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v; // creating a vector for storing result 
    stack <long long> s; // creating a stack for temp. hold the values from array
    for (int i=0;i<n;i++){ 
      if(s.size() ==0) // when stack size is empty there is no element in stack return output as -1;
        v.push_back(-1);
      else if (s.size()>0 && s.top()<arr[i]) // when there is element in stack and stack top is smaller then array element 
      {
        v.push_back(s.top()); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top()>=arr[i]) // when there is element in stack and that element is greater then equal to array element 
      {
        while(s.size()>0 && s.top()>=arr[i]) // upto when there is element and stack top is greater then equal to array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if (s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top()); // else push stack top in the vector 
        }
      }
      s.push(arr[i]); // push array in stack
    }
    return v;
  }
};
     

// Time Complexity: O(N)
// Auxiliary Space: O(N)

// 4. Nearest Smaller element on right
https://www.geeksforgeeks.org/next-smaller-element/

class
{
    public:
  vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> v; // creating a vector for storing result 
    stack <long long> s; // creating a stack for temp. hold the values from array
    for (int i=n-1;i>=0;i--){
      if(s.size() ==0) // when stack size is empty there is no element in stack return output as -1;
        v.push_back(-1);
      else if (s.size()>0 && s.top()<arr[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top()); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top()>=arr[i]) // when there is element in stack and that element is greater then or equal to array element 
      {
        while(s.size()>0 && s.top()>=arr[i]) // upto when there is element and stack top is greater then or equal to array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if (s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top()); // else push stack top in the vector 
        }
      }
      s.push(arr[i]); // push array in stack
    }
    reverse(v.begin(),v.end()); // while returning reverse the vector and return it.
    return v;
  }
};
     

// Time Complexity: O(N)
// Auxiliary Space: O(N)

//5. Stock span problem
https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
  public:
  vector <int> calculateSpan(int price[], int n)
  {
    vector <int> v; // creating vector to store result 
    stack<pair<int,int>> s; // creating the pair stack
    for (int i=0;i<n;i++)
    {
      if(s.size()==0) // when stack is empty return -1;
      {
        v.push_back(-1);
      }
      else if (s.size()>0 && s.top().first>price[i]) // when there is element in stack and stack top is greater then array element 
      {
        v.push_back(s.top().second); // take stack top in the result vector 
      }
      else if (s.size()>0 && s.top().first<=price[i] ){ // when there is element in stack and that element is less then array element 
        while (s.size()>0 && s.top().first<=price[i] )// upto when there is element and stack top is less then array's element delete the element from stack
        {
          s.pop(); // delete the element from stack
        }
        if(s.size()==0) // when stack became empty return -1
        {
          v.push_back(-1);
        }
        else
        {
          v.push_back(s.top().second); // else push stack top in the vector 
        }
      }
      s.push({price[i],i}); // take price array and index i inside pair stack
    }
    for (int i=0;i<v.size();i++)
    {
       v[i]=i-v[i]; // subtract normal index from the vector index v[i]
    }
    return v;
  }
};
//6.Maximum area in histogram
https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#
class Solution
{
  public:
  long long getMaxArea(long long arr[], int n)
    {
    vector<int> left,right;
    stack<pair<int,int>> s1,s2;
    int pseudo_index =-1;
    int pseudo_index1 =n;
    for (int i=0;i<n;i++)
    {
      if (s1.size()==0)
      {
        left.push_back(pseudo_index);
      }
      else if (s1.size()>0 && s1.top().first<arr[i])
      {
        left.push_back(s1.top().second);
      }
      else if (s1.size()>0 && s1.top().first>=arr[i])
      {
         while(s1.size()>0 && s1.top().first>=arr[i])
         {
           s1.pop();
         }
        if (s1.size()==0)
        {
          left.push_back(pseudo_index);
        }
        else
        {
          left.push_back(s1.top().second);
        }
      }
      s1.push({arr[i],i});
    }
    for (int i=n-1;i>=0;i--)
    {
      if (s2.size()==0)
      {
        right.push_back(pseudo_index1);
      }
      else if (s2.size()>0 && s2.top().first<arr[i])
      {
        right.push_back(s2.top().second);
      }
      else if (s2.size()>0 && s2.top().first >= arr[i])
      {
        while(s2.size()>0 && s2.top().first >= arr[i])
        {
          s2.pop();
        }
        if (s2.size()==0)
        {
          right.push_back(pseudo_index1);
        }
        else
        {
          right.push_back(s2.top().second);
        }
      }
      s2.push({arr[i],i});
    }
    reverse(right.begin(),right.end());
    long long m=INT_MIN;
    for (long long i=0;i<n;i++)
    {
      m=max(m,(right[i]-left[i]-1)*arr[i]); // taking max after finding area
    }
    return m;
  }
};

//7. Maximum area rectangle in binary matrix
https://leetcode.com/problems/maximal-rectangle/description/

//https://leetcode.com/problems/maximal-rectangle/
class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        vector<int> left,right;
    stack<pair<int,int>> s1,s2;
    int pseudo_index =-1;
    int pseudo_index1 =n;
    for (int i=0;i<n;i++)
    {
      if (s1.size()==0)
      {
        left.push_back(pseudo_index);
      }
      else if (s1.size()>0 && s1.top().first<heights[i])
      {
        left.push_back(s1.top().second);
      }
      else if (s1.size()>0 && s1.top().first>=heights[i])
      {
         while(s1.size()>0 && s1.top().first>=heights[i])
         {
           s1.pop();
         }
        if (s1.size()==0)
        {
          left.push_back(pseudo_index);
        }
        else
        {
          left.push_back(s1.top().second);
        }
      }
      s1.push({heights[i],i});
    }
    for (int i=n-1;i>=0;i--)
    {
      if (s2.size()==0)
      {
        right.push_back(pseudo_index1);
      }
      else if (s2.size()>0 && s2.top().first<heights[i])
      {
        right.push_back(s2.top().second);
      }
      else if (s2.size()>0 && s2.top().first >= heights[i])
      {
        while(s2.size()>0 && s2.top().first >= heights[i])
        {
          s2.pop();
        }
        if (s2.size()==0)
        {
          right.push_back(pseudo_index1);
        }
        else
        {
          right.push_back(s2.top().second);
        }
      }
      s2.push({heights[i],i});
    }
    reverse(right.begin(),right.end());
    int m=INT_MIN;
    for (long long i=0;i<n;i++)
    {
      m=max(m,(right[i]-left[i]-1)*heights[i]);// taking max after finding area
    }
    return m;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0) return 0;
        int n=matrix[0].size(), result=0;
        vector<int> histogram(n, 0);
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1')
                    histogram[j]+=1;
                else
                    histogram[j]=0;
            }
            
            result = max(result, largestRectangleArea(histogram));
            cout<<result<<" ";
        }
        return result;
    }
};
 
//8. Design and Implement Special Stack Data Structure 
https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

// pseudo code

stack<int>s;
stack<int>ss;
void push(int a)
{
    s.push(a);
    if(ss.size()==0 || ss.top()>=a )
     ss.push(a);
    return;
}

int pop()
{
    if(s.size()==0)
    return -1;
     int ans=s.top();
     s.pop();
     if(ss.top()==ans)
     ss.pop();
    return ans;
}

int getMin()
{
    if(ss.size()==0)
    return -1;
   
   return ss.top();

}

// Min stack implementation in O(1) space
int minEle=-1;
void pop()
{
    if(s.size()==0)
    return -1;
    else
    {
        if(s.top()>=minEle)
        s.pop();
    else if(s.top()<minEle)
    {
        minEle=2*minEle-s.top();
        s.pop();
    }
    } 
}
int top()
{
    if(s.size()==0)
    return -1;
    else
    {
        if(s.top()>=minEle)
        {
           return s.top(); 
        }
        else if(s.top()<minEle)
        {
            return minEle;
        }
    }
}



void push(int x)
{
    if(s.size()==0)
    {
        s.push(x);
        minEle=x;
    }
    else
    {
       if(x>=minEle)
       {
        s.push(x);
       } 
       else if(x<minEle)
       {
        // push 2*x-minEle
        s.push(2*x-minEle);
        minEle=x;
       }
    }
}


int getMin()
{
    if(s.size()==0)
    return -1;
    
    return minEle;
}

// remember this 2 equations
//-> 2X-minEle
//->2minEle-Y

//9. Celebrity Problem
https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        //step2: get 2 elements and copare them
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        //step3: single element in stack is potential celeb
        //so verify it
        
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends