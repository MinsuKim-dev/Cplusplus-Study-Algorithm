#include <iostream>

// 선형 자료구조

// 선형과 비선형
// 1. 선형 구조
// 선형 구조는 자료를 순차적으로 나열한 형태
// 배열, 연결 리스트, 스택 / 큐

// 2. 비선형 구조
// 비선형 구조는 하나의 자료 뒤에 다수의 자료가 올 수 있는 형태
// 트리, 그래프

// ---------------------------------------------------------------------
// 배열, 동적 배열, 연결 리스트
// 가정: 호텔의 방을 예약하는 상황]
// 호텔 = 메모리(RAM)
// 방 = 데이터

// ---------------------------------------------------------------------
// 배열
// 1. 사용할 방 개수를 고정해서 계약하고(절대 변경 불가)
// 2. 연속된 방으로 배정 받아 사용
// 장점 : 연속된 방
// 단점 : 방을 추가하거나 축소할 수 없다.

// ---------------------------------------------------------------------
// 동적 배열
// 1. 사용할 방 개수를 유동적으로 계약
// 2. 연속된 방으로 배정 받아 사용
// 3. 문제점 : 이사 비용은 어떻게?

// 동적 배열 메모리 할당 정책
// 실제로 사용할 방보다 많이, 여유분을 두고 예약(대략 1.5 ~ 2배)
// 이사 횟수를 최소화

// 동적 배열의 장, 단점
// 장점 : 유동적인 계약(방 여유분 추가 예약으로 이사 횟수 최소화)
// 단점 : 중간 삽입, 삭제

// ---------------------------------------------------------------------
// 연결 리스트
// 1. 연속되지 않은 방을 사용
// 장점 : 중간 삽입, 삭제에 이점
// 단점 : N 번째 방을 바로 찾을 수 없음(임의 접근, Random Access 불가)

int main()
{

}