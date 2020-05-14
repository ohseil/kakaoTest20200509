#include "problem4.h"

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int problem4::solution(vector<vector<int>> board) {

	int answer = 0;

	vector<vector<int>> check;

	int size = board.size();

	for (int i = 0; i < size; i++) {
		vector<int> v;
		for (int j = 0; j < size; j++) {
			v.push_back(0);
		}
		check.push_back(v);
	}

	stack<pair<int, pair<int, int>>> st;
	st.push(make_pair(-1, make_pair<int, int>(0, 0)));

	while (!st.empty())
	{
		pair<int, pair<int, int>> data = st.top();
		st.pop();

		for (int i = 0; i < 4; i++)
		{
			// i=0 : y + 1
			// i=1 : y - 1
			// i=2 : x + 1
			// i=3 : x - 1
			int y = data.second.first + dy[i];
			int x = data.second.second + dx[i];

			if ((0 <= x && x <= size - 1) && (0 <= y && y <= size - 1))
			{
				if (board[y][x] == 0)
				{

					int value = 0;

					if (data.first == -1) {
						// 처음 시작
						value = check[data.second.first][data.second.second] + 100;
					}
					else if (data.first == i) {
						// 직선
						value = check[data.second.first][data.second.second] + 100;
					}
					else {
						// 꺾임
						value = check[data.second.first][data.second.second] + 600;
					}

					if (check[y][x] == 0 || value <= check[y][x]) {
						check[y][x] = value;
						st.push(make_pair(i, make_pair<int&, int&>(y, x)));
						cout << "  push x: " << x << " y: " << y << " i: " << i << endl;
					}
				}
			}
		}
	}

	cout << endl << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	return answer;
}

void problem4::execute() {

	vector<vector<int>> v;
	vector<int> vv;
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	v.push_back(vv);
	vv.clear();
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	v.push_back(vv);
	vv.clear();
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	v.push_back(vv);
	vv.clear();
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	v.push_back(vv);
	vv.clear();
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	v.push_back(vv);
	vv.clear();
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	v.push_back(vv);
	vv.clear();
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	v.push_back(vv);
	vv.clear();
	vv.push_back(1);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	vv.push_back(0);
	v.push_back(vv);

	solution(v);
}