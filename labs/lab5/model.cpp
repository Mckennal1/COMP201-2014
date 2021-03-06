#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    Coordinate head;
    Coordinate tail;
    direction = RIGHT;
    head.x = 1;
    head.y = 0;
    tail.x = 0;
    tail.y = 0;
    food.x = 5;
    food.y = 10;
    snake.push_front(head);
    snake.push_back(tail);
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
}

bool Model::gameOver() {
    return snake.empty() || snake.size() == width * height;
}

// Which way should the snake face?
void Model::go(Direction d) {
    direction = d;
}

// Move foward
void Model::crawl() {
    Coordinate front = snake.front();


    // TODO: Colliding with food grows the snake (so don't pop_back in that case)/ done
    if(front.x == food.x && front.y == food.y){
        Coordinate back = snake.back();
        snake.push_back(back);
        food.x = rand()%width;
        food.y = rand()%height;
    }
    else {
        snake.pop_back();
    }

    // detect collision
    // set direction = DEAD
    // TODO: Colliding with the perimeter of the screen should set direction to DEAD
    // When DEAD, the snake slowly shrinks down to nothing
    if (front.x < 0 || front.x == width || front.y < 0 || front.y == height){
        direction = DEAD;
        snake.pop_back();
    }
    // TODO: Also, colliding with food should cause us to place the food somewhere
    // else, but not anywhere on the snake.
    for (std::list<Coordinate>::iterator it=(++snake.begin()); it!=snake.end(); it++) {
        if (front.x == it->x && front.y == it->y) {
            direction = DEAD;
        }
    }

    switch(direction) {
    case UP: front.y--; break;
    case DOWN: front.y++; break;
    case LEFT: front.x--; break;
    case RIGHT: front.x++; break;
    case DEAD: break;
    }
    if (direction != DEAD) {
        snake.push_front(front);
    }
}
