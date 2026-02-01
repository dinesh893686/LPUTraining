/// SLiding Window Problems

// 8. Maximum sum subarray of size K
https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// https://www.geeksforgeeks.org/find-maximum-minimum-sum-subarray-size-k/
//Time Complexity : O(n)
//Auxiliary Space : O(1)
class Solution{
  public:
int maximumSumSubarray(int K, vector<int> &Arr , int N){
  int i=0;
  int j=0;
  int sum=0;
  int mx=INT_MIN;
  while (j<N){
    sum=sum+Arr[j]; // do calculation to reduse tc
    if (j-i+1<K) J++; // increament j upto when the size of the size of window is not equal to required size
    else// when window size hit to the required window size
    {
      mx=max(mx,sum); // selecting ans from the candidates
      sum=sum-Arr[i]; // start removing from the first
      i++;
      j++;
    }
  }
  return mx;
}
};


//9. First negative integer in every window of size k
https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/
/*
Time Complexity: O(n)
Auxiliary Space: O(k)
*/
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
 long long i=0;
 long long j=0;
 vector<long long> ans;
 list<long long> l;
  while (j<N){
    if (A[j]<0)
      l.push_back(A[j]);
    if (j-i+1<K) j++;
    else if ((j-i+1)==K)
    {
      if (l.size()==0)
        ans.push_back(0);
      else
        ans.push_back(l.front());
      if(A[i]<0)
        l.pop_front();
      i++;
      j++;
    }
  }
  return ans;
}


// 10. Count Occurences of anagrams
https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution{
  public:

  int search(string pat, string txt) {
  unordered_map <char, int> m;
  for(auto i: pat)
  m[i]++;

  int k = pat.size();
  int count = m.size();
  int ans = 0;
  int i = 0, j = 0;

  while(j < txt.size()) {

  if(m.find(txt[j]) != m.end()) {
  m[txt[j]]--;

  if(m[txt[j]] == 0)
  count--;
  }

  if(j - i + 1 < k) j++;

  else if(j - i + 1 == k) {
  if(count == 0)
  ans++;

  if(m.find(txt[i]) != m.end()) {
  m[txt[i]]++;

  if(m[txt[i]] == 1)
  count++;
  }

  i++; j++;
  }
  }

  return ans;
  }
};



// 11. Max of all subarrays of size K
https://www.interviewbit.com/problems/sliding-window-maximum/


// instead of list you can also use dequeue it allows
//deque<int> dq;
//dq.push_front(10);
//dq.push_back(20);
//dq.pop_front();
//dq.pop_back();
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> ans;
        list<int> l;
        int i=0;
        int j=0;

        if (k>nums.size()) // edge case
        {
            ans.push_back(*max_element(l.begin(),l.end()));
            return ans;
        }

        while (j<nums.size())
        {
            while(l.size()>0 && l.back() <nums[j])
            {
                l.pop_back();
            }
            l.push_back(nums[j]);
            if ((j-i+1)<k)
                j++;
            else if (j-i+1==k)
            {
                ans.push_back(l.front());
                if (l.front()==nums[i])
                    l.pop_front();
                i++;
                j++;
            }

        }
        return ans;
    }
};


// vaiable size sliding problem
//11. https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
Problem Description:

Given an array containing N positive integers and an integer K. Your task is to find the length of the longest Sub-Array with sum of the elements equal to the given value K.

For Input:
1
7 5
4 1 1 1 2 3 5
your output is:
4 .



// 12. Longest substring With  K unique characters
https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

int longestKSubstr(string &s, int k) {
        // your code here
       int i=0;
       int j=0;
       unordered_map<char,int>mp;
       while(j<s.length())
       {
        mp[s[j]]++;
        if(mp.size()<k)
        {
            j++;
        }
        else if(mp.size()==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(mp.size()>k)
        {
            while(mp.size()>k)
            {
               mp[s[i]]--;
               if(mp[s[i]]==0)
               {
                mp.erase(s[i]);
               }
               i++;
            }
            j++;
        }
       }

        return mx;
    }




//13. Longest Substring without repeating  characters - means all unique characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i=0;
        int j=0;
        int mx=INT_MIN;
        if (s.size()==0) return 0;
        while(j<s.size())
        {
            mp[s[j]]++;
            if (mp.size()==j-i+1)
            {
                mx=max(mx,j-i+1);
            }
            else if (mp.size()<j-i+1)
            {
                while(mp.size()<j-i+1)
                {
                    mp[s[i]]--;
                    if (mp[s[i]]==0)
                    {
                        mp.erase(s[i]);
                    }
                    i++;
                }

            }
            j++;
        }
        return mx;
    }
};

//////

//1.  Pick toys
John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.


Example:
Input:
1
abaccab


#include<iostream>
#include<algorithm>
#include<map>
#define INT_MIN (-2147483647 - 1)
using namespace std;
int main(){
    string s;
    cin>>s;
    int k,j=0,i=0;
    k=2;
    map<char,int>m;
    int ans=0;
    while(j<s.size()){
        m[s[j]]++;
        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            ans=max(ans,j-i+1);
            j++;
        }else{
            while(m.size()>k){
                m[s[i]]--;
                if((m[s[i]]==0)){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    cout<<ans;
}


//2. Minimum window substring
https://leetcode.com/problems/minimum-window-substring/description/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string smallestWindow (string s, string p)
{
    // Your code here
    map<char,int>m;
    int n=s.size();
    for(int i=0;i<p.size();i++){
        m[p[i]]++;
    }
    int c=m.size();
    int i=0,j=0;
    int resStart=0,reslen=INT_MAX;
    while(j<n){
        m[s[j]]--;
        if(m[s[j]]==0){
            c--;
        }
        if(c==0){
            while(c==0){
                if(reslen>(j-i+1)){
                    reslen=j-i+1;#include<iostream>
                                 #include<bits/stdc++.h>
                                 using namespace std;
                                 string smallestWindow (string s, string p)
                                 {
                                     // Your code here
                                     map<char,int>m;
                                     int n=s.size();
                                     for(int i=0;i<p.size();i++){
                                         m[p[i]]++;
                                     }
                                     int c=m.size();
                                     int i=0,j=0;
                                     int resStart=0,reslen=INT_MAX;
                                     while(j<n){
                                         m[s[j]]--;
                                         if(m[s[j]]==0){
                                             c--;
                                         }
                                         if(c==0){
                                             while(c==0){
                                                 if(reslen>(j-i+1)){
                                                     reslen=j-i+1;
                                                     resStart=i;
                                                 }
                                                 m[s[i]]++;
                                                 if(m[s[i]]>0){
                                                     c++;
                                                 }
                                                 i++;
                                             }
                                         }
                                         j++;

                                     }
                                     if(reslen==INT_MAX){
                                         return "-1";
                                     }
                                     return s.substr(resStart,reslen);
                                 }
                                 int main(){
                                     string s,p;
                                     cin>>s>>p;
                                     cout<<smallestWindow(s,p);
                                 }

                    resStart=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0){
                    c++;
                }
                i++;
            }
        }
        j++;

    }
    if(reslen==INT_MAX){
        return "-1";
    }
    return s.substr(resStart,reslen);
}
int main(){
    string s,p;
    cin>>s>>p;
    cout<<smallestWindow(s,p);
}

