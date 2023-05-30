
#include <iostream>
#include <vector>

using namespace std;

void printField(vector<vector<int>> top_nums, vector<vector<int>> left_nums, vector<vector<int>> field) {
	for (int i = 0; i < 3; i++) {
		cout << "      ";
		for (int j = 0; j < 5; j++) {
			if (top_nums[i][j]) cout << top_nums[i][j]; else cout << " ";
			cout << " ";
		}cout << endl;
	}
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 3; k++) {
			if (left_nums[i][k]) cout << left_nums[i][k]; else cout << " ";
			cout << " ";
		}
		for (int j = 0; j < 5; j++) {
			if (field[i][j] == 1) cout << char(178); else if (field[i][j] == 2) cout << "X"; else cout << char(176);
			cout << " ";
		}
		cout << endl;
	}
}



int main()
{
	vector<vector<int>>
		top_nums,
		left_nums,
		right_field;
	string title;
	cout << "Choose a game (number 1, 2, 3, 4 or 5)" << endl;
	int num = 1;
	cin >> num;
	if (num == 1) {
			top_nums = { {0,0,0,0,0}, {0, 2, 1, 2, 0}, {3, 2, 1, 2, 3} },
			left_nums = { {0,0, 3}, {0, 2, 2}, {0, 1, 1}, {0, 2, 2}, {0, 0, 3} },
			right_field = {
							{0, 1, 1, 1, 0},
							{1, 1, 0, 1, 1},
							{1, 0, 0, 0, 1},
							{1, 1, 0, 1, 1},
							{0, 1, 1, 1, 0}
		};
			title = "ring";
	}
	else if (num == 2) {
			top_nums = { {0,0,0,0,0}, {0, 0, 0, 0, 0}, {2, 4, 4, 4, 2} },
			left_nums = { {0,1,1}, {0, 0, 5}, {0, 0, 5}, {0, 0, 3}, {0, 0, 1} },
			right_field = {
							{0, 1, 0, 1, 0},
							{1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1},
							{0, 1, 1, 1, 0},
							{0, 0, 1, 0, 0}
		};
			title = "heart";

	}
	else if (num == 3) {
		top_nums = { {0,0,0,0,0}, {0, 0, 0, 0, 0}, {2, 4, 5, 4, 2} },
			left_nums = { {0,0,1}, {0, 0, 3}, {0, 0, 5}, {0, 0, 5}, {0, 0, 3} },
			right_field = {
							{0, 0, 1, 0, 0},
							{0, 1, 1, 1, 0},
							{1, 1, 1, 1, 1},
							{1, 1, 1, 1, 1},
							{0, 1, 1, 1, 0}
		};
		title = "apple";

	}
	else if (num == 4) {
		top_nums = { {0,0,1,0,0}, {0, 0, 1, 0, 0}, {3, 5, 1, 5, 3} },
			left_nums = { {0,0,3}, {0, 1, 1}, {0, 0, 5}, {0, 2, 2}, {0, 0, 5} },
			right_field = {
							{0, 1, 1, 1, 0},
							{0, 1, 0, 1, 0},
							{1, 1, 1, 1, 1},
							{1, 1, 0, 1, 1},
							{1, 1, 1, 1, 1}
		};
		title = "lock";

	}
	else {
			top_nums = { {0,0,0,0,0}, {1, 2, 0, 2, 1}, {1, 2, 5, 2, 1} },
			left_nums = { {0,0, 5}, {0, 0, 3}, {0, 0, 1}, {0, 0, 3}, {0, 0, 5} },
			right_field = {
							{1, 1, 1, 1, 1},
							{0, 1, 1, 1, 0},
							{0, 0, 1, 0, 0},
							{0, 1, 1, 1, 0},
							{1, 1, 1, 1, 1}
		};
			title = "hourglass";
	}
	vector<vector<int>>
		field = {
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0}
	};
	int ceils = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 5; j++)
		{
			ceils += top_nums[i][j];
		}
	}
	printField(top_nums, left_nums, field);
	cout << "Please, select the cell" << endl;
	int x, y;
	int marked_ceils = 0;
	while (marked_ceils < ceils) {
		cin >> x >> y;
		if (x > 0 && y > 0 && x < 6 && y < 6) {
			x--;
			y--;
			if (field[x][y] == 1 || field[x][y] == 2) {
				cout << "You already used this cell!" << endl;
			}
			else {
				if (right_field[x][y] == 1 && field[x][y] == 0) {
					field[x][y] = 1;
					marked_ceils++;
					printField(top_nums, left_nums, field);
				}
				else if (right_field[x][y] == 0 && field[x][y] == 0) {
					field[x][y] = 2;
					printField(top_nums, left_nums, field);
				}
			}
		}
		else {
			cout << "Wrong input, try again" << endl;
		}
	}
	cout << "\n\n\n\n   " << title << endl;
	for (int i = 0; i < 5; i++) {
		cout << "   ";
		for (int j = 0; j < 5; j++) {
			if (field[i][j] == 1) cout << char(178); else cout << " ";
			cout << " ";
		}
		cout << endl;
	}	
	cout << "    You won!" << endl;


}
