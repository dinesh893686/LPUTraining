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


// Searching in a nearly sorted array
https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1
// https://www.geeksforgeeks.org/search-almost-sorted-array/
int binarySearch(int arr[], int l, int r, int x)
{
if (r >= l)
{
		int mid = l + (r - l) / 2;

		// If the element is present at
		// one of the middle 3 positions
		if (arr[mid] == x)
			return mid;
		if (mid > l && arr[mid - 1] == x)
			return (mid - 1);
		if (mid < r && arr[mid + 1] == x)
			return (mid + 1);

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 2, x); // this time check on mid-2 cz mid-1 is already checked

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 2, r, x); // this time check on mid+2 cz mid+1 is already checked
}

// floor of an element in sorted array
https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1


class Solution{
  public:
    int findFloor(vector<long long> v, long long n, long long x){

        long long s = 0;
        long long e = n-1;
        long long ans = -1;
        long long mid = s + (e-s)/2;

        while(s<=e) {
            if(v[mid] == x) {
                return mid;
            }
            if(v[mid] > x) {
                e = mid - 1;
            }
            else {
                ans = mid;
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};


// Ceil of an element in sorted array
https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1
class Solution{
  public:
    int findCeil(vector<long long> v, long long n, long long x){

        long long s = 0;
        long long e = n-1;
        long long ans = -1;
        long long mid = s + (e-s)/2;

        while(s<=e) {
            if(v[mid] == x) {
                return mid;
            }
            if(v[mid] < x) {
                s = mid + 1;
            }
            else {
                ans = mid;
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};

// Next alphabetical element
https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end= letters.size()-1;
        char res=letters[start];
        while (start<=end){
            int mid = start+ (end-start)/2;
            if (target == letters[mid])
                start=mid+1; // here we dont want to return the matched we want the greater then target
            else if (target<letters[mid])
            {
                res=letters[mid];
                end=mid-1;
            }
            else
                start=mid+1;
        }
        return res;
    }
};


//find position of element in infinite sorted array
https://www.geeksforgeeks.org/dsa/find-position-element-sorted-array-infinite-numbers/

int findPosition(vector<int>& arr, int n, int k)
{
    int s = 0;
    int e = 1;

    while(arr[e] < k) {
        s = e;
        e = e*2;
    }
    return binarySearch(arr, s, e, k);
}

// Find first 1 in infinite sorted array
https://www.geeksforgeeks.org/dsa/find-index-first-1-infinite-sorted-array-0s-1s/


int findFirstOne(vector<int>& arr) {
    int s = 0;
    int e = 1;

    while(arr[e] == 0) {
        s = e;
        e = e*2;
    }

    // just here will be some chnages that you have to find 1 instead of k and that is first occcurance means code will be same to find first occurance
    return binarySearch(arr, s, e, 1);
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



//Given a sorted array, find the element in the array which has minimum difference with the given number. .

// absolute difference


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findClosestElement(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;

    // Handle edge cases
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return arr[mid];

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // After loop, low is next greater, high is next smaller
    if (abs(arr[low] - target) < abs(arr[high] - target))
        return arr[low];
    else
        return arr[high];
}

int main() {
    vector<int> arr = {1, 3, 8, 10, 15};
    int target = 12;
    cout << "Closest element to " << target << " is " << findClosestElement(arr, target) << endl;

    return 0;
}

// Search in a matrix that is row wise and column wise sorted

https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

🔗 Problem Link
👉 Search in a Matrix (GFG)

You're given an n x m matrix where each row and each column is sorted in increasing order. Find if a given target exists in the matrix.

💡 Why start at (i=0, j=m-1)?
📌 When you start at the top-right corner:

The element at mat[0][m-1] is:

The largest in its row

The smallest in its column

✅ This gives you maximum elimination power at each step:

If target == mat[i][j]: found it!

If target < mat[i][j]: move left (since all elements to the left are smaller)

If target > mat[i][j]: move down (since all elements below are larger)

⚡ This approach eliminates one row or one column at a time, reducing search space efficiently in O(n + m) time.

💻 C++ Solution
cpp
Copy
Edit
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int n, int m, int target) {
    int i = 0, j = m - 1;

    while (i < n && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        }
        else if (matrix[i][j] > target) {
            j--; // Move left
        }
        else {
            i++; // Move down
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    int target = 5;

    if (searchMatrix(matrix, n, m, target)) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}


⌛ Time Complexity
scss
Copy
Edit
O(n + m)
Each move eliminates a row or column.

📌 Key Idea Recap
We start at top-right (0, m-1) because:

From there, we can efficiently decide to go left (smaller values) or down (larger values).

Starting at bottom-left (n-1, 0) would work similarly but flipped directions.

👉 If you want this in another language (Python, Java) or to return coordinates, just say the word! 🚀










