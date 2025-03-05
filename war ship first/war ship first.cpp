#include<Windows.h>
#include "gra.h"
#include <iostream>
#include<vector>
#include<random>
#include"graphic.h"
using namespace std;
int main()
{
    toado ship = {19,2};
    vector<toado> fire;
    vector<toado> enemy;
    nhap(18, 2, fire);
    nhap(1, 3, enemy);
    char move='w';
    int x = 2; int y = 2;
    int dem = 0;
    int reload = 0;
    vector<int> damage = { 0 };
    while (true) {
        
        print(ship, fire,enemy);
        Sleep(500);
        if (_kbhit() == true) {
            move = _getch();
        }
        system("cls");
        controlship(move, ship);
        
        
        for (int i = 0; i < (int)fire.size(); i++) {
            fire[i].x--;
        }
        for (int i = 0; i < (int)enemy.size(); i++) {
            enemy[i].x++;
        }
        if (dem == 5)
        {
            enemy.push_back({ 1,random(2,5) });
            dem = 0;
            damage.push_back(0);
        }
        if(reload==2)
        {
            fire.push_back({ ship.x - 1,ship.y });
            reload = 0;
        }
        move = ' ';
        dem++; reload++;
        for (int i = 0; i < (int)enemy.size(); i++) {
            for (int j = 0;j<(int)fire.size();j++) {
                if ((fire[j].x == enemy[i].x - 2 and fire[j].y == enemy[i].y) or (fire[j].x == enemy[i].x-1 and fire[j].y == enemy[i].y)) {
                    damage[i]++;
                    fire.erase(fire.begin() +j);
                }
            }
        }
        for (int i = 0; i < (int)enemy.size(); i++) {
            if (damage[i] == 3) {
                enemy.erase(enemy.begin() + i);
                damage.erase(damage.begin() + i);

            }
        }
        
    }
    cout << "charge";
    //charge part 2
}
