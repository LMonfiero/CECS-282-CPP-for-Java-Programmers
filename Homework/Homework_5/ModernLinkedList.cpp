#include "ModernLinkedList.h"
#include <memory>
#include <iostream>
using namespace std;

//Louis Monfiero - 016336266
//I'm so glad I finished it lmaooo


//Adds a new last item - Read Descr #2
//Done! (I hope :D)
void ModernLinkedList::PushBack(int value)	{
	auto newNode = std::make_unique<Node>(value);
	if (mSize == 0)	{
		newNode->mNext = std::move(mHead);
		mHead = std::move(newNode);
	}

	else	{
		Node* temp = mHead.get();
		while (temp->mNext != nullptr)	{
			temp = temp->mNext.get();
		}
		temp->mNext = std::move(newNode);	
	}
	
	mSize++;
}

//Done (Given)
void ModernLinkedList::PushFront(int value) {
	auto newNode = std::make_unique<Node>(value);
	// Any time we change a link, we must use std::move.
	newNode->mNext = std::move(mHead);

	// Transfer ownership of this new head node to the List object.
	mHead = std::move(newNode);

	// Increase the size by 1.
	mSize++;
}

// Read Descr #2
//Mad confusing but gg no re I win
void ModernLinkedList::Insert(int index, int value)	{
	auto newNode = std::make_unique<Node>(value);
	
	if (index == 0)	{
		PushFront(value);
	}

	else if (index == mSize - 1)	{
		PushBack(value);
	}
	else	{
		auto newNode = std::make_unique<Node>(value);
		Node* temp = mHead.get();
		Node* prev = nullptr;
		while (temp != nullptr && index-- > 0)	{
			prev = temp;
			temp = temp->mNext.get();
		}
		newNode->mNext = std::move(prev->mNext);
		prev->mNext = std::move(newNode);

	}
	

	mSize++;
}

//Done (Given)
void ModernLinkedList::PopBack() {
	if (mSize == 1) {
		// Set head to nullptr, which destroys the only remaining node.
		// Reminder: to change ownership, use std::move.
		mHead = std::move(nullptr);
		mSize = 0;
	}
	else {
		// First walk to the second-to-last node in the list.
		// See PrintList().
		Node* temp = mHead.get();
		while (temp->mNext->mNext != nullptr) {
			temp = temp->mNext.get();
		}
		
		// If temp's next's next is null, then temp is the second to last node.
		// temp's next must now be set to null, which will destroy what used to be last.
		temp->mNext = std::move(nullptr);
		mSize--;
	}
}

//Done
void ModernLinkedList::PopFront(){
	if (mSize == 1) {
		mHead = std::move(nullptr);
		mSize = 0;
	}

	else	{
		mHead = std::move(mHead->mNext);

		mSize--;
	}
}

// Read Descr #2
//Also confusing but gg ez I win
void ModernLinkedList::RemoveAt(int index){
	Node* temp = mHead.get();
	if (index == 0)	{
		PopFront();
	}

	else if (index == mSize - 1)	{
		PopBack();
	}	

	else	{
		Node* temp = mHead.get();
		Node* prev = nullptr;
		while (temp != nullptr && index-- >= 0)	{
			prev = temp;
			temp = temp->mNext.get();
		}
		
		prev->mData = temp->mData;
		prev->mNext = std::move(temp->mNext);

		temp = std::move(nullptr); 


	}


	mSize--;
}

//Done
void ModernLinkedList::Clear(){
	while (mSize > 0)	{
		PopFront();
	}
}

// Read Descr #2 - Equivalent of Java get 
//Done! A lot simpler than I overhyped it to be!
int& ModernLinkedList::operator[](int index){
	Node* temp = mHead.get();

	while (temp != nullptr && index-- > 0)	{
		temp = temp->mNext.get();
	}
	return temp->mData;
}

//Done (Given)
void ModernLinkedList::PrintList() const {
	// To walk this list, we need to create a temp that points to the head node, and then gets moved
	// to the next, to the next, etc. This temp does not want to claim ownership of any of these nodes,
	// so it can't be a unique_ptr. A "raw" Node pointer will let us "use" each Node's values without
	// having to be an owner of that memory.

	cout << "[";
	Node* temp = mHead.get(); // reminder: a unique_ptr's .get() gives us back the raw pointer.
	// As long as the Node that temp points to is not null.
	while (temp != nullptr) {
		if (temp != mHead.get()) {
			// Separate each element with a comma.
			cout << ", ";
		}
		cout << temp->mData;
		temp = temp->mNext.get();
	}
	cout << "]" << endl;
}