#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// [!] ���� Ž�� Ʈ��

// ���� Ž��(binary search)
// �ð� ���⵵ : O(log N)
// '���ĵǾ� �ִ� ������'���� Ư���� ���� ã�Ƴ��� �˰���
// Ž�� ������ ������ ������, ã�� ���� �����ϴ� ������ �������� ���

// '���ĵ� �迭'�� �̿��ϸ� ���� Ž�� �����ϴ�. 
// ������, ���ĵ� ���� ����Ʈ�δ� �Ұ�(���� ������ ��ȿ�����̱� ����)
// �ٸ�, �߰� ���� / ������ ������. - ���� Ž���� �Ѱ� - ���� Ž�� Ʈ���� �ʿ伺

// Q) 82��� ���ڰ� �迭�� �ִ°�?
vector<int> numbers;

void BinarySearch(int number)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		cout << "Ž�� ���� : " << left << " ~ " << right << endl;
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
			cout << "ã��" << endl;
			break;
		}
	}
}

int main()
{
	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(82);
}
