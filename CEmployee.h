//
// Created by 下水道的小老鼠 on 2023/6/3.
//

#ifndef untitled_EMPLOYEE_H
#define untitled_EMPLOYEE_H

#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct BDay {
    int year;
    int month;
    int day;

    BDay(int y, int m, int d) : year(y), month(m), day(d) {}
};

class CEmployee {
private:
    string _name;                //姓名
    string _sex;                  //性别
    string _kind;                //类型
    BDay _birthday;                //生日，自定义结构BDay，格式：1990-1-1
    double _totalSalary;           //月薪
public:
    //构造函数
    CEmployee(string name, string sex, string kind, BDay birthday, double totalSalary)
            : _birthday(birthday), _totalSalary(totalSalary) {
        _name = name;
        _sex = sex;
        _kind = kind;
    };

    //返回雇员名字
    string getName() {
        return _name;
    }

    string getSex() {
        return _sex;
    }

    string getKind() {
        return _kind;
    }

    BDay getBirthday() {
        return _birthday;
    }

    //返回月薪
    double getTotalSalary() const {
        return _totalSalary;
    }

    void setBirthday(const BDay &birthday) {
        _birthday = birthday;
    }

    void setTotalSalary(double totalSalary) {
        _totalSalary = totalSalary;
    }

    //输出雇员基本信息
    void printData() {
        cout << "Name: " << _name << endl;
        cout << "Sex: " << _sex << endl;
        cout << "Kind: " << _kind << endl;
        cout << "Birthday: " << _birthday.year << "-" << _birthday.month << "-" << _birthday.day << endl;
        cout << "TotalSalary: " << _totalSalary << endl;
    };

    //计算雇员薪水
    void computePay() {
        cout << "TotalSalary: " << _totalSalary << endl;
    };


    //析构函数
    virtual ~CEmployee() = default;
};


#endif //untitled_EMPLOYEE_H
