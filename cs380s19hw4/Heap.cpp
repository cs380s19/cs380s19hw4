//***************************************************************************
// File name: 
// Author: 
// Date: 
// Class: 
// Assignment: 
// Purpose: 
//***************************************************************************

#include "Heap.h"


Heap::Heap()
{
	HNode* pTemp = NULL;
	//	mSortDir = MAX;
		//mHeapArray.pushBack(pTemp);
	mHeapArray[++mCurrentHeapPosition] = pTemp;
}

Heap::~Heap()
{
	//mHeapArray.clear();
	mCurrentHeapPosition = -1;
}

void Heap::deallocateItems()
{
	for (unsigned int i = 0; i < /*(int) mHeapArray.count()*/ mCurrentHeapPosition + 1; i++)
	{
		delete mHeapArray[i];
	}
}


bool Heap::updateEachKey(int keyUpdate)
{
	bool pResult = true;
	for (unsigned int i = 1; i < mCurrentHeapPosition + 1 /*mHeapArray.count()*/; i++)
	{
		pResult = pResult && mHeapArray[i]->calculateNewKey(keyUpdate);
	}
	this->buildHeap();
	return pResult;
}

/// FIX AND POST MESSAGE ABOUT THIS
/// the key is already increased, size is really the node index
void Heap::heapIncreaseKey(int index)
{
	int parent = static_cast<int>((index) / 2.0);
	HNode * pTemp;

	if (index > this->size())
		//pNode->comparator(mHeapArray[size]) == -1 )
	{
		// errors
	}

	while (index > 1 && needSwap(mHeapArray[parent], mHeapArray[index]))
		//*mHeapArray[parent] < *mHeapArray[size] )

		//mHeapArray[parent]->comparator(mHeapArray[size]) == -1 )
	{
		pTemp = mHeapArray[index];
		mHeapArray[index] = mHeapArray[parent];
		mHeapArray[parent] = pTemp;
		index = parent;
		parent = static_cast<int>(index / 2.0);
	}
}


// Function to insert a new node into the heap and maintain
// the heap property

void Heap::insert(HNode * pNode)
{
	//mHeapArray.push_back(pNode);
	mHeapArray[++mCurrentHeapPosition] = pNode;

	heapIncreaseKey(/*mHeapArray.size()*/mCurrentHeapPosition + 1 - 1);

}

// Function that will display the heap. Note that this function will call
// the Node display function to display the heap to either a file or the
// screen as specified in Node

std::ostream& operator<<(std::ostream &os, const Heap &theHeap)
{
	for (unsigned int i = 1; i </*theHeap.mHeapArray.size()*/ theHeap.mCurrentHeapPosition + 1; i++)
	{
		os << *theHeap.mHeapArray[i] << " ";
	}
	return os;
}

// Function to build a heap from the current vector

void Heap::buildHeap()
{
	int i = static_cast<int>((/*this->mHeapArray.size()*/mCurrentHeapPosition + 1 - 1) / 2.0); // FLOOR[n/2]
	while (i >= 1)
	{
		this->heapify(i);
		i--;
	}
}

// Function to maintain the heap property starting from the given index

void Heap::heapify(int i)
{
	unsigned int left, right, largest = i;
	HNode *pTemp;

	left = 2 * i;
	right = left + 1;

	if (left < mCurrentHeapPosition + 1 /*mHeapArray.size()*/ && needSwap(mHeapArray[i], (mHeapArray[left])))
		//*mHeapArray[left] > *(mHeapArray[i]) ) 
		//(mHeapArray[left]->comparator(mHeapArray[i]) == 1) )
	{
		largest = left;
	}
	if (right < mCurrentHeapPosition + 1 /*mHeapArray.size()*/ && needSwap(mHeapArray[largest], (mHeapArray[right])))
		//(*mHeapArray[right] > *(mHeapArray[largest]) ))
		//(mHeapArray[right]->comparator(mHeapArray[largest]) == 1))
	{
		largest = right;
	}
	if (largest != i)
	{
		pTemp = mHeapArray[i];
		mHeapArray[i] = mHeapArray[largest];
		mHeapArray[largest] = pTemp;
		heapify(largest);
	}
}

// Function to remove the root of the heap and return it to the calling
// function

HNode* Heap::heapExtract()
{
	HNode* pMax;

	if (mCurrentHeapPosition + 1/*mHeapArray.size()*/ < 1)
	{
		//error
		return NULL;
	}

	pMax = mHeapArray[1];

	mHeapArray[1] = mHeapArray[mCurrentHeapPosition]; // mHeapArray.back ();

	//mHeapArray.pop_back();
	mCurrentHeapPosition--;

	heapify(1);

	return pMax;
}

// Function to return the root of the heap but NOT remove it from the heap

const HNode  * Heap::heapExtreme() const
{
	if (mCurrentHeapPosition + 1/*mHeapArray.size()*/ < 2)
	{
		//error
		return NULL;
	}
	return mHeapArray[1];
}

int Heap::size() const
{
	return mCurrentHeapPosition + 1/* mHeapArray.size()*/ - 1;
}

//********************************************************
// Method:	setSortDirection 
//
// Description: Set the sort direction (ASC/DESC) of this algorithm.
//
// Parameters: A Direction
//
// Returned: none
//	
//********************************************************
//void Heap::setSortDirection(Heap::Direction dir )
//{
//	mSortDir = dir;
//}

//********************************************************
// Method:	getSortDirection 
//
// Description: get the sort direction (ASC/DESC) of this algorithm.
//
// Parameters: none
//
// Returned: the current sort Direction
//	
//********************************************************
//Heap::Direction Heap::getSortDirection()  const
//{ 
//	return mSortDir; 
//}

bool Heap::needSwap(const HNode *pParent, const HNode *pChild)
{
	return *pParent > *pChild;
	//(MIN == getSortDirection() && *pParent > *pChild) ||
			//(MAX == getSortDirection() && *pParent < *pChild);
}
