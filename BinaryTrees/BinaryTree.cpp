// Binary Tree Travesls

#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

vector<int> levelOrderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }

    return result;
}


void inorder(node* root) {
}

void preorder(node* root) {
}

void postorder(node* root) {
}

void buildFromLevelOrder(node* &root) {
 }


int main() {

    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    /*
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);

    cout << "inorder traversal is:  ";
    inorder(root); 

    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    cout << endl << "postorder traversal is:  ";
    postorder(root); 
    */


    return 0;
}

//1. Height of binary tree
https://www.geeksforgeeks.org/problems/height-of-binary-tree/1


    int height(struct Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }


//2.Diameter of binary tree
https://www.geeksforgeeks.org/problems/height-of-binary-tree/1


// brute force
int height(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diaThroughRoot = leftHeight + rightHeight;

    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    return max(diaThroughRoot, max(leftDia, rightDia));
}

class Solution {
 
  public:
    // Function to return the diameter of a Binary Tree.
    
    pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    int diameter(Node* root) {
    
        return diameterFast(root).first;
        
    }
};

//3. https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }


//4. https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

// Function to check if two trees are identical
bool isIdentical(Node* root1, Node* root2) {
    // If both nodes are null, they match
    if (root1 == nullptr && root2 == nullptr)
        return true;

    // If one is null and the other is not, they don’t match
    if (root1 == nullptr || root2 == nullptr)
        return false;

    // Check current node’s data, then recurse on left and right subtrees
    return (root1->data == root2->data)
           && isIdentical(root1->left, root2->left)
           && isIdentical(root1->right, root2->right);
}


//5. https://www.geeksforgeeks.org/problems/sum-tree/1

 pair<bool,int> isSumTreeFast(Node* root) {
        
        //base case
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL ) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> leftAns = isSumTreeFast(root->left);
        pair<bool,int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool condn = root->data == leftSum + rightSum;
        
        pair<bool, int> ans;
        
        if(isLeftSumTree && isRightSumTree && condn) {
            ans.first = true;
            ans.second = root->data + leftSum + rightSum ;
        }
        else
        {
            ans.first = false;
            ans.second=root->data + leftSum + rightSum ;
        }
        return ans;
        
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }




//6. https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	if(root == NULL)
    	    return result;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool leftToRight = true;
    	
    	while(!q.empty()) {
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	    
    	    //Level Process
    	    for(int i=0; i<size; i++) {
    	        
    	        Node* frontNode = q.front();
    	        q.pop();
    	        
    	        //normal insert or reverse insert 
    	        int index = leftToRight ? i : size - i - 1;
    	        ans[index] = frontNode -> data;
    	        
    	        if(frontNode->left)
    	            q.push(frontNode -> left);
    	            
    	        if(frontNode->right)
    	            q.push(frontNode -> right);
    	    }
    	    
    	    //direction change karni h
    	    leftToRight = !leftToRight;
    	   
    	  for(auto i: ans) {
    	      result.push_back(i);
    	  }  
    	}
    	    return result;
    }
};


//7.https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1


class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans) {
        //base case
        if( (root == NULL) || (root->left == NULL && root->right == NULL) )
            return ;
            
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
            
    }
    
    void traverseLeaf(Node* root, vector<int> &ans) {
        //base case
        if(root == NULL)
            return ;
            
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
    }
    
    void traverseRight(Node* root, vector<int> &ans) {
        //base case
        if( (root == NULL) || (root->left == NULL && root->right == NULL) )
            return ;
        
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
            
        //wapas aagye
        ans.push_back(root->data);
            
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL)
            return ans;
            
        ans.push_back(root->data);
        
        //left part print/store
        traverseLeft(root->left, ans);
        
        //traverse Leaf Nodes
        
        //left subtree
        traverseLeaf(root->left, ans);
        //right subtree
        traverseLeaf(root->right, ans);
        
        //traverse right part
        traverseRight(root->right, ans);
        
        return ans;     
    }
};


//8.https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

class Solution
{
public:
    vector<int> verticalOrder(Node *root)
    {
        if (!root)
            return {};

        // Unordered map to store nodes grouped by vertical levels
        unordered_map<int, vector<int>> verticalMap;

        // Variables to track the range of vertical levels
        int minLevel = 0, maxLevel = 0;

        // Queue for BFS: {node, verticalLevel}
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int verticalLevel = front.second;

            // Update min and max vertical levels
            minLevel = min(minLevel, verticalLevel);
            maxLevel = max(maxLevel, verticalLevel);

            // Add node's data to the corresponding vertical level
            verticalMap[verticalLevel].push_back(node->data);

            // Add children to the queue with updated vertical levels
            if (node->left)
                q.push({node->left, verticalLevel - 1});
            if (node->right)
                q.push({node->right, verticalLevel + 1});
        }

