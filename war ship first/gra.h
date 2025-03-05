#pragma once
#include<iostream>
#include<vector>
#include<random>
using namespace std;

struct toado {
	int x;
	int y;
};
int random(int i,int j) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <> dis(i, j);
	int rand = dis(gen);
	return rand;
}
bool checkarr(vector<toado> mang,int i,int j) {
	bool thu = false;
	for (toado k : mang)
	{

		if (i == k.x and j == k.y) {
			thu = true;
		}
	}
	return thu;
}
void print(toado ship, vector<toado> fire, vector<toado> enemy) {
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 6; j++) {
			if (i == 0 or i == 20 or (j == 0 and i > 0 and i < 20) or (j == 6 and i > 0 and i < 20)) cout << "0 ";
			else {
				if (i == ship.x and j == ship.y) cout << "A ";
				else if (checkarr(enemy, i, j)) cout << "V ";
				else if (checkarr(fire, i, j)) cout << "! ";
				else cout << "  ";
			}

		}
		cout << endl;
	}


}
void nhap(int x, int y, vector<toado>& mang) {
	mang.push_back({ x, y });
}

void controlship(char move, toado &ship) {
	if (move == 'w') ship.x--;
	else if (move == 's') ship.x++;
	else if (move == 'd') ship.y++;
	else if (move == 'a') ship.y--;
}




