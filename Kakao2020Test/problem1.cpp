#include "problem1.h"

int problem1::calculateDistance(pair<int, int> a, pair<int, int> b) {

	int result = 0;

	int x1 = a.first, x2 = b.first;
	int y1 = a.second, y2 = b.second;

	result = abs(x1 - x2) + abs(y1 - y2);

	return result;
}

string problem1::solution(vector<int> numbers, string hand) {

	string answer = "";

	// 왼손, 오른손 위치 초기화
	pair<int, int> lPos = make_pair(0, 0);
	pair<int, int> rPos = make_pair(2, 0);

	// 키패드의 위치를 저장해 놓는 맵
	map<int, pair<int, int>> m;

	m.insert(make_pair(1, make_pair(0, 3)));
	m.insert(make_pair(2, make_pair(1, 3)));
	m.insert(make_pair(3, make_pair(2, 3)));
	m.insert(make_pair(4, make_pair(0, 2)));
	m.insert(make_pair(5, make_pair(1, 2)));
	m.insert(make_pair(6, make_pair(2, 2)));
	m.insert(make_pair(7, make_pair(0, 1)));
	m.insert(make_pair(8, make_pair(1, 1)));
	m.insert(make_pair(9, make_pair(2, 1)));
	m.insert(make_pair(0, make_pair(1, 0)));

	for (int num : numbers) {

		if (num == 1 || num == 4 || num == 7) {
			answer += "L";
			lPos = m[num];
		}
		else if (num == 3 || num == 6 || num == 9) {
			answer += "R";
			rPos = m[num];
		}
		else {
			if (calculateDistance(lPos, m[num]) < calculateDistance(rPos, m[num])) {
				answer += "L";
				lPos = m[num];
			}
			else if (calculateDistance(lPos, m[num]) > calculateDistance(rPos, m[num])) {
				answer += "R";
				rPos = m[num];
			}
			else {
				// 왼손과 오른손의 거리가 같은 경우
				if (hand == "left") {
					answer += "L";
					lPos = m[num];
				}
				else {
					answer += "R";
					rPos = m[num];
				}
			}
		}

	}

	return answer;
}

void problem1::execute() {


	vector<int> nums;
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(8);
	nums.push_back(2);
	nums.push_back(8);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(6);
	nums.push_back(2);
	cout << problem1::solution(nums, "left") << endl;
}