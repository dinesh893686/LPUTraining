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


#include <bits/stdc++.h>
using namespace std;

int CountSubsetsWithSum(int arr[], int n, int sum) {
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

int CountSubsetsWithDiff(int arr[], int n, int diff) {
	int sumOfArray = 0;
	for (int i = 0; i < n; i++)
		sumOfArray += arr[i]; // taking sum of the array 

	if ((sumOfArray + diff) % 2 != 0)
		return 0;
	else
		return CountSubsetsWithSum(arr, n, (sumOfArray + diff) / 2);// we will get the number of array(subset) with particular sum 
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int diff; cin >> diff;

	cout << CountSubsetsWithDiff(arr, n, diff) << endl;
	return 0;
}

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


class Solution {
public:
   int CountSubsetsWithSum(vector<int>& nums,int sum) {
       int n= nums.size();
	int t[n + 1][sum + 1]; // DP - matrix
	// initialization
	t[0][0] = 1;
	int k = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0 && j > 0)
				t[i][j] = 0;
			if (j == 0 && i > 0) {
				if (nums[i - 1] == 0) {
					t[i][j] = pow(2, k);
					k++;
				}
				else
					t[i][j] = t[i - 1][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (nums[i - 1] <= j)
				t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
			else
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][sum];
}
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n= nums.size();
	int sumOfArray = 0;
	for (int i = 0; i < n; i++)
		sumOfArray += nums[i];

	if ((sumOfArray + diff) % 2 != 0)
		return 0;
	else
		return CountSubsetsWithSum(nums, (sumOfArray + diff) / 2);

    
    }
};

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

#include <bits/stdc++.h>
using namespace std;

int Un_knapsack(int wt[], int val[], int W, int n) {
	int t[n + 1][W + 1]; // DP matrix

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0) // base case
				t[i][j] = 0;
			else if (wt[i - 1] <= j) { // current wt can fit in bag
				int val1 = val[i - 1] + t[i][j - wt[i - 1]]; // take current wt
				int val2 = t[i - 1][j]; // skip current wt
				t[i][j] = max(val1, val2);
			}
			else if (wt[i - 1] > j) // current wt doesn't fit in bag
				t[i][j] = t[i - 1][j];
		}
	}

	return t[n][W];
}

signed main() {
	int n; cin >> n; // number of items
	int val[n], wt[n]; // values and wts array
	for (int i = 0; i < n; i++)
		cin >> wt[i];
	for (int i = 0; i < n; i++)
		cin >> val[i];
	int W; cin >> W; // capacity

	cout << Un_knapsack(wt, val, W, n) << endl;
	return 0;
}

//9. Rod Cutting Problem
https://www.geeksforgeeks.org/problems/rod-cutting0840/1

Rod Cutting Problem
 Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the  maximum value obtainable by cutting up the rod and selling the pieces. 
Example: 
if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)


length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20

//https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
#include <bits/stdc++.h>
using namespace std;

int getMaxProfit(int length[], int price[], int n, int L) {
	int dp[n + 1][L + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= L; j++)
			if (j == 0 || i == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= L; j++) {
			if (length[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j],
				               price[i - 1] + dp[i][j - length[i - 1]]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][L];
}

signed main() {
	int n; cin >> n;
	int length[n], price[n];
	for (int i = 0; i < n; i++)
		cin >> length[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];
	int L; cin >> L;

	cout << getMaxProfit(length, price, n, L) << endl;
	return 0;
}

// 10.
https://www.geeksforgeeks.org/problems/coin-change2448/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
Coin Change Problem Maximum Number of ways
Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
Example:
for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.


#include <bits/stdc++.h>
using namespace std;

int getMaxNumberOfWays(int coins[], int n, int sum) {
	int t[n + 1][sum + 1];
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (i == 0)
				t[i][j] = 0;
			if (j == 0)
				t[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
			if (coins[i - 1] <= j)
				t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
			else
				t[i][j] = t[i - 1][j];

	return t[n][sum];
}

signed main() {
	int n; cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum; cin >> sum;

	cout << getMaxNumberOfWays(coins, n, sum) << endl;
	return 0;
}

//11. Get minimum number of coins
https://leetcode.com/problems/coin-change/description/

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX-1

int getMinNumberOfCoins(int coins[], int n, int sum) {
	int t[n + 1][sum + 1];
	// initialization
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum; j++) {
			if (j == 0)
				t[i][j] = 0;
			if (i == 0)
				t[i][j] = INF;
			if (i == 1) {
				if (j % coins[i - 1] == 0)
					t[i][j] = j / coins[i - 1];
				else
					t[i][j] = INF;
			}
		}
	}

	t[0][0] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++)
			if (coins[i - 1] <= j)
				t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
			else
				t[i][j] = t[i - 1][j];

	return t[n][sum];
}