        // Collect results in sorted order of vertical levels
        vector<int> result;
        for (int i = minLevel; i <= maxLevel; ++i)
        {
            result.insert(result.end(), verticalMap[i].begin(), verticalMap[i].end());
        }

        return result;
    }
};

//9. Top view of binary tree

https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
public:
    vector<int> topView(Node *root)
    {
        if (!root)
            return {};

        // Horizontal distance range
        int minHD = 0, maxHD = 0;

        // Queue for BFS: {node, horizontal distance}
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // Use an unordered_map to track the first node at each HD
        unordered_map<int, int> topNodeMap;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int hd = front.second;

            // Update minHD and maxHD
            if (topNodeMap.find(hd) == topNodeMap.end())
            {
                topNodeMap[hd] = node->data;
                minHD = min(minHD, hd);
                maxHD = max(maxHD, hd);
            }

            // Add children to the queue with updated horizontal distances
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // Collect results from minHD to maxHD
        vector<int> result;
        for (int hd = minHD; hd <= maxHD; ++hd)
        {
            result.push_back(topNodeMap[hd]);
        }

        return result;
    }
};

// 10. bottom view of binary tree
https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        if (!root)
            return {};

        // Horizontal distance range
        int minHD = 0, maxHD = 0;

        // Queue for BFS: {node, horizontal distance}
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // Use an unordered_map to track the last node at each HD
        unordered_map<int, int> bottomNodeMap;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int hd = front.second;

            // Update the map with the current node
            // This ensures that the last node encountered at this HD is stored
            bottomNodeMap[hd] = node->data;

            // Update minHD and maxHD
            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);

            // Add children to the queue with updated horizontal distances
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        // Collect results from minHD to maxHD
        vector<int> result;
        for (int hd = minHD; hd <= maxHD; ++hd)
        {
            result.push_back(bottomNodeMap[hd]);
        }

        return result;
    }
};


//11. Left view of binary tree
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

class Solution
{
public:
    vector<int> leftView(Node *root)
    {
        if (!root)
            return {};

        // Vector to store the left view
        vector<int> result;

        // Queue for BFS: {node, level}
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // Track the maximum level processed
        int maxLevel = -1;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int level = front.second;

            // If this is the first node of the current level, add it to the result
            if (level > maxLevel)
            {
                result.push_back(node->data);
                maxLevel = level;
            }

            // Add left child first, then right child (to ensure leftmost node is encountered first)
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        return result;
    }
};

//12 . Right view of binary tree
https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1


class Solution
{
public:
    vector<int> rightView(Node *root)
    {
        if (!root)
            return {};

        // Vector to store the right view
        vector<int> result;

        // Queue for BFS: {node, level}
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        // Track the maximum level processed
        int maxLevel = -1;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            Node *node = front.first;
            int level = front.second;

            // If this is the first node of the current level (processed right to left), add it
            if (level > maxLevel)
            {
                result.push_back(node->data);
                maxLevel = level;
            }

            // Add right child first, then left child (to ensure the rightmost node is processed first)
            if (node->right)
                q.push({node->right, level + 1});
            if (node->left)
                q.push({node->left, level + 1});
        }

        return result;
    }
};




// 13. https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
class Solution {
public:
    // Helper function to find the sum of the longest bloodline
    void findLongestPath(Node* root, int currSum, int currLength, int &maxLength, int &maxSum) {
        // If the current node is NULL, return
        if (root == NULL) {
            return;
        }
        
        // Add the current node's value to the sum and increment the length
        currSum += root->data;
        currLength++;

        // If it's a leaf node, check if it's the longest path so far
        if (root->left == NULL && root->right == NULL) {
            if (currLength > maxLength) {
                // If we found a longer path, update maxLength and maxSum
                maxLength = currLength;
                maxSum = currSum;
            } else if (currLength == maxLength) {
                // If the length is the same, take the path with the maximum sum
                maxSum = max(maxSum, currSum);
            }
            return;
        }

        // Recursively explore the left and right subtrees
        if (root->left) {
            findLongestPath(root->left, currSum, currLength, maxLength, maxSum);
        }
        if (root->right) {
            findLongestPath(root->right, currSum, currLength, maxLength, maxSum);
        }
    }

    // Function to find the sum of the longest bloodline
    int sumOfLongRootToLeafPath(Node* root) {
        int maxLength = -1;
        int maxSum = 0;
        findLongestPath(root, 0, 0, maxLength, maxSum);
        return maxSum;
    }
};

