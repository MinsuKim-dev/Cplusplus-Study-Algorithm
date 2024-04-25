#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// 자료구조 "Queue"(FIFO, First-In-First-Out, 선입선출)
// front << [ ][ ][ ][ ][ ] << rear(back)
// 먼저 들어오면 먼저 나간다.
// ex) 대기열

// Queue 구현 연습
// vector보다 list로 구현하는 것이 성능적으로 옳다.
// vector는 중간 삽입, 삭제가 굉장히 비효율적임
template<typename T>
class Queue
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_front();
	}

	T& front()
	{
		return _container.front();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	list<T> _container;
	// deque<T> _container;
};

// 동적 배열을 이용한 queue만들기 연습 - 순환 구조
template<typename T>
class ArrayQueue
{
public:
	ArrayQueue()
	{
		// _container.resize(100);
	}

	void push(const T& value)
	{
		// 다 찾는지 확인 및 증설
		if (_size == _container.size())
		{
			int newSize = max(1, _size * 2); // max는 왼쪽과 오른쪽의 값 중 더 큰 값을 리턴함
			vector<T> newData;
			newData.resize(newSize);

			// 데이터 복사
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size(); // 원본의 데이터
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size(); // 순환 구조를 만들 때 유용한 방식
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};

// 배열을 할당을 받고 순환하는 구조로 만들자
// [front, back][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
// [front][ ][ ][ ][ ][ ][ ][back][ ][ ][ ][ ]
// [ ][ ][ ][ ][front][ ][ ][back][ ][ ][ ][ ]
// 처음엔 front와 back이 서로 0번 인덱스를 가리키고
// 데이터가 많아질 수록 back은 뒤로 간다. (back의 이전까지만 유효 데이터)
// 데이터를 꺼낼 수록 front는 앞으로 간다.

// 할당 받은 배열을 다 쓰게 된다면?
// [ ][ ][ ][ ][ ][ ][ ][ ][front][ ][back]
// [ ][ ][ ][back][ ][ ][ ][front][ ][ ][ ]
// back은 다시 가장 앞으로 가서 순환하는 구조로 만든다.

int main()
{
	ArrayQueue<int> q;

	for (int i = 0; i < 100; i++)
		q.push(i);

	while (q.empty() == false)
	{
		int value = q.front();
		q.pop();
		cout << value << endl;
	}

	int size = q.size();
}