signed main() {
	int n; cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	int sum; cin >> sum;

	cout << getMinNumberOfCoins(coins, n, sum) << endl;
	return 0;
}

// LCS- Longest Common Subsequence
https://leetcode.com/problems/longest-common-subsequence/description/

->Recursive approch

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0)
		return 0;

  // choice diagram
	// when both string X and Y is having same last char
	if (X[n - 1] == Y[m - 1])
		return 1 + LCS(X, Y, n - 1, m - 1); // count the number and decreament the both's string length
	// when both string's last character is not same 
	else
		return max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last and vice versa 
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}

-> Memoized approch

#include <bits/stdc++.h>
using namespace std;


int dp[1001][1001];

int LCS(string X, string Y, int n, int m) {
	// base case
	if (n == 0 || m == 0)
		dp[n][m] = 0;

	if (dp[n][m] != -1) // when table is not having -1 then return the value which is preseent in that block
		return dp[n][m];

  // choice diagram 
	// when last character is same
	if (X[n - 1] == Y[m - 1])
		dp[n][m] = 1 + LCS(X, Y, n - 1, m - 1);// count the number and decreament the both's string length // store the value in particular block 
	// when last character is not same -> pick max
	else
		dp[n][m] = max(LCS(X, Y, n - 1, m), LCS(X, Y, n, m - 1)); // one take full and another by leaving last char and vice versa // store the value in particular block 

	return dp[n][m];
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	memset(dp, -1, sizeof(dp)); // intialize the whole dp matrix with -1; // from memset we can initialise either -1 and zero;

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}

-> Tabulation approch

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// initialize 1st row and of dp matrix with 0 according to the base condition of recursion // base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;
// choise diagram is used to fill rest of the matrix 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m]; // last row and last column element will give the length of the LCS;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}

// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/#:~:text=Time%20complexity%20of%20the%20above,length%20of%20LCS%20is%200.&text=In%20the%20above%20partial%20recursion,%E2%80%9D)%20is%20being%20solved%20twice.


// Longest common substring
https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include <bits/stdc++.h>
using namespace std;

int LCSubstr(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

  // base condition 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0; //

  // choice diagram 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when both string's last char is same
				dp[i][j] = 1 + dp[i - 1][j - 1]; // count the number and decrement the table 
			else
				dp[i][j] = 0; // variation from LCS(DP)

	int mx = INT_MIN;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, dp[i][j]);

	return mx;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCSubstr(X, Y, n, m) << endl;
	return 0;
}

// https://www.geeksforgeeks.org/longest-common-substring-dp-29/



// https://leetcode.com/problems/jump-game-ii/description/

int min_jumps(vector<int>arr, int n, vector<int>dp,int i)
{
   if(i==n-1)
   {
      return 0;

   }
   if(i>=n)
   {
   return INT_MAX;
   }

   //rec case
   if(dp[i]!=0)
   {
   return dp[i];
   }
   //assume
   int steps=INT_MAX;
   int max_jump= arr[i];
   for(int jump=1; jump<=max_jump; jump++)
   {
   int next_cell= i+jump;
   int subprob= min_jumps(arr,n,dp,next_cell);
   if(subprob!=INT_MAX)
   {
   steps= min(steps,subprob+1);
   }
   }
   return dp[i]=steps;

}



//  Print LCS
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
#include <bits/stdc++.h>
using namespace std;

string LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string lcs = ""; // store charecter when it is equal in the table 
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			lcs += X[i - 1]; // insert in string 
			i--, j--;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--; // move to the larger side 
			else
				i--;
		}
	}
	reverse(lcs.begin(), lcs.end()); // at last reverse the string to get LCS 

	return lcs;
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << LCS(X, Y, n, m) << endl;
	return 0;
}


//Frog's Min Cost
There are N stones given in the form an array , each element in array represents the height of the stone.There is a frog who is initially on the first stone. Frog will repeat the following action some number of times to reach stone N:
If the frog is currently on stone i, he can jump to stone i+1 or stone i+2.
Here , a cost of |hi - hj| is incurred when the frog jumps from stone i to stone j.
Find the minimum possible total cost incurred before the frog reaches stone N.

