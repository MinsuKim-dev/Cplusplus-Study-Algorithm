#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// �ڷᱸ�� "Queue"(FIFO, First-In-First-Out, ���Լ���)
// front << [ ][ ][ ][ ][ ] << rear(back)
// ���� ������ ���� ������.
// ex) ��⿭

// Queue ���� ����
// vector���� list�� �����ϴ� ���� ���������� �Ǵ�.
// vector�� �߰� ����, ������ ������ ��ȿ������
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

// ���� �迭�� �̿��� queue����� ���� - ��ȯ ����
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
		// �� ã���� Ȯ�� �� ����
		if (_size == _container.size())
		{
			int newSize = max(1, _size * 2); // max�� ���ʰ� �������� �� �� �� ū ���� ������
			vector<T> newData;
			newData.resize(newSize);

			// ������ ����
			for (int i = 0; i < _size; i++)
			{
				int index = (_front + i) % _container.size(); // ������ ������
				newData[i] = _container[index];
			}

			_container.swap(newData);
			_front = 0;
			_back = _size;
		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size(); // ��ȯ ������ ���� �� ������ ���
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

// �迭�� �Ҵ��� �ް� ��ȯ�ϴ� ������ ������
// [front, back][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
// [front][ ][ ][ ][ ][ ][ ][back][ ][ ][ ][ ]
// [ ][ ][ ][ ][front][ ][ ][back][ ][ ][ ][ ]
// ó���� front�� back�� ���� 0�� �ε����� ����Ű��
// �����Ͱ� ������ ���� back�� �ڷ� ����. (back�� ���������� ��ȿ ������)
// �����͸� ���� ���� front�� ������ ����.

// �Ҵ� ���� �迭�� �� ���� �ȴٸ�?
// [ ][ ][ ][ ][ ][ ][ ][ ][front][ ][back]
// [ ][ ][ ][back][ ][ ][ ][front][ ][ ][ ]
// back�� �ٽ� ���� ������ ���� ��ȯ�ϴ� ������ �����.

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