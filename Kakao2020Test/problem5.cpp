#include "problem5.h"


bool problem5::solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	bool answer = true;

	map<int, int> pathMap;

	// order�� ������� ����.
	// 0������ ù��° ������ �ι�° ������ ã�ư���.
	// ã�ư��� ����� dfs?�� ���.
	// ã�µ��� ��θ� �����ؼ� ã���� �� ���ƴ� ���� Ȯ��.
	// �ٸ� order�� �ι�° ������ �������� Ȯ��.
	// �̷������� ��� ������ �� �ɸ��� �κ��� ���ٸ� return true;
	// �ɸ��°� �ִٸ� return false.

	for (auto item : order) {

		// ù��° ������ �ι�° ����.
		int a = item[0];
		int b = item[1];

		vector<int> findPath;

		stack<int> dfs;

		dfs.push(0);

		while (dfs.top() != a) {

		}

		while (!dfs.empty()) {
			findPath.push_back(dfs.top());
			dfs.pop();
		}

		dfs.push(a);

		//while(dfs.)
	}

	return answer;
}

void problem5::execute() {


}