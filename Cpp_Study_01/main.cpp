//
//  main.cpp
//  Cpp_Study_01
//
//  Created by ssas on 2015. 5. 7..
//  Copyright (c) 2015년 ShockRabbit. All rights reserved.
//

#include <iostream> // cpp 에서는 보통 iostream

using namespace std;

int iVal = 15;

typedef struct
{
    int iX_;
    int iY_;
}Point;

namespace KJH {
    typedef struct
    {
        char* sName_;
        int   iDamge_;
        Point cPosition_;
    }Player;
}

using namespace KJH;    // 하나만 -> using KJH::Player

typedef struct
{
    int iHp_;
    bool bIsEnemy_; // true 면 적이고 false 면 적이 아니다.
}Monster;

void AttackToMonster(Player& pPlayer, Monster& pMonster)
{
    if (!pMonster.bIsEnemy_)
        return;
    pMonster.iHp_ -= pPlayer.iDamge_;
    if (pMonster.iHp_ < 0)
        pMonster.iHp_ = 0;
    
    // Monster* pMonster; pMonster->iHp_ // (*pMonster).iHp_
}

void AttackToMonster(Player* pPlayer, Monster* pMonster, int iNum=0)
{
    if (!pMonster->bIsEnemy_)
        return;
    pMonster->iHp_ -= pPlayer->iDamge_ * iNum;
    if (pMonster->iHp_ < 0)
        pMonster = 0;
}

Monster* CreateMonster(int iHp, bool bIsEnemy)
{
    Monster* pMonster = new Monster;
    pMonster->iHp_ = iHp;
    pMonster->bIsEnemy_ = bIsEnemy;
    
    return pMonster;
}

void PrintNum(int iNum = 17)
{
    cout<<iNum<<endl;
}

/*
void setPosition(const Point& cPoint)
{
    point.x = cPoint.x;
    point.y = cPoint.y;
}
*/

int main(int argc, const char * argv[]) {
    int iNum = 17;
    const char* sStr = "Hello hahaha!!";
    int iInputNum;
    char cInputStr[255];
    int iVal = 27;
    int iVal2 = 99;
    int& Ref = iVal;
    //int& Ref;             // error
    //int& Ref = 10;        // error
    
    //Player* pPlayer;
    //Monster* pMonster;
    
    //AttackToMonster(pPlayer, pMonster);
    //AttackToMonster(pPlayer, pMonster);
    
    Player cPlayer;
    Monster cMonster;
    AttackToMonster(cPlayer, cMonster);
    
    PrintNum();
    PrintNum(10);
    PrintNum(::iVal);
    PrintNum(iVal);
    Ref += 20;
    PrintNum(iVal);
    
    Ref = iVal2;    // iVal = iVal2
    
    /*
    printf("Num : %d, Str: %s\n", iNum, sStr);  // C style
    
    std::cout<<"Cpp_Num : "<<iNum<<", Str: "<<sStr<<std::endl;  // C++ Style
    
    printf("Input Num : ");
    scanf("%d", &iInputNum);
    printf("Input Str : ");
    scanf("%s", cInputStr);
    printf("result : %d, %s\n", iInputNum, cInputStr);      // C Style
    
    std::cout<<"Input Num : ";
    std::cin>>iInputNum;
    std::cout<<"Input Str : ";
    std::cin>>cInputStr;
    std::cout<<"result : "<<iInputNum<<", "<<cInputStr<<std::endl;  // C++ style
    */
    
    return 0;
}
