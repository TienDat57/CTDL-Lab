#include<iostream>

using namespace std;

int fib_recur(int n, int& count_assign, int& count_compare) {
	if (++count_compare && n <= 1)
		return 1;
	else
	return fib_recur(n - 1,++count_assign,count_compare) + fib_recur(n - 2,++count_assign, count_compare);
}

int fib(int n, int& count_assign, int& count_compare) {
	if (++count_compare && n <= 1)
		return 1;
	int last = 1; ++count_assign;
	int nextToLast = 1; ++count_assign;
	int answer = 1; ++count_assign;
	for (int i = 2; ++count_compare && i <= n; ++count_assign && i++) {
		answer = last + nextToLast; ++count_assign;
		nextToLast = last; ++count_assign;
		last = answer; ++count_assign;
	}
	return answer;
}

int main(int argc, char* argv[]) {
	if (argc < 2) cout << "Not enough arguments \n";
	else {
		int n = atoi(argv[1]);
		int ca = 0;
		int cc = 0;
		fib_recur(n, ca, cc);
		cout << "Assign counts = " << ca << endl;
		cout << "fib_recur(n) is O(" << cc << ")" << endl;

		ca = 0; cc = 0;
		fib(n, ca, cc);
		cout << "Assign counts = " << ca << endl;
		cout << "fib(n) is O(" << cc << ")" << endl;
	}
	return 0;
}