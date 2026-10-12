#include <conio.h>
#include <ctime>
#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> range1(33, 44);
uniform_int_distribution<> range2(46, 160);

char maze[48][164] = {"################################################################################################"
                      "###################################################################",
                      "################################################################################################"
                      "###################################################################",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##******                               &                                   &                    "
                      "                                                                 ##",
                      "##                                     &##                                 &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &mmmmmmmmmmmmmmmmmmmmmmmmmmmm       &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                 ##&                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &       mmmmmmmmmmmmmmmmmmmmmmmmmmmm&                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &##                                 &                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &mmmmmmmmmmmmmm       mmmmmmmmmmmmmm&                    "
                      "                                                                 ##",
                      "##                                     &                                   &                    "
                      "                                                                 ##",
                      "##                                     &*************        **************&                    "
                      "                                                                 ##",
                      "##                                     &*******                       *****&                    "
                      "                                                                 ##",
                      "##     #                               &****************         **********&                    "
                      "                                                                 ##",
                      "##     #     #                         &                                   &                    "
                      "                                                                 ##",
                      "##     #     #     #                   &                                   &                    "
                      "                                                                 ##",
                      "##     #     #     #     #             &                                   &                    "
                      "                                                                 ##",
                      "############################           &##         ##         ##         ##&                    "
                      "                                                                 ##",
                      "##~~~~~~~~~~~~~~##                     &##         ##         ##         ##&                    "
                      "                                                                 ##",
                      "##~~~~~~~~~~~~~~##                     &##         ##         ##         ##&                    "
                      "                                                                 ##",
                      "##~~~~~~~~~~~~~~##                     &##         ##         ##         ##&                    "
                      "                                                                 ##",
                      "##################                                                                              "
                      "                                                                 ##",
                      "##                                                                                              "
                      "                                                                 ##",
                      "##                                                                                              "
                      "                                                                 ##",
                      "##                                                                                              "
                      "                                                                 ##",
                      "##                               #                                                              "
                      "                                                                 ##",
                      "##                               ###                                                            "
                      "                                                                 ##",
                      "##                               ######                                                         "
                      "                                                                 ##",
                      "##                               #####                                                          "
                      "                                                                 ##",
                      "##                               ########                                                       "
                      "                                                                 ##",
                      "##                               #######                                                        "
                      "                                                                 ##",
                      "##                               ##########                                                     "
                      "                                                                 ##",
                      "##                               #########                                                      "
                      "                                                                 ##",
                      "##                               #############                                                  "
                      "                                                                 ##",
                      "##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
                      "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%##",
                      "##&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"
                      "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&##",
                      "################################################################################################"
                      "###################################################################"};

int lose();
int win();
void frame();
void printMenu();
string menuOptions();
void printHealthPill();
void eraseHealthPill();
void healthPillDown();
void resetGame();

void printSpecialPill();
void eraseSpecialPill();
void specialPillLeft();

void healthPillLeft();

void printMaze();

void printPlayer();
void printPlayerRight();
void printPlayerLeft();
void decreaseHealth();

void scoreUp();
void scoreDown();
void scoreRight();
void scoreLeft();

void crossUp();
void crossDown();
void crossRight();
void crossLeft();

void movePlayerRight();
void movePlayerLeft();
void movePlayerUp();
void movePlayerDown();

void printBulletRight(int x, int y);
void printBulletLeft(int x, int y);
void printBulletDown(int x, int y);

void makeBulletRightInactive(int index);
void makeBulletLeftInactive(int index);
void makeBulletDownInactive(int index);

void generatebulletRight();
void generatebulletLeft();
void generatebulletDown();

void moveBulletRight();
void moveBulletLeft();
void moveBulletDown();

void printEnemy1();
void printEnemy2();
void printEnemy3();

void moveEnemy1();
void moveEnemy2();
void moveEnemy3();

void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();

void printEnemyBullet(int x, int y);
void eraseEnemyBullet(int x, int y);
void generateEnemy3Bullet(int &enemy3RangeCount);
void moveEnemy3Bullet();
void decreaseEnemyHealth(int x, int y, int &enemyHealth);

void printBox(int bx, int by, int boxHealth);
void eraseBox(int bx, int by);
void boxMovementVertical(int &bx, int &by, int &incrementY, int boxHealth);
void decreaseBoxHealth(int &x, int &y, int &boxHealth);

int randomNumber(int n);
void printPill();
void printCross();
void removePill(int counter);
void removeCross(int counter);
void lasers(int lx, int ly, int increment);
void eraseLazers(int lx, int ly, int increment);
void sideMenu();

int enemy3RangeCount = 0;

int hx = 4, hy = 43;
int sx = 43, sy = 4;

int pX = 3, pY = 2;
int increaseScore = 0;
int increaseCross = 0;
int playerHealth = 100;
int power = 0;
int energy = 0;

int e1x = 33, e1y = 8;
int e2x = 23, e2y = 42;
int e3x = 155, e3y = 29;

int enemyHealth1 = 100;
int enemyHealth2 = 100;
int enemyHealth3 = 100;

int bx1 = 83, by1 = 2;
int bx2 = 103, by2 = 8;
int bx3 = 123, by3 = 14;
int bx4 = 143, by4 = 20;

int increment1Y = 1;
int increment2Y = 1;
int increment3Y = 1;
int increment4Y = 1;

int bulletRightX[10];
int bulletRightY[10];
bool isBulletRightActive[10];
int bulletRightCount = 0;

int bulletLeftX[10];
int bulletLeftY[10];
bool isBulletLeftActive[10];
int bulletLeftCount = 0;

int bulletDownX[7];
int bulletDownY[7];
bool isBulletDownActive[7];
int bulletDownCount = 0;

int enemy3BulletRightX[100000];
int enemy3BulletRightY[100000];
bool isBullet3RightActive[100000];
int enemy3RightCount = 0;

int enemy3BulletLeftX[100000];
int enemy3BulletLeftY[100000];
bool isBullet3LeftActive[100000];
int enemy3LeftCount = 0;

int directionEnemy1 = 1;
int directionEnemy2 = -1;
int directionEnemy3 = -1;
char pill = (char)248;
int pillCount = 0;
int crossCount = 0;

int boxHealth1 = 9;
int boxHealth2 = 9;
int boxHealth3 = 9;
int boxHealth4 = 9;

int arrPillX[10] = {};
int arrPillY[10] = {};

int arrCrossX[15] = {};
int arrCrossY[15] = {};

char rightBullet = (char)175;
char leftBullet = (char)174;
char downBullet = '|';

char healthPill = (char)254;
char specialPill = (char)177;
char bomb = '@';

int timer = 0, timerCount = 0;

