#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* CreateRandomNums();
void GetStrikeAndBall(int nums1[4], int nums2[4], int* strike, int* ball);

void main() {
	int* ranNums;
	int answer[4]; 
	int strike;
	int ball;

	srand((unsigned int)time(NULL));
	
	ranNums = CreateRandomNums();

	//테스트 코드
	/*printf("테스트 중, 정답 : ");
	for (int i = 0; i < 4; i++) {
		printf("%d", ranNums[i]);
	}
	printf("\n");*/

	printf("숫자를 입력하세요. ex)0 1 2 3\n");
	
	while(1) {
		strike = 0;
		ball = 0;
		
		scanf_s("%d %d %d %d", &answer[0], &answer[1], &answer[2], &answer[3]);
		
		GetStrikeAndBall(ranNums, answer, &strike, &ball);

		printf("strike : %d\n", strike);
		printf("ball : %d\n\n", ball);

		if (strike == 4) {
			printf("정답입니다.\n");
			break;
		}
	}
	system("PAUSE");
}

int* CreateRandomNums() {
	static int ranNums[4]; // C는 지역 변수의 반환을 지원하지 않습니다.
	int doubleCheck;

	for (int i = 0; i < 4; i++) {
		doubleCheck = 0;
		ranNums[i] = rand() % 10;
		for (int j = 0; j < i; j++) {
			if (ranNums[i] == ranNums[j]) {
				doubleCheck = 1;
				break;
			}
		}

		if (doubleCheck == 1) {
			i--;
			continue;
		}
	}
	return ranNums;
}

void GetStrikeAndBall(int nums1[4], int nums2[4], int* strike, int* ball) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j && nums1[i] == nums2[j]) {
				*strike = *strike + 1;
				break;
			}
			else if (nums1[i] == nums2[j]) {
				*ball = *ball + 1;
				break;
			}
		}
	}
}