#pragma once
//the heap structure can be used to implement priority_queue
//can also be used for heapsort 

//k /2 is the parent
//2k+1 and 2k+2 is the child
template <typename TYPE, typename COMPARATOR=std::less>
class Heap
{
public:
	
	Heap() 	: _size (0)
	{
	}
	~Heap()
	{
		_heap.clear();
	}

	const T top();
	void pop();
	int add(const T& val);
private:
		//swim
		//sink
	void swim(const int uint32_t);
	void sink(const int uint32_t);

	
	std::vector <TYPE> _heap;
	COMPARATOR	 _comp;
	uint32_t _size;
};

//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
template <typename TYPE, typename COMPARATOR>
void
Heap::swim(const uint32_t index)
{
	
	//we dont use zero index to keep calculations clean
	//so the array is used from index 1 to size() -1
	uint32_t child = index;
	uint32_t parent = index / 2;
	while (parent >= 1)
	{
		if (_comp(_heap[child], _heal[parent))
		{
			std::swap(_heap[child], _heap[parent]);
		}
		else
			break;
		child = parent;
		parent = parent / 2;
	}
	return;
}


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
template <typename TYPE, typename COMPARATOR>
void
Heap::sink(const uint32_t index)
{
	uint32_t parent = index;
	uint32_t child = (index << 2);

	while (child <= _size)
	{
		if (_comp(_heap[child], _heap[parent]))
		{
			std::swap(_head[child], heap[parent);
			parent = child;
			child = parent << 2;
		}
		else if (_comp(_heap[child + 1], _heap[parent]))
		{
			std::swap(_head[child + 1], heap[parent);
			parent = child;
			child = (child + 1) << 2;
		}
		else
			break;
	}
}

template <typename TYPE, typename COMPARATOR>
const T
Heap::top()
{
	return _heap[size];
}

template <typename TYPE, typename COMPARATOR>
void 
Heap::pop()
{
	size -= 1;
}

template <typename TYPE, typename COMPARATOR>
int 
Heap::add(const T& val)
{
	_heap.push_back(val);
	++size;

}
