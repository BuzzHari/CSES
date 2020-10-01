/*
 *  Implmented a BST for this, it times out tho, maybe for cases which makes the 
 *  tree skewed. A self-balancing tree will be a good solution. 
 *  
 *  Can be done also with C++ std::set
 */
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <set>
#include <climits>

// Defines for some data types. 
#define ui unsigned int
#define uli unsigned long int
#define ulli unsigned long long int
#define li long int
#define lli long long int

// Define for some utility function. 
#define MAX(a,b) a > b ? a : b
#define MIN(a,b) a < b ? a : b

using namespace std;

/*
 *int main() {
 *    
 *    set<int> numbers;
 *    int n;
 *    cin >> n;
 *    int temp;
 *    for (int i = 0; i < n; i++) {
 *        cin >> temp;
 *        numbers.insert(temp);
 *    }
 *
 *    printf("%d\n", numbers.size());
 *
 *    return 0;
 *}
 */

// Implmenting a BST for this. 

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
}Node;

typedef struct BinSTree {
    int nodes;
    struct Node *root;
}BinSTree;


Node* ins(Node *root,  Node *newNode, int& dup) {

    if (!root) {
        return newNode;
    }

    if (newNode->value == root->value)
        dup = 1;
    else if (newNode->value > root->value) 
        root->right = ins(root->right, newNode, dup);
    else 
        root->left = ins(root->left, newNode, dup);
    
    return root;
}

void insert(BinSTree& tree, int value) {
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    int dup = 0; // To check if key already exists in the tree.

    if (tree.root == NULL) 
        tree.root = newNode;
    else
       ins(tree.root, newNode, dup);
    
    if (dup != 1)
        tree.nodes+=1;
}


int main() {
    
    BinSTree myset;
    myset.nodes = 0;
    myset.root = NULL;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        insert(myset, num);
    }
    printf("%d\n", myset.nodes);
}


