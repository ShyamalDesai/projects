// HeapTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Heap.h"

using namespace Util::Photosophus;

int main()
{
	Heap <int> minHeap;
	std::cout << "top= " << minHeap.top() << std::endl;
	minHeap.pop();

	
	minHeap.add(11);
	minHeap.add(8);
	minHeap.add(84);
	minHeap.add(-5);
	minHeap.add(99);
	minHeap.add(54);
	minHeap.add(32);
	minHeap.add(1);

	std::cout << "top= " << minHeap.top() << std::endl;
	minHeap.pop();

	std::cout << "top= " << minHeap.top() << std::endl;
	minHeap.pop();

	std::cout << "top= " << minHeap.top() << std::endl;
	minHeap.pop();


	//test max heap
	return 0;
}

