#include "problem3.h"

vector<int> problem3::solution(vector<string> gems) {

	vector<int> answer;

	set<string> s;
	map<string, int> m;

	for (string str : gems) {
		s.insert(str);
	}

	int a = 0, b = 0;

	bool isFirst = false;
	for (int i = 0; i < gems.size(); i++) {

		if (isFirst == false) {
			m[gems[i]]++;
			if (m.size() == s.size()) {
				// 모든 종류가 포함됨.
				b = i;

				for (int j = a; j < b; j++) {
					if (m[gems[j]] - 1 <= 0) {
						break;
					}
					else {
						// 빠져도 모든 종류 포함됨.
						m[gems[j]]--;
						a = j + 1;
					}
				}

				answer.push_back(a + 1);
				answer.push_back(b + 1);
				cout << "처음. " << a << "," << b << endl;
				isFirst = true;
			}
		}
		else {
			// 첫 길이가 완성 된 이후
			m[gems[a]]--;
			m[gems[i]]++;
			if (m[gems[a]] > 0) {
				a++;
				b = i;

				for (int j = a; j < b; j++) {
					if (m[gems[j]] - 1 <= 0) {
						break;
					}
					else {
						// 빠져도 모든 종류 포함됨.
						m[gems[j]]--;
						a = j + 1;
					}
				}

				if (answer[1] - answer[0] > b - a) {
					answer.push_back(a + 1);
					answer.push_back(b + 1);
					cout << "다음. " << a << "," << b << endl;
				}
			}
		}
	}

	return answer;
}


void problem3::execute() {

	vector<string> v;

	v.push_back("DIA");
	v.push_back("RUBY");
	v.push_back("RUBY");
	v.push_back("DIA");
	v.push_back("DIA");
	v.push_back("EMERALLD");
	v.push_back("SAPPHIRE");
	v.push_back("DIA");

	vector<int> vv = solution(v);
	cout << vv[0] << " " << vv[1] << endl;

}