#include "TopN.h"

using namespace std;

class TopN {
private:
	vector<pair<int, int>> TableN;
	int NumOfEntries;
public:
	TopN(int Num) {
		NumOfEntries = Num;
		for (int i = 0; i <= NumOfEntries + 1; i++)
			TableN.push_back(make_pair(0, 0));
		TableN[0] = make_pair(1000000, 1000000);
	};

	~TopN() {
	};

	void TestChange() {
		for (int i = 0; i <= NumOfEntries + 1; i++)
			TableN[i] = make_pair(i, 2 * i);
	}

	static bool TopNCmp(pair<int, int> n1, pair<int, int> n2) {
		return (n1.second > n2.second);
	}

	void TSort() {
		sort(&TableN[1], &TableN[NumOfEntries], &TopNCmp);
	}

	void TOut() {
		for (int i = 1; i <= NumOfEntries; i++) {
			cout << TableN[i].first << " " << TableN[i].second << endl;
		}
	}
};