https://atcoder.jp/contests/dp/tasks/dp_a














// Shortest Common Supersequence


#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

int SCS(string X, string Y, int n, int m) {
	return m + n - LCS(X, Y, n, m); // formula // n-> length of string x ; m-> length of string y
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << SCS(X, Y, n, m) << endl;
	return 0;
}


// Minimum insertion deletion to convert a to b.cpp

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

void MinInsertDel(string X, string Y, int n, int m) {
	int lcs_len = LCS(X, Y, n, m);
	cout << "Minimum number of deletions = " << (n - lcs_len)<<endl;
    cout << "Minimum number of insertions = " << (m - lcs_len)<<endl;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	MinInsertDel(X, Y, n, m) << endl;
	return 0;
}


// Longest Palindromic Subsequence.cpp

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end()); // reverse the string // take reversed string as another string of lcs and apply lcs 
	return LCS(X, rev_X, n, n);
}

signed main() {
	string X, Y; cin >> X;
	int n = X.length();

	cout << LPS(X, n) << endl;
	return 0;
}

//minimum number of deletions to make a string a palindrome
#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n);
}
// . minimum number of deletions 
  // min = n – len
int MinDelForPallindrome(string X, int n) {
	return n - LPS(X, n); // substract LPS from the length of string to get Minimum number of deletions to make a string palindrome
}

signed main() {
	string X, Y; cin >> X;
	int n = X.length();

	cout << MinDelForPallindrome(X, n) << endl;
	return 0;
}

// Print SCS

#include <bits/stdc++.h>
using namespace std;

string SCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string scs = "";
	while (i > 0 && j > 0) {
		if (X[i - 1] == Y[j - 1]) { // when char are eqaul from table obs 
			scs += X[i - 1]; // take only once 
			i--, j--; // and decrement both
		}
		else if (dp[i][j - 1] > dp[i - 1][j]) {
			scs += Y[j - 1]; // in this we will take the charecter to string 
			j--;
		}
		else {
			scs += X[i - 1]; // taking the charecter to string 
			i--;
		}
	}

	while (i > 0) {
		scs += X[i - 1]; // take left chareter from str1
		i--;
	}

	while (j > 0) {
		scs += Y[j - 1]; // take left chareter from str1
		j--;
	}

	reverse(scs.begin(), scs.end());

	return scs;
}

int main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	cout << SCS(X, Y, n, m) << endl;
	return 0;
}

//  https://www.geeksforgeeks.org/longest-repeating-subsequence/


#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1] && i != j) // jsut add an condition that element at ith index should not be equal to jth index 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

signed main() {
	string X; cin >> X;
	int n = X.length();

	cout << LCS(X, X, n, n) << endl;
	return 0;
}


// https://leetcode.com/problems/is-subsequence/description/
#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

bool SeqPatternMatching(string X, string Y, int n, int m) {
	return LCS(X, Y, n, m) == min(n, m); // condition to get sequence // if string x is there in y print boolean value according to LCS 
}

signed main() {
	string X, Y; cin >> X >> Y;
	int n = X.length(), m = Y.length();

	SeqPatternMatching(X, Y, n, m) ? "YES\n" : "NO\n";
	return 0;
}

//Dynamic Programming
//26 Minimum Number of insertion to make a string palindrome.cpp

#include <bits/stdc++.h>
using namespace std;

int LCS(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (X[i - 1] == Y[j - 1]) // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	return dp[n][m];
}

int LPS(string X, int n) {
	string rev_X = X;
	reverse(rev_X.begin(), rev_X.end());
	return LCS(X, rev_X, n, n);
}

int MinInsertForPallindrome(string X, int n) {
	return n - LPS(X, n); // substract LPS from the length of string to get Minimum number of insertion to make a string palindrome
}

int main() {
	string X, Y; cin >> X;
	int n = X.length();

	cout << MinInsertForPallindrome(X, n) << endl;
	return 0;
}

// MCM problem

// Recursive

#include <bits/stdc++.h>
using namespace std;

int Solve(int arr[], int i, int j) {
	if (i >= j)
		return 0;

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans); // take temp minimum value from the temp answers
	}

	return ans;
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << Solve(arr, 1, n - 1) << endl;
	return 0;
}

//Memoziation
#include <bits/stdc++.h>
using namespace std;

const int D = 1000;
int t[D][D];

