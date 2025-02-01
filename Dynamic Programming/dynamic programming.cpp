// 0-1 knapsack 
 https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// ->Recursive
#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	// every recursive solution will have a base condition 
  // for base condition we need to think of the smallest valid input that we can pass 
  // array size can be atleast 0 || min weight can be 0 but not negetive; 
	if (n == 0 || W == 0)
		return 0;

	// these are the choices we are having 
	if (wt[n - 1] <= W) {
		return max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),
		           Knapsack(wt, val, W, n - 1));
	}
	else if (wt[n - 1] > W) // if the weight is greater then the required weight there is no sence for taking that value. 
		return Knapsack(wt, val, W, n - 1); // return as it is by redusing the size of array 
	else
		return -1; 
}

int main() {
	int n,W; 
  cin >> n; // number of items
	int val[n], wt[n]; // values and weights of array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	
  cin >> W; // Knapsack capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}
// T(N) = 2T(N-1) + O(1), which is simplified to O(2^N).


// -> Memoization


#include <iostream>
using namespace std;

const int D = 1000; // DP - matrix dimension

int t[D][D]; // DP matrix

int Knapsack(int wt[], int val[], int W, int n) {
	// base case
	if (n == 0 || W == 0)
		return 0;

	// if already calculated
  
  
	if (t[n][W] != -1)
		return t[n][W];
  
	// else calculate
	else {
		if (wt[n - 1] <= W)
			t[n][W] = max(val[n - 1] + Knapsack(wt, val, W - wt[n - 1], n - 1),Knapsack(wt, val, W, n - 1));
		else if (wt[n - 1] > W)
			t[n][W] = Knapsack(wt, val, W, n - 1);

		return t[n][W];
	}
}

signed main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // capacity

	// matrix initialization
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= W; j++)
			t[i][j] = -1; // initialize matrix with -1

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
} 

// Tabulation

#include <iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) // base case // filling 1st row and 1st column of the matrix with zero as per the base condition of the recursive solution 
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag // this is for the choice diagram of the recursive solution
				int val1 = val[i - 1] + t[i - 1][j - wt[i - 1]]; // take current wt // and after taking weight substract the inserted weight from the final weight 
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j]; // move to next
		}
	}

	return t[n][W];
}

int main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // capacity

	cout << Knapsack(wt, val, W, n) << endl;
	return 0;
}

/* Complexity Analysis: 

Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/
//


//2. Subset Sum Problem
// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include <iostream>
using namespace std;

bool isSubsetPossible(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) { // itereate as long it is less then length of the array
		for (int j = 0; j <= sum; j++) { 
			if (i == 0)// when array(i) is empty than there is no meaning of sum of elements so return false
				t[i][j] = false;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
				t[i][j] = true;
		}
	}
// start from 1 since 1st row and column is already considerd 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) 
        // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array 
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // either take or(||) do not take 
			else // if sum is less than array size just leave and increment 
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum]; // at last return T/F
}

int main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum; cin >> sum;

	isSubsetPossible(arr, n, sum) ? cout << "Yes\n" : cout << "No\n";
	return 0; 
}
/*
Complexity Analysis: 

Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.
*/


//3. Equal Sum partition 

// https://www.geeksforgeeks.org/partition-problem-dp-18/
#include <bits/stdc++.h>
using namespace std;

bool isSubsetPossible(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) { // itereate as long it is less then length of the array
		for (int j = 0; j <= sum; j++) { 
			if (i == 0)// when array(i) is empty than there is no meaning of sum of elements so return false
				t[i][j] = false;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return it as true;
				t[i][j] = true;
		}
	}
// start from 1 since 1st row and column is already considerd 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) 
        // after taking and element substract from the (sum) i.e -> in {3,8} 3 is taken then we want 11-3=8in the array 
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // either take or(||) do not take 
			else // if sum is less than array size just leave and increment 
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum]; // at last return T/F
}

bool EqualSumPartitionPossible(int arr[], int n) {
	int sum = 0; // sum of all elements of arr
	for (int i = 0; i < n; i++) // take the sum of array 
		sum += arr[i];

	if (sum % 2 != 0) // if sum is odd --> not possible to make equal partitions
		return false;

	return isSubsetPossible(arr, n, sum / 2); // when even divide sum of array into two part and apply subset sum 
}

int main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	EqualSumPartitionPossible(arr, n) ? cout << "YES\n" : cout << "NO\n";
	return 0;
}

/*
Time Complexity: O(sum * n)
Auxiliary Space: O(sum)
*/


// 4. Count subsets with given sum

// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/
#include <bits/stdc++.h>
using namespace std;

int CountSubsets(int arr[], int n, int sum) {
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization 
  // here we are setting 1st row and 1st column 
  // i denotes the size of the array 
  // j denotes the target sum (subset sum)
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0) // when array(i) is empty than there is no meaning of sum of elements so return count of subset as 0;
				t[i][j] = 0;
			if (j == 0) // when sum(j) is zero and there is always a chance of empty subset so return count as 1;
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j) // when element in the list is less then target sum 
				t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j]; // either exclude or inxlude and add both of them to get final count 
			else
				t[i][j] = t[i - 1][j]; // exclude when element in the list is greater then the sum 
		}
	}

	return t[n][sum]; // finally return the last row and last column element 
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum; cin >> sum;

	cout << CountSubsets(arr, n, sum) << endl;
	return 0;
}

/*
Time Complexity: O(sum*n), where the sum is the ‘target sum’ and ‘n’ is the size of the array.

Auxiliary Space: O(sum*n), as the size of the 2-D array, is sum*n. 
*/ 

//5. Minimum subset sum difference
https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

vector<int> isSubsetPoss(int arr[], int n, int sum) {
	bool t[n + 1][sum + 1]; // DP - matrix
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = false; 
			if (j == 0)
				t[i][j] = true;
		}
	}
// taking from the 2nd row and 2nd column 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (arr[i - 1] <= j)
				t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j]; // include or exclude
			else
				t[i][j] = t[i - 1][j]; // exclude
		}
	}

	vector<int> v; // contains all subset sums possible with n elements // creating a vector varible to store all the element of the last row 
	for (int j = 0; j <= sum; j++) // from the range we need to exclude the element which is not there in the existing problem 
		if (t[n][j] == true) // keep true to only those place whose subset sum exist
			v.push_back(j); // store in the vector 

	return v;
}

int MinSubsetSumDiff(int arr[], int n) {
	int range = 0;
	for (int i = 0; i < n; i++)
		range += arr[i]; // taking sum of the array for range 

	vector<int> v = isSubsetPoss(arr, n, range);
	int mn = INT_MAX;
	for (int i = 0; i < v.size(); i++) // iterating through the last row of the matrix 
		mn = min(mn, abs(range - 2 * v[i])); // taking minimum from the last row 

	return mn;
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << MinSubsetSumDiff(arr, n) << endl;
	return 0;
}

//6. Count the number of subsets with given difference 
https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Given an array Arr[] and a difference diff, find the number of subsets that array can be divided so that each the difference between the two subset is the given diff.

Example1:
Input:
Arr[] : 1,1,2,3
diff: 1
Output: 3 . 

//7. Target Sum

https://leetcode.com/problems/target-sum/description/

Target Sum Problem
Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

//8. Unbounded Knapsack
https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Unbounded Knapsack (Repetition of items allowed)
 Given a knapsack weight W and a set of n items with certain value vali and weight wti, we need to calculate minimum amount that could make up this quantity exactly. This is different from classical Knapsack problem, here we are allowed to use unlimited number  of instances of an item.
Examples:

Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.