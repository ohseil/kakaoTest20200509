#include "problem5.h"

/*
	order�� ��� ������ Ȯ��. (permutation ����ؼ�.)
	�� �������� path�� �����ؼ� Ž�� ����.
	�����ϸ鼭 ���İ� �� Ȯ���ϰ� ǥ��.
	Ȯ���� �� ������ ���� �ʾ��� ��� break �ϰ� ���� ������ �Ѿ��.
	Ž���� �ѹ��̶� �������� ��� return true.
*/

// n = �氳��
bool problem5::solution(int n, vector<vector<int>> path, vector<vector<int>> order) {

	bool answer = false;

	map<int, vector<int>> pathMap;

	vector<int> check(n); // dfs �κп��� �湮 ��� �ʱ�ȭ �Ҷ� ���.

	for (auto a : path) {
		pathMap[a[0]].push_back(a[1]);
		pathMap[a[1]].push_back(a[0]);
	}

	// ���� �� �߰�.
	// 0 : �ѹ��� ��������. 1 : ù��° �� ������. 2 : �ι�° ����� ��� ������.
	for (auto& a : order)
		a.push_back(0);

	sort(order.begin(), order.end());

	while (true) {

		// �� �������� map �ʱ�ȭ.
		vector<vector<int>> orderMapTemp = order;
		
		bool isAnswerTop = true; // ������ �ִٴ� flag.

		for (int i = 0; i < order.size(); i++) {

			// �湮��� �ʱ�ȭ
			vector<int> visited = check;

			int first = order[i][0]; // ù��° ��
			int second = order[i][1]; // �ι�° ��

			// ù��° ����� ���� �湮�ϱ� ���� dfs �̿�.

			deque<int> dq;
			dq.push_back(0);
			visited[0] = 1;

			while (true) {

				int top = dq.back();

				// ù��° �� ���� �� dfs ����.
				if (top == first)
					break;

				// ���� ��ΰ� �ִ����� ���� flag.
				bool isPath = false;

				for (auto a : pathMap[top]) {
					if (visited[a] == 0) {
						dq.push_back(a);
						visited[a] = 1;
						isPath = true;
						break;
					}
				}

				// ���̻� ��ΰ� ���ٸ� ���� ��η� �ǵ��ư���.
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
						// �湮�� ���� order�� ù��° ���� ���
						// �� ��쿡�� ���� order�� �ι� �湮�� ���°� �ƴ϶��
						// ù��° ���� �湮�ߴٰ� ǥ��.
						if (a[2] != 2)
							a[2] = 1;
					}
					else if (front == a[1]) {
						// �湮�� ���� order�� �ι�° ���� ���
						// �� ��쿡�� ���°� 1�̳� 2 ��� ���¸� 2�� ǥ��.
						// 0 �̶�� ���� �湮 Ž�� �����δ� ����.
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

			// ù��° ���� �������� �ι�° �� ã�ư���.
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