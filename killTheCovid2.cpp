#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
typedef long long int ll;

vector<vector<double> >arr(6, vector<double>(2, 0));
class Hexagon
{
public:
	string nameOfHexagon;
	vector<Hexagon*>neighbors;
	double x, y;
	Hexagon(string name)
	{
		nameOfHexagon = name;
		for (int i = 0; i < 6; i++)
			neighbors.push_back(NULL);
	}
};
void getNeighbors(string name, unordered_map<string, Hexagon*>&m)
{
	if(m.count(name)==0)
	{
		cout<<"No such Hexagon present"<<endl;
		return;
	}
	Hexagon * currHexagon = m[name];
	int i, flag = 0;
	for (i = 0; i < 6; i++)
	{
		Hexagon * tempHexagon = (currHexagon->neighbors)[i];
		if (tempHexagon != NULL)
		{
			if (flag == 0)
			{
				flag = 1;
				cout << "[(" << i << "," << tempHexagon->nameOfHexagon << ")";
			}
			else
				cout << ", (" << i << "," <<  tempHexagon->nameOfHexagon << ")";
		}
	}
	if (flag == 1)
		cout << "]" << endl;
	else
		cout << "It does not have any neighbors" << endl;

}
void addHexagon(string name, pair<double, double>cd, unordered_map<string, Hexagon*>&m, unordered_map<string , Hexagon*>&m2)
{
	Hexagon * currHexagon = new Hexagon(name);
	m[name] = currHexagon;
	currHexagon->x = cd.f;
	currHexagon->y = cd.s;

	string t = to_string(cd.f) + " " + to_string(cd.s);
	m2[t] = currHexagon;
	pair<double, double>temp;
	int i;
	for (i = 0; i <= 5; i++)
	{
		//cout<<"In the loop"<<endl;
		temp.f = currHexagon->x + arr[i][0];
		temp.s = currHexagon->y + arr[i][1];
		string temp2 = to_string(temp.f) + " " + to_string(temp.s);
		
		//cout<<temp2<<endl; 
		
		if (m2.count(temp2) != 0)
		{
			Hexagon * nr = m2[temp2]; //nr means neighbor
			(nr->neighbors)[(i + 3) % 6] = currHexagon;
			(currHexagon->neighbors)[i] = nr;
		//	cout<<"Hello i neighbour added"<<endl;
		}
	}

}
void dfs(string name, unordered_map<string, Hexagon*>&m, unordered_map<string, bool>&vis)
{
	int i;
	Hexagon * currHexagon = m[name];
	for (i = 0; i <= 5; i++)
	{
		if ((currHexagon->neighbors)[i] != NULL && 	vis[(currHexagon->neighbors)[i]->nameOfHexagon] == false)
		{
			vis[(currHexagon->neighbors)[i]->nameOfHexagon] = true;
			dfs((currHexagon->neighbors)[i]->nameOfHexagon, m, vis);
		}
	}
}
void removeHexagon(string name, unordered_map<string, Hexagon*>&m, unordered_map<string , Hexagon*>&m2)
{
	Hexagon * currHexagon;
	if (m.count(name) != 0)
		currHexagon = m[name];
	else
	{
		cout << "No such Hexagon present" << endl;
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if ((currHexagon->neighbors)[i] != NULL)
		{
			Hexagon * tempHexagon = (currHexagon->neighbors)[i];
			(tempHexagon->neighbors)[(i + 3) % 6] = NULL;
			(currHexagon->neighbors)[i] = NULL;
		}
	}
	pair<double, double>cd;

	cd.f = currHexagon->x;
	cd.s = currHexagon->y;

	string t = to_string(cd.f) + " " + to_string(cd.s);

	m2.erase(t);
	m.erase(name);
	delete (currHexagon);

	unordered_map<string, bool>vis;
	int j;
	int count = 0;
	for (auto it : m)
	{
		if (vis.count(it.first) == 0)
		{
			vis[it.first] = true;
			dfs(it.first, m, vis);
			count++;
		}
		if (count == 2)
			break;
	}
	if (count == 2)
	{
		addHexagon(name, cd, m, m2);
		cout << "Deletion will result in more than 1 cluster" << endl;
	}
	else
		cout << "Successfully deleted" << endl;
}
int main()
{

	arr[0][0] = 0.000000;
	arr[0][1] = sqrt(3.0);
	arr[1][0] = (3.0 / 2);
	arr[1][1] = sqrt(3.0) / 2;
	arr[2][0] = (3.0 / 2);
	arr[2][1] = (-1) * (sqrt(3.0) / 2);
	arr[3][0] = 0.000000;
	arr[3][1] = (-1) * sqrt(3.0);
	arr[4][0] = (-1) * (3.0 / 2);
	arr[4][1] = (-1) * (sqrt(3.0) / 2);
	arr[5][0] = (-1) * (3.0 / 2);
	arr[5][1] = sqrt(3.0) / 2;

	unordered_map<string, Hexagon*>m;
	unordered_map< string , Hexagon*>m2;
	int temp;
	temp = 1;
	while (temp)
	{
		cout << endl;
		cout << "1. Enter 1 to find the neighbors of the Hexagon" << endl;
		cout << "2. Enter 2 to add a Hexagon to the cluster" << endl;
		cout << "3. Enter 3 to delete a Hexagon from the cluster" << endl;
		cout << "4. Enter 4 to exit" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			string name;
			cout << "Enter Hexagon name: ";
			cin >> name;
			getNeighbors(name, m);
			break;
		}
		case 2:
		{
			string name;
			cout << "Enter Hexagon name which is to be added: ";
			cin >> name;
			cout << "Enter 1 if it has a neighbor else enter 0"<<endl;
			int num;
			cin >> num;
			if (num == 1)
			{
				string nr;
				int edge;
				cout << "Enter the border number and name of hexagon respectively ";
				cin >> edge >> nr;

 				double x_cd = (m[nr]->x) + arr[edge][0];
     			double y_cd = (m[nr]->y) + arr[edge][1];
				
				pair<double, double>cd;
				cd.f = x_cd;
				cd.s = y_cd;
				addHexagon(name,cd, m, m2);
			}
			else if (num == 0)
			{
				if (m.size() != 0)
				{
					cout << "It must has a neighbor as a single cluster should be there" << endl;
				}
				else
				{
					pair<double, double>cd; //coordinates
					cd.f = 0.000000;
					cd.s = 0.000000;
					addHexagon(name, cd, m, m2);
				}
			}
			else
				cout << "Invalid Input";
			break;
		}
		case 3:
		{
			string name;
			cout << "Enter Hexagon name which is to be removed: ";
			cin >> name;
			removeHexagon(name, m, m2);
			break;
		}
		case 4:
		{
			temp = 0;
			break;
		}
		default:
			cout << "Invalid Input" << endl;
			break;
		}
	}
	return 0;
}
