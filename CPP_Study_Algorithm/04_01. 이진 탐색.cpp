#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// [!] 이진 탐색 트리

// 이진 탐색(binary search)
// 시간 복잡도 : O(log N)
// '정렬되어 있는 데이터'에서 특정한 값을 찾아내는 알고리즘
// 탐색 범위를 반으로 나누어, 찾는 값을 포함하는 범위를 좁혀가는 방식

// '정렬된 배열'을 이용하면 이진 탐색 가능하다. 
// 하지만, 정렬된 연결 리스트로는 불가(임의 접근이 비효율적이기 때문)
// 다만, 중간 삽입 / 삭제는 느리다. - 이진 탐색의 한계 - 이진 탐색 트리의 필요성

// Q) 82라는 숫자가 배열에 있는가?
vector<int> numbers;

void BinarySearch(int number)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		cout << "탐색 범위 : " << left << " ~ " << right << endl;
		int middle = (left + right) / 2;

		if (number < numbers[middle])
		{
			cout << number << " < " << numbers[middle] << endl;
			right = middle - 1;
		}
		else if (number > numbers[middle])
		{
			cout << number << " > " << numbers[middle] << endl;
			left = middle + 1;
		}
		else
		{
			cout << "찾음" << endl;
			break;
		}
	}
}

int main()
{
	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(82);
}
