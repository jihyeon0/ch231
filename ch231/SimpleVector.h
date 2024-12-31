#pragma once
//3번 과제
#include <algorithm>

template <typename T>
class SimpleVector
{
public:
	SimpleVector()
	:currentCapacity(10), currentSize(0)
	{
		data = new T[currentCapacity];
		for (int i = 0; i < currentCapacity; i++)
		{
			data[i] = T();
		}
	}
	SimpleVector(const int capacity)
	:currentCapacity(capacity), currentSize(0)
	{
		data = new T[currentCapacity];
		for (int i = 0; i < currentCapacity; i++)
		{
			data[i] = T();
		}
	} 

	SimpleVector(const SimpleVector<T>& object) //복사생성자 -> SimpleVector<obj> a; SimpleVector<obj> b = SimpleVector<obj>(a);
		:currentCapacity(object.currentCapacity), currentSize(object.currentSize)
	{
		data = new T[currentCapacity]; //새로운 메모리 영역에 할당 후 데이터 복사, 독립적으로 동작
		for (int i = 0; i < currentSize; i++)
		{
			data[i] = object.data[i];
		}
	}

	~SimpleVector()
	{
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	const T& operator[](int index) const
	{
		if (0 <= index && index < currentSize)
			return data[index];
	}

	void reserve(int newCapacity)
	{
		if (currentCapacity < newCapacity)
		{
			resize(newCapacity);
		}
	}

	void push_back(const T& value)
	{
		if (currentSize == currentCapacity)
		{
			resize(currentCapacity+5);
		}
		data[currentSize] = value;
		currentSize++;

	}

	void pop_back()
	{
		if (0 < currentSize)
			currentSize--;		// 원소 8개 인덱스 마지막[7]
	}

	void  resize(int newCapacity)
	{ 
		if (currentCapacity < newCapacity)
		{
			T* arr = new T[newCapacity];
			for (int i = 0; i < currentSize; i++)
			{
				arr[i] = data[i];
			}
			for (int i = currentSize; i < newCapacity; i++)
			{
				arr[i] = T();
			}
			delete[] data;
			data = arr;
			currentCapacity = newCapacity;
		}
	}

	void sortData()
	{
		std::sort(&data[0], &data[currentSize]);
	}

	const int  size() { return currentSize; }
	const int  capacity() { return currentCapacity; }
	void clear() { currentSize = 0; }

private:
	T* data = nullptr;
	int currentSize;
	int currentCapacity;
};

