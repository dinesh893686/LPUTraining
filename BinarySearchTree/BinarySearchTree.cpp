
//Binary_search_tree_implentations
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* FrontNode = Q.front();
        Q.pop();

        if(FrontNode == NULL) {
            cout << endl;
            
            if(!Q.empty()) {
                Q.push(NULL);
            }
        } else {
            cout << FrontNode->data << " ";

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            }

            if(FrontNode->right) {
                Q.push(FrontNode->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Level Order Traversal : ";
    levelOrderTraversal(root);

    return 0;
}

//BST traversals
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void preOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

void inOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

void postOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "InOrder Traversal : ";
    inOrderRecursive(root);

    cout << endl << "PreOrder Traversal : ";
    preOrderRecursive(root);

    cout << endl << "PostOrder Traversal : ";
    postOrderRecursive(root);

    return 0;
}

// Search in a bst
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

bool SearchBST(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key > root->data) {
        return SearchBST(root->right, key);
    } else {
        return SearchBST(root->left, key);
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    int key;
    cout << "Enter the key to search : ";
    cin >> key;

    bool found = SearchBST(root, key);
    
    if(found) {
        cout << "Key present in BST!" << endl;
    } else {
        cout << "Key absent in BST!" << endl;
    }

    return 0;
}

// Min max of bst
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int minVal(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node* root) {
    if(root == NULL) {
        return -1;
    }
    
    Node* temp = root;
    while(temp->right) {
        temp = temp->right;
    }

    return temp->data;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Minimum Value : " << minVal(root);
    cout << endl << "Maximum Value : " << maxVal(root);

    return 0;
}

// Deletion in  bst
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* FrontNode = Q.front();
        Q.pop();

        if(FrontNode == NULL) {
            cout << endl;
            
            if(!Q.empty()) {
                Q.push(NULL);
            }
        } else {
            cout << FrontNode->data << " ";

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            }

            if(FrontNode->right) {
                Q.push(FrontNode->right);
            }
        }
    }
}

int minVal(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }

    return temp->data;
}

