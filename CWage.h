//
// Created by 下水道的小老鼠 on 2023/6/3.
//

#ifndef untitled_CWAGE_H
#define untitled_CWAGE_H

#include "CSales.h"
#include <iostream>
#include <string>

using namespace std;

class CWage : public CSales {
//根据你的设计自定义类CWage，月薪=浮动奖金+销售提成
//浮动奖金和销售提成的值自定义
private:
    double moneyBonus;         // 浮动奖金
    double moneyCommission;    // 销售提成
public:
    CWage(const char *name, const char *sex, const char *kind, BDay birthday,
          double bonus, double commission) : moneyBonus(bonus), moneyCommission(commission),
                                             CSales(name, sex, kind, birthday, 0.0, 0.0) {}

    // 计算月薪，等于浮动奖金加上销售提成
    void monSalary() {
        cout << "monSalary = " << moneyBonus + moneyCommission << endl;
    }

    ~ CWage() override {};
};

#endif //untitled_CWAGE_H