// 14. LCA in binary tree
https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //base case
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root->data == n1 || root->data == n2) 
        {
            return root;
        }
        
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);
        
        if(leftAns != NULL && rightAns != NULL) 
        {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL)
            return leftAns;
        else if(leftAns == NULL && rightAns != NULL)
            return rightAns;
        else
            return NULL;
    }
};

//15. K sum path
https://www.geeksforgeeks.org/problems/k-sum-paths/1
class Solution{
  public:
    void solve(Node* root, int k, int &count, vector<int> &path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->data);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};

//16. Kth Ancestor in a tree
https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

Node* solve(Node* root, int &k, int node) {
    //base case
    if(root == NULL)
        return NULL;
        
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);


    //wapas
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    

}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

//17 Max sum of non adjacent nodes
https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1


class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

//18. Construct Tree from Inorder & Preorder 
https://www.geeksforgeeks.org/problems/construct-tree-1/1

class Solution{
   public:
   //
   void createMapping(int in[],map<int,int>&nodeToIndex,int n)
   {
    for(int i=0;i<n;i++)
    {
        nodeToIndex[in[i]]=i;
    }
   }
   int findInorderIndex(int[] inorder, int value, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1; // Should not reach here if inputs are valid
    }
   Node* solve(int in[],int pre[],int index,int inorderStart,int inorderEnd, int n)
   {
    //base case
    if(index>=n ||inorderStart>inorderEnd)
    {
        return NULL;
    }
    int element= pre[index++];
    Node* temp=new Node(element);
    int position =findInorderIndex(in,element);
    temp->left=solve(in,pre,index,inorderStart,position-1,n);
    temp->right=solve(in, pre, index,position+1,inorderEnd,n);
    return temp;
   }


     Node* buildTree(int in[],int pre[],int n)
     {
        int preOrderIndex=0;
       Node* ans= solve(in,pre,preOrderIndex,0,n-1,n);
       return ans;

     }

}

// 19. Construct a BT from PreOrder/PostOrder traversal

https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1


class Solution{
   public:
   //
   void createMapping(int in[],map<int,int>&nodeToIndex,int n)
   {
    for(int i=0;i<n;i++)
    {
        nodeToIndex[in[i]]=i;
    }
   }
   int findInorderIndex(int[] inorder, int value, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1; // Should not reach here if inputs are valid
    }
   Node* solve(int in[],int pre[],int index,int inorderStart,int inorderEnd, int n)
   {
    //base case
    if(index<0 ||inorderStart>inorderEnd)
    {
        return NULL;
    }
    int element= post[index--];
    Node* temp=new Node(element);
    int position= nodeToIndex[element];
   // int position =findInorderIndex(in,element);
    temp->right=solve(in, post, index,position+1,inorderEnd,n);
    temp->left=solve(in, post ,index,inorderStart,position-1,n);

    return temp;
   }


     Node* buildTree(int in[],int post[],int n)
     {
        int postOrderIndex=n-1;
        map<int,int>nodeToIndex;
        createMapping(in, nodeToIndex,n);
       Node* ans= solve(in,post,postOrderIndex,0,n-1,n);
       return ans;

     }

}

// 20. Minimum time to burn the tree
https://www.geeksforgeeks.org/problems/burning-tree/1

Node* createParentMapping(Node* root,int target,map<Node*,Node*>&nodeToParent)
{
    Node* res=NULL;
    queue<Node*>q;
    q.push(root);
    nodeToParent[root]=NULL;
    while(!q.empty())
    {
        Node* front=q.front();
        q.pop ();
        if(front->data==target)
        {
            res=front;
        }
        if(front->left)
        {
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right)
        {
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(Node* root,map<Node*,Node*>&nodeToParent)
{
    map<Node*,bool>visited;
    queue<Node*>q;
    q.push(root);
    visited[root]=true;
    int ans=0;
    while(!q.empty())
    {
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size();i++)
        {
            Node* front=q.front();
            q.pop();
            if(front->left&&!visited[front->left])
            {
                flag=1;
                q.push(front->left);
                visited[front->left]=1;

            }
            if(front->right&& !visited[front->right])
            {
                flag=1;
                q.push(front->right);
                visited[front->right]=1;
            }
            if(nodeToParent[front]&& !visited[nodeToParent[front]])
            {
                flag=1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]]=1;
            }
        }
        if(flag=1)
        {
            ans++;
        }
    }
    return ans;
}
int minTime(Node* root,int target)
{
    map<Node*,Node*>nodeToParent;
    Node* targetNode=createParentMapping(root,target,nodeToParent);
    int ans= burnTree(targetNode,nodeToParent);
    return ans;
}

// Morris Traversal
https://www.geeksforgeeks.org/problems/inorder-traversal/1
Why use Morris Traversal?
Normally, tree traversals like inorder, preorder, etc., use:

Recursion → consumes O(h) stack space (where h is tree height)