Node* DeletionInBST(Node* root, int data) {
    if(root == NULL) {
        return root;
    }

    if(root->data == data) {
        
        // 0 Child
        if(root->left==NULL && root->right==NULL) {
            delete root;
            return NULL;
        }

        // 1 Child
        // Left Child
        if(root->left!=NULL && root->right==NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        if(root->left==NULL && root->right!=NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 Child
        if(root->left!=NULL && root->right!=NULL) {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = DeletionInBST(root->right, mini);
            return root;
        }

    } else if(data > root->data) {
        root->right = DeletionInBST(root->right, data);
        return root;
    } else {
        root->left = DeletionInBST(root->left, data);
        return root;
    }
}

int main() {
    Node* root = NULL;
    int key;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the key to delete : ";
    cin >> key;

    cout << endl << "Before Deletion : " << endl;
    levelOrderTraversal(root);
    
    root = DeletionInBST(root, key);

    cout << endl << "After Deletion : " << endl;
    levelOrderTraversal(root);

    return 0;
}


// 1. Validate BST
https://www.naukri.com/code360/problems/validate-bst_799483?leftPanelTab=0

bool ValidateBST(Node* root, int min, int max) {
    if(root == NULL) {
        return true;
    }

    if(root->data >= min && root->data <= max) {
        bool left = ValidateBST(root->left, min, root->data);
        bool right = ValidateBST(root->right, root->data, max);

        return (left && right);
    }

    return false;
}

//2. Find kth smallest element in bst
https://www.naukri.com/code360/problems/find-k-th-smallest-element-in-bst_1069333?leftPanelTab=0

int kthSmallest(Node* root, int &index, int K) {
    if(root == NULL) {
        return -1;
    }

    int left = kthSmallest(root->left, index, K);

    if(left != -1) {
        return left;
    }

    index++;
    if(index == K) {
        return root->data;
    }

    return kthSmallest(root->right, index, K);
}

//3.https://www.naukri.com/code360/problems/_893049

/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode* KeyNode = root;
    int pred = -1;
    int succ = -1;
    
    while(KeyNode->data != key) {
        if(KeyNode->data > key) {
            succ = KeyNode->data;
            KeyNode = KeyNode->left;
        } else {
            pred = KeyNode->data;
            KeyNode = KeyNode->right;
        }
    }

    // Prdecessor
    TreeNode* leftTree = KeyNode->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Successor
    TreeNode* rightTree = KeyNode->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
    
}

//4.LCA in BST
https://www.naukri.com/code360/problems/lca-in-a-bst_981280?leftPanelTab=0
// Recursive Way
Node* LCAinBST(Node* root, Node* P, Node* Q) {
    if(root == NULL) {
        return NULL;
    }

    if(root->data < P->data && root->data < Q->data) {
        return LCAinBST(root->right, P, Q);
    }

    if(root->data > P->data && root->data > Q->data) {
        return LCAinBST(root->left, P, Q);
    }

    return root;
}

// Iterative Way
Node* LCAinBST(Node* root, Node* P, Node* Q) {
    while(root != NULL) {
        if(root->data < P->data && root->data < Q->data) {
            root = root->right;
        } else if (root->data > P->data && root->data > Q->data) {
            root = root->left;
        } else {
            return root;
        }
    }
}

// Two sum in bst
https://www.naukri.com/code360/problems/two-sum-in-a-bst_1062631?leftPanelTab=0

void inOrder(Node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool checkTwoSum(Node* root, int target) {
    if(root == NULL) {
        return false;
    }

    vector<int> arr;
    inOrder(root, arr);

    int i=0, j=arr.size()-1;
    while(i <= j) {
        if(arr[i] + arr[j] == target) {
            return true;
        }

        if(arr[i] + arr[j] > target) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

//  Flatten bst to sorted list
https://www.naukri.com/code360/problems/flatten-bst-to-a-sorted-list_1169459?leftPanelTab=0


void inOrder(Node* root, vector<Node*>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root);
    inOrder(root->right, ans);
}


void flattenBST(Node* &root) {
    if(root == NULL) {
        return;
    }

    vector<Node*> arr;
    inOrder(root, arr);

    for(int i=0; i<arr.size()-1; i++) {
        arr[i]->left = NULL;
        arr[i]->right = arr[i+1];
    }

    arr[arr.size()-1]->left = NULL;
    arr[arr.size()-1]->right = NULL;

    root = arr[0];
}

// Normal BST To Balanced BST
https://www.naukri.com/code360/problems/normal-bst-to-balanced-bst_920472?leftPanelTab=0
void inOrder(Node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

Node* balanceBST(vector<int>& arr, int start, int end) {
    if(end-start < 0) {
        return NULL;
    }

    int mid = start + (end-start)/2;
    Node* temp = new Node(arr[mid]);

    temp->left = balanceBST(arr, start, mid-1);
    temp->right = balanceBST(arr, mid+1, end);

    return temp;
}

Node* NormalToBalance(Node* &root) {
    if(root == NULL) {
        return NULL;
    }

    vector<int> arr;
    inOrder(root, arr);

    Node* newBST = balanceBST(arr, 0, arr.size()-1);

    return newBST;
}
// BST from preorder 

Node* createPreorder(vector<int> &inorder, int &index, int min, int max) {
    if(index >= inorder.size()) {
        return NULL;
    }

    int data = inorder[index];

    if(data < min || data > max) {
        return NULL;
    }

    Node* temp = new Node(data);
    index++;

    temp->left = createPreorder(inorder, index, min, data);
    temp->right = createPreorder(inorder, index, data, max);

    return temp;
}

// Merge two BSTs
https://www.naukri.com/code360/problems/h_920474

//1_Merge2BST_Inorder.cpp
#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

void inOrder(Node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() == 0 || arr2.size() == 0) {
        return (arr1.size()) ? arr1 : arr2;
    }

    int i=0, j=0;
    vector<int> solution;

    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] < arr2[j]) {
            solution.push_back(arr1[i++]);
        } else {
            solution.push_back(arr2[j++]);
        }
    }
    
    while(i<arr1.size()) {
        solution.push_back(arr1[i++]);
    }
    
    while(j<arr2.size()) {
        solution.push_back(arr2[j++]);
    }

    return solution;
}

Node* createBST(vector<int> &arr, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end-start)/2;
    Node* temp = new Node(arr[mid]);

    temp->left = createBST(arr, start, mid-1);
    temp->right = createBST(arr, mid+1, end);

    return temp;
}

