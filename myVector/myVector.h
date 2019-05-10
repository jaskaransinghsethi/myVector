#pragma once

template <class T>
class myVector
{
public:
	using iterator = T *;
	myVector();
	myVector(size_t size);
	myVector(size_t size, const T& initial);
	myVector(const myVector<T>& v);
	myVector(myVector<T>&& v);

	myVector<T>& operator=(const myVector<T>& v);
	myVector<T>& operator=(myVector&& v);
	T& operator[](size_t index);

	size_t size() const;
	
	bool empty() const;

	iterator begin();
	iterator end();

	T& front();
	T& back();

	void push_back(const T& value);
	void pop_back();

	void reserve(size_t capacity);
	void resize(size_t size);

	void clear();

	~myVector();
private:
	size_t mySize;
	size_t myCapacity;
	T* buffer;
};

template<class T>
inline myVector<T>::myVector() : mySize(0), myCapacity(0), buffer(nullptr)
{
}

template<class T>
inline myVector<T>::myVector(size_t size) : mySize(size), myCapacity(size), buffer(new T[size])
{
}

template<class T>
inline myVector<T>::myVector(size_t size, const T& initial) : mySize(size), myCapacity(size), buffer(new T[size])
{
	for (size_t i = 0; i < size; i++)
		buffer[i] = initial;
}

template<class T>
inline myVector<T>::myVector(const myVector<T>& v) : mySize(v.mySize), myCapacity(v.myCapacity), buffer(new T[mySize])
{
	for (size_t i = 0; i < mySize; i++)
		buffer[i] = v.buffer[i];
}

template<class T>
inline myVector<T>::myVector(myVector<T>&& v) : mySize(v.mySize), myCapacity(v.myCapacity), buffer(v.buffer)
{
	v.buffer = nullptr;
}

template<class T>
inline myVector<T>& myVector<T>::operator=(const myVector<T>& v)
{
	delete[] buffer;
	mySize = v.mySize;
	myCapacity = v.myCapacity;
	buffer = new T[mySize];
	for (int i = 0; i < mySize; i++)
		buffer[i] = v.buffer[i];
	return *this;
}

template<class T>
inline myVector<T>& myVector<T>::operator=(myVector&& v)
{
	delete[] buffer;
	mySize = v.mySize;
	myCapacity = v.myCapacity;
	buffer = v.buffer;
	v.buffer = nullptr;
	return *this;
}

template<class T>
inline T& myVector<T>::operator[](size_t index)
{
	return buffer[index];
}

template<class T>
inline size_t myVector<T>::size() const
{
	return mySize;
}

template<class T>
inline bool myVector<T>::empty() const
{
	if (mySize == 0)
		return true;
	else false;
}

template<class T>
inline typename myVector<T>::iterator myVector<T>::begin()
{
	return buffer;
}

template<class T>
inline typename myVector<T>::iterator myVector<T>::end()
{
	return buffer + size();
}

template<class T>
inline T& myVector<T>::front()
{
	return buffer[0];
}

template<class T>
inline T& myVector<T>::back()
{
	return buffer[mySize - 1];
}

template<class T>
inline void myVector<T>::push_back(const T& value)
{
	if (mySize >= myCapacity)
		if (myCapacity == 0)
			reserve(1);
		else reserve(myCapacity * 2);
	buffer[mySize++] = value;
}

template<class T>
inline void myVector<T>::pop_back()
{
	mySize--;
}

template<class T>
inline void myVector<T>::reserve(size_t capacity)
{
	if (buffer == nullptr) {
		mySize = 0;
		myCapacity = 0;
	}
	T* newBuffer = new T[capacity];
	size_t newSize = capacity < mySize ? capacity : mySize;

	for (size_t i = 0; i < newSize; i++) {
		newBuffer[i] = buffer[i];
	}
	
	myCapacity = capacity;
	delete[] buffer;
	buffer = newBuffer;
}

template<class T>
inline void myVector<T>::resize(size_t size)
{
	reserve(size);
	mySize = size;
}

template<class T>
inline void myVector<T>::clear()
{
	mySize = 0;
	myCapacity = 0;
	buffer = nullptr;
}

template<class T>
inline myVector<T>::~myVector()
{
	delete[] buffer;
	buffer = nullptr;
}
