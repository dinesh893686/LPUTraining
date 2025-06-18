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
    int mid = s + (e-s)/2;

    while(arr[e] < k) {
        s = e;
        e = e*2;
        mid = s + (e-s)/2;
    }
    return binarySearch(arr, s, e, k);
}

// Find first 1 in infinite sorted array
https://www.geeksforgeeks.org/dsa/find-index-first-1-infinite-sorted-array-0s-1s/


int findFirstOne(vector<int>& arr) {
    int s = 0;
    int e = 1;
    int mid = s + (e-s)/2;

    while(arr[e] == 0) {
        s = e;
        e = e*2;
        mid = s + (e-s)/2;
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
