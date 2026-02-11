#pragma once
#include <iostream>
#include <string>
using namespace std;

class Player {
   private:
    string m_name;
    int m_score;

   public:
    Player() {}
    Player(string name, int score) : m_name(name), m_score(score) {}
    Player(const Player& p) : Player(p.m_name, p.m_score) {}
    void set_score(int score) { this->m_score = score; }
    void set_name(string name) { this->m_name = name; }
    string get_name() { return this->m_name; }
    int get_score() { return this->m_score; }
};

ostream& operator<<(ostream& cout, Player& p) {
    cout << p.get_name() << "的平均分为:" << p.get_score();
    return cout;
}