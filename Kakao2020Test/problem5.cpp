#include "problem5.h"

/*
	order의 모든 순서를 확인. (permutation 사용해서.)
	각 순서마다 path를 경유해서 탐색 수행.
	수행하면서 거쳐간 방 확인하고 표시.
	확인할 때 순서가 맞지 않았을 경우 break 하고 다음 순서로 넘어가기.
	탐색이 한번이라도 성공했을 경우 return true.
*/

// n = 방개수
bool problem5::solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	bool answer = false;

	map<int, vector<int>> pathMap;

	vector<int> check(n); // dfs 부분에서 방문 기록 초기화 할때 사용.

	for (auto a : path) {
		pathMap[a[0]].push_back(a[1]);
		pathMap[a[1]].push_back(a[0]);
	}

	// 상태 값 추가.
	// 0 : 한번도 안지나감. 1 : 첫번째 방 지나감. 2 : 두번째 방까지 모두 지나감.
	for (auto& a : order)
		a.push_back(0);

	sort(order.begin(), order.end());

	while (true) {

		// 각 루프마다 map 초기화.
		vector<vector<int>> orderMapTemp = order;
		
		bool isAnswerTop = true; // 정답이 있다는 flag.

		for (int i = 0; i < order.size(); i++) {

			// 방문기록 초기화
			vector<int> visited = check;

			int first = order[i][0]; // 첫번째 방
			int second = order[i][1]; // 두번째 방

			// 첫번째 방부터 방을 방문하기 위해 dfs 이용.

			deque<int> dq;
			dq.push_back(0);
			visited[0] = 1;

			while (true) {

				int top = dq.back();

				// 첫번째 방 도착 시 dfs 종료.
				if (top == first)
					break;

				// 다음 경로가 있는지에 관한 flag.
				bool isPath = false;

				for (auto a : pathMap[top]) {
					if (visited[a] == 0) {
						dq.push_back(a);
						visited[a] = 1;
						isPath = true;
						break;
					}
				}

				// 더이상 경로가 없다면 이전 경로로 되돌아가기.
				if (isPath == false)
					dq.pop_back();
			}


			bool isAnswer = true;

			while (!dq.empty()) {

				int front = dq.front();
				dq.pop_front();

				bool isAnswerInternal = true;

				for (auto& a : orderMapTemp) {

					if (front == a[0]) {
						// 방문한 방이 order의 첫번째 방일 경우
						// 이 경우에는 현재 order가 두번 방문한 상태가 아니라면
						// 첫번째 방을 방문했다고 표시.
						if (a[2] != 2)
							a[2] = 1;
					}
					else if (front == a[1]) {
						// 방문한 방이 order의 두번째 방일 경우
						// 이 경우에는 상태가 1이나 2 라면 상태를 2로 표시.
						// 0 이라면 현재 방문 탐색 순서로는 실패.
						if (a[2] == 0) {
							isAnswerInternal = false;
							break;
						}
						else
							a[2] = 2;
					}
				}

				if (isAnswerInternal == false) {
					isAnswer = false;
					break;
				}
			}

			if (isAnswer == false) {
				isAnswerTop = false;
				break;
			}

			// 첫번째 방을 시작으로 두번째 방 찾아가기.
			dq.clear();
			dq.push_back(first);
			visited = check;
			visited[first] = 1;

			while (true) {

				int top = dq.back();

				if (top == second)
					break;

				bool isPath = false;

				for (auto a : pathMap[top]) {
					if (visited[a] == 0) {
						dq.push_back(a);
						visited[a] = 1;
						isPath = true;
						break;
					}
				}

				if (isPath == false) {
					dq.pop_back();
				}
			}

			isAnswer = true;

			while (!dq.empty()) {
				int front = dq.front();
				dq.pop_front();

				bool isAnswerInternal = true;

				for (auto& a : orderMapTemp) {
					if (front == a[0]) {
						if (a[2] != 2)
							a[2] = 1;
					}
					else if (front == a[1]) {
						if (a[2] == 0) {
							isAnswerInternal = false;
							break;
						}
						else {
							a[2] = 2;
						}
					}
				}

				if (isAnswerInternal == false) {
					isAnswer = false;
					break;
				}
			}

			if (isAnswer == false) {
				isAnswerTop = false;
				break;
			}

		}

		if (isAnswerTop == true) {
			answer = true;
			break;
		}

		if (next_permutation(order.begin(), order.end()) == false)
			break;
	}

	

	return answer;
}

void problem5::execute() {

	int n = 9;
	vector<vector<int>> path, order;

	vector<int> p;
	p.push_back(8); p.push_back(1); path.push_back(p);
	p[0] = 0; p[1] = 1; path.push_back(p);
	p[0] = 1; p[1] = 2; path.push_back(p);
	p[0] = 0; p[1] = 7; path.push_back(p);
	p[0] = 4; p[1] = 7; path.push_back(p);
	p[0] = 0; p[1] = 3; path.push_back(p);
	p[0] = 7; p[1] = 5; path.push_back(p);
	p[0] = 3; p[1] = 6; path.push_back(p);

	vector<int> o;
	o.push_back(4); o.push_back(1); order.push_back(o);
	o[0] = 8; o[1] = 7; order.push_back(o);
	o[0] = 6; o[1] = 5; order.push_back(o);

	cout << solution(n, path, order) << endl;

}