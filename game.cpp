#include <Windows.h>
#include <iostream>
#include "game.h"
#include "animations.h"


Game::Game(int enemies)
{
    object = new Object[2+enemies];     // create player, oat, and enemies
    object[0].x(0);
    object[0].y(0);

    cols        = console.getCols()-2;   // set initial values
    enemySlowD  = 10;
    level       = 1;
    oatWorth    = 200;
    objects     = 2+enemies;
    playerSlowD = 2;
    rows        = console.getRows()-2;
    score       = 0;
    ticks       = GetTickCount();

    srand(ticks);                        // set random start locations for oat and enemies
    for (int i = 1; i < 2+enemies; i++) setLocation(object[i]);
}

Game::~Game()
{
    delete[] object;
}
bool Game::contact(Object& player, Object& object)
{
    return ((player.x() >= object.x()-1 && player.x() <= object.x()+1) && 
            (player.y() >= object.y()-1 && player.y() <= object.y()+1));
}

int Game::gameLoop()
{
    Object ScoreDisplay(0,0);
    int displayScore  = 0;
    int moveEnemy = 0;
    int movePlayer = 0;
    int oatpoints = oatWorth;
    int moveScoreUp = 0;
    int nextRandomMove = 0;
    int lastScore = 0;
    int nextLevel = 0;
    int rMove = 0;
    bool done = false;

    while(!done)
    {
        ticks = GetTickCount();
        //theme();
        render();

        if (nextRandomMove==100)
        {
            srand(ticks);
            for(int i = 2; i < objects; object[i++].setDirection(0));
            nextRandomMove=0;
        }
        if (nextLevel > 1000)
        {
            levelUp();
            nextLevel = 0;
        }

        // input and output of user and enemies
        if (movePlayer >= playerSlowD)
        {
            object[0].getInput();
            movePlayer = 0;
        }
        if (moveEnemy >= enemySlowD)
        {
            for (int i = 2; i < objects; i++)
            {
                if(!tooClose(object[0], object[i])) object[i].randMove(rand()%5);
            }
            moveEnemy = 0;
        }
        for (int i = 0; i < objects; testCollision(object[i++]));
        for (int i = 2; i < objects && !done; done = contact(object[0],object[i++]));

        // check if player ate oat
        if (contact(object[0],object[1]))
        {
            ScoreDisplay.x() = object[1].x();
            ScoreDisplay.y() = object[1].y();
            setLocation(object[1]);
            score+=oatpoints;
            nextLevel += oatpoints;
            if (oatWorth > MAXOATWORTH) console.alarm();
            lastScore  = oatpoints;
            oatpoints  = oatWorth;
        }

        // display score of oat just eaten
        if (lastScore > 0 && moveScoreUp < showScorexln)
        {
            if (displayScore < showScore1ln)
            {
                console.setPos(ScoreDisplay.y(), ScoreDisplay.x());
                std::cout << lastScore;
                displayScore++;
            }
            else
            {
                ScoreDisplay.x()++;
                ScoreDisplay.y()--;
                displayScore = 0;
                moveScoreUp++;
            }
        }
        else 
        {
            moveScoreUp = 0;
            lastScore   = 0;
        }

        // change counter values
        if (oatpoints > 0) oatpoints--;
        moveEnemy++;
        movePlayer++;
        nextRandomMove++;

        // regulate fps
        if (1000/FPS > GetTickCount()-ticks)
        {
            Sleep(1000/FPS-(GetTickCount()-ticks));
        }
    }

    return score;
}

int Game::getScore() { return score; }
int Game::getLevel() { return level; }

void Game::levelUp()
{
    if (enemySlowD-2 > MINENEMYSPEED) enemySlowD -= 2;
    else enemySlowD = MINENEMYSPEED;

    if (oatWorth < MAXOATWORTH) oatWorth *= 1.10;
    else oatWorth = MAXOATWORTH;

    if (oatWorth != MAXOATWORTH && enemySlowD != MINENEMYSPEED) level++;
}

void Game::moveEnemyClose(Object& player, Object& enemy)
{
    if(player.x() > enemy.x()) enemy.moveRight();
    if(player.x()+1 < enemy.x()) enemy.moveLeft();
    if(player.y() > enemy.y()) enemy.moveDown();
    if(player.y()+1 < enemy.y()) enemy.moveUp();
}

void Game::render()
{
    console.clear();
    object[1].draw(oat);
    object[0].draw(character);
    for (int i = 2; i < objects; object[i++].draw(zombie));
}
void Game::setLocation(Object& object)
{
    object.x(rand()%cols);
    object.y(rand()%rows);
}

void Game::testCollision(Object& object)
{
    if(object.x() < 0) object.x(0);
    if(object.y() < 0) object.y(0);
    if(object.x()+1 > cols) object.x(cols-1);
    if(object.y()+1 > rows) object.y(rows-1);
}

void Game::theme()
{
    static int i = 0;
    int freq[8] = {500,500,500,500,600,600,600,600};
    _beep(freq[i++],100);
    if (i > 7) i=0;
}
bool Game::tooClose(Object& player, Object& enemy)
{
    if ((player.x() > enemy.x() - 20) &&
        (player.x()+1 < enemy.x() + 20) &&
        (player.y() > enemy.y() - 20) &&
        (player.y()+1 < enemy.y() + 20))
    {
        moveEnemyClose(player, enemy);
        return true;
    }
    else return false;
}
