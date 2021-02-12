#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string ExtractIPAddress(const string & str) {
	return str.substr(0, str.find(' '));
}

string findTopIpAddress(vector<string> & lines) {
	unordered_map<string, size_t> StrMap;

	string TempStr;
	for (const string & str : lines){
		TempStr = ExtractIPAddress(str);
		++StrMap[TempStr];
	}
	size_t MaxCount = 0;
	for (const auto & MapElement : StrMap) {
		if (MapElement.second > MaxCount) {
			MaxCount = MapElement.second;
			TempStr = MapElement.first;
		}
	}
	return TempStr;
}

int doTestsPass() {

	// todo: implement some tests
	vector<string> lines;
	lines.emplace_back("10.0.0.1 - frank [10/Dec/2000:12:34:56 - 0500] \"GET /a.gif HTTP/1.0\" 200 234");
	lines.emplace_back("10.0.0.1 - frank [10/Dec/2000:12:34:57 - 0500] \"GET /b.gif HTTP/1.0\" 200 234");
	lines.emplace_back("10.0.0.2 - nancy [10/Dec/2000:12:34:58 - 0500] \"GET /c.gif HTTP/1.0\" 200 234");

	string result = findTopIpAddress(lines);
	if (result.compare("10.0.0.1") == 0) {
		cout << "test passed" << endl;
		return 1;
	}
	else {
		cout << "test failed" << endl;
		return 0;
	}
}

int main() 
{
	exit(doTestsPass());
}