#include <iostream>
#include <windows.h>

using namespace std;

class Vector
{
	unsigned int size = 0;
	unsigned int capacity = 10;
	int* data = nullptr;

public:
	Vector() : Vector(10)
	{
		// cout << "C-TOR WITHOUT PARAMS!\n";
	}

	Vector(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		// cout << "C-TOR WITH PARAMS!\n";
	}

	~Vector()
	{
		// cout << "DESTRUCTOR!\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

private:
	void EnsureCapacity()
	{
		if (size < capacity)
		{
			return;
		}

		capacity *= 2;

		int* temp = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[] data;
		data = temp;
	}

public:

	unsigned int GetSize() const
	{
		return size;
	}

	unsigned int GetCapacity() const
	{
		return capacity;
	}

	void Insert(int value, unsigned int index)
	{
		if (index > size)
		{
			cout << "Error!!\n";
			throw;
		}
		EnsureCapacity();
		for (unsigned int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;

	}

	void RemoveByIndex(unsigned int index)
	{
		if (index >= size)
		{
			cout << "Error!!\n";
		}
		for (unsigned int i = index; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

	void RemoveByValue(int value)
	{
		unsigned int index = 0;
		while (index < size)
		{
			if (data[index] == value)
			{
				for (unsigned int i = index; i < size - 1; i++)
				{
					data[i] = data[i + 1];
				}
				size--;
			}
			else
			{
				index++;
			}
		}
	}

	void PopFront()
	{
		if (size == 0)
		{
			cout << "Error!!\n";
			throw;
		}
		for (unsigned int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

	void PopBack()
	{
		if (size == 0)
		{
			cout << "Error!!\n";
			throw;
		}
		size--;
	}

	void PushBack(int value)
	{
		EnsureCapacity();
		data[size] = value;
		size++;

	}

	void PushFront(int value)
	{
		EnsureCapacity();
		for (int i = size; i > 0; i--) 
		{
			data[i] = data[i - 1];
		}
		data[0] = value;
		size++;
	}

	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}


};

int main()
{
	Vector bo;

	for (int i = 0; i < 10; i++)
	{
		bo.PushBack(rand() % 100);
		Sleep(15);
	}
	bo.Print();

	cout << "\nFunction Remove By Index: \n";
	bo.RemoveByIndex(0);
	bo.Print();

	cout << "\nFunction Pop Front: \n";
	bo.PopFront();
	bo.Print();

	cout << "\nFunction Insert: \n";
	bo.Insert(52, 3);
	bo.Print();

	cout << "\nFunction Pop Back: \n";
	bo.PopBack();
	bo.Print();

	cout << "\nFunction Remove By Value: \n";
	bo.RemoveByValue(76);
	bo.Print();
}