void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void hideCursor();

int main()
{
    while (true)
    {
        printMenu();
        frame();
        string choice = menuOptions();
        if (choice == "1")
        {

            bool boxFlag1 = false;
            bool boxFlag2 = false;
            bool boxFlag3 = false;
            bool boxFlag4 = false;
            bool enemyFlag1 = false;
            bool enemyFlag2 = false;
            bool enemyFlag3 = false;

            int lazer1Count = 0, lazer2Count, lazer3Count;
            hideCursor();
            system("cls");
            printMaze();
            sideMenu();
            printPlayer();
            printHealthPill();
            printSpecialPill();
            while (true)
            {
                if (playerHealth <= 0 || increaseCross >= 3)
                {
                    lose();
                    cin.ignore();
                    cin.get();
                    resetGame();
                    break;
                }
                if (enemyHealth1 <= 0 && enemyHealth2 <= 0 && enemyHealth3 && boxHealth1 <= 0 && boxHealth2 <= 0 &&
                    boxHealth3 <= 0 && boxHealth4 <= 0)
                {
                    win();
                    cin.ignore();
                    cin.get();
                    resetGame();
                    break;
                }

                if (lazer1Count >= 25 && lazer1Count <= 30)
                {
                    lasers(41, 6, 1);
                }
                if (lazer1Count > 30)
                {
                    eraseLazers(41, 6, 1);
                    lazer1Count = 0;
                }
                if (lazer2Count >= 20 && lazer2Count <= 25)
                {
                    lasers(73, 12, -1);
                }
                if (lazer2Count > 25)
                {
                    eraseLazers(73, 12, -1);
                    lazer2Count = 0;
                }
                if (lazer3Count >= 15 && lazer3Count <= 20)
                {
                    lasers(41, 18, 1);
                }
                if (lazer3Count > 20)
                {
                    eraseLazers(41, 18, 1);
                    lazer3Count = 0;
                }
                lazer1Count++;
                lazer2Count++;
                lazer3Count++;

                generatebulletRight();
                generatebulletLeft();
                generatebulletDown();
                if (boxHealth1 > 0)
                {
                    boxMovementVertical(bx1, by1, increment1Y, boxHealth1);
                    decreaseBoxHealth(bx1, by1, boxHealth1);
                    boxFlag1 = true;
                }
                else if (boxFlag1)
                {
                    eraseBox(bx1, by1);
                    boxFlag1 = false;
                }
                if (boxHealth2 > 0)
                {
                    boxMovementVertical(bx2, by2, increment2Y, boxHealth2);
                    decreaseBoxHealth(bx2, by2, boxHealth2);
                    boxFlag2 = true;
                }
                else if (boxFlag2)
                {
                    eraseBox(bx2, by2);
                    boxFlag2 = false;
                }
                if (boxHealth3 > 0)
                {
                    boxMovementVertical(bx3, by3, increment3Y, boxHealth3);
                    decreaseBoxHealth(bx3, by3, boxHealth3);
                    boxFlag3 = true;
                }
                else if (boxFlag3)
                {
                    eraseBox(bx3, by3);
                    boxFlag3 = false;
                }
                if (boxHealth4 > 0)
                {
                    boxMovementVertical(bx4, by4, increment4Y, boxHealth4);
                    decreaseBoxHealth(bx4, by4, boxHealth4);
                    boxFlag4 = true;
                }
                else if (boxFlag4)
                {
                    eraseBox(bx4, by4);
                    boxFlag4 = false;
                }
                if (enemyHealth1 > 0)
                {
                    moveEnemy1();
                    decreaseEnemyHealth(e1x, e1y, enemyHealth1);
                    enemyFlag1 = true;
                }
                else if (enemyFlag1)
                {
                    eraseEnemy1();
                    enemyFlag1 = false;
                }
                if (enemyHealth2 > 0)
                {
                    moveEnemy2();
                    decreaseEnemyHealth(e2x, e2y, enemyHealth2);
                    enemyFlag2 = true;
                }
                else if (enemyFlag2)
                {
                    eraseEnemy2();
                    enemyFlag2 = false;
                }
                if (enemyHealth3 > 0)
                {
                    decreaseEnemyHealth(e3x, e3y, enemyHealth3);
                    moveEnemy3();
                    generateEnemy3Bullet(enemy3RangeCount);
                    enemyFlag3 = true;
                }
                else if (enemyFlag3)
                {
                    eraseEnemy3();
                    enemyFlag3 = false;
                }

                moveEnemy3Bullet();
                decreaseHealth();
                movePlayerRight();
                movePlayerLeft();
                movePlayerUp();
                movePlayerDown();

                // getch();
                gotoxy(193, 12);
                cout << increaseCross;
                gotoxy(193, 10);
                cout << increaseScore;
                if(power == 100)
                {
                gotoxy(193, 14);
                cout << "Got pill";
                }
                if(energy == 100)
                {
                gotoxy(193, 16);
                cout << "Got Pill";
                }
                gotoxy(193, 23);
                cout << "   ";
                gotoxy(193, 29);
                cout << "   ";
                gotoxy(193, 35);
                cout << "   ";
                gotoxy(193, 8);
                cout << "      ";
                gotoxy(193, 23);
                cout << enemyHealth1;
                gotoxy(193, 29);
                cout << enemyHealth2;
                gotoxy(193, 35);
                cout << enemyHealth3;
                gotoxy(193, 8);
                cout << playerHealth;
                timerCount++;
                if (timerCount == 8)
                {
                    timer = timer + 1;
                    gotoxy(193, 43);
                    cout << timer;
                    timerCount = 0;
                }

                Sleep(100);

                if (pillCount < 10)
                {
                    printPill();
                }
                if (crossCount < 15)
                {
                    printCross();
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    break;
                }
            }
        }
        else if (choice == "2")
        {
        }
        else if (choice == "3")
        {
            return 0;
        }
    }
}
void sideMenu()
{
    int x = 164, y = 0;
    gotoxy(x, y++);
    cout << "##############################################";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                   PLAYER                 ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Health:                        ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Pills:                         ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Poison:                        ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Bonus Pill 1:                  ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Bonus Pill 2:                  ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                    ENEMY 1               ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Health:                        ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                    ENEMY 2               ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##           Health:                        ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                    ENEMY 3               ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##             Health:                      ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                    TIMER                 ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##             Time:                        ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##                                          ##";
    gotoxy(x, y++);
    cout << "##############################################";
}
void printPlayer()
{
    gotoxy(pX, pY);
    cout << "<o>";
    gotoxy(pX, pY + 1);
    cout << "/|\\";
    gotoxy(pX, pY + 2);
    cout << "/ \\";
}
void printPlayerRight()
{
    gotoxy(pX, pY);
    cout << "<=>";
    gotoxy(pX, pY + 1);
    cout << "(|\\";
    gotoxy(pX, pY + 2);
    cout << "/ )";
}
void printPlayerLeft()
{
    gotoxy(pX, pY);
    cout << "<=>";
    gotoxy(pX, pY + 1);
    cout << "/|)";
    gotoxy(pX, pY + 2);
    cout << "( \\";
}
void erasePlayer()
{
    gotoxy(pX, pY);
    cout << "   ";
    gotoxy(pX, pY + 1);
    cout << "   ";
    gotoxy(pX, pY + 2);
    cout << "   ";
}
void movePlayerRight()
{
    if ((GetAsyncKeyState(VK_RIGHT)) &&
        (getCharAtxy(pX + 3, pY) == ' ' || getCharAtxy(pX + 3, pY) == pill || getCharAtxy(pX + 3, pY) == 'x' ||
         getCharAtxy(pX + 3, pY) == '-') &&
        (getCharAtxy(pX + 3, pY + 1) == ' ' || getCharAtxy(pX + 3, pY + 1) == pill ||
         getCharAtxy(pX + 3, pY + 1) == 'x' || getCharAtxy(pX + 3, pY + 1) == '-') &&
        (getCharAtxy(pX + 3, pY + 2) == ' ' || getCharAtxy(pX + 3, pY + 2) == pill ||
         getCharAtxy(pX + 3, pY + 2) == 'x' || getCharAtxy(pX + 3, pY + 2) == '-'))
    {
        erasePlayer();
        scoreRight();
        crossRight();
        pX = pX + 1;
        printPlayerRight();
    }
}
void movePlayerLeft()
{
    if (GetAsyncKeyState(VK_LEFT) &&
        (getCharAtxy(pX - 1, pY) == ' ' || getCharAtxy(pX - 1, pY) == pill || getCharAtxy(pX - 1, pY) == healthPill ||
         getCharAtxy(pX - 1, pY) == specialPill || getCharAtxy(pX - 1, pY) == 'x' || getCharAtxy(pX - 1, pY) == '-') &&
        (getCharAtxy(pX - 1, pY + 1) == ' ' || getCharAtxy(pX - 1, pY + 1) == pill ||
         getCharAtxy(pX - 1, pY + 1) == healthPill || getCharAtxy(pX - 1, pY + 1) == specialPill ||
         getCharAtxy(pX - 1, pY + 1) == 'x' || getCharAtxy(pX - 1, pY + 1) == '-') &&
        (getCharAtxy(pX - 1, pY + 2) == ' ' || getCharAtxy(pX - 1, pY + 2) == pill ||
         getCharAtxy(pX - 1, pY + 2) == healthPill || getCharAtxy(pX - 1, pY + 2) == specialPill ||
         getCharAtxy(pX - 1, pY + 2) == 'x' || getCharAtxy(pX - 1, pY + 2) == '-'))
    {
        erasePlayer();
        scoreLeft();
        crossLeft();
        specialPillLeft();
        healthPillLeft();
        pX = pX - 1;
        printPlayerLeft();
    }
}
void movePlayerUp()
{
    if (GetAsyncKeyState(VK_UP) &&
        (getCharAtxy(pX, pY - 1) == ' ' || getCharAtxy(pX, pY - 1) == pill || getCharAtxy(pX, pY - 1) == 'x' ||
         getCharAtxy(pX, pY - 1) == '-') &&
        (getCharAtxy(pX + 1, pY - 1) == ' ' || getCharAtxy(pX + 1, pY - 1) == pill ||
         getCharAtxy(pX + 1, pY - 1) == 'x' || getCharAtxy(pX + 1, pY - 1) == '-') &&
        (getCharAtxy(pX + 2, pY - 1) == ' ' || getCharAtxy(pX + 2, pY - 1) == pill ||
         getCharAtxy(pX + 2, pY - 1) == 'x' || getCharAtxy(pX + 2, pY - 1) == '-'))
    {
        erasePlayer();
        scoreUp();
        crossUp();
        pY = pY - 1;
        printPlayer();
    }
}
void movePlayerDown()
{
    if ((GetAsyncKeyState(VK_DOWN)) &&
        (getCharAtxy(pX, pY + 3) == ' ' || getCharAtxy(pX, pY + 3) == pill || getCharAtxy(pX, pY + 3) == healthPill ||
         getCharAtxy(pX, pY + 3) == 'x' || getCharAtxy(pX, pY + 3) == '-') &&
        (getCharAtxy(pX + 1, pY + 3) == ' ' || getCharAtxy(pX + 1, pY + 3) == pill ||
         getCharAtxy(pX + 1, pY + 3) == healthPill || getCharAtxy(pX + 1, pY + 3) == 'x' ||
         getCharAtxy(pX + 1, pY + 3) == '-') &&
        (getCharAtxy(pX + 2, pY + 3) == ' ' || getCharAtxy(pX + 2, pY + 3) == pill ||
         getCharAtxy(pX + 2, pY + 3) == healthPill || getCharAtxy(pX + 2, pY + 3) == 'x' ||
         getCharAtxy(pX + 2, pY + 3) == '-'))
    {
        erasePlayer();
        scoreDown();
        crossDown();
        healthPillDown();
        pY = pY + 1;
        printPlayer();
    }
}
void scoreUp()
{
    for (int i = 0; i < pillCount; i++)
    {
        if ((pX == arrPillX[i] && pY - 1 == arrPillY[i]) || (pX + 1 == arrPillX[i] && pY - 1 == arrPillY[i]) ||
            (pX + 2 == arrPillX[i] && pY - 1 == arrPillY[i]))
        {
            increaseScore = increaseScore + 1;
            removePill(i);
        }
    }
}
void scoreDown()
{
    for (int i = 0; i < pillCount; i++)
    {
        if ((pX == arrPillX[i] && pY + 3 == arrPillY[i]) || (pX + 1 == arrPillX[i] && pY + 3 == arrPillY[i]) ||
            (pX + 2 == arrPillX[i] && pY + 3 == arrPillY[i]))
        {
            increaseScore = increaseScore + 1;
            removePill(i);
        }
    }
}
void scoreRight()
{
    for (int i = 0; i < pillCount; i++)
    {
        if ((pX + 3 == arrPillX[i] && pY == arrPillY[i]) || (pX + 3 == arrPillX[i] && pY + 1 == arrPillY[i]) ||
            (pX + 3 == arrPillX[i] && pY + 2 == arrPillY[i]))
        {
            increaseScore = increaseScore + 1;
            removePill(i);
        }
    }
}
void scoreLeft()
{
    for (int i = 0; i < pillCount; i++)
    {
        if ((pX - 1 == arrPillX[i] && pY == arrPillY[i]) || (pX - 1 == arrPillX[i] && pY + 1 == arrPillY[i]) ||
            (pX - 1 == arrPillX[i] && pY + 2 == arrPillY[i]))
        {
            increaseScore = increaseScore + 1;
            removePill(i);
        }
    }
}
void crossUp()
{
    for (int i = 0; i < crossCount; i++)
    {
        if ((pX == arrCrossX[i] && pY - 1 == arrCrossY[i]) || (pX + 1 == arrCrossX[i] && pY - 1 == arrCrossY[i]) ||
            (pX + 2 == arrCrossX[i] && pY - 1 == arrCrossY[i]))
        {
            increaseCross = increaseCross + 1;
            removeCross(i);
        }
    }
}
void crossDown()
{
    for (int i = 0; i < crossCount; i++)
    {
        if ((pX == arrCrossX[i] && pY + 3 == arrCrossY[i]) || (pX + 1 == arrCrossX[i] && pY + 3 == arrCrossY[i]) ||
            (pX + 2 == arrCrossX[i] && pY + 3 == arrCrossY[i]))
        {
            increaseCross = increaseCross + 1;
            removeCross(i);
        }
    }
}
void crossRight()
{
    for (int i = 0; i < crossCount; i++)
    {
        if ((pX + 3 == arrCrossX[i] && pY == arrCrossY[i]) || (pX + 3 == arrCrossX[i] && pY + 1 == arrCrossY[i]) ||
            (pX + 3 == arrCrossX[i] && pY + 2 == arrCrossY[i]))
        {
            increaseCross = increaseCross + 1;
            removeCross(i);
        }
    }
}
void crossLeft()
{
    for (int i = 0; i < crossCount; i++)
    {
        if ((pX - 1 == arrCrossX[i] && pY == arrCrossY[i]) || (pX - 1 == arrCrossX[i] && pY + 1 == arrCrossY[i]) ||
            (pX - 1 == arrCrossX[i] && pY + 2 == arrCrossY[i]))
        {
            increaseCross = increaseCross + 1;
            removeCross(i);
        }
    }
}
void decreaseHealth()
{
    if (getCharAtxy(pX, pY + 3) == '%' || getCharAtxy(pX + 1, pY + 3) == '%' || getCharAtxy(pX + 2, pY + 3) == '%' ||
        (pX, pY + 3) == '=' || getCharAtxy(pX + 1, pY + 3) == '=' || getCharAtxy(pX + 2, pY + 3) == '=' ||
        (pX, pY - 1) == '=' || getCharAtxy(pX + 1, pY - 13) == '=' || getCharAtxy(pX + 2, pY - 1) == '=' ||
        getCharAtxy(pX + 1, pY) == '-' || getCharAtxy(pX + 1, pY + 1) == '-' || getCharAtxy(pX + 1, pY + 2) == '-' ||
        getCharAtxy(pX + 3, pY) == '.' || getCharAtxy(pX + 3, pY + 1) == '.' || getCharAtxy(pX + 3, pY + 2) == '.' ||
        getCharAtxy(pX - 1, pY) == '.' || getCharAtxy(pX - 1, pY + 1) == '.' || getCharAtxy(pX - 1, pY + 2) == '.' ||
        getCharAtxy(pX + 4, pY) == '.' || getCharAtxy(pX + 4, pY + 1) == '.' || getCharAtxy(pX + 4, pY + 2) == '.' ||
        getCharAtxy(pX - 2, pY) == '.' || getCharAtxy(pX - 2, pY + 1) == '.' || getCharAtxy(pX - 2, pY + 2) == '.')
    {
        playerHealth = playerHealth - 1;
    }
    // for(int i = 0; i < crossCount; i++)
    // {
    // if((pX == arrPillX[i] && pY - 1 == arrPillY[i]) || (pX + 1 == arrPillX[i] && pY - 1 == arrPillY[i]) || (pX + 2 ==
    // arrPillX[i] && pY - 1 == arrPillY[i]))
    // {
    //     playerHealth = playerHealth - 1;
    //     removeCross(i);
    // }
    // else if((pX == arrPillX[i] && pY + 3 == arrPillY[i]) || (pX + 1 == arrPillX[i] && pY + 3 == arrPillY[i]) || (pX +
    // 2 == arrPillX[i] && pY + 3 == arrPillY[i]))
    // {
    //     playerHealth = playerHealth - 1;
    //     removeCross(i);
    // }
    // else if((pX - 1 == arrPillX[i] && pY == arrPillY[i]) || (pX - 1 == arrPillX[i] && pY + 1 == arrPillY[i]) || (pX -
    // 1 == arrPillX[i] && pY + 2 == arrPillY[i]))
    // {
    //     playerHealth = playerHealth - 1;
    //     removeCross(i);
    // }
    // else if((pX - 1 == arrPillX[i] && pY == arrPillY[i]) || (pX - 1 == arrPillX[i] && pY + 1 == arrPillY[i]) || (pX -
    // 1 == arrPillX[i] && pY + 2 == arrPillY[i]))
    // {
    //     playerHealth = playerHealth - 1;
    //     removeCross(i);
    // }
    // }
}

