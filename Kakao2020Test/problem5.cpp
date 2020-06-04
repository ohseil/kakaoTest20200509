#include "problem5.h"


bool problem5::solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	bool answer = true;

	map<int, int> pathMap;

	// order의 순서대로 시작.
	// 0번부터 첫번째 지점과 두번째 지점을 찾아간다.
	// 찾아가는 기법은 dfs?를 사용.
	// 찾는동안 경로를 저장해서 찾았을 때 거쳤던 지점 확인.
	// 다른 order의 두번째 지점이 없었는지 확인.
	// 이런식으로 모두 돌았을 때 걸리는 부분이 없다면 return true;
	// 걸리는게 있다면 return false.

	for (auto item : order) {

		// 첫번째 지점과 두번째 지점.
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