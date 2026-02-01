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


// Rain water trapping problem
https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1


// Car fleet

CAR FLEET — SHORT & CLEAR SUMMARY
🧠 Problem in One Line

Cars move towards the same destination.
Faster cars may catch slower cars in front, forming fleets.
Once merged, they move together and never separate.
👉 Count how many such fleets reach the destination.

✅ Core Logic (Explain This to Student)

Cars cannot overtake, only merge.

Only cars behind can catch cars in front.

So, sort cars by position in decreasing order (closest to target first).

Convert each car’s movement into time to reach target.

Traverse from front to back:

If current car’s time ≤ time of fleet in front → it merges.

If current car’s time > time of fleet in front → new fleet forms.

Use a stack to store arrival times of fleets.

Stack size at the end = number of fleets.

🧱 Why Stack?

We only compare with the latest fleet formed

Fleets are formed in one direction

Once merged, fleets never change

👉 Stack naturally models this behavior.

💻 FULLY COMMENTED C++ CODE (LINE-BY-LINE)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        // Number of cars

        vector<pair<int, double>> cars;
        // Each pair will store:
        // first  -> position of car
        // second -> time required to reach target

        // Step 1: Calculate time for each car to reach the target
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            // Time = distance / speed

            cars.push_back({position[i], time});
            // Store position and time together
        }

        // Step 2: Sort cars by position in descending order
        // (closest to target first)
        sort(cars.begin(), cars.end(), greater<>());

        stack<double> st;
        // Stack will store time taken by each fleet

        // Step 3: Process each car
        for (int i = 0; i < n; i++) {

            double currTime = cars[i].second;
            // Time taken by current car to reach target

            // If stack is empty OR
            // current car cannot catch the fleet ahead
            if (st.empty() || currTime > st.top()) {

                // Current car forms a new fleet
                st.push(currTime);
            }
            // Else:
            // currTime <= st.top()
            // means current car catches the fleet ahead
            // so it merges and we do NOTHING
        }

        // Step 4: Number of fleets = stack size
        return st.size();
    }
};

🎯 One-Sentence Explanation for Students

“Sort cars by position, convert each to time, and count how many times a slower car appears when moving from front to back.”

🧠 Memory Trick

Time increases → New Fleet

Time decreases → Merge


//////////////////
Q. 1622. Clumsy Factorial
The factorial of a positive integer n is the product of all positive integers less than or equal to n.

For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
We make a clumsy factorial using the integers in decreasing order by swapping out the multiply operations for a fixed rotation of operations with multiply '*', divide '/', add '+', and subtract '-' in this order.

For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

Additionally, the division that we use is floor division such that 10 * 9 / 8 = 90 / 8 = 11.

Given an integer n, return the clumsy factorial of n.



First: What problem are we trying to solve?

We have an expression like:

10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1


And math rules say:

* and / must be handled before + and -

* and / go left to right

This is exactly the kind of situation where a stack helps.

🧸 Think of a stack like a pile of numbers

A stack is just:

You push numbers in

You sometimes change the top number

At the end, you add everything

Nothing scary.

🧸 The SIMPLE IDEA (core intuition)

Start from n

Go down to 1

Apply operations one by one

Use the stack to store partial results

🧠 The Golden Rule (this makes everything click)

When you see * or /
👉 Immediately calculate with the top of the stack

When you see + or -
👉 Just push the number (positive or negative)

Why?
Because + and - are done later.

🧩 Walkthrough with a stack (VERY important)

Let’s do n = 5

Operations order:

*  /  +  -

Step-by-step

Start with:

stack = []

Number = 5 (first number)

Push it:

stack = [5]

Next number = 4, operation = *

Pop top → 5
Compute:

5 * 4 = 20


Push result:

stack = [20]

Next number = 3, operation = /

Pop top → 20
Compute:

20 / 3 = 6   (floor division)


Push result:

stack = [6]

Next number = 2, operation = +

Just push 2:

stack = [6, 2]

Next number = 1, operation = -

Push -1:

stack = [6, 2, -1]

🧸 Final step: add everything
6 + 2 - 1 = 7

🎉 Final Answer
clumsy(5) = 7

🧠 WHY stack works (important)

Stack helps because:

* and / are handled immediately

+ and - are delayed

At the end, adding everything respects math rules

This avoids complex parsing.

🧠 What if we don’t use a stack?

You can do it without a stack, but:

It becomes confusing

Harder to get right

Easier to make mistakes

For beginners, stack = clarity.

🧠 Final takeaway (remember this)

When a problem has mixed operators and precedence,
a stack helps control evaluation order.


///

Gray code problem




What is this problem REALLY asking?

You are given a number A.

A = number of bits

You must create a list of numbers

These numbers must follow Gray Code rules

The list must start with 0

That’s all.

🧸 Step 1: What is a “bit”?

A bit can be only:

0 or 1


Examples:

1 bit → 0, 1

2 bits → 00, 01, 10, 11

🧸 Step 2: What is Gray Code?

Gray Code is a special ordering of binary numbers.

The ONLY rule of Gray Code

Two neighboring numbers must differ in exactly ONE bit

Not zero bits
Not two bits
Exactly one bit

🧸 Step 3: Smallest cases (to build intuition)
Case A = 0

No bits.

Only one value exists:

[0]

Case A = 1

1 bit.

Possible values:

0
1


Difference:

0 → 1  (1 bit changed ✅)


Gray Code:

[0, 1]

🧸 Step 4: Case A = 2 (important)

2 bits → normally:

00
01
10
11


But this is NOT Gray Code because:

01 → 10  (2 bits changed ❌)

✅ Correct Gray Code for A = 2
00
01
11
10


Check carefully:

00 → 01  (1 bit)
01 → 11  (1 bit)
11 → 10  (1 bit)


Decimal form:

[0, 1, 3, 2]

🧠 Key Question: How do we build this systematically?

This is the most important idea.

🔥 The Core Idea (remember this)

To build Gray Code for A bits:

Take Gray Code for A − 1 bits

Copy it

Reverse the copied list

Add 0 in front of each number in the original list

Add 1 in front of each number in the reversed list

Join both lists

That’s it.

🧸 Step-by-step example (A = 2)
Gray Code for A = 1
0
1

Prefix 0
00
01

Reverse and prefix 1
11
10

Final Gray Code (A = 2)
00
01
11
10

🧸 Example (A = 3)
Gray Code for A = 2
00
01
11
10

Prefix 0
000
001
011
010

Reverse and prefix 1
110
111
101
100

Final Gray Code (A = 3)
000
001
011
010
110
111
101
100


Decimal:

[0, 1, 3, 2, 6, 7, 5, 4]

🧠 Why does this always work?

Because:

The original list already follows the “one-bit difference” rule

Reversing ensures the connection in the middle also differs by one bit

Adding 0 and 1 changes only one new bit

So the rule is never broken.

🧠 What exactly do you need to return?

Return the decimal values of the Gray Code sequence

The sequence must start with 0

✍️ Very simple solution (iterative, beginner-friendly)
vector<int> grayCode(int A) {
    vector<int> result;
    result.push_back(0);

    for (int i = 0; i < A; i++) {
        int size = result.size();
        for (int j = size - 1; j >= 0; j--) {
            result.push_back(result[j] | (1 << i));
        }
    }
    return result;
}

🧠 Read this slowly (what the code is doing)

Start with [0]

For every new bit:

Copy the list in reverse

Add a new bit to those numbers

Append them

This matches the explanation exactly.

🧠 Final one-line takeaway (very important)

Gray Code is built by mirroring the previous list and adding one new bit.

If you understand this sentence, you understand the problem.

If you want, next I can:

Draw this with boxes and arrows

Explain the code line by line

Show a non-recursive mental trick

Practice with custom examples

Just tell me where you’re still confused 😊