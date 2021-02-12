Instructions to the candidate.
1) Run this code in REPL to observe it's behaviour . The execution entry point is main()
2) Consider adding some additional tests in doTestsPass()
3) Implement findTopIpAddress() correctly
4) if time permits,try to improve your implementation.

Psuedo Code:

#include<cassert>
#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
  
/*  string findTopIpaddress(vector<string>lines)
 * Given an Apache log file, return IP address(es) which accesses the site most often.

 * Our log file is in this format(common Log Format). One entry for line and it starts with an IP address which accessed the site,
  followed by a whitespace.

 * 10.0.0.1  -frank [10/Dec/2000:12:34:56 -0500] " GET /a.gif HTTP/1.0" 200 234

 * Log file entries are passed as a vector */

string findTopAddress(vector<string> lines) {
    //todo: implement logic
    return "10.0.0.1";
}

/** void dotestspass()   
  *returns 1 if the test passes, otherwise retun 0 */

int doTestspass() {
	//todo: implement some tests
	vector<string> lines;
	lines.push_back("10.0.0.1 - frank [10/Dec/2000:12:34:56 - 0500] \"GET /a.gif HTTP/1.0\ " 200 234");
	lines.push_back("10.0.0.1 - frank [10/Dec/2000:12:34:57 - 0500] \"GET /b.gif HTTP/1.0\ " 200 234");
	lines.push_back("10.0.0.2 - nancy [10/Dec/2000:12:34:58 - 0500] \"GET /c.gif HTTP/1.0\ " 200 234");
	
	string result = findTopIpAddress(lines);
	if(result.compare("10.0.0.1")==0) {
		cout<< "test passed" << endl;
		return 1;
	}else {
	    cout<<"test failed"<<endl;
	    return 0;
	}
}

int main() {
	exit (doTestsPass());
}