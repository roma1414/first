// test_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "functions.h"

class IntArray
{
private:
	int m_length;
	int *m_data;
public:
	IntArray() :
		m_length(0), m_data(nullptr)
	{
	}

	IntArray(int length) :m_length(length)
	{
		assert(length >= 0);
		if (length > 0) {
			m_data = new int[length];
		}
		else {
			m_data = nullptr;
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	void reallocate(int);
	void resize(int);
	void insertBefore(int, int);
	void remove(int);
	void insertAtBeginning(int);
	void insertAtEnd(int);
	int getLength();

};

void IntArray::reallocate(int newLength)
{
	erase();
	if (newLength <= 0) {
		return;
	}
	m_data = new int[newLength];
	m_length = newLength;
}

void IntArray::resize(int newLength)
{
	if (newLength == m_length) {
		return;
	}
	if (newLength <= 0) {
		erase();
		return;
	}
	int *data = new int[newLength];
	if (m_length > 0) {
		int elementsToCopy = (newLength > m_length) ? m_length : newLength;
		for (int i = 0; i < elementsToCopy; i++) {
			data[i] = m_data[i];
		}
	}
	delete m_data;
	m_length = newLength;
	m_data = data;
}

void IntArray::insertBefore(int value, int index)
{
	assert(index >= 0 && index <= m_length);
	int *data = new int[m_length + 1];
	for (int i = 0; i < index; i++) {
		data[i] = m_data[i];
	}
	data[index] = value;
	for (int i = index; i < m_length; i++) {
		data[i + 1] = m_data[i];
	}
	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntArray::remove(int index) {
	assert(index >= 0 && index < m_length);
	if (m_length == 1) {
		erase();
		return;
	}
	int *data = new int[m_length - 1];
	for (int i = 0; i < index; i++) {
		data[i] = m_data[i];
	}
	for (int i = index+1; i < m_length; i++) {
		data[i-1] = m_data[i];
	}
	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}

int IntArray::getLength()
{
	return m_length;
}


int main()
{
	// Declare an array with 10 elements
	IntArray array(10);

	// Fill the array with numbers 1 through 10
	for (int i = 0; i < 10; i++)
		array[i] = i + 1;

	// Resize the array to 8 elements
	array.resize(8);

	// Insert the number 20 before element with index 5
	array.insertBefore(20, 5);

	// Remove the element with index 3
	array.remove(3);

	// Add 30 and 40 to the end and beginning
	array.insertAtEnd(30);
	array.insertAtBeginning(40);

	// Print out all the numbers
	for (int j = 0; j < array.getLength(); j++)
		std::cout << array[j] << " ";

	return 0;
}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
