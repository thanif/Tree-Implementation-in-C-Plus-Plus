#ifndef NODE_IMPL_H
#define NODE_IMPL_H
#include "node.h"

template<typename T>
TreeNode<T>::TreeNode()
{

	val = 0;
	parent = NULL;
	firstChild = NULL;
	nextSibling = NULL;
	prevSibling = NULL;

}
template<typename T>
TreeNode<T>::TreeNode(T val)
{
	this->val = val;
	parent = NULL;
	firstChild = NULL;
	nextSibling = NULL;
	prevSibling = NULL;
	
}
template<typename T>
bool TreeNode<T>::IsRoot()
{
	if (this->parent)
	{
		return false;
	}
	
	return true;
}
template<typename T>
bool TreeNode<T>::IsExternal()
{
	if (firstChild)
	{
		return false;
	}
	
	return true;
}
template<typename T>
int TreeNode<T>::GetHeight()
{
	if (this->IsExternal())
	{
		return 0;
	}
	return 1 + max(this->firstChild->GetHeight(), this->prevSibling->GetHeight(), this->nextSibling->GetHeight());
}
template<typename T>
int TreeNode<T>::GetDepth()
{
	if (this->IsRoot())
	{
		return 0;
	}
	return 1 + this->parent->GetDepth();
}
template<typename T>
T TreeNode<T>::GetValue()
{
	return val;
}
template<typename T>
void TreeNode<T>::SetValue (T val)
{
	this->val = val;
}
template<typename T>
bool TreeNode<T>::AddChild(T val)
{
	if (firstChild == NULL)
	{
		firstChild = new TreeNode<T>(val);
		
		return true;
	}
	
	if (firstChild->val == val)
	{
		return false;
	}
	
	TreeNode<T>* p_fc = firstChild;
	
	firstChild = new TreeNode<T>(val);
	
	p_fc->prevSibling = firstChild;
	
	firstChild->nextSibling = p_fc;
	
	return true;
}
template<typename T>
void TreeNode<T>::DeleteChild(T val)
{
	if (firstChild->val == val)
	{
		TreeNode<T>* c_fc = firstChild;
		firstChild = firstChild->nextSibling;
		firstChild->prevSibling = NULL;
		delete c_fc;
	}
	else
	{
		TreeNode<T>* current = firstChild->nextSibling;
		while (current != NULL)
		{
			if (current->val == val)
			{
				TreeNode<T>* c = current;
				
				current->nextSibling->prevSibling = current->prevSibling;
				current->prevSibling->nextSibling = current->nextSibling; 
				
				current = current->nextSibling;
				
				delete c;
				
			}
			else
			{
				current = current->nextSibling;
			}
		}
	
	}
	
}
template<typename T>
TreeNode<T>* TreeNode<T>::SearchChild(T val)
{
	if (firstChild->val == val)
	{
		return firstChild;
	}
	else
	{
		TreeNode<T>* current = firstChild->nextSibling;
		while (current != NULL)
		{
			if (current->val == val)
			{
				return current;
				
			}
			
			current = current->nextSibling;
		}
		
		return NULL;
	
	}	
}
template<typename T>
TreeNode<T>* TreeNode<T>::GetParent()
{
	return parent;
}
template <typename T>
TreeNode<T>* TreeNode<T>::GetNextSibling()
{
	return nextSibling;
}
template <typename T>
TreeNode<T>* TreeNode<T>::GetPrevSibling()
{
	return prevSibling;
}
template <typename T>
TreeNode<T>* TreeNode<T>::GetFirstChild()
{
	return firstChild;
}
#endif
