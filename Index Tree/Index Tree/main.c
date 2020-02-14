#include <stdio.h>
#define NUMBER 7

int tree[NUMBER];

// 1부터 N까지의 구간 합 구하기
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		// 마지막 비트만큼 빼면서 앞으로 이동
		i -= (i & -i);
	}
	return res;
}

// 특정 인덱스 수정하기
void update(int i, int dif) {
	while (i <= NUMBER) {
		tree[i] += dif;
		// 마지막 비트만큼 더하면서 뒤로 이동
		i += (i & -i);
	}
}

// 구간 합 계산 함수 구현하기
int getSection(int start, int end) {
	return sum(end) - sum(start - 1);
}

// 메인 함수
int main(void) {
	update(1, 7);
	update(2, 1);
	update(3, 9);
	update(4, 5);
	update(5, 6);
	update(6, 4);
	update(7, 1);
	printf("1부터 7까지의 구간 합: %d\n", getSection(1, 7));
	printf("인덱스 6의 원소를 +3만큼 수정\n");
	update(6, 3);
	printf("4부터 7까지의 구간 합: %d\n", getSection(4, 7));
	system("pause");
}
