#pragma once
#include <memory>
template <typename KEY, typename VALUE>
struct BSTNode
{
	BSTNode(const KEY key, const VALUE value, int count)
		: _key (key)
		, _value(value)
		, _parent (nullptr)
		, _leftChild(nullptr)
		, _rightChild(nullptr)
		, _count (count)
	{
		_comp = COMPARATOR();
	}
	const KEY _key;
	VALUE _value;
	BSTNode <T>* _parent;
	BSTNode <T>* _leftChild;
	BSTNode <T>* _rightChild;
	int _count;

private:
	BSTNode(const BSTNode<T>&) = delete;
	BSTNode<T>& operator =(const BSTNode<T>& rhs) = delete;


};

template <typename KEY, typename VALUE, typename COMPARATOR = std::less<KEY>>
class BST
{
public:
	BST(const KEY key, const VALUE value) 
		: _root(new BSTNode <KEY,VALUE> (key, value))
	{
	}
		
	BST() : _root(nullptr)
	{

	}
	~BST() {
			removeFrom(_root);
	}

	bool get(const KEY key, const VALUE& value);
	bool  insert(const KEY key, const VALUE& value);
	BSTNode<KEY, VALUE>*  put(const KEY key, const VALUE& value);
	
private:
	void removeFrom(BSTNode<T>* pNext)
	{

		BSTNode<T>* pref = pNext;
		if (pref->_leftChild)
			removeFrom(pref->_leftChild);
		else if (pref->_rightChild)
			removeFrom(pref->_rightChild);

		if (pNext-> == _root)
		{
			delete pNext;
			pNext = nullptr;
		}
	}

	BSTNode<KEY, VALUE> *_root;
	COMPARATOR _comp;
};

template <typename KEY, typename VALUE, typename COMPARATOR=std::less<KEY> >
bool 
BST<KEY, VALUE, COMPARATOR>::get(const KEY key, VALUE& value)
{
	bool bRet(false);
	BSTNode<KEY, VALUE>* pNext = _root;
	while (pNext)
	{
		if (pNext->_key == key)
		{
			value = pNext->_value;
			bRet = true;
			break;
		}
		else if (key > pNext->_key)
		{
			pNext = pNext->_rightChild;
			continue;
		}
		else
		{
			pNext = pNext->_leftChild;
		}
	}
	return bRet;
}

template <typename KEY, typename VALUE, typename COMPARATOR = std::less<KEY>>
bool 
BST<KEY, VALUE, COMPARATOR>::insert(const KEY& key, VALUE& value)
{
	_root = put(_root, key, value);
}


template <typename KEY, typename VALUE, typename COMPARATOR = std::less<KEY> >
BST<KEY, VALUE, COMPARATOR>*
BST<KEY, VALUE, COMPARATOR>::put(BSTNode<KEY, VALUE, COMPARATOR>* node, 
											const KEY& key, 
											VALUE& value)
{
	if (node == nullptr) {
		return new BSTNode<KEY, VALUE, COMPARATOR>(key, value, 1);
	}
	if (key == node->_key)
	{
		node->value = value;
	}
	else
	{

		bool bLess = _comp(key, node->_key);
		if (bLess)
			node->_leftChild = put(node->_leftChild, key, value);
		else if (key > node->_key)
			node->_rightChild = put(node->_rightChild, key, value);

		node._count = 1 + size(node._leftChild) + size(node._rightChild);
	}
	
	return node;
}
