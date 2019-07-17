#include<iostream>
#include<vector>
#include <algorithm>
#include<climits>
#include <string>
#include "heap.h"
using namespace std;

int main()
{
	string line;

	vector<string> names;
	vector<vector<int> > scores;

	string name;
	string score;
	int space;

	float sum = 0;
	float max = 0;
	string winner = " ";


	// Takes Input from the uses, saves it in k, scores, names !
	getline(cin, line);
	int k = stoi(line);
	int line_count = 0;

	while(getline(cin, line) && line_count<1)
	{
		if (line.empty())
		{
    		line_count++;
		}
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

	// Calculating top k average score of a student, ignoring student with < k scores.
	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i].size() >= k)
		{
			sum = 0;
			MaxHeap h(scores[i]); 
			h.buildHeap();
			for (int j=0; j<k; j++)
			{
				sum += h.deleteMax();
			}

			sum = sum/k;

			if (sum >= max)
			{
				max = sum;
				winner = names[i];
			}
		}
	}

	if (k>0)
	{
		if (winner != " ")
		{
			cout << winner << endl;
		}
		else
		{
			cout << "Error : No student with " << k << " test scores" << endl;
		}
	}
	else
	{
		cout << "Error : Invalid k = " << k << ", must be greater than 0" << endl;
	}

	return 0;
}