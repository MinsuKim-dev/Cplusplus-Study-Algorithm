#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector
{
public:
	Vector()
	{

	}

	~Vector()
	{
		if (_data)
			delete[] _data;
	}

	void push_back(const T& value)
	{
		// 여유분이 꽉 찼다면?
		if (_size == _capacity)
		{
			// 여유분 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			// 증설 상세 내용
			reserve(newCapacity);
		}

		// 데이터 저장
		_data[_size] = value;

		// 데이터 개수 증가
		_size++;
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		// 요청 받은 여유분 만큼 메모리 증설
		_capacity = capacity;

		// 새로운 여유분의 공간 생성
		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 기존 데이터 삭제
		if (_data)
			delete[] _data;

		// 교체
		_data = newData;
	}

	T& operator[](const int pos) { return _data[pos]; }

	int size()		{ return _size; }
	int capacity()	{ return _capacity; }

	void clear()
	{
		if (_data)
		{
			delete[] _data;
			_data = new T[_capacity];
		}

		_size = 0;
	}

private:
	T*		_data = nullptr;
	int		_size = 0;
	int		_capacity = 0;
};

int main()
{
	Vector<int> v;

	// v.size(10);

	v.reserve(100);

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	v.clear();
	cout << v.size() << " " << v.capacity() << endl;
}