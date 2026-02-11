#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;

void creat_player(vector<Player>& v) {
    string name_seed = "ABCDE";
    for (int i = 0; i < 5; i++) {
        string name = "选手";
        name += name_seed[i];
        int score = 0;
        Player p(name, score);
        v.push_back(p);
    }
}

void set_score(vector<Player>& v) {
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {
        deque<int> d;
        for (int i = 0; i < 10; i++) {
            int score = rand() % 41 + 60;
            d.push_back(score);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
            sum += *dit;
        }
        it->set_score(sum / d.size());
    }
}

void show_player(vector<Player>& v) {
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}

int main() {
    srand((unsigned int)time(NULL));
    vector<Player> v;
    creat_player(v);
    set_score(v);
    show_player(v);
    return 0;
}