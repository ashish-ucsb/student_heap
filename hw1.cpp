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

	vector<string> names;
	vector<vector<int> > scores;

	string name;
	string score;
	int space;


	// Takes Input from the uses, saves it in k, scores, names !
	getline(cin, line);
	int k = stoi(line);
	int line_count = 0;

	while(getline(cin, line) && line_count<1)
	{
		if (line.empty())
    		line_count++;
    	else
    	{
    		space = line.find(' ');
    		name = line.substr(0, space);
    		score = line.substr(space+1);

    		vector<string>::iterator it = find(names.begin(), names.end(), name);

    		if (it != names.end()) // Element Found
    		{
    			int index = distance(names.begin(), it);
    			(scores[index]).push_back(stoi(score));
    		}
    		else // Element Not Found
    		{
    			vector<int> temp;
    			names.push_back(name);
    			temp.push_back(stoi(score));
    			scores.push_back(temp);
    		}
    	}
	}

	cout << "K = " << k << endl;

	cout << "Names:" << endl;
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << endl;
	}

	cout << "Scores:" << endl;
	for (int i = 0; i < scores.size(); i++)
	{
		for (int j = 0; j < scores[i].size(); j++)
		{
			cout << scores[i][j]  << " ";
		}
		cout << endl;
	}

	return 0;
}