Explicit stack → also O(h) extra memory

📌 Morris Traversal avoids both by temporarily modifying the tree using threaded binary tree logic — and then restores it back.

🔄 Basic Idea
For each node:

If it has no left child: Visit the node and go right.

If it has a left child:

Find the rightmost node (inorder predecessor) in its left subtree.

Make the right pointer of that node point back to the current node (threading).

Move to the left child.

On second visit (when thread is encountered), remove the thread and move right.

👨‍💻 Morris Inorder Traversal (Step-by-step):


void morrisInorder(Node* root) {
    Node* current = root;

    while (current != NULL) {
        if (current->left == NULL) {
            // Case 1: No left child — visit and go right
            cout << current->data << " ";
            current = current->right;
        } else {
            // Case 2: Find inorder predecessor
            Node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                // Threading: link predecessor to current
                predecessor->right = current;
                current = current->left;
            } else {
                // Already threaded: remove link and visit
                predecessor->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}


https://www.spoj.com/problems/UCV2013J/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Process input continuously until N = 0, which marks the end
    while (true) {
        int N;
        cin >> N; // Read the number of nodes in the tree

        // If N is 0, end of input, break the loop
        if (N == 0) {
            break;
        }

        // Vector to store the valences of each node
        vector<int> valences(N);

        // Read the valences of the nodes
        for (int i = 0; i < N; ++i) {
            cin >> valences[i]; // Read valence for each node
        }

        // Initialize sum to 0
        int sum = 0;

        // Leaf nodes in a complete binary tree are from index N/2 to N-1 in the array
        // Traverse the array from N/2 to N-1 to sum the valences of leaf nodes
        for (int i = N / 2; i < N; ++i) {
            sum += valences[i]; // Add valence of each leaf node to sum
        }

        // Output the sum of valences of the leaf nodes
        cout << sum << endl;
    }

    return 0; // End of program
}

//https://codeforces.com/contest/913/problem/B

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; // number of vertices (nodes)
    while (cin >> n && n != 0) {
        vector<vector<int>> tree(n + 1); // tree representation using an adjacency list
        // Read the parent-child relationships
        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            tree[parent].push_back(i); // Add child i to parent node
        }

        bool isSpruce = true; // Initially assume it's a spruce tree
        // Check the non-leaf nodes
        for (int i = 1; i <= n; ++i) {
            if (tree[i].size() > 0) { // If node i has children (it's a non-leaf node)
                int leafCount = 0;
                for (int child : tree[i]) {
                    if (tree[child].empty()) { // Check if the child is a leaf
                        leafCount++;
                    }
                }
                if (leafCount < 3) {
                    isSpruce = false; // If any non-leaf node has fewer than 3 leaf children, it's not a spruce
                    break;
                }
            }
        }

        if (isSpruce)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}



https://www.spoj.com/problems/TREEDEGREE/



//
//  main.cpp
//  practice
//
//  Created by Mahmud on 10/13/18.
//  Copyright © 2018 Mahmud. All rights reserved.
//

/*
 A simple O(T * N) solution
 Problem can be solved using dfs or some other techniques as well.
 */

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

const int S = 1 << 18;

int T, N;
int order[S];
int was[S], neighbors[S];

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T --) {
        cin >> N;
        for (int i = 1; i <= N + N; i ++) {
            cin >> order[i];
        }
        for (int i = 1; i <= N; i ++) {
            neighbors[i] = 0;
            was[i] = 0;
        }
        stack<int> open;
        for (int i = 1; i <= N + N; i ++) {
            if (!was[order[i]]) {
                if (!open.empty()) {
                    neighbors[open.top()] ++;
                    neighbors[order[i]] ++;
                }
                was[order[i]] = 1;
                open.push(order[i]);
            } else {
                open.pop();
            }
        }
        cout << *max_element(neighbors, neighbors + N + 1) << endl;
    }

    return 0;
}




// https://www.spoj.com/problems/GCPC11J/

#include <bits/stdc++.h>
using namespace std;

// BFS from src, fills dist[], and returns the node farthest from src.
int bfs(int src, const vector<vector<int>>& adj, vector<int>& dist) {
    int N = adj.size();
    dist.assign(N, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    int far = src;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[far])
                    far = v;
            }
        }
    }
    return far;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;                     // number of computers (nodes)
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;            // edge between a and b
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist;
    // 1) BFS from node 0 to find one end of the diameter
    int u = bfs(0, adj, dist);
    // 2) BFS from u to find the true diameter D = dist[v]
    int v = bfs(u, adj, dist);
    int D = dist[v];

    // 3) Radius = ceil(D/2) = (D+1)/2
    int radius = (D + 1) / 2;
    cout << radius << "\n";

    return 0;
}


