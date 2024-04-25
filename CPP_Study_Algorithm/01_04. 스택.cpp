#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

// 자료구조 "stack"(LIFO, Last-In-First-Out, 후입선출)
// 데이터는 한쪽 방향으로만 쌓이고 데이터의 제거는 마지막에 할당된 데이터부터 제거된다.
// 가장 최근에 들어온 데이터가 가장 먼저 나간다.

// stack의 기능
// .push(value)	: 최상위 원소 뒤에 데이터 삽입
// .pop()		: 최상위 원소 제거
// .top()		: 최상위 원소 찾기(.top()과 .pop()은 짝으로 기억한다. 찾은 다음 제거)
// .size()		: 스택에 있는 데이터 개수(int)
// .empty()		: 스택이 비어있는지 확인(true, false)

// ex) 되돌리기 기능 - Undo(Ctrl + Z)

// 스택 구현 연습
// 마지막의 데이터를 넣고 빼는 기능을 할 수 있다면 
// 동적 배열이나 연결 리스트를 활용할 수 있다.
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
	// vector<T> _container;	동적 배열을 랩핑
	// list<T> _container;		연결 리스트를 랩핑 
	Container _container;	 // 템플릿으로 동적 배열과 연결 리스트 선택 - 인터페이스 통일의 장점
};

int main()
{
	Stack<int, vector<int>> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);

	// 스택이 비었는지 확인
	while (s.empty() == false)
	{	
		// 최상위 원소 찾기
		int data = s.top();

		// 최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	// 스택에 있는 데이터의 개수
	int size = s.size();
}