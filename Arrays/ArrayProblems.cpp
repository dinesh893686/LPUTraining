

// 1. Duplicate in array
https://www.naukri.com/code360/problems/duplicate-in-array_893397

#include<vector>
using namespace std;
int findDuplicate(vector<int> &arr) 
{
    int ans = 0;
    
    //XOR ing all array elements
    for(int i = 0; i<arr.size(); i++ ) {
    	ans = ans^arr[i];
    }
	
    //XOR [1, n-1]
    for(int i = 1; i<arr.size();i++ ) {
    	ans = ans^i;
    }
    return ans;
}

// 2.Intersection of two sorted arrays
https://www.naukri.com/code360/problems/intersection-of-2-arrays_1082149
using namespace std;
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = 0, j = 0;
    vector<int> ans;
    while(i<n && j<m) {
    
    if(arr1[i]==arr2[j])
    {
    	ans.push_back(arr1[i]);
        i++;
        j++;
    }
    else if (arr1[i] < arr2[j]) {
  		i++;
    }
    else
    {
    	j++;
    }
    
    }
    return ans;
}

//3. Pair Sum 
https://www.naukri.com/code360/problems/pair-sum_697295

#include<vector>
using namespace std;
vector<vector<int> > pairSum(vector<int> &arr, int s){
   vector< vector<int> > ans;
   
   for(int i=0;i<arr.size(); i++ )
   {
   		for(int j = i+1; j<arr.size(); j++) {
        	if(arr[i] +arr[j] == s)
            {
            	vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
				ans.push_back(temp);
            }
        }
   }
   sort(ans.begin(), ans.end());
   return ans;
}

4. //Sort 0s and 1s
https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card 

#include<iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortOne(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        while(arr[left] == 0 && left < right )  {
            left++;
        }

        while(arr[right]==1 && left < right){
            right--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        if(left<right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

}

int main() {

    int arr[8] = {1,1,0,0,0,0,1,0};

    sortOne(arr, 8);
    printArray(arr, 8);


    return 0;
}


// 5. Indexes of subarray sum

https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include <bits/stdc++.h>
using namespace std;

/**
 * Finds a contiguous subarray of non-negative integers whose sum equals S.
 * Returns a pair of 0-based indices {start, end}, or {-1, -1} if none exists.
 */
pair<int,int> subarraySum(const vector<int>& nums, long long S) {
    int n = nums.size();
    long long current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        current_sum += nums[right];

        // Shrink window from the left as long as current_sum > S
        while (current_sum > S && left <= right) {
            current_sum -= nums[left];
            ++left;
        }

        // Check if we hit the target sum
        if (current_sum == S) {
            return { left, right };
        }
    }

    return { -1, -1 };
}


// 6. Problem : Merge Two Sorted Arrays In-Place
https://leetcode.com/problems/merge-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

/**
 * Merges array B into A in-place.
 * A has size m + n, with the first m elements valid and the last n elements empty (or arbitrary).
 * B has size n.
 * After the function, A contains all m+n elements in sorted order.
 */
void mergeInto(vector<int>& A, int m, const vector<int>& B, int n) {
    int i = m - 1;         // Last valid element in A
    int j = n - 1;         // Last element in B
    int k = m + n - 1;     // End of merged array in A

    // Merge from the back
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k--] = A[i--];
        } else {
            A[k--] = B[j--];
        }
    }
    // If any elements remain in B, copy them
    while (j >= 0) {
        A[k--] = B[j--];
    }
}



// Repeat and missing number array

https://www.interviewbit.com/problems/repeat-and-missing-number-array/


// this approch works for both more than one repeating and missing number


Given an unsorted array of size n. Array elements are in the range from 1 to n. Some numbers from set {1, 2, …n} are missing and some are repeating in the array. Find these two numbers in order of one space.


Input:[3 1 1 5 3]

Duplicate = 3,1  Missing = 2,4 .

#include <vector>
using namespace std;

// Returns a pair of vectors: {missing_numbers, duplicate_numbers}
pair<vector<int>,vector<int>> findMissingAndDuplicates(vector<int>& A) {
    int n = A.size();
    // 1) Cyclic sort: place each number v in position v-1
    for (int i = 0; i < n; ++i) {
        // While A[i] is in [1..n], and not already in its correct spot,
        // and not swapping a duplicate onto itself:
        while (A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i]) {
            swap(A[i], A[A[i]-1]);
        }
    }
    // 2) Collect missing & duplicates
    vector<int> missing, duplicates;
    for (int i = 0; i < n; ++i) {
        if (A[i] != i + 1) {
            // i+1 didn't end up at index i → it's missing
            missing.push_back(i + 1);
            // whatever did end up here is a duplicate
            duplicates.push_back(A[i]);
        }
    }
    return { missing, duplicates };
}


//7. Kadane Algorithm
https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
};

// longest Band
https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr){
	int n = arr.size();
	unordered_set<int> s;

	//Data inside a set
	for(int x : arr){
		s.insert(x);
	}

	//Iterate over the arr
	int largestLen = 1;

	for(auto element : s){
		int parent = element - 1;

		if(s.find(parent)==s.end()){
			//find entire band / chain starting from element
			int next_no = element + 1;
			int cnt = 1;

			while(s.find(next_no)!=s.end()){
				next_no++;
				cnt++;
			}

			if(cnt>largestLen){
				largestLen = cnt;
			}
		}
	}


	return largestLen;
}



int main(){

	vector<int> arr{1, 9, 3, 0, 18, 5, 2, 10, 7, 12, 6};
	cout << largestBand(arr)<<endl;

	return 0;
}


// Largest mountain in array
https://leetcode.com/problems/longest-mountain-in-array/description/

#include<iostream>
#include<vector>
using namespace std;


int highest_mountain(vector<int> a){
	int n = a.size();

	int largest = 0;

	for(int i=1;i<=n-2;){

		//check a[i] is peak or not
		if(a[i]>a[i-1] and a[i]>a[i+1]){
			//do some work
			int cnt = 1;
			int j = i;
			//cnt backwards (left)
			while(j>=1 and a[j]>a[j-1]){
				j--;
				cnt++;
			}
			//cnt forwards (right)
			while(i<=n-2 and a[i]>a[i+1]){
				i++;
				cnt++;
			}
			largest = max(largest,cnt);

		}
		else{
			i++;
		}
	}
	return largest;

}

int main(){

	vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

	cout<< highest_mountain(arr)<<endl;



	return 0;
}

// trapping rain water
https://leetcode.com/problems/trapping-rain-water/description/

// subarray sort
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> arr,int i){
	int x = arr[i];
	if(i==0){
		return x > arr[1];
	}
	if(i==arr.size()-1){
		return x < arr[i-1];
	}
	return x > arr[i+1] or x < arr[i-1];

}

pair<int,int> subarraySort(vector<int> arr) {

	int smallest = INT_MAX;
	int largest = INT_MIN;

	for(int i=0;i<arr.size();i++){
		int x = arr[i];

		if(outOfOrder(arr,i)){
			smallest = min(smallest,x);
			largest = max(largest,x);
		}
	}

	//next step find the right index where smallest and largest lie (subarray) for out solution
	if(smallest==INT_MAX){
		return {-1,-1};
	}

	int left = 0;
	while(smallest >= arr[left]){
		left++;
	}
	int right = arr.size() - 1;
	while(largest <= arr[right]){
		right--;
	}

	return {left,right};

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    cout<< p.first <<" and "<<p.second <<endl;

    return 0;
}
