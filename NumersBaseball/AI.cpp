#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

vector<int*> SetAllCaseNums();
bool CheckOverlap(int* nums);
vector<int*> RemoveElements(vector<int*> list, int nums[4], int strike, int ball);
void GetStrikeAndBall(int nums1[4], int nums2[4], int* strike, int* ball);

int main() {
	vector<int*> allCaseNums = SetAllCaseNums();
	int strike, ball;

	while (allCaseNums.size() != 1) {
		printf("AI : ");
		for (int i = 0; i < 4; i++)
			printf("%d", allCaseNums[0][i]);
		printf("\n");

		strike = 0;
		ball = 0;

		printf("strike : ");
		scanf_s("%d", &strike);

		printf("ball : ");
		scanf_s("%d", &ball);
		printf("\n");

		allCaseNums = RemoveElements(allCaseNums, allCaseNums[0], strike, ball);
	}

	printf("AI : 정답은 ");
	for (int i = 0; i < 4; i++)
		printf("%d", allCaseNums[0][i]);
	printf("입니다.\n");

	system("PAUSE");
	return 0;
}

vector<int*> SetAllCaseNums() {
	vector<int*> allCaseNums;
	string strNums = "0123";
	int nums = 0;
	int* pNums = new int[4] {0, 1, 2, 3};
	allCaseNums.push_back(pNums);

	while(nums < 9876) {
		// 숫자 증가
		nums = stoi(strNums);	 // string to int
		strNums = to_string(++nums); // int to string

		// 3자리면 앞자리에 0 추가
		if (strNums.length() == 3) {
			strNums.insert(0, "0");
		}

		// 배열화
		pNums = new int[4];
		for (int i = 0; i < 4; i++) {
			pNums[i] = strNums[i] - '0';
		}

		// 중복 체크
		if (CheckOverlap(pNums)) {
			continue;
		}

		// 리스트에 저장
		allCaseNums.push_back(pNums); 
	}

	return allCaseNums;
}

bool CheckOverlap(int* nums) {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (nums[i] == nums[j]) {
				return true;
			}
		}
	}
	return false;
}

vector<int*> RemoveElements(vector<int*> list, int nums[4], int strike, int ball) {
	for (int i = 0; i < list.size(); i++) {
		int tempStrike = 0, tempBall = 0;
		GetStrikeAndBall(list[i], nums, &tempStrike, &tempBall);

		if (strike != tempStrike || ball != tempBall) {
			list.erase(list.begin() + i);
			i--; // 한 칸 삭제해서 한 칸 밂
		}
	}
	return list;
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