int Solve(int arr[], int i, int j) {
	if (i >= j) {
		t[i][j] = 0;
		return 0;
	}

	if (t[i][j] != -1)// when it is not zero means return the value from the table other than -1
		return t[i][j]; 

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans; // store it in table 
}

signed main() {
	int n; cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	memset(t, -1, sizeof(t));

	cout << Solve(arr, 1, n - 1) << endl;
	return 0;
}
//https://www.techiedelight.com/matrix-chain-multiplication/


// Palindromic Partition

// Recursive
#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string X, int i, int j) { // function to check either a string is palindrome or not 
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j))
		return 0;

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1;
		ans = min(ans, temp_ans);
	}

	return ans;
}

int main() {
	string X; cin >> X;

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}


//Memoized

#include <bits/stdc++.h>
using namespace std;

const int D = 1001;
int t[D][D];

bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string X, int i, int j) {
	if (i >= j || isPallindrome(X, i, j)) {
		t[i][j] = 0;
		return 0;
	}

	if (t[i][j] != -1)
		return t[i][j];

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int temp_ans = Solve(X, i, k) + Solve(X, k + 1, j) + 1;
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans;
}

int main() {
	string X; cin >> X;

	memset(t, -1, sizeof(t));

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}

// Memoization+further optimaztion
#include <bits/stdc++.h>
using namespace std;

const int D = 1001;
int t[D][D];

bool isPallindrome(string X, int i, int j) {
	while (i <= j) {
		if (X[i] != X[j])
			return false;
		i++, j--;
	}

	return true;
}

int Solve(string X, int i, int j) {
	if (t[i][j] != -1)
		return t[i][j];

	if (i >= j || isPallindrome(X, i, j)) {
		t[i][j] = 0;
		return 0;
	}

	int ans = INT_MAX;
	for (int k = i; k < j; k++) {
		int left, right;
		if (t[i][k] == -1)
			left = Solve(X, i, k);
		else
			left = t[i][k];

		if (t[k + 1][j] == -1)
			right = Solve(X, k + 1, j);
		else
			right = t[k + 1][j];

		int temp_ans = left + right + 1;
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans;
}

int main() {
	string X; cin >> X;

	memset(t, -1, sizeof(t));

	cout << Solve(X, 0, X.length() - 1) << endl;
	return 0;
}


//Evaluate Expression to true Recursive
https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1
#include <bits/stdc++.h>
using namespace std;

int Solve(string X, int i, int j, bool isTrue) {
	if (i >= j) {
		if (isTrue)
			return X[i] == 'T';
		else
			return X[i] == 'F';
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	return ans;
}

int main() {
	string X; cin >> X;
	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}
// memoization using map
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> ump;

int Solve(string X, int i, int j, bool isTrue) {
	string key = to_string(i) + " " + to_string(j) + " " + (isTrue ? "T" : "F");

	if (ump.find(key) != ump.end())
		return ump[key];

	if (i >= j) {
		if (isTrue)
			ump[key] = X[i] == 'T';
		else
			ump[key] = X[i] == 'F';
		return ump[key];
	}

	int ans = 0;
	for (int k = i + 1; k < j; k += 2) {
		int l_T = Solve(X, i, k - 1, true);
		int l_F = Solve(X, i, k - 1, false);
		int r_T = Solve(X, k + 1, j, true);
		int r_F = Solve(X, k + 1, j, false);

		if (X[k] == '|') {
			if (isTrue == true)
				ans += l_T * r_T + l_T * r_F + l_F * r_T;
			else
				ans += l_F * r_F;
		}
		else if (X[k] == '&') {
			if (isTrue == true)
				ans += l_T * r_T;
			else
				ans += l_T * r_F + l_F * r_T + l_F * r_F;
		}
		else if (X[k] == '^') {
			if (isTrue == true)
				ans += l_T * r_F + l_F * r_T;
			else
				ans += l_T * r_T + l_F * r_F;
		}

	}

	return ump[key] = ans;
}

signed main() {
	string X; cin >> X;
	ump.clear();
	cout << Solve(X, 0, X.length() - 1, true) << endl;
	return 0;
}

// Scramble String
https://www.interviewbit.com/problems/scramble-string/


#include <bits/stdc++.h>
using namespace std;

bool Solve(string X, string Y) {
	if (X.compare(Y) == 0)
		return true;
	if (X.length() <= 1)
		return false;

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) || // these are two condition for swapping and not swapping the string 
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true; // change the  flag to true and break 
			break;
		}
	}

	return flag;
}

