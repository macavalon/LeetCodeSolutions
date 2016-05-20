
#include <string>
#include <unordered_set>

using namespace std;

class test127_wordladder {
	struct node {
			string val;
			int depth;
			node(string val = "", int depth = 0) {
				this->val = val;
				this->depth = depth;
			}
		};

public:
	test127_wordladder() {};
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList);
};