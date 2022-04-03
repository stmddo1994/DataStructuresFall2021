//File: BSTree_Final.h
//Project: CSIS 3400 Assignment 10
//Author: Mathew Doty
//Version: 2.2 Nov 11, 2021

#include <iostream>
#include "QueArrT.h"
using namespace std;
enum OrderType { Pre_Order, Post_Order, In_Order };
template<class ItemType>
class TreeNode
{
public:
    ItemType data;
    TreeNode* left;
    TreeNode* right;
};
template<class ItemType>
class BSTree
{
public:
    BSTree(); //No arg constructor
    ~BSTree(); // Destructor
    BSTree(const BSTree& origTree); //Copy Constructor
    void operator = (const BSTree& origTree); // Assignment Operator
    void makeEmpty();
    inline bool isEmpty() const;
    bool isFull() const;
    void addItemIter(ItemType item);
    void deleteItemIter(ItemType item);
    //Recursive Functions
    void printTree();
    void addItem(ItemType item);
    void deleteItem(ItemType item);
    ItemType getItem(ItemType item, bool& found);
    void resetTree(OrderType order);
    ItemType getNextItem(OrderType order, bool& finished);
    //Assgn 10 functions
    ItemType calcMinMathew();
    ItemType calcMaxMathew();
    bool findNodeMathew(TreeNode<ItemType>* tree, ItemType item, TreeNode<ItemType>*& nodePtr, TreeNode<ItemType>*& parentPtr);
    void findNodeMathewMain(ItemType item);
    int countNodesMathew(TreeNode<ItemType>* tree);
    void countNodesMathewMain();
    void deleteAllNodesMathew(TreeNode<ItemType>* tree);
    void deleteAllNodesMathewMain();
    int computeOneChildNodesMathew(TreeNode<ItemType>* tree);
    void computeOneChildNodesMathewMain();
private:
    TreeNode<ItemType>* root;
    QueArrT<ItemType> preQue;
    QueArrT<ItemType> postQue;
    QueArrT<ItemType> inQue;
    void destroy(TreeNode<ItemType>*& tree);
    void copyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* origTree);
    void printNode(TreeNode<ItemType>*& tree);
    void insert(TreeNode<ItemType>*& tree, ItemType& item);
    void retrieve(TreeNode<ItemType>*& tree, ItemType& item, bool& found);
    void deleteNode(TreeNode<ItemType>*& tree);
    void del(TreeNode<ItemType>*& tree, ItemType& item);
    void getPredecessor(TreeNode<ItemType>* tree, ItemType& item);
    void findNode(TreeNode<ItemType>* tree, ItemType item,
        TreeNode<ItemType>*& nodePtr, TreeNode<ItemType>*& parentPtr);
    void preOrder(TreeNode<ItemType>* tree, QueArrT<ItemType>& q);
    void postOrder(TreeNode<ItemType>* tree, QueArrT<ItemType>& q);
    void inOrder(TreeNode<ItemType>* tree, QueArrT<ItemType>& q);
};
template <class ItemType>
BSTree<ItemType>::BSTree()
{
    root = NULL;
}
template <class ItemType>
BSTree<ItemType>::~BSTree()
{
    destroy(root);
}
template <class ItemType>
void BSTree<ItemType>::destroy(TreeNode<ItemType>*& tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}
template <class ItemType>
BSTree<ItemType>::BSTree(const BSTree& origTree)
{
    copyTree(root, origTree.root);
}
template<class ItemType>
void BSTree<ItemType>::operator=(const BSTree& origTree)
{
    if (&origTree == this)
        return;
    destroy(root);
    copyTree(root, origTree.root);
}
template<class ItemType>
void BSTree<ItemType>::makeEmpty()
{
    destroy(root);
    root = NULL;
}
template<class ItemType>
inline bool BSTree<ItemType>::isEmpty() const
{
    return root == NULL;
}
template<class ItemType>
bool BSTree<ItemType>::isFull() const
{
    TreeNode<ItemType>* location;
    try
    {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}
template<class ItemType>
inline void BSTree<ItemType>::addItemIter(ItemType item)
{
    TreeNode<ItemType>* newNode;
    TreeNode<ItemType>* nodePtr;
    TreeNode<ItemType>* parentPtr;
    newNode = new TreeNode<ItemType>;
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    findNode(root, item, nodePtr, parentPtr);
    if (parentPtr == NULL)
        root = newNode;
    else if (item < parentPtr->data)
        parentPtr->left = newNode;
    else
        parentPtr->right = newNode;
}
template<class ItemType>
inline void BSTree<ItemType>::deleteItemIter(ItemType item)
{
    TreeNode<ItemType>* nodePtr;
    TreeNode<ItemType>* parentPtr;
    findNode(root, item, nodePtr, parentPtr);
    if (nodePtr == root)
        deleteNode(root);
    else
    {
        if (parentPtr->left == nodePtr)
            deleteNode(parentPtr->left);
        else
            deleteNode(parentPtr->right);
    }
}
template<class ItemType>
inline void BSTree<ItemType>::printTree()
{
    printNode(root);
    cout << endl;
}
template<class ItemType>
inline void BSTree<ItemType>::addItem(ItemType item)
{
    insert(root, item);
}
template<class ItemType>
inline void BSTree<ItemType>::deleteItem(ItemType item)
{
    del(root, item);
}
template<class ItemType>
inline ItemType BSTree<ItemType>::getItem(ItemType item, bool& found)
{
    retrieve(root, item, found);
    return item;
}
template<class ItemType>
inline void BSTree<ItemType>::resetTree(OrderType order)
{
    switch (order)
    {
    case Pre_Order: preOrder(root, preQue);
        break;
    case Post_Order: postOrder(root, postQue);
        break;
    case In_Order: inOrder(root, inQue);
        break;
    }
}
template<class ItemType>
inline ItemType BSTree<ItemType>::getNextItem(OrderType order, bool& finished)
{
    ItemType item;
    finished = false;
    switch (order)
    {
    case Pre_Order: preQue.deque(item);
        if (preQue.isEmpty())
            finished = true;
        break;
    case Post_Order: postQue.deque(item);
        if (postQue.isEmpty())
            finished = true;
        break;
    case In_Order: inQue.deque(item);
        if (inQue.isEmpty())
            finished = true;
        break;
    }
    return item;
}
//New public classes
template<class ItemType>
inline ItemType BSTree<ItemType>::calcMinMathew()
{
    TreeNode<ItemType>* min = root;
    while (min->left != NULL)
        min = min->left;
    return min->data;
}
template<class ItemType>
inline ItemType BSTree<ItemType>::calcMaxMathew()
{
    TreeNode<ItemType>* max = root;
    while (max->right != NULL)
        max = max->right;
    return max->data;
}
template<class ItemType>
inline bool BSTree<ItemType>::findNodeMathew(TreeNode<ItemType>* tree, ItemType item, TreeNode<ItemType>*& nodePtr, TreeNode<ItemType>*& parentPtr)
{
    nodePtr = tree;
    parentPtr = NULL;
    bool found = false;
    while (nodePtr != NULL && !found)
    {
        if (item < nodePtr->data)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->left;
        }
        else if (item > nodePtr->data)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->right;
        }
        else
        {
            found = true;
        }
    }
    return found;
}
template<class ItemType>
inline void BSTree<ItemType>::findNodeMathewMain(ItemType item)
{
    TreeNode<ItemType>* nodePtr;
    TreeNode<ItemType>* parentPtr;
    if (findNodeMathew(root, item, nodePtr, parentPtr) == false)
        cout << item << " is not found in the BST." << endl;
    else
        cout << item << " is in the BST." << endl;
}
template<class ItemType>
inline int BSTree<ItemType>::countNodesMathew(TreeNode<ItemType>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return 1 + countNodesMathew(tree->left) + countNodesMathew(tree->right);
}
template<class ItemType>
inline void BSTree<ItemType>::countNodesMathewMain()
{
    cout << countNodesMathew(root) << endl;
}

