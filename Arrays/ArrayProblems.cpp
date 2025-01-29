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