Node* MergeBST(Node* root1, Node* root2) {
    vector<int> arr1;
    vector<int> arr2;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> resultArray = mergeArrays(arr1, arr2);
    Node* answer = createBST(resultArray, 0, resultArray.size()-1);

    cout << endl << "Level Order Traversal of merged BST (infunc) : " << endl;
    levelOrderTraversal(answer);
    return answer;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    int target;

    cout << "Enter data to create BST 1 : ";
    takeinput(root1);
    
    cout << "Enter data to create BST 2 : ";
    takeinput(root2);

    cout << endl << "Level Order Traversal of BST 1 : " << endl;
    levelOrderTraversal(root1);
    
    cout << endl << "Level Order Traversal of BST 2 : " << endl;
    levelOrderTraversal(root2);
    
    Node* result = MergeBST(root1, root2);

    cout << endl << "Level Order Traversal of merged BST : " << endl;
    levelOrderTraversal(result);
    
    return 0;
}

//2_Merge2BST_LinkedList.cpp
//#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

void flattenBST(Node* root, Node* &head) {
    if(root == NULL) {
        return;
    }

    flattenBST(root->right, head);
    root->right = head;
    
    if(head != NULL) {
        head->left = root;
    }

    head = root;
    flattenBST(root->left, head);
}

Node* mergeLinkedhead(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "\nBEFORE FIRST WHILE\n";
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    cout << "\nAFTER FIRST WHILE\n";
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* LL_2_BST(Node* head, int n) {
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    int temp = n/2;
    Node* root = head;
    while(temp--) {
        root = root->right;
    }

    root->left = LL_2_BST(head, n/2);
    root->right = LL_2_BST(root->right, n-n/2-1);
    return root;

    // Node* left = LL_2_BST(head, n/2);

    // Node* root = head;
    // root->left = left;
    // head = head->right;
    // root->right = LL_2_BST(head, n-n/2-1);

    // return root;
}

Node* MergeBST(Node* root1, Node* root2) {
    // Step 1 : Convert BST into DLL
    Node* head1 = NULL;
    Node* head2 = NULL;

    flattenBST(root1, head1);
    flattenBST(root2, head2);

    head1->left = NULL;
    head2->left = NULL;

    // Merge Sorted Linked List
    Node* list = mergeLinkedhead(head1, head2);

    // Convert List into BST
    Node* result = LL_2_BST(list, countNodes(list));

    return result;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    int target;

    cout << "Enter data to create BST 1 : ";
    takeinput(root1);
    
    cout << "Enter data to create BST 2 : ";
    takeinput(root2);

    cout << endl << "Level Order Traversal of BST 1 : " << endl;
    levelOrderTraversal(root1);
    
    cout << endl << "Level Order Traversal of BST 2 : " << endl;
    levelOrderTraversal(root2);
    
    Node* result = MergeBST(root1, root2);

    cout << endl << "Level Order Traversal of merged BST : " << endl;
    levelOrderTraversal(result);
    
    return 0;
}

//Largest BST
https://www.geeksforgeeks.org/problems/largest-bst/1

#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

class Info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;

        Info() {
            this->maxi = INT_MIN;
            this->mini = INT_MAX;
            this->isBST = true;
            this->size = 0;
        }

        Info(int min, int max, bool isBST, int size) {
            this->maxi = max;
            this->mini = min;
            this->isBST = isBST;
            this->size = size;
        }
};

Info* MaxBST(Node* root, int &answer) {
    if(root == NULL) {
        Info* temp = new Info();
        return temp;
    }

    Info* left = MaxBST(root->left, answer);
    Info* right = MaxBST(root->right, answer);

    Info* currNode = new Info();

    currNode->size = left->size + right->size + 1;
    currNode->maxi = max(root->data, right->maxi);
    currNode->mini = min(root->data, left->mini);

    if(left->isBST && right->isBST && (root->data > left->maxi) && (root->data < right->mini)) {
        currNode->isBST = true;
    } else {
        currNode->isBST = false;
    }

    if(currNode->isBST) {
        answer = max(answer, currNode->size);
    }

    return currNode;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create a tree : ";
    root = buildBinaryTree(root);
    
    int answer = INT_MIN;
    Info* solve = MaxBST(root, answer);

    cout << endl << "Max BST : " << answer;
    
    return 0;
}





