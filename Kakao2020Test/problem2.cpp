#include "problem2.h"

long long problem2::calculate(long long a, long long b, char cal) {
	long long result = 0;

	switch (cal) {
	case '*':
		result = a * b;
		break;
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	}

	return result;
}

long long problem2::solution(string expression) {

	long long answer = 0;

	map<int, char> m;

	vector<char> v;
	vector<string> vv;

	int poscheck = 0;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-') {
			bool isValue = false;
			for (char check : v)
				if (check == expression[i]) {
					isValue = true;
					break;
				}
			if (isValue == false)
				v.push_back(expression[i]);

			string tempNum = "";
			for (int j = poscheck; j < i; j++)
				tempNum += expression[j];
			vv.push_back(tempNum);

			string tempCal = "";
			tempCal += expression[i];
			vv.push_back(tempCal);

			poscheck = i + 1;

		}

		if (i == expression.length() - 1) {
			string tempNum = "";
			for (int j = poscheck; j < expression.length(); j++)
				tempNum += expression[j];
			vv.push_back(tempNum);
		}
	}

	sort(v.begin(), v.end());

	while (next_permutation(v.begin(), v.end())) {

		queue<string> q;

		for (string str : vv)
			q.push(str);

		for (char ch : v) {

			string tempNum;
			bool isTempNum = false;

			while (!q.empty()) {

				string curNum = q.front();
				q.pop();

				if (isTempNum == true) {
					curNum = to_string(calculate(stoll(tempNum), stoll(curNum), ch));
					isTempNum = false;
					tempNum = "";
				}

				if (q.empty()) {
					long long temp = abs(stoll(curNum));
					if (answer < temp)
						answer = temp;
					break;
				}

				string curCal = q.front();
				if (curCal.length() > 1 || (curCal[0] != '*' && curCal[0] != '+' && curCal[0] != '-')) {
					q.push(curNum);
					break;
				}
				q.pop();

				if (curCal[0] == ch) {
					tempNum = curNum;
					isTempNum = true;
				}
				else {
					q.push(curNum);
					q.push(curCal);
				}
			}

		}
	}

	return answer;
}

void problem2::execute() {

	string expression = "100-200*300-500+20";

	vector<char> v;

	cout << solution(expression) << endl;

}