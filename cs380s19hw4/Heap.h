//***************************************************************************
// File name:	Heap.h
// Author:		Shereen Khoja
// Author:		Chadd Williams
// Date:			02/16/2011
// Edited:		09/12/2013
// Class:			CS380
// Assignment:Disk Scheduling
// Purpose:		This is the header file for the Heap class.
//**************************************************************************

#pragma once

#include "HNode.h"
//#include <vector>
#include <iostream>
#include <iomanip>

class Heap
{
public:
	Heap();

	// Destructor for Heap that will NOT delete all of the HNode*'s
	// You WILL have to delete the pointers in your driver
	~Heap();

	// convience function to deallocate the data pointed to by
	// the pointers in the heap
	void deallocateItems();

	// Function to insert a new node into the heap and maintain
	// the heap property
	void insert(HNode  *);

	// display the heap by calling the << operator on each HNode
	friend std::ostream& operator<<(std::ostream &os, const Heap &theHeap);

	// Function to build a heap from the current vector
	void buildHeap();

	// Function to remove the root of the heap and return it to the calling
	// function
	HNode* heapExtract();

	// Function to return the root of the heap but NOT remove it from the heap
	const HNode  * heapExtreme() const;

	// get the size of the heap
	int size() const;

	// This will visit each item in the heap, and call HNode::updateKey
	// Lastly, buildHeap() is called.
	bool updateEachKey(int keyUpdate);

	virtual bool needSwap(const HNode *pParent, const HNode *pChild);

private:

	// Function to maintain the heap property starting from the given index
	void heapify(int i);

	void heapIncreaseKey(int index);

	// The heap stored as a vector of HNode*'s
	// std::vector<HNode*> mHeapArray;

	static const int MAX_HEAP_SIZE = 1024;
	HNode* mHeapArray[MAX_HEAP_SIZE];
	unsigned int mCurrentHeapPosition = -1;

	//Direction mSortDir;
};