int main() {
	string X, Y; cin >> X >> Y;

	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}

// Optimaziation(top-down dp)
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> ump;

bool Solve(string X, string Y) {
	string key = X + " " + Y;
	if (ump.find(key) != ump.end()) // if we did not found the and travesed upto end of the map 
		return ump[key];

	if (X.compare(Y) == 0) {
		ump[key] = true;
		return true;
	}
	if (X.length() <= 1) {
		ump[key] = false;
		return false;
	}

	int n = X.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((Solve(X.substr(0, i), Y.substr(n - i, i)) && Solve(X.substr(i), Y.substr(0, n - i))) ||
		        (Solve(X.substr(0, i), Y.substr(0, i)) && Solve(X.substr(i), Y.substr(i)))) {
			flag = true;
			break;
		}
	}

	return ump[key] = flag; // store in table for further reference 
}

int main() {
	string X, Y; cin >> X >> Y;

	ump.clear();

	if (X.length() != Y.length())
		cout << "No\n";
	else
		Solve(X, Y) ? cout << "Yes\n" : cout << "No\n";
	return 0;
}


// egg dropping puzzle

// recursive

#include <bits/stdc++.h>
using namespace std;

int Solve(int eggs, int floors) {
	if (eggs == 1)
		return floors;
	if (floors == 0 || floors == 1)
		return floors;

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k)); // once egg break means decrement both floor and egg another agg did not break means check egg dropping from above 
		mn = min(mn, temp_ans);
	}

	return mn;
}

int main() {
	int eggs, floors;
	cin >> eggs >> floors;

	cout << Solve(eggs, floors) << endl;
	return 0;
}

//top-down

#include <bits/stdc++.h>
using namespace std;

const int D = 101;
int t[D][D];

int Solve(int eggs, int floors) {
	if (t[eggs][floors] != -1)
		return t[eggs][floors];

	if (eggs == 1 || floors == 0 || floors == 1) {
		t[eggs][floors] = floors;
		return floors;
	}

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int temp_ans = 1 + max(Solve(eggs - 1, k - 1), Solve(eggs, floors - k));
		mn = min(mn, temp_ans);
	}

	return t[eggs][floors] = mn; // store in table for further reference 
}

signed main() {
	int eggs, floors;
	cin >> eggs >> floors;

	memset(t, -1, sizeof(t));

	cout << Solve(eggs, floors) << endl;
	return 0;
}

//further optimization

#include <bits/stdc++.h>
using namespace std;

const int D = 101;
int dp[D][D];

int Solve(int eggs, int floors) {
	if (dp[eggs][floors] != -1) // if value is already there in the table then return the value 
		return dp[eggs][floors];

	if (eggs == 1 || floors == 0 || floors == 1) { // base condition
		dp[eggs][floors] = floors;
		return floors;
	}

	int mn = INT_MAX;
	for (int k = 1; k <= floors; k++) {
		int top, bottom;
		if (dp[eggs - 1][k - 1] != -1) // break the temp in sub problemes 
			top = dp[eggs - 1][k - 1];
		else {
			top = Solve(eggs - 1, k - 1);
			dp[eggs - 1][k - 1] = top;
		}

		if (dp[eggs][floors - k] != -1)
			bottom = dp[eggs][floors - k];
		else {
			bottom = Solve(eggs, floors - k);
			dp[eggs][floors - k] = bottom;
		}
		int temp_ans = 1 + max(top, bottom);
		mn = min(mn, temp_ans);
	}

	return dp[eggs][floors] = mn;
}

int main() {
	int eggs, floors;
	cin >> eggs >> floors;

	memset(dp, -1, sizeof(dp));

	cout << Solve(eggs, floors) << endl;
	return 0;
}


//
https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/



// Wine Selling Problem

Problem Statement
Given a row of n wines, with integers representing the cost of each wine. You can sell the first or last wine in a row every year. The cost of wine, on the other hand, rises over time. Let the initial profits from the wines be P1, P2, P3…Pn. In the Yth year, the profit from the ith wine will be Y*Pi.

The goal is to calculate the maximum profit that can be made by selling all of the wines.

Input: WinePrice: 2 4 6 2 5
Output: 64


Explanation:

price = 2*1 = 2, remaining WinePrice = [ 4, 6, 2, 5 ], Profit = 2
price = 5*2 = 10, remaining WinePrice = [ 4, 6, 2 ], Profit = 12
price = 2*3 = 6, remaining WinePrice = [ 4, 6], Profit = 18
price = 4*4 = 16, remaining WinePrice = [ 6 ], Profit = 34
price = 6*5 = 30, remaining WinePrice = [ ], Profit = 64



Count Square Submatrices with All Ones
// https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/




// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

Given a wooden stick of length n units. The stick is labelled from 0 to n. For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.

 

Example 1:

Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
Example 2:

Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
 

Constraints:

2 <= n <= 106
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1

SOLUTION - INTERVAL DYNAMIC PROGRAMMING:

Key Insight: This is an interval DP problem. The order of cuts matters!
- When we make a cut, the cost is the current stick length
- After a cut, we work with two independent subproblems (left and right pieces)
- We need to try all possible "last cuts" and pick the minimum

Approach:
1. Add boundaries: cuts = [0] + sorted(cuts) + [n]
2. dp[i][j] = minimum cost to make all cuts between position cuts[i] and cuts[j]
3. For segment [i, j], try each cut k in between as the "last cut"
   - Cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j]
   - The length (cuts[j] - cuts[i]) is added because this is the cost of making the last cut
4. Build from smaller segments to larger ones
*/

class Solution {
public:
    // Method 1: Top-Down DP with Memoization
    int minCost_Memoization(int n, vector<int>& cuts) {
        // Add boundaries and sort
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        
        return solve(0, m - 1, cuts, dp);
    }
    
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        // Base case: no cuts between i and j
        if (j - i <= 1) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int minCost = INT_MAX;
        
        // Try each position k as a cut point
        for (int k = i + 1; k < j; k++) {
            // Cost of cutting at k + cost of left part + cost of right part
            int cost = (cuts[j] - cuts[i]) + solve(i, k, cuts, dp) + solve(k, j, cuts, dp);
            minCost = min(minCost, cost);
        }
        
        return dp[i][j] = minCost;
    }
    
    // Method 2: Bottom-Up DP (Tabulation)
    int minCost(int n, vector<int>& cuts) {
        // Add boundaries and sort
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        // Build from smaller segments to larger ones
        // length represents the number of elements between i and j
        for (int length = 2; length < m; length++) {
            for (int i = 0; i + length < m; i++) {
                int j = i + length;
                dp[i][j] = INT_MAX;
                
                // Try each position k as a cut point
                for (int k = i + 1; k < j; k++) {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[0][m - 1];
    }
};

/*
DRY RUN Example: n = 7, cuts = [1, 3, 4, 5]

Step 1: Add boundaries and sort
cuts = [0, 1, 3, 4, 5, 7]
indices: 0  1  2  3  4  5

Step 2: Build DP table
dp[i][j] = minimum cost to cut stick from cuts[i] to cuts[j]

Length = 2 (adjacent elements, no cuts between):
dp[0][1] = 0, dp[1][2] = 0, dp[2][3] = 0, dp[3][4] = 0, dp[4][5] = 0

Length = 3 (one cut between):
dp[0][2]: segment [0,3], cut at 1
  cost = (3-0) + dp[0][1] + dp[1][2] = 3 + 0 + 0 = 3

dp[1][3]: segment [1,4], cut at 3
  cost = (4-1) + dp[1][2] + dp[2][3] = 3 + 0 + 0 = 3

... and so on

Final answer: dp[0][5] = minimum cost for entire stick

Time Complexity: O(m^3) where m = cuts.length + 2
Space Complexity: O(m^2)

WHY THIS WORKS:
- We consider each possible "last cut" in a segment
- The cost of the last cut is the length of that segment
- After making a cut, left and right parts are independent subproblems
- By trying all possibilities and taking minimum, we get optimal answer

Similar Problems:
- Matrix Chain Multiplication
- Burst Balloons
- Minimum Cost Tree From Leaf Values
*/

void test_minCostToCutStick() {
    Solution sol;
    
    // Test case 1
    vector<int> cuts1 = {1, 3, 4, 5};
    cout << "Test 1 - n=7, cuts=[1,3,4,5]: " << sol.minCost(7, cuts1) << endl;
    // Expected: 16
    
    // Test case 2
    vector<int> cuts2 = {5, 6, 1, 4, 2};
    cout << "Test 2 - n=9, cuts=[5,6,1,4,2]: " << sol.minCost(9, cuts2) << endl;
    // Expected: 22
}
