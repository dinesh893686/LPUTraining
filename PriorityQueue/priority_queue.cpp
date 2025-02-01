// Kth smallest element

priority_queue<int>maxH;
for(int i=0;i<size;i++)
{
    maxH.push(arr[i]);
    if(maxH.size()>k)
    {
        maxH.pop();
    }
}
return maxH.top();


// k largest element in an array
https://leetcode.com/problems/kth-largest-element-in-an-array/description/
//k Largest elements

// sort a k sorted Array
https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/0
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
	int n,k;
  cin>>t;
	while (t--)
  {
    cin>>n>>k;
	    int a;
    vector<int> v;
	    priority_queue<int,vector<int>,greater<int>> minh;
    for (int i=0;i<n;i++)
	    {
      cin>>a;
      minh.push(a);
      if (minh.size()>k)
      {
        int val= minh.top();
	      minh.pop();
        v.push_back(val);
      }
    }
    while (!minh.empty())
    {
      int val = minh.top();
      minh.pop();
      v.push_back(val);
    }
    for (int i=0;i<n;i++){
      cout<<v[i]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}

// k closest numbers
https://leetcode.com/problems/find-k-closest-elements/description/

    

// top k frequent numbers
https://leetcode.com/problems/top-k-frequent-elements/description/
priority_queue<int,vector<int>,greater<int>>minH;

for(auto i=mp.begin();i!=mp.end();i++)
{
    minH.push({i->second,i->first});
}

// frequency sort
https://leetcode.com/problems/sort-array-by-increasing-frequency/description/


//K - closest points to origin
https://leetcode.com/problems/k-closest-points-to-origin/description/
Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.

Note: The distance between two points on a plane is the Euclidean distance.

Example:
Input : point = [[3, 3], [5, -1], [-2, 4]], K = 2 . 


//Connect Ropes
https://www.interviewbit.com/problems/connect-ropes/


//Sum of elements between k1 smallest and k2 smallest numbers
https://www.geeksforgeeks.org/problems/sum-of-elements-between-k1th-and-k2th-smallest-elements3133/0