template<class ItemType>
inline void BSTree<ItemType>::deleteAllNodesMathew(TreeNode<ItemType>* tree)
{
    if (tree == NULL)
        return;
    
    deleteAllNodesMathew(tree->left);
    deleteAllNodesMathew(tree->right);
    delete tree;
}

template<class ItemType>
inline void BSTree<ItemType>::deleteAllNodesMathewMain()
{
    deleteAllNodesMathew(root);
    root = NULL;
}

template<class ItemType>
inline int BSTree<ItemType>::computeOneChildNodesMathew(TreeNode<ItemType>* tree)
{
    if (tree == NULL)
        return 0;
    else if ((tree->left != NULL && tree->right == NULL) || (tree->left == NULL && tree->right != NULL))
        return 1 + computeOneChildNodesMathew(tree->left) + computeOneChildNodesMathew(tree->right);
    else
        return computeOneChildNodesMathew(tree->left) + computeOneChildNodesMathew(tree->right);
}

template<class ItemType>
inline void BSTree<ItemType>::computeOneChildNodesMathewMain()
{
    cout << computeOneChildNodesMathew(root) << endl;
}

//Private classes
template<class ItemType>
void BSTree<ItemType>::copyTree(TreeNode<ItemType>*& copy, const
    TreeNode<ItemType>* origTree)
{
    if (origTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode<ItemType>;
        copy->data = origTree->data;
        copyTree(copy->left, origTree->left);
        copyTree(copy->right, origTree->right);
    }
}
template<class ItemType>
inline void BSTree<ItemType>::printNode(TreeNode<ItemType>*& tree)
{
    if (tree == root)
        cout << "Root's data " << root->data << endl;
    if (tree != NULL)
    {
        printNode(tree->left);
        cout << tree->data << " ";
        printNode(tree->right);
    }
}
template<class ItemType>
inline void BSTree<ItemType>::insert(TreeNode<ItemType>*& tree, ItemType& item)
{
    if (tree == NULL)
    {
        tree = new TreeNode<ItemType>;
        tree->data = item;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (item <= tree->data)
        insert(tree->left, item);
    else
        insert(tree->right, item);
}
template<class ItemType>
inline void BSTree<ItemType>::retrieve(TreeNode<ItemType>*& tree, ItemType& item,
    bool& found)
{
    if (tree == NULL)
        found = false;
    else if (item < tree->data)
        retrieve(tree->left, item, found);
    else if (item > tree->data)
        retrieve(tree->right, item, found);
    else
    {
        item = tree->data;
        found = true;
    }
}
template<class ItemType>
inline void BSTree<ItemType>::deleteNode(TreeNode<ItemType>*& tree)
{
    ItemType item;
    TreeNode<ItemType>* tmpPtr;
    tmpPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tmpPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tmpPtr;
    }
    else
    {
        getPredecessor(tree->left, item);
        tree->data = item;
        del(tree->left, item);
    }
}
template<class ItemType>
inline void BSTree<ItemType>::del(TreeNode<ItemType>*& tree, ItemType& item)
{
    if (item < tree->data)
        del(tree->left, item);
    else if (item > tree->data)
        del(tree->right, item);
    else
        deleteNode(tree);
}
template<class ItemType>
inline void BSTree<ItemType>::getPredecessor(TreeNode<ItemType>* tree, ItemType&
    item)
{
    while (tree->right != NULL)
        tree = tree->right;
    item = tree->data;
}
template<class ItemType>
inline void BSTree<ItemType>::findNode(TreeNode<ItemType>* tree, ItemType item,
    TreeNode<ItemType>*& nodePtr, TreeNode<ItemType>*&
    parentPtr)
{
    nodePtr = tree;
    parentPtr = NULL;
    bool found = false;
    while (nodePtr != NULL && !found)
    {
        if (item < nodePtr->data)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->left;
        }
        else if (item > nodePtr->data)
        {
            parentPtr = nodePtr;
            nodePtr = nodePtr->right;
        }
        else
        {
            found = true;
        }
    }
}
template<class ItemType>
inline void BSTree<ItemType>::preOrder(TreeNode<ItemType>* tree, QueArrT<ItemType>&
    preQue)
{
    if (tree != NULL)
    {
        preQue.enque(tree->data);
        preOrder(tree->left, preQue);
        preOrder(tree->right, preQue);
    }
}
template<class ItemType>
inline void BSTree<ItemType>::postOrder(TreeNode<ItemType>* tree,
    QueArrT<ItemType>& postQue)
{
    if (tree != NULL)
    {
        postOrder(tree->left, postQue);
        postOrder(tree->right, postQue);
        postQue.enque(tree->data);
    }
}
template<class ItemType>
inline void BSTree<ItemType>::inOrder(TreeNode<ItemType>* tree, QueArrT<ItemType>&
    inQue)
{
    if (tree != NULL)
    {
        inOrder(tree->left, inQue);
        inQue.enque(tree->data);
        inOrder(tree->right, inQue);
    }
}

