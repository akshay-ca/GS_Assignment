* Instructions
1) Debug why the included test cases aren't succeeding and account for them in code

A description of the expected behavior is given below

Given two words returns the shortest distance between their two midpoints in number of characters
Words can appear multiple times in any order and should be case insensitive.

E.g. for the document="This is a sample document we just made up"
shortestDistance(document,"we","just")==4
shortestDistance(document,"is","a")==2.5
shortestDistance(document,"is","not")==-1

*Pseudo Code

#include<cmath>
#include<string>
#include<vector>
#include<boost/algorithm/string.hpp>

using namespace std;

double shortestDistance(const string& document, const string& word1, const string& word2) {
	vector<string> words;
	string Delimts(" .,");
	boost::split(words, document, boost::is_any_of(Delimts));

	int index = 0;
	double shortest = document.length();
	double word1_loc = 0;
	double word2_loc = 0;
	for (const string& word : words)
	{
		if (boost::iequals(word, word1)) {
			word1_loc = index + (word.length() / (double)2);
		}
		else if (boost::iequals(word, word2)) {
			word2_loc = index + (word.length() / (double)2);
		}
		if (word1_loc > 0 && word2_loc > 0) {
			double current = fabs(word1_loc - word2_loc);
			if (current < shortest) {
				shortest = current;
			}
		}
		index += word.length() + 1;
	}
	if (word1_loc == 0 || word2_loc == 0)
	{
		return -1;
	}
	return shortest;
}

TEST_CASE("Shortest distance in document"){
const string document =
		"In publishing and graphic design, lorem ipsum is a filler text commonly used to demonstrate the graphic elements"
		"of a document or visual presentation. Replacing meaningful content that could be distracting with placeholder text"
		"may allow viewers to focus on graphic aspects such as font , typography, and page layout.it laso reduces the need"
		"for the designer to come up with meaningful text,as they can instead use hastily generated lorem ipsum text. The"
		"lorem ipsum text is tipically a scrambled section of De finibus bonorum et malorum, a 1st-century BC latin text by"
		"Cicero, with words altered, added, and removed to make it nonsensical,improper latin. A variation of the ordinary"

		"lorem ipsum text has been used in typesetting since the 1960s or earlier, when it was popularized by advertisment"
		"for Letraset transfer sheets.It was introduce to the Information Age in the mid-1980s by Aldus corporation, which"
		"employed it in graphics and word processing templates for its desktop publishing program, PageMaker, for the Apple"
		"Macintosh. A common for of lorem ipsum reads: Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do"
		"eiusemod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation"
		"ullamco laboris nisi ut aliquip ex ea commodo consequat. duis aute irure dolor in reprehenderit in voluptate velit"
		"esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui"
		"officia deserunt mollit anim id est laborm."; 
	SECTION("Scenario #1") {
		REQUIRE(shortestDistance(document,"and","graphic")==6.0);
	}
	SECTION("Scenario #2") {
		REQUIRE(shortestDistance(document,"transfer","it")==14.0);
	}
	SECTION("Scenario #3") {
	REQUIRE(shortestDistance(document,"layout","it")==6.0);
	}
	SECTION("Scenario #4") {
		REQUIRE(shortestDistance(document,"Design","filler")==25.0);
	}
	SECTION("Scenario #5") {
		REQUIRE(shortestDistance(document,"it","transfer")==14.0);
	}
	SECTION("Scenario #6") {
		REQUIRE(fabs(shortestDistance(document,"of","lorem")-4.5)< 0.000001);
	}
	SECTION("Scenario #7") {
		REQUIRE(shortestDistance(document,"thiswordisnotthere","lorem")==-1.0);
	}
}