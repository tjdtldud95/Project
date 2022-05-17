#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include<algorithm>
using namespace std;



string a(string s)
{
	string answer = s;
	int len = answer.size();
	answer[0] = toupper(answer[0]);
	
	for (int i = 1; i < len; i++)
	{
		answer[i - 1] == ' ' ? answer[i] = toupper(answer[i]) : answer[i] = tolower(answer[i]);
	}

	return answer;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//solution(9, { 0,0,1,2,0,1,1,1,1,1,1 });
	cout << a(" ");
	return 0;
}