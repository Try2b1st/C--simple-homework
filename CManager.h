//
// Created by 下水道的小老鼠 on 2023/6/3.
//

#ifndef untitled_MANAGER_H
#define untitled_MANAGER_H

#include "CEmployee.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class CManager : public CEmployee {
private :
    int late;                    //迟到天数，迟到1天扣50元
    int leave;                //请假天数，迟到1天扣200元
    double salary = 1000;        //经理固定薪水1000元
public:
    //重载构造函数：参数自定义
    CManager(const char *name, const char *sex, const char *kind, BDay birthday, int lateDays, int leaveDays)
            : late(lateDays), leave(leaveDays),
              CEmployee(name, sex, kind, birthday, (1000 - lateDays * 50 - leaveDays * 200)) {};

    //输出经理信息
    void printData()  {
        cout << "Name: " << getName() << endl;
        cout << "Sex: " << getSex() << endl;
        cout << "Kind: " << getKind() << endl;
        cout << "Birthday: " << getBirthday().year << "-" << getBirthday().month << "-" << getBirthday().day << endl;
        cout << "late: " << late <<endl;
        cout << "leave: " << leave <<endl;
        cout << "salary: " << salary <<endl;
        cout << "TotalSalary: " << getTotalSalary() << endl;
    };

    //计算经理月薪：salary=固定薪水－扣款
    void computePay() {
        cout << "computePay = " << (salary - late * 50 - leave * 200);
    };

    double getComputePay() {
        return (salary - late * 50 - leave * 200);
    }

    //析构函数
    ~CManager() override = default;

};

#endif //untitled_MANAGER_H
