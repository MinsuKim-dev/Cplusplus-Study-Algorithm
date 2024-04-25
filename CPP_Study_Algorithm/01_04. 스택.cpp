#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

// �ڷᱸ�� "stack"(LIFO, Last-In-First-Out, ���Լ���)
// �����ʹ� ���� �������θ� ���̰� �������� ���Ŵ� �������� �Ҵ�� �����ͺ��� ���ŵȴ�.
// ���� �ֱٿ� ���� �����Ͱ� ���� ���� ������.

// stack�� ���
// .push(value)	: �ֻ��� ���� �ڿ� ������ ����
// .pop()		: �ֻ��� ���� ����
// .top()		: �ֻ��� ���� ã��(.top()�� .pop()�� ¦���� ����Ѵ�. ã�� ���� ����)
// .size()		: ���ÿ� �ִ� ������ ����(int)
// .empty()		: ������ ����ִ��� Ȯ��(true, false)

// ex) �ǵ����� ��� - Undo(Ctrl + Z)

// ���� ���� ����
// �������� �����͸� �ְ� ���� ����� �� �� �ִٸ� 
// ���� �迭�̳� ���� ����Ʈ�� Ȱ���� �� �ִ�.
template<typename T, typename Container = vector<T>>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	// vector<T> _container;	���� �迭�� ����
	// list<T> _container;		���� ����Ʈ�� ���� 
	Container _container;	 // ���ø����� ���� �迭�� ���� ����Ʈ ���� - �������̽� ������ ����
};

int main()
{
	Stack<int, vector<int>> s;

	// ����
	s.push(1);
	s.push(2);
	s.push(3);

	// ������ ������� Ȯ��
	while (s.empty() == false)
	{	
		// �ֻ��� ���� ã��
		int data = s.top();

		// �ֻ��� ���� ����
		s.pop();

		cout << data << endl;
	}

	// ���ÿ� �ִ� �������� ����
	int size = s.size();
}