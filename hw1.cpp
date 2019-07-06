#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
	string line;
	vector<string> v;

	int line_count = 0;
	while(getline(cin, line) && line_count<1)
	{
    	if (line.empty())
    		line_count++;
    	v.push_back(line);
	}

	cout << "Output:" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}