// Binary Search Code 
#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}


int main() { 

    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);

    cout << " Index of 6 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);

    cout << " Index of 14 is " << oddIndex << endl;


    return 0;
}

// https://leetcode.com/problems/find-peak-element/description/
int findPeak(int arr[], int n) {

    int s =0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {
        //cout<<" s " << s <<" e " << e << endl;
        if(arr[mid] < arr[mid+1]){
            s = mid+1; 
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

//1. Find fast and last occurance 
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include<vector>
using namespace std;
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    
    return p;
}

//2. Find total Number of occurances

//3. Peak in mountain
https://leetcode.com/problems/peak-index-in-a-mountain-array

#include<vector>
using namespace std;

class Solution {
public:
  
    int find_pivot(vector<int> v) {
	int s = 0, e = v.size() - 1;
	int mid=(s + e) / 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find_pivot(arr);
    }
};

// 4. Search in sorted and rotated array
https://www.naukri.com/code360/problems/search-in-rotated-sorted-array_1082554

#include<vector>
using namespace std;

int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {

    int start = s;
    int end = e;

    int mid = start + (end-start)/2;

    while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }
    
    return -1;
}



int findPosition(vector<int>& arr, int n, int k)
{
    int pivot = getPivot(arr, n);
    if( k >= arr[pivot] && k <= arr[n-1])
    {//BS on second line
        return binarySearch(arr, pivot, n-1, k);
    }
    else
    {//BS on first line
        return binarySearch(arr, 0, pivot - 1, k);
    }
    
}

//5. Square Root of number using binary Search
https://www.naukri.com/code360/problems/square-root_893351

#include<iostream>
using namespace std;

 long long int sqrtInteger(int n) {
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}

// 5. Book Allocation Problem
https://www.geeksforgeeks.org/allocate-minimum-number-pages/
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    //cout << "checking for mid "<< mid <<endl;
    
    for(int i = 0; i<n; i++) {
        if(pageSum + arr[i] <= mid) {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if(studentCount > m || arr[i] > mid ) {
            return false;
        }
            pageSum = arr[i];
        }
        if(studentCount > m) {
            return false;
        }
        //cout << " for i " << i << " Student "<< studentCount << " pageSum " << pageSum << endl;
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0;
    int sum = 0;
    
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(arr,n,m,mid)) {
            //cout<<" Mid returned TRUE" << endl;
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}


//6. Painters Partition Problem
https://www.naukri.com/code360/problems/painter's-partition-problem_1089557



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

