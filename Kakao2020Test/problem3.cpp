#include "problem3.h"

vector<int> problem3::solution(vector<string> gems) {

	vector<int> answer;

	set<string> s;
	map<string, int> m;

	for (string str : gems) {
		s.insert(str);
	}

	int a = 0, b = 0, length = 0;

	answer.push_back(0);
	answer.push_back(gems.size());

	bool plusFlag = false;

	while (true) {

		if (m.size() == s.size()) {
			m[gems[a]]--;
			if (m[gems[a]] <= 0)
				m.erase(gems[a]);
			a++;
			plusFlag = false;
		}
		else if (b == gems.size()) {
			break;
		}
		else if (m.size() != s.size()) {
			m[gems[b]]++;
			plusFlag = true; // b++ ÀÌ¶ó´Â flag.
		}

		if (m.size() == s.size()) {
			if (answer[1] - answer[0] > b - a) {
				answer.clear();
				answer.push_back(a + 1);
				answer.push_back(b + 1);
			}
		}
		else {
			b++;
		}

	}

	return answer;
}


void problem3::execute() {

	vector<string> v;

	v.push_back("ZZZ");
	v.push_back("YYY");
	v.push_back("NNNN");
	v.push_back("YYY");
	v.push_back("BBB");
	//v.push_back("EMERALLD");
	//v.push_back("SAPPHIRE");
	//v.push_back("DIA");

	vector<int> vv = solution(v);
	cout << vv[0] << " " << vv[1] << endl;

}