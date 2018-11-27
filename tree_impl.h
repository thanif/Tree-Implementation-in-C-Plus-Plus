#ifndef TREE_IMPL_H
#define TREE_IMPL_H

#include "tree.h"
// Constructor
template<typename T>
Tree<T>::Tree()
{
	size = 0;
        root = NULL;
        cursor = root;
}
// Destructor
template<typename T>
Tree<T>::~Tree()
{
	delete root;
	delete cursor;
}

// Return pointer to root node
template<typename T>
TreeNode<T>* Tree<T>::Root()
{
	return root;
}
// Return true if the tree is empty, false otherwise
template<typename T>
bool Tree<T>::IsEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	
	return false;
}
// Return the size of the tree
template<typename T>
int Tree<T>::Size()
{
	return size;	
}
// Preorder traversal of entire tree
template<typename T>
void Tree<T>::PreOrder()
{
	PreOrder(root,0);
}
// Postorder traversal of entire tree
template<typename T>
void Tree<T>::PostOrder()
{
	PostOrder(root,0);	
}
// Preorder traversal of sub tree rooted at n
template<typename T>
void Tree<T>::PreOrder(TreeNode<T>* p, int depth)
{

   
		
   if (p == NULL) 
        return; 
  
   
   for (int i=0;i<depth;i++)
   {
   	cout <<" ";
   }
   cout<< p->GetValue()<<endl; 
   
   PreOrder(p->GetFirstChild(),depth+1);  
  

  
   
   PreOrder(p->GetNextSibling(),depth); 		
}
// Postorder traversal of sub tree rooted at n
template<typename T>
void Tree<T>::PostOrder(TreeNode<T>* p, int depth)
{

  

   if (p == NULL) 
       return; 
  
   
   
   PostOrder(p->GetFirstChild(),depth+1); 
  
    
   
   PostOrder(p->GetNextSibling(),depth); 
  
  
   
   for (int i=0;i<depth;i++)
   {
   	cout <<" ";
   } 
   cout<< p->GetValue() << endl; 
   
}
// Search and return pointer to the first node storing element with value matching val in the entire tree 
template<typename T>
TreeNode<T>* Tree<T>::Search(T val)
{
	SearchBelow(root, val);
}
// Search and return pointer to node storing element with value matching val in the subtree rooted at n
template<typename T>
TreeNode<T>* Tree<T>::SearchBelow(TreeNode<T>* n, T val)
{
   
		
   if (n == NULL) 
        return NULL; 
  
   
   if (n->GetValue() == val)
   {
   	return n;
   } 
  
   
   SearchBelow(n->GetFirstChild(),val);  
  
   
   
   SearchBelow(n->GetNextSibling(),val); 		
}
template<typename T>
TreeNode<T>* Tree<T>::SearchChildren(TreeNode<T>*n, T val)
{
	if (n->GetFirstChild()->GetValue() == val)
	{
		return n->GetFirstChild();
	}
	
	else
	{
		TreeNode<T>* c = n->GetFirstChild();
		
		while (c != NULL)
		{
			if (c->GetValue() == val)
			{
				return c;
			}
			
			c = c->GetNextSibling();
			
		}
		
		return NULL;
		
	}		
}

template<typename T>
TreeNode<T>* Tree<T>::SearchChildren(T val)
{
	if (cursor->firstChild->val == val)
	{
		return cursor->firstChild;
	}
	
	else
	{
		TreeNode<T>* c = cursor->nextSibling;
		
		while (c != NULL)
		{
			if (c->val == val)
			{
				return c;
			}
			
			c = c->nextSibling;
			
		}
		
		return NULL;
		
	}
}

// Insert a child node with element value val below the node parent
template<typename T>
TreeNode<T>* Tree<T>::InsertChild(TreeNode<T>* parent, T val)
{
	parent->AddChild(val);
	
	return parent->GetFirstChild();
}
// Delete the child (and the subtree rooted at it) storing element with value matching val below the node n
template<typename T>
void Tree<T>::Delete(TreeNode<T>* n, T val)
{
	Deallocate(n);
}
// De-allocate all nodes in the tree
template<typename T>
void Tree<T>::Destroy()
{
	Deallocate(root);
}
// insert a root node, if one does not already exist
template<typename T>
void Tree<T>::InsertRootNode(T val)
{
	if (root == NULL)
	{
		root = new TreeNode<T>(val);
	}
}

template<typename T>
TreeNode<T>* Tree<T>::InsertChild(T val)
{
	cursor->AddChild(val);
	
	
	return cursor->GetFirstChild();	
}

template<typename T>
void Tree<T>::Deallocate(TreeNode<T>* p)
{
   
		
   if (p == NULL) 
        return; 
  
   
   free (p); 
  
   
   
   Deallocate(p->GetFirstChild());  
  
   
   
   Deallocate(p->GetNextSibling()); 		  
}
// Move to the first child of the node pointed to by cursor. Update cursor or return false if this operation isn't possible.
template<typename T>
bool Tree<T>::MoveDown()
{
	if (cursor->firstChild == NULL)
	{
		return false;
	}
	
	cursor = cursor->firstChild;
	
	return true;
}
// Move to the next sibling. Update cursor or return false if this operation isn't possible
template<typename T>
bool Tree<T>::MoveRight()
{
	if (cursor->GetNextSibling() == NULL)
	{
		return false;
	}
	
	cursor = cursor->GetNextSibling();
	
	return true;		
}

// Move to the parent of the node pointed to by cursor. Update cursor or return false if this operation isn't possible.
template<typename T>
bool Tree<T>::MoveUp()
{
	if (cursor->parent == NULL)
	{
		return false;
	}
	
	cursor = cursor->parent;
	
	return true;		
}
// Move to the previous sibling. Update cursor or return false if this operation isn't possible
template<typename T>
bool Tree<T>::MoveLeft()
{
	if (cursor->GetPrevSibling() == NULL)
	{
		return false;
	}
	
	cursor = cursor->GetPrevSibling();
	
	return true;		
}

// Return a pointer to the node pointed to by cursor
template<typename T>
TreeNode<T>* Tree<T>::GetNode()
{
	return cursor;
}
template<typename T>
void Tree<T>::ResetCursor()
{
	cursor = root;
}
#endif
