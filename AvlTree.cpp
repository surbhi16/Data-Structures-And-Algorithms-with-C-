#include <iostream>
#include "AvlTree.h"

using namespace std;

AvlTree::AvlTree()
    : BinarySearchTree()
{
}

AvlTree::~AvlTree()
{
}

int AvlTree::height(const BinaryNode *ptr) const
{
    return ptr == nullptr ? -1 : ptr->height;
}

void AvlTree::insert(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    rebalance(ptr);
}

void AvlTree::remove(const long data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    rebalance(ptr);
}

BinaryNode *AvlTree::rebalance(BinaryNode* &ptr)
{
if (ptr == nullptr) return ptr;

    // Left side too high.
    if (height(ptr->left) - height(ptr->right) > 1)
    {
        if (height(ptr->left->left)
                >= height(ptr->left->right))
        {
            ptr = singleRightRotation(ptr);
            cout << "    --- Single right rotation at node "
                 << ptr->data << endl;
        }
        else
        {
            ptr = doubleLeftRightRotation(ptr);
            cout << "    --- Double left-right rotation at node "
                 << ptr->data << endl;
        }
    }

    // Right side too high.
    else if (height(ptr->right) - height(ptr->left) > 1)
    {
        if (height(ptr->right->right)
                >= height(ptr->right->left))
        {
            ptr = singleLeftRotation(ptr);
            cout << "    --- Single left rotation at node "
                 << ptr->data << endl;
        }
        else
        {
            ptr = doubleRightLeftRotation(ptr);
            cout << "    --- Double right-left rotation at node "
                 << ptr->data << endl;
        }
    }

    // Recompute the node's height.
    ptr->height = (max(height(ptr->left),
                        height(ptr->right)) + 1);

    if (checkBalance(ptr) < 0)
    {
        cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
 BinaryNode* node;
	if(k2 == nullptr) {
		cout<<"Error in node"<<endl;
	}else if(k2->left == nullptr){
		cout<<"Cannot rotate right"<<endl;
	} else {
		node = k2->left;
		k2->left = node->right;
		node->right = k2;
		k2->height-=1;
		k2=node;
		return k2;
	}
}

BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
  
	BinaryNode* lnode = k3->left;
	BinaryNode* rnode = lnode->right;

	k3->left = lnode->right;
	lnode->right = rnode->left;
	lnode->height-=1;
	rnode->left = lnode;

	k3->left = rnode->right;
	rnode->right = k3;
	rnode->height -=1;
	k3 = rnode;
	return k3;

}

BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
    BinaryNode* rnode = k1->right;
	BinaryNode* lnode = rnode->left;

	k1->right = rnode->left;
	rnode->left = lnode ->right;
	rnode->height-=1;
	lnode->right = rnode;

	k1->right = lnode->left;
	lnode->left = k1;
	lnode->height-=1;
	k1=lnode;
	return k1;
}

BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
    BinaryNode* node;
	if (k1 == nullptr) {
		cout << "Error in node" << endl;
	} else if (k1->right == nullptr) {
		cout << "Cannot rotate left" << endl;
	} else {
		node = k1->right;
		k1->right = node->left;
		node->left = k1;
		k1->height-=1;
		k1 = node;
		return k1;
	}
}

int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->left);
    int rightHeight = checkBalance(ptr->right);

    if ((abs(height(ptr->left) - height(ptr->right)) > 1)
        || (height(ptr->left)  != leftHeight)
        || (height(ptr->right) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
