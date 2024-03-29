#include <iostream>

using namespace std;

class Character {
protected:
    int hp;
    int x;
    int y;
public:
    // Constructor: set the values of x and y and hp to 0
    Character();

    // Constructor: set the values of hp, x and y to each parameter
    Character(int hp, int x, int y);

    // Set and get hp
    int getHp();
    void setHp(int hp);

    // Set and get x
    int getX();
    void setX(int x);
    
    // Set and get y
    int getY();
    void setY(int y);

    // Get Manhattan distance to other character
    int getManhattanDistTo(Character* other);
};

Character::Character() {
    // STUDENT ANSWER
    hp = x = y = 0;
}

Character::Character(int hp, int x, int y) {
    // STUDENT ANSWER
    this->hp = hp;
    this->x = x;
    this->y = y;
}

int Character::getHp() {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp = hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x = x;
}

int Character::getY() {
    // STUDENT ANSWER
    return this->y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y = y;
}

int Character::getManhattanDistTo(Character* other) {
    // STUDENT ANSWER
    int x_distance = (this->x < other->getX()) ? (other->getX() - this->x) 
                    : (-other->getX() + this->x);
    int y_distance = (this->y < other->getY()) ? (other->getY() - this->y) 
                    : (-other->getY() + this->y);
    return x_distance + y_distance;
}


// program driver for testing, not needed
int main () {
    Character ch1(100, 3, 6);
    cout << ch1.getHp() << " " << ch1.getX() << " " << ch1.getY();
    Character ch2(20, 30, 2);
    cout << endl;
    cout << ch1.getManhattanDistTo(&ch2);
    
    return 0;
}