void printMaze()
{
    for (int i = 0; i <= 47; i++)
    {
        for (int j = 0; j <= 163; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
}
void printEnemy1()
{
    gotoxy(e1x, e1y);
    cout << "[~]";
    gotoxy(e1x, e1y + 1);
    cout << "/1\\";
    gotoxy(e1x, e1y + 2);
    cout << "v-v";
}
void printEnemy2()
{
    gotoxy(e2x, e2y);
    cout << "^,^";
    gotoxy(e2x, e2y + 1);
    cout << "(2)";
    gotoxy(e2x, e2y + 2);
    cout << "!.!";
}
void printEnemy3()
{
    gotoxy(e3x, e3y);
    cout << "(\")";
    gotoxy(e3x, e3y + 1);
    cout << "<3>";
    gotoxy(e3x, e3y + 2);
    cout << "o^o";
}
void eraseEnemy1()
{
    gotoxy(e1x, e1y);
    cout << "   ";
    gotoxy(e1x, e1y + 1);
    cout << "   ";
    gotoxy(e1x, e1y + 2);
    cout << "   ";
}
void eraseEnemy2()
{
    gotoxy(e2x, e2y);
    cout << "   ";
    gotoxy(e2x, e2y + 1);
    cout << "   ";
    gotoxy(e2x, e2y + 2);
    cout << "   ";
}
void eraseEnemy3()
{
    gotoxy(e3x, e3y);
    cout << "   ";
    gotoxy(e3x, e3y + 1);
    cout << "   ";
    gotoxy(e3x, e3y + 2);
    cout << "   ";
}
void moveEnemy1()
{
    char hurdle, hurdle1, hurdle2;
    if (directionEnemy1 == 1)
    {
        hurdle = getCharAtxy(e1x, e1y + directionEnemy1 + 2);
        hurdle1 = getCharAtxy(e1x + 1, e1y + directionEnemy1 + 2);
        hurdle2 = getCharAtxy(e1x + 2, e1y + directionEnemy1 + 2);
    }
    else
    {
        hurdle = getCharAtxy(e1x, e1y + directionEnemy1);
        hurdle1 = getCharAtxy(e1x + 1, e1y + directionEnemy1);
        hurdle2 = getCharAtxy(e1x + 2, e1y + directionEnemy1);
    }
    eraseEnemy1();

    if (hurdle != ' ' || hurdle1 != ' ' || hurdle2 != ' ' || getCharAtxy(e1x, e1y - 1) == downBullet ||
        getCharAtxy(e1x + 1, e1y - 1) == downBullet || getCharAtxy(e1x + 2, e1y - 1) == downBullet)
    {
        directionEnemy1 = -1 * directionEnemy1;
    }
    e1y = e1y + directionEnemy1;

    printEnemy1();
}
void moveEnemy2()
{
    char hurdle, hurdle1, hurdle2;
    if (directionEnemy2 == 1)
    {
        hurdle = getCharAtxy(e2x, e2y + directionEnemy2 + 2);
        hurdle1 = getCharAtxy(e2x + 1, e2y + directionEnemy2 + 2);
        hurdle2 = getCharAtxy(e2x + 2, e2y + directionEnemy2 + 2);
    }
    else
    {
        hurdle = getCharAtxy(e2x, e2y + directionEnemy2);
        hurdle1 = getCharAtxy(e2x + 1, e2y + directionEnemy2);
        hurdle2 = getCharAtxy(e2x + 2, e2y + directionEnemy2);
    }
    eraseEnemy2();

    if (hurdle != ' ' || hurdle1 != ' ' || hurdle2 != ' ' || getCharAtxy(e2x, e2y - 1) == downBullet ||
        getCharAtxy(e2x + 1, e2y - 1) == downBullet || getCharAtxy(e2x + 2, e2y - 1) == downBullet ||
        getCharAtxy(e2x + 3, e2y) == rightBullet || getCharAtxy(e2x + 3, e2y) == leftBullet ||
        getCharAtxy(e2x + 3, e2y + 1) == rightBullet || getCharAtxy(e2x + 3, e2y + 1) == leftBullet ||
        getCharAtxy(e2x + 3, e2y + 2) == rightBullet || getCharAtxy(e2x + 3, e2y + 2) == leftBullet ||
        getCharAtxy(e2x - 1, e2y) == rightBullet || getCharAtxy(e2x - 1, e2y) == leftBullet ||
        getCharAtxy(e2x - 1, e2y + 1) == rightBullet || getCharAtxy(e2x - 1, e2y + 1) == leftBullet ||
        getCharAtxy(e2x - 1, e2y + 2) == rightBullet || getCharAtxy(e2x - 1, e2y + 2) == leftBullet)
    {
        directionEnemy2 = -1 * directionEnemy2;
    }
    e2x = e2x + directionEnemy2;
    e2y = e2y + directionEnemy2;

    printEnemy2();
}
void moveEnemy3()
{
    char hurdle, hurdle1, hurdle2;
    if (directionEnemy3 == 1)
    {
        hurdle = getCharAtxy(e3x + directionEnemy3 + 2, e3y);
        hurdle1 = getCharAtxy(e3x + directionEnemy3 + 2, e3y + 1);
        hurdle2 = getCharAtxy(e3x + directionEnemy3 + 2, e3y + 2);
    }
    else
    {
        hurdle = getCharAtxy(e3x + directionEnemy3, e3y);
        hurdle1 = getCharAtxy(e3x + directionEnemy3, e3y + 1);
        hurdle2 = getCharAtxy(e3x + directionEnemy3, e3y + 2);
    }
    eraseEnemy3();

    if (hurdle != ' ' || hurdle1 != ' ' || hurdle2 != ' ' || getCharAtxy(e3x + 3, e3y) == rightBullet ||
        getCharAtxy(e3x + 3, e3y) == leftBullet || getCharAtxy(e3x + 3, e3y + 1) == rightBullet ||
        getCharAtxy(e3x + 3, e3y + 1) == leftBullet || getCharAtxy(e3x + 3, e3y + 2) == rightBullet ||
        getCharAtxy(e3x + 3, e3y + 2) == leftBullet || getCharAtxy(e3x - 1, e3y) == rightBullet ||
        getCharAtxy(e3x - 1, e3y) == leftBullet || getCharAtxy(e3x - 1, e3y + 1) == rightBullet ||
        getCharAtxy(e3x - 1, e3y + 1) == leftBullet || getCharAtxy(e3x - 1, e3y + 2) == rightBullet ||
        getCharAtxy(e3x - 1, e3y + 2) == leftBullet)
    {
        directionEnemy3 = -1 * directionEnemy3;
    }
    e3x = e3x + directionEnemy3;

    printEnemy3();
}
int randomNumber(int n)
{
    if (n == 44)
    {
        return range1(gen);
    }
    else
    {
        return range2(gen);
    }
}
void printPill()
{
    while (pillCount < 10)
    {
        int a = randomNumber(162);
        int b = randomNumber(44);
        if (getCharAtxy(a, b) == ' ')
            int b = randomNumber(44);
        {
            gotoxy(a, b);
            cout << pill;
            arrPillX[pillCount] = a;
            arrPillY[pillCount] = b;
            pillCount++;
        }
    }
}
void printCross()
{
    while (crossCount < 15)
    {
        int a = randomNumber(162);
        int b = randomNumber(44);
        if (getCharAtxy(a, b) == 'x')
            int b = randomNumber(44);
        {
            gotoxy(a, b);
            cout << "x";
            arrCrossX[crossCount] = a;
            arrCrossY[crossCount] = b;
            crossCount++;
        }
    }
}
void removePill(int counter)
{
    for (int i = counter; i < pillCount; i++)
    {
        arrPillX[i] = arrPillX[i + 1];
        arrPillY[i] = arrPillY[i + 1];
    }
    pillCount--;
}
void removeCross(int counter)
{
    for (int i = counter; i < crossCount; i++)
    {
        arrCrossX[i] = arrCrossX[i + 1];
        arrCrossY[i] = arrCrossY[i + 1];
    }
    crossCount--;
}
void lasers(int lx, int ly, int increment)
{
    for (int i = 0; i < 32; i++)
    {
        gotoxy(lx = lx + increment, ly);
        cout << '-';
    }
}
void eraseLazers(int lx, int ly, int increment)
{
    for (int i = 0; i < 32; i++)
    {
        gotoxy(lx = lx + increment, ly);
        cout << ' ';
    }
}
void printBox(int bx, int by, int boxHealth)
{
    gotoxy(bx, by);
    cout << "===" << endl;
    gotoxy(bx, by + 1);
    cout << "|" << boxHealth << "|" << endl;
    gotoxy(bx, by + 2);
    cout << "===" << endl;
}
void eraseBox(int bx, int by)
{
    gotoxy(bx, by);
    cout << "   " << endl;
    gotoxy(bx, by + 1);
    cout << "   " << endl;
    gotoxy(bx, by + 2);
    cout << "   " << endl;
}
void boxMovementVertical(int &bx, int &by, int &incrementY, int boxHealth)
{
    eraseBox(bx, by);

    by = by + incrementY;

    if (by == 2 || by == 22 || getCharAtxy(bx, by - 1) == '=' || getCharAtxy(bx + 1, by - 1) == '=' ||
        getCharAtxy(bx + 2, by - 1) == '=' || getCharAtxy(bx, by + 3) == '=' || getCharAtxy(bx + 1, by - 1) == '=' ||
        getCharAtxy(bx + 2, by + 3) == '=')
    {
        incrementY = incrementY * -1;
    }
    printBox(bx, by, boxHealth);
}
void printHealthPill()
{
    gotoxy(hx, hy);
    cout << healthPill;
}
void eraseHealthPill()
{
    gotoxy(hx, hy);
    cout << " ";
}
void healthPillDown()
{
    if ((pX == hx && pY + 3 == hy) || (pX + 1 == hx && pY + 3 == hy) || (pX + 2 == hx && pY + 3 == hy))
    {
        power = power + 100;
        eraseHealthPill();
    }
}
void healthPillLeft()
{
    if ((pX - 1 == hx && pY == hy) || (pX - 1 == hx && pY + 1 == hy) || (pX - 1 == hx && pY + 2 == hy))
    {
        power = power + 100;
        eraseHealthPill();
    }
}
void printSpecialPill()
{
    gotoxy(sx, sy);
    cout << specialPill;
}
void eraseSpecialPill()
{
    gotoxy(sx, sy);
    cout << " ";
}
void specialPillLeft()
{
    if ((pX - 1 == sx && pY == sy) || (pX - 1 == sx && pY + 1 == sy) || (pX - 1 == sx && pY + 2 == sy))
    {
        energy = energy + 100;
        eraseSpecialPill();
    }
}
void printEnemyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseEnemyBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void generateEnemy3Bullet(int &enemy3RangeCount)
{
    if (enemy3RangeCount % 3 == 0 && getCharAtxy(e3x + 3, e3y + 1) == ' ' && getCharAtxy(e3x - 1, e3y + 1) == ' ')
    {
        if (directionEnemy3 == 1)
        {
            enemy3BulletRightX[enemy3RightCount] = e3x + 3;
            enemy3BulletRightY[enemy3RightCount] = e3y + 1;
            isBullet3RightActive[enemy3RightCount] = true;
            gotoxy(enemy3BulletRightX[enemy3RightCount], enemy3BulletRightY[enemy3RightCount]);
            cout << ".";
            enemy3RightCount = enemy3RightCount + 1;
        }
        else
        {
            enemy3BulletLeftX[enemy3LeftCount] = e3x - 1;
            enemy3BulletLeftY[enemy3LeftCount] = e3y + 1;
            isBullet3LeftActive[enemy3LeftCount] = true;
            gotoxy(enemy3BulletLeftX[enemy3LeftCount], enemy3BulletLeftY[enemy3LeftCount]);
            cout << ".";
            enemy3LeftCount = enemy3LeftCount + 1;
        }
    }
    // getch();
    enemy3RangeCount++;
}
void moveEnemy3Bullet()
{
    // if(  isBullet3RightActive[enemy3RightCount] ){

    for (int x = 0; x < enemy3RightCount; x++)
    {
        if (isBullet3RightActive[x])
        {

            char next1 = getCharAtxy(enemy3BulletRightX[x] + 1, enemy3BulletRightY[x]);
            char next2 = getCharAtxy(enemy3BulletRightX[x] + 2, enemy3BulletRightY[x]);
            char next3 = getCharAtxy(enemy3BulletRightX[x] + 3, enemy3BulletRightY[x]);
            if (next1 != ' ' || next2 != ' ' || next3 != ' ')
            {
                eraseEnemyBullet(enemy3BulletRightX[x], enemy3BulletRightY[x]);
                isBullet3RightActive[x] = false;
            }
            else
            {
                eraseEnemyBullet(enemy3BulletRightX[x], enemy3BulletRightY[x]);
                enemy3BulletRightX[x] = enemy3BulletRightX[x] + 3;
                printEnemyBullet(enemy3BulletRightX[x], enemy3BulletRightY[x]);
            }
        }
    }
    for (int x = 0; x < enemy3LeftCount; x++)
    {
        if (isBullet3LeftActive[x])
        {

            char next1 = getCharAtxy(enemy3BulletLeftX[x] - 1, enemy3BulletLeftY[x]);
            char next2 = getCharAtxy(enemy3BulletLeftX[x] - 2, enemy3BulletLeftY[x]);
            char next3 = getCharAtxy(enemy3BulletLeftX[x] - 3, enemy3BulletLeftY[x]);
            if (next1 != ' ' || next2 != ' ' || next3 != ' ')
            {
                eraseEnemyBullet(enemy3BulletLeftX[x], enemy3BulletLeftY[x]);
                isBullet3LeftActive[x] = false;
            }
            else
            {
                eraseEnemyBullet(enemy3BulletLeftX[x], enemy3BulletLeftY[x]);
                enemy3BulletLeftX[x] = enemy3BulletLeftX[x] - 3;
                printEnemyBullet(enemy3BulletLeftX[x], enemy3BulletLeftY[x]);
            }
        }
    }
    // }
}
void printBulletRight(int x, int y)
{
    gotoxy(x, y);
    cout << (char)175;
}
void printBulletLeft(int x, int y)
{
    gotoxy(x, y);
    cout << (char)174;
}
void printBulletDown(int x, int y)
{
    gotoxy(x, y);
    cout << "|";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletRightInactive(int index)
{
    isBulletRightActive[index] = false;
}
void generatebulletRight()
{
    if (GetAsyncKeyState(0x44) && bulletRightCount != 10)
    {
        bulletRightX[bulletRightCount] = pX + 3;
        bulletRightY[bulletRightCount] = pY + 1;
        isBulletRightActive[bulletRightCount] = true;
        gotoxy(pX + 3, pY + 1);
        cout << (char)175;
        bulletRightCount++;
    }
    moveBulletRight();
}
void moveBulletRight()
{
    for (int x = 0; x < bulletRightCount; x++)
    {
        if (isBulletRightActive[x] == true)
        {
            char next = getCharAtxy(bulletRightX[x] + 1, bulletRightY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletRightX[x], bulletRightY[x]);
                makeBulletRightInactive(x);
                for (int y = x; y < bulletRightCount; y++)
                {
                    bulletRightX[y] = bulletRightX[y + 1];
                    bulletRightY[y] = bulletRightY[y + 1];
                    isBulletRightActive[y] = isBulletRightActive[y + 1];
                }
                bulletRightCount--;
            }
            else
            {
                eraseBullet(bulletRightX[x], bulletRightY[x]);
                bulletRightX[x] = bulletRightX[x] + 1;
                printBulletRight(bulletRightX[x], bulletRightY[x]);
            }
        }
    }
}
void makeBulletLeftInactive(int index)
{
    isBulletLeftActive[index] = false;
}
void generatebulletLeft()
{
    if (GetAsyncKeyState(0x41) && bulletLeftCount != 10)
    {
        bulletLeftX[bulletLeftCount] = pX - 1;
        bulletLeftY[bulletLeftCount] = pY + 1;
        isBulletLeftActive[bulletLeftCount] = true;
        gotoxy(pX - 1, pY + 1);
        cout << (char)174;
        bulletLeftCount++;
    }
    moveBulletLeft();
}
void moveBulletLeft()
{
    for (int x = 0; x < bulletLeftCount; x++)
    {
        if (isBulletLeftActive[x] == true)
        {
            char next = getCharAtxy(bulletLeftX[x] - 1, bulletLeftY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletLeftX[x], bulletLeftY[x]);
                makeBulletLeftInactive(x);
                for (int y = x; y < bulletLeftCount; y++)
                {
                    bulletLeftX[y] = bulletLeftX[y + 1];
                    bulletLeftY[y] = bulletLeftY[y + 1];
                    isBulletLeftActive[y] = isBulletLeftActive[y + 1];
                }
                bulletLeftCount--;
            }
            else
            {
                eraseBullet(bulletLeftX[x], bulletLeftY[x]);
                bulletLeftX[x] = bulletLeftX[x] - 1;
                printBulletLeft(bulletLeftX[x], bulletLeftY[x]);
            }
        }
    }
}
void makeBulletDownInactive(int index)
{
    isBulletDownActive[index] = false;
}
void generatebulletDown()
{
    if (GetAsyncKeyState(0x53) && bulletDownCount != 7)
    {
        bulletDownX[bulletDownCount] = pX + 1;
        bulletDownY[bulletDownCount] = pY + 2;
        isBulletDownActive[bulletDownCount] = true;
        gotoxy(pX + 1, pY + 2);
        cout << "|";
        bulletDownCount++;
    }
    moveBulletDown();
}
void moveBulletDown()
{
    for (int x = 0; x < bulletDownCount; x++)
    {
        if (isBulletDownActive[x] == true)
        {
            char next = getCharAtxy(bulletDownX[x], bulletDownY[x] + 1);
            if (next != ' ')
            {
                eraseBullet(bulletDownX[x], bulletDownY[x]);
                makeBulletDownInactive(x);
                for (int y = x; y < bulletDownCount; y++)
                {
                    bulletDownX[y] = bulletDownX[y + 1];
                    bulletDownY[y] = bulletDownY[y + 1];
                    isBulletDownActive[y] = isBulletDownActive[y + 1];
                }
                bulletDownCount--;
            }
            else
            {
                eraseBullet(bulletDownX[x], bulletDownY[x]);
                bulletDownY[x] = bulletDownY[x] + 1;
                printBulletDown(bulletDownX[x], bulletDownY[x]);
            }
        }
    }
}
void decreaseBoxHealth(int &x, int &y, int &boxHealth)
{
    if (getCharAtxy(x - 1, y) == rightBullet || getCharAtxy(x - 1, y + 1) == rightBullet ||
        getCharAtxy(x - 1, y + 2) == rightBullet || getCharAtxy(x + 3, y) == rightBullet ||
        getCharAtxy(x + 3, y + 1) == rightBullet || getCharAtxy(x + 3, y + 2) == rightBullet ||
        getCharAtxy(x, y - 1) == downBullet || getCharAtxy(x + 1, y - 1) == downBullet ||
        getCharAtxy(x + 2, y - 1) == downBullet || getCharAtxy(x - 1, y) == leftBullet ||
        getCharAtxy(x - 1, y + 1) == leftBullet || getCharAtxy(x - 1, y + 2) == leftBullet ||
        getCharAtxy(x + 3, y) == leftBullet || getCharAtxy(x + 3, y + 1) == leftBullet ||
        getCharAtxy(x + 3, y + 2) == leftBullet)
    {
        boxHealth = boxHealth - 1;
    }
}
void decreaseEnemyHealth(int x, int y, int &enemyHealth)
{
    char one, two, three, four, five, six, seven, eight, nine;
    one = getCharAtxy(x, y - 1);
    two = getCharAtxy(x + 1, y - 1);
    three = getCharAtxy(x + 2, y - 1);
    four = getCharAtxy(x + 3, y);
    five = getCharAtxy(x + 3, y + 1);
    six = getCharAtxy(x + 3, y + 2);
    seven = getCharAtxy(x - 1, y);
    eight = getCharAtxy(x - 1, y + 1);
    nine = getCharAtxy(x - 1, y + 2);

    if (one == downBullet || two == downBullet || three == downBullet || four == leftBullet || five == leftBullet ||
        six == leftBullet || seven == rightBullet || eight == rightBullet || nine == rightBullet)
    {
        enemyHealth = enemyHealth - 5;
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

int lose()
{
    system("cls");
    int x = 55, y = 23;
    gotoxy(x, y++);
    cout << "d8888b. d88888b d888888b d888888b d88888b d8888b.          db      db    db  .o88b. db   dD   \n";
    gotoxy(x, y++);
    cout << "88  `8D 88'     `~~88~~' `~~88~~' 88'     88  `8D          88      88    88 d8P  Y8 88 ,8P'   \n";
    gotoxy(x, y++);
    cout << "88oooY' 88ooooo    88       88    88ooooo 88oobY'          88      88    88 8P      88,8P     \n";
    gotoxy(x, y++);
    cout << "88~~~b. 88~~~~~    88       88    88~~~~~ 88`8b            88      88    88 8b      88`8b     \n";
    gotoxy(x, y++);
    cout << "88   8D 88.        88       88    88.     88 `88.          88booo. 88b  d88 Y8b  d8 88 `88.   \n";
    gotoxy(x, y++);
    cout << "Y8888P' Y88888P    YP       YP    Y88888P 88   YD          Y88888P ~Y8888P'  `Y88P' YP   YD   \n";
    gotoxy(x, y++);
    cout << "                                                                                              \n";
    gotoxy(x, y++);
    cout << "                                                                                              \n";
    gotoxy(x, y++);
    cout << "     d8b   db d88888b db    db d888888b      d888888b d888888b .88b  d88. d88888b    \n";
    gotoxy(x, y++);
    cout << "     888o  88 88'     `8b  d8' `~~88~~'`      ~~88~~'   `88'   88'YbdP`88 88'        \n";
    gotoxy(x, y++);
    cout << "     88V8o 88 88ooooo  `8bd8'     88            88       88    88  88  88 88ooooo    \n";
    gotoxy(x, y++);
    cout << "     88 V8o88 88~~~~~  .dPYb.     88            88       88    88  88  88 88~~~~~    \n";
    gotoxy(x, y++);
    cout << "     88  V888 88.     .8P  Y8.    88            88      .88.   88  88  88 88.        \n";
    gotoxy(x, y++);
    cout << "     VP   V8P Y88888P YP    YP    YP            YP    Y888888P YP  YP  YP Y88888P    \n";

    return 0;
}

string menuOptions()
{
    string option;
    int x = 90, y = 17;
    gotoxy(x, y = y + 4);
    cout << "1. START GAME";
    gotoxy(x, y = y + 4);
    cout << "2. INSTRUCTIONS";
    gotoxy(x, y = y + 4);
    cout << "3. EXIT GAME";

    gotoxy(85, y = 40);
    cout << "Choose what you want to do:";
    cin >> option;

    return option;
}

int win()
{
    system("cls");
    int x = 55, y = 23;
    gotoxy(x, y++);
    cout << " d888b   .d88b.  db      d8888b. d88888b d8b   db        d888b  db       .d88b.  d8888b. db    db \n";
    gotoxy(x, y++);
    cout << "88' Y8b .8P  Y8. 88      88  `8D 88'     888o  88       88' Y8b 88      .8P  Y8. 88  `8D `8b  d8' \n";
    gotoxy(x, y++);
    cout << "88      88    88 88      88   88 88ooooo 88V8o 88       88      88      88    88 88oobY'  `8bd8'  \n";
    gotoxy(x, y++);
    cout << "88  ooo 88    88 88      88   88 88~~~~~ 88 V8o88       88  ooo 88      88    88 88`8b      88    \n";
    gotoxy(x, y++);
    cout << "88. ~8~ `8b  d8' 88booo. 88  .8D 88.     88  V888       88. ~8~ 88booo. `8b  d8' 88 `88.    88    \n";
    gotoxy(x, y++);
    cout << " Y888P   `Y88P'  Y88888P Y8888D' Y88888P VP   V8P        Y888P  Y88888P  `Y88P'  88   YD    YP    \n";
}

void resetGame()
{
    enemy3RangeCount = 0;
    hx = 4, hy = 43;
    sx = 43, sy = 4;
    pX = 3, pY = 2;
    increaseScore = 0;
    increaseCross = 0;
    playerHealth = 100;
    power = 0;
    energy = 0;
    e1x = 33, e1y = 8;
    e2x = 23, e2y = 42;
    e3x = 155, e3y = 29;
    enemyHealth1 = 100;
    enemyHealth2 = 100;
    enemyHealth3 = 100;
    bx1 = 83, by1 = 2;
    bx2 = 103, by2 = 8;
    bx3 = 123, by3 = 14;
    bx4 = 143, by4 = 20;
    increment1Y = 1;
    increment2Y = 1;
    increment3Y = 1;
    increment4Y = 1;
    bulletRightCount = 0;
    bulletLeftCount = 0;
    bulletDownCount = 0;
    enemy3RightCount = 0;
    enemy3LeftCount = 0;
    directionEnemy1 = 1;
    directionEnemy2 = -1;
    directionEnemy3 = -1;
    pill = (char)248;
    pillCount = 0;
    crossCount = 0;
    boxHealth1 = 9;
    boxHealth2 = 9;
    boxHealth3 = 9;
    boxHealth4 = 9;
    rightBullet = (char)175;
    leftBullet = (char)174;
    downBullet = '|';
    healthPill = (char)254;
    specialPill = (char)177;
    bomb = '@';
    timer = 0, timerCount = 0;
}

void printMenu()
{
    system("cls");
    int x = 65, y = 5;
    gotoxy(x, y++);
    cout << " _  ___    _____  _   _     _   _  _____  ___    _  _______  _____  _   _ \n";
    gotoxy(x, y++);
    cout << "(_)|  _`\\ (  _  )( ) ( )   ( ) ( )(  _  )|  _`\\ (_)(_____  )(  _  )( ) ( )\n";
    gotoxy(x, y++);
    cout << "| || (_) )| ( ) || `\\| |   | |_| || ( ) || (_) )| |     /'/'| ( ) || `\\| |\n";
    gotoxy(x, y++);
    cout << "| || ,  / | | | || , ` |   |  _  || | | || ,  / | |   /'/'  | | | || , ` |\n";
    gotoxy(x, y++);
    cout << "| || |\\ \\ | (_) || |`\\ |   | | | || (_) || |\\ \\ | | /'/'___ | (_) || |`\\ |\n";
    gotoxy(x, y++);
    cout << "(_)(_) (_)(_____)(_) (_)   (_) (_)(_____)(_) (_)(_)(_______)(_____)(_) (_)\n";
}

void frame()
{
    int x = 62, y = 19, z = 37;
    gotoxy(x, y++);
    cout << "*********************************************************************************";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*********************************************************************************";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*********************************************************************************";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*                                                                               *";
    gotoxy(x, y++);
    cout << "*********************************************************************************";
    gotoxy(x, z++);
    cout << "*********************************************************************************";
    gotoxy(x, z++);
    cout << "*********************************************************************************";
    gotoxy(x, z++);
    cout << "**                                                                             **";
    gotoxy(x, z++);
    cout << "**                                                                             **";
    gotoxy(x, z++);
    cout << "**                                                                             **";
    gotoxy(x, z++);
    cout << "*********************************************************************************";
    gotoxy(x, z++);
    cout << "*********************************************************************************";
}
