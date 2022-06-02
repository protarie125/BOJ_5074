#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string a, b;
	cin >> a >> b;
	while ("00:00" != a || "00:00" != b) {
		auto iss1 = istringstream{ a.substr(0, 2) };
		int h1;
		iss1 >> h1;

		auto iss2 = istringstream{ a.substr(3, 2) };
		int m1;
		iss2 >> m1;

		auto iss3 = istringstream{ b.substr(0, 2) };
		int h2;
		iss3 >> h2;

		auto iss4 = istringstream{ b.substr(3, 2) };
		int m2;
		iss4 >> m2;

		auto n = int{ 0 };

		auto h = h1 + h2;
		auto m = m1 + m2;

		if (60 <= m) {
			m -= 60;
			h += 1;
		}

		n = h / 24;
		h %= 24;

		cout << setw(2) << setfill('0') << h << ":"
			<< setw(2) << setfill('0') << m;
		if (0 < n) {
			cout << " +" << n;
		}
		cout << '\n';

		cin >> a >> b;
	}

	return 0;
}