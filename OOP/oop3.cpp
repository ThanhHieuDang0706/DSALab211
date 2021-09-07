#include <iostream>

using namespace std;

class Character {
private:
    int x;
    int y;
protected:
    int hp;
public:
    Character();
    Character(int hp, int x, int y);
    int getHp();
    void setHp(int hp);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getManhattanDistTo(Character* other);
    void operator()();
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

void Character::operator()() {
    // STUDENT ANSWER
    cout << this->hp << '-' << this->x << '-' << this->y;
}

/*
Declare and define the derived class Player that satisfies:
    - Methods of base class Character cannot be accessed outside Player class using Player instances.
        Ex: Player pl; pl.setX(); will raise errors when compiled.
    - Player class has these methods and constructors:
        + Constructor Player(): acts just like Character()
        + Constructor Player(int hp, int x, int y): acts just like Character(hp, x, y)
        + Method void printPlayerData(): print data of the instance with format: hp-x-y
        + Method void moveTo(int x, int y): set the values of x, y to new values
    - The mentioned constructors and methods can be accessed outside Player class
*/

class Player {
private:
    Character *character;
public:
    Player();
    Player(int hp, int x, int y);
    void printPlayerData();
    void moveTo(int x, int y);
};

Player::Player() {
    character = new Character;
}

Player::Player(int hp, int x, int y)  {
    character = new Character(hp, x, y);
}

void Player::printPlayerData() {
    (*character)();
}

void Player::moveTo(int x, int y) {
    character->setX(x);
    character->setY(y);
}

int main () {
    Player pl1(100, 3, 6);
    pl1.printPlayerData();

    return 0;
}