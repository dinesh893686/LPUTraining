//Example1 

int sum=0
for(int i=0;i<n;i++)
{
    sum+=arr[i];
    cout<<sum;
}


//Example -2
//N Factorial Problem TIme Complexity Analysis

int fact=1;
for(int i=1;i<=n;i++)
{
    fact*=i;
}

// Nth Fibonacci-DP
for(int i=2;i<=n;i++)
{
    dp[i]=dp[i-1]+dp[i-2];
}

//Kadanes Algorithm
int currSum=0, ans=INT_MIN;
for(int i=0;i<n;i++)
{
    currSum+=arr[i];
    ans=max(currSum,ans);
    currSum=currSum<0?0:currSum;
}



///Bubble Sort
for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }
}

//Binary Search

int s=0, e=n-1;
while(s<=e)
{
    int mid =s+(e-s)/2;
    if(arr[mid]<target)
    {
        s=mid+1;
    }
    else if(arr[mid]>target)
    {
        e=mid-1;
    }
    else{
        return mid;
    }
}


// prime number - TIme Complexity
for(int i=2;i*i<=n;i++)
{
    if(n%i==0)
    {
        cout<<"Non Prime ";
        break;
    }
}


// Selection Sort
for(int i=0;i<n-1;i++)
{
    int minIdx=i;
    for(int j=i+1;j<n;j++)
    {
        if(arr[j]<arr[minIdx]
        )
        {
            minIdx=j;
        }
    }
    swap(arr[i],arr[minIdx]);
}