#pragma once
#include <vector>
//the heap structure can be used to implement priority_queue
//can also be used for heapsort 

//k /2 is the parent
//2k+1 and 2k+2 is the child

namespace Util
{
	namespace Photosophus
	{
		template <typename TYPE, typename COMPARATOR = std::less<TYPE> >
		class Heap
		{
		public:

			Heap(int initialSize=100) :_heap (initialSize), _size(1)
			{
				_heap.push_back(0);
			}
			~Heap()
			{

				_heap.clear();
			}

			const TYPE& top();
			void pop();
			int add(const TYPE& val);
		private:
			//swim
			//sink
			void swim(const uint32_t);
			void sink(const uint32_t);
			void swap(const int leftIndex, const int rightIndex)
			{
				TYPE val = _heap[leftIndex];
				_heap[leftIndex] = _heap[rightIndex];
				_heap[rightIndex] = val;
			}

			std::vector <TYPE> _heap;
			COMPARATOR	 _comp;
			uint32_t _size;
		};

		//-----------------------------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------------------------
		template <typename TYPE, typename COMPARATOR = std::less<TYPE> >
		void
		Heap<TYPE, COMPARATOR>::swim(const uint32_t index)
		{

			//we dont use zero index to keep calculations clean
			//so the array is used from index 1 to size() -1
			uint32_t child = index;
			uint32_t parent = index>> 1;
			while (parent >= 1)
			{
				if (_comp(_heap[child], _heap[parent]))
				{
					swap(child, parent);
				}
				else
					break;
				child = parent;
				parent = parent >> 1;
			}
			return;
		}


		//-----------------------------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------------------------
		template <typename TYPE, typename COMPARATOR = std::less<TYPE> >
		void
		Heap<TYPE, COMPARATOR>::sink(const uint32_t index)
		{
			uint32_t parent = index;
			uint32_t child = (index << 1);

			while (child <= _size)
			{
				if (_comp(_heap[child], _heap[parent]))
				{
					swap(child, parent);
					parent = child;
					child = parent << 1;
				}
				else if (_comp(_heap[child + 1], _heap[parent]))
				{
					swap(child + 1, parent);
					parent = child;
					child = (child + 1) << 1;
				}
				else
					break;
			}
		}

		template <typename TYPE, typename COMPARATOR = std::less<TYPE> >
		const TYPE&
		Heap<TYPE, COMPARATOR>::top()
		{
			if (_size > 1)
				return _heap[1];
			else
				return 0; //returning error is a better idea
		}

		template <typename TYPE, typename COMPARATOR = std::less<TYPE> >
		void
		Heap<TYPE, COMPARATOR>::pop()
		{
			if (_size > 1)
			{
				swap(1, _size - 1);
				sink(1);
				_size -= 1;
			}
		}

		template <typename TYPE, typename COMPARATOR = std::less<TYPE> >
		int
		Heap<TYPE, COMPARATOR>::add(const TYPE& val)
		{
			if (_size > _heap.size())
			{
				//reallocate
				_heap.resize(_heap.size() *2);
			}
			_heap[_size] = val;
			swim(_size);
			++_size;
			
			return 0;
		}
	}
}