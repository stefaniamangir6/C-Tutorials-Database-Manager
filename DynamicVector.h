#pragma once
#include "Tutorial.h"

typedef Tutorial TElem; // for templates

template<typename TElem>
class DynamicVector {
private:
	int capacity;
	int size;
	TElem* elems;


public:

	// default constructor for a DynamicVector
	DynamicVector(int capacity = 100);

	//copy constructor for the dynamic vector
	DynamicVector(const DynamicVector& newVector);

	void resize(const DynamicVector<TElem>& originalDynamicVector);

	void add(TElem newTutorial);
	/*
			-adds an element of type Tutorial to the current dynamic vector 
			- if the capacity is not enough, the function resizes the vector

			input: entity of type Tutorial
			output: the function add one more element to the vector
	*/

	void remove(int position);

	/*
			- removes an element of type Tutorial of the current dynamic vector

			input: position of type int, meaning the position of the elemnt we want to delete 
			output: the function deletes the  element from position "position" from the vector, if the position is valid 
	*/

	void update(TElem t, int position);

	/*
			- updates an element of type Tutorial of the current dynamic vector

			input: position of type int, meaning the position of the elemnt we want to delete and t - an element of type tutorial, which 
					contains the link of the tutorial we want to modify and the new details 

			output: the function updates the  element from position "position" from the vector, if the position is valid with t
	*/

	//get current size(length/number of elements) of the vector 
	int sizee() const;

	//assignment operator
	TElem & operator[](int position);

	//assignment operator 
	DynamicVector& operator = (const DynamicVector& newVector);

	// destructor
	~DynamicVector();
};

template<typename TElem>
DynamicVector<TElem>::DynamicVector(int capacity) {
	this->capacity = capacity;
	this->size = 0;
	this->elems = new TElem[this->capacity];
}

template<typename TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector& newVector) {
	this->capacity = newVector.capacity;
	this->size = newVector.size;
	this->elems = new TElem[this->capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->elems[i] = newVector.elems[i];
	}
}


template<typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator = (const DynamicVector& newVector) {
	if (this == &newVector) {
		return *this;
	}

	this->capacity = newVector.capacity;
	this->size = newVector.size;

	delete[]this->elems;
	this->elems = new TElem[newVector.capacity];
	for (int i = 0; i < this->capacity; i++) {
		this->elems[i] = newVector.elems[i];
	}

	return *this;
}


template<typename TElem>
void DynamicVector<TElem>::resize(const DynamicVector<TElem>& originalDynamicVector) {
	this->capacity *= 2;
	TElem* tempArray = new TElem[this->capacity];
	for (int i = 0; i < this->size; i++) {
		tempArray[i] = originalDynamicVector.elems[i];
	}
	delete[] this->elems;
	this->elems = tempArray;
}


template<typename TElem>
void DynamicVector<TElem>::add(TElem newTutorial) {
	if (this->capacity == this->size) {
		this->resize(*this);
	}
	this->elems[this->size++] = newTutorial;
}


template<typename TElem>
void DynamicVector<TElem>::remove(int position)
{
	if (position < 0 || position > this->size)
		return;

	for (int i = position; i < this->size; i++)
		this->elems[i] = this->elems[i + 1];

	this->size--;
}


template<typename TElem>
void DynamicVector<TElem>::update(TElem t, int position)
{
	if (position < 0 || position > this->size)
		return;

	this->elems[position] = t;
}


template<typename TElem>
TElem & DynamicVector<TElem>::operator[](int position) {
	return elems[position];
}

template<typename TElem>
int DynamicVector<TElem>::sizee() const {
	return this->size;
}

template<typename TElem>
DynamicVector<TElem>::~DynamicVector() {
	delete[]this->elems;
}