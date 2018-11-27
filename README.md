# Tree-Implementation-in-C-plus-plus

Trees are an important data structure used in various applications. This repository first implements (general) trees in C++. Then, uses the tree data structure to load a dataset of weekly sales by various departments in multiple stores owned by a single retail store chain and then uses this tree to answer interesting queries on that data.

# Description of individual classes and/or files

# Class TreeNode
This class defines a node in the tree data structure. It is templatized to be generic. It includes pointers to
other TreeNode objects, specifically, a parent pointer, a pointer to the first child, a pointer to the next
sibling and a pointer to the previous sibling.

<div align="center">
    <img src="1.jpg" width="400px"</img> 
</div>

An explanation of what each member function of this class is supposed to do, follows. The implementation
of these functions is provided in the file node_impl.h:

TreeNode<T>() : This is the default constructor. It should assign a default value to all object members.
TreeNode<T>(T val) : This is a parameterized constructor. The value in variable val should be copied to
the value member of the object, while all pointers should be assigned a default value.
bool IsRoot() : This function should return true if the current object is the root node of the tree,
otherwise return false.
bool IsExternal() : This function should return true if the current object is an external node of the tree,
otherwise return false.
int GetHeight() : This function should return the height of the node in the tree.
int GetDepth() : This function should return the depth of the node in the tree.
T GetValue() : This function should return the value stored at the current node.
void SetValue (T val) : This function should update the value stored at the current node based on what
is passed as argument.
bool AddChild(T val) : Create a new node object and add it as a child of the current node. For efficiency,
the new node should be added as the first child of the current node. If a first child already exists, it should
now become the second child. If a child node already has the value in variable val, this function should
not modify the tree and return false. Return true if the child is successfully added.
void DeleteChild(T val) : Delete the child that stores the same value as in the variable val, if any.
TreeNode<T>* SearchChild(T val) : Search for a child node (NOTE: one level lower only) of this object
that stores the value in variable val. Return that child node’s address. Return NULL if no child node of the
current node stores this value.
TreeNode<T>* GetParent() : Return the address of the parent node of the current node.
TreeNode<T>* GetNextSibling() : Return the address of this node’s next sibling.
TreeNode<T>* GetPrevSibling() : Return the address of this node’s previous sibling.
TreeNode<T>* GetFirstChild() : Return the address of the first child of the current node.
