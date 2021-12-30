#pragma once

#include <iostream>
#include <string>

namespace Minecraft {

	template <class T>
	class Buffer
	{
	private:
		T* Arr;
		int MaxSize;
		int CurrentSize;

	public:
		Buffer();
		Buffer(T* arr, int maxSize);
		Buffer(int maxSize);

		~Buffer();

		void Put(T element);
		T& Get(int i);

		T* GetArray();

		int GetCurrentSize();

		int GetMaxSize();

		std::string ToString();

		template<unsigned int I>
		std::array<T, I> ToArray();

		T operator[](int i) const
		{
			return Arr[i];
		}

		T& operator[](int i)
		{
			return Arr[i];
		}
	};

	template<class T>
	Buffer<T>::Buffer()
	{
	}

	template<typename T>
	inline Buffer<T>::Buffer(T* arr, int size)
	{
		Arr = new T[size];
		MaxSize = size;
		CurrentSize = size;

		for (int i = 0; i < size; i++)
		{
			Arr[i] = arr[i];
		}
	}

	template<class T>
	Buffer<T>::Buffer(int size)
	{
		Arr = new T[size]{ 0 };
		MaxSize = size;
		CurrentSize = 0;
	}

	template<class T>
	Buffer<T>::~Buffer()
	{
		//delete arr;
	}

	template<class T>
	void Buffer<T>::Put(T element)
	{
		if (CurrentSize >= MaxSize)
		{
			std::cerr << "Array overflow halted" << std::endl;
			return;
		}

		Arr[CurrentSize++] = element;
	}

	template<class T>
	inline T* Buffer<T>::GetArray()
	{
		return Arr;
	}

	template<class T>
	inline T& Buffer<T>::Get(int i)
	{
		return Arr[i];
	}

	template<class T>
	int Buffer<T>::GetCurrentSize()
	{
		return CurrentSize;
	}

	template<class T>
	inline int Buffer<T>::GetMaxSize()
	{
		return MaxSize;
	}

	template<class T>
	std::string Buffer<T>::ToString()
	{
		std::string str = "";
		for (int i = 0; i < CurrentSize; i++)
		{
			str += std::to_string(Arr[i]) + " ";
		}
		return str;
	}

	template<class T> template<unsigned int I>
	inline std::array<T, I> Buffer<T>::ToArray()
	{
		if (I > MaxSize)
		{
			std::cerr << "Size mismatch" << std::endl;
		}

		std::array<T, I> arr;

		for (int i = 0; i < I; i++)
		{
			arr[i] = Arr[i];
		}

		return arr;
	}
}