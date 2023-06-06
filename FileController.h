//
// Created by 下水道的小老鼠 on 2023/6/3.
//

#ifndef UNTITLED_FILECONTROLLER_H
#define UNTITLED_FILECONTROLLER_H

#include "CEmployee.h"
#include <optional>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class FileController {
public:

    /**
     * 读取文件中的数据
     *
     * @param filename 文件名
     * @return
     */
    static vector<CEmployee> readEmployeesFromFile(const string &filename) {
        vector<CEmployee> employees;
        ifstream infile(filename);

        if (!infile.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return employees;
        }

        string line;
        while (getline(infile, line)) {
            istringstream iss(line);
            vector<string> tokens;
            string token;

            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() == 5) {
                BDay birthday = BDay(0, 0, 0);
                std::stringstream ss(tokens[3]);
                ss >> birthday.year;
                ss.ignore();
                ss >> birthday.month;
                ss.ignore();
                ss >> birthday.day;
                employees.emplace_back(tokens[0].c_str(), tokens[1].c_str(), tokens[2].c_str(), birthday,
                                       stod(tokens[4]));
            } else {
                cout << "Invalid line: " << line << endl;
            }
        }

        infile.close();
        return employees;
    }

    /**
     * 向文件中写入员工数据
     *
     * @param employees 员工的数据
     * @param filename 要写入的文件名
     */
    static void writeEmployeeToFile(vector<CEmployee> &employees, const string &filename) {
        // ios_base::app 表示在文件尾部添加新数据
        ofstream outfile(filename, ios_base::app);

        if (!outfile.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return;
        }
        for (CEmployee employee: employees) {
            outfile << employee.getName() << "," << employee.getSex() << "," << employee.getKind() << ","
                    << employee.getBirthday().year << "-"
                    << employee.getBirthday().month << "-"
                    << employee.getBirthday().day << ","
                    << employee.getTotalSalary() << endl;
        }

        outfile.close();
    }

    /**
     * 根据名字删除文件中文件中员工信息
     *
     * @param name 员工名字
     * @param filename 文件名
     */
    static void deleteEmployeeFromFile(const string &name, const string &filename) {
        std::ifstream infile(filename);
        //ios_base::trunc 是指如果文件已经存在，则先删除源文件，然后重新创建一个空文件，以便进行下一步的写入操作
        std::ofstream outfile("temp.data", ios_base::trunc);

        if (!infile.is_open() || !outfile.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        bool found = false;
        while (std::getline(infile, line)) {
            istringstream iss(line);
            vector<std::string> tokens;
            string token;

            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            // 判断是否为要删除的行
            if (!tokens.empty() && tokens[0] == name) {
                found = true;
                //跳过这次循环，不将此行输出到临时文件中
                continue;
            }

            //将不是要删除的行复制到临时文件
            outfile << line << endl;
        }

        infile.close();
        outfile.close();

        //如果没有要删除的行，则要删除掉临时文件
        if (!found) {
            cout << "Could not find employee: " << name << endl;
            remove("temp.data");
            return;
        }

        //删除之前的文件，并将临时文件改名为原来的文件名
        remove(filename.c_str());
        rename("temp.data", filename.c_str());

        cout << "Deleted employee: " << name << endl;
    }

    /**
     * 根据员工名字修改员工的信息
     *
     * @param name 员工名字
     * @param employee 员工要修改后的信息
     * @param filename 文件名
     */
    static void UpdateEmployeeFromFile(const string &name, CEmployee employee, const string &filename) {
        std::ifstream infile(filename);
        std::ofstream outfile("temp.data", ios_base::trunc);

        if (!infile.is_open() || !outfile.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return;
        }

        std::string line;
        bool found = false;
        while (std::getline(infile, line)) {
            istringstream iss(line);
            vector<std::string> tokens;
            string token;

            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            // 判断是否为要修改的行
            if (!tokens.empty() && tokens[0] == name) {
                found = true;
                //将要修改的数据输出到临时文件
                outfile << employee.getName() << "," << employee.getSex() << "," << employee.getKind() << ","
                        << employee.getBirthday().year << "-"
                        << employee.getBirthday().month << "-"
                        << employee.getBirthday().day << ","
                        << employee.getTotalSalary() << endl;
                //跳过这次循环，不仔将此行输出到临时文件中
                continue;
            }

            //将不是要修改的行复制到临时文件
            outfile << line << endl;
        }

        infile.close();
        outfile.close();

        //如果没有要删除的行，则要删除掉临时文件
        if (!found) {
            cout << "Could not find employee: " << name << endl;
            remove("temp.data");
            return;
        }

        //删除之前的文件，并将临时文件改名为原来的文件名
        remove(filename.c_str());
        rename("temp.data", filename.c_str());

        cout << "Update employee: " << name << endl;
    }

    /**
     * 根据员工名字查询员工
     *
     * @param name 员工名字
     * @param filename 文件名
     * @return
     */
    static optional<CEmployee> searchByNameFormFile(const string &name, const string &filename) {
        std::ifstream infile(filename);

        if (!infile.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            //返回空指针  引入的 optional 来表示一个值或者空值
            return nullopt;
        }

        std::string line;
        bool found = false;
        while (std::getline(infile, line)) {
            istringstream iss(line);
            vector<std::string> tokens;
            string token;

            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            // 判断是否为要搜索的员工
            if (!tokens.empty() && tokens[0] == name) {
                BDay birthday = BDay(0, 0, 0);
                std::stringstream ss(tokens[3]);
                ss >> birthday.year;
                ss.ignore();
                ss >> birthday.month;
                ss.ignore();
                ss >> birthday.day;
                CEmployee cEmployee(tokens[0].c_str(), tokens[1].c_str(), tokens[2].c_str(), birthday,
                                    stod(tokens[4]));
                found = true;
                cout << "find employee: " << name << endl;
                return cEmployee;
            }

        }

        infile.close();

        //如果没有找到指定员工返回空指针
        if (!found) {
            cout << "Could not find employee: " << name << endl;
            return nullopt;
        }
    }

    /**
     * 根据员工职位查询员工
     *
     * @param type 职位
     * @param filename 文件名
     * @return
     */
    static vector<CEmployee> searchByTypeFromFile(const string &type, const string &filename){
        vector<CEmployee> employees;
        ifstream infile(filename);

        if (!infile.is_open()) {
            cout << "Error opening file: " << filename << endl;
            return employees;
        }

        string line;
        while (getline(infile, line)) {
            istringstream iss(line);
            vector<string> tokens;
            string token;

            while (getline(iss, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() == 5 && tokens[2] == type) {
                BDay birthday = BDay(0, 0, 0);
                std::stringstream ss(tokens[3]);
                ss >> birthday.year;
                ss.ignore();
                ss >> birthday.month;
                ss.ignore();
                ss >> birthday.day;
                employees.emplace_back(tokens[0].c_str(), tokens[1].c_str(), tokens[2].c_str(), birthday,
                                       stod(tokens[4]));
            } else {
                cout << "Invalid line: " << line << endl;
            }
        }

        infile.close();
        return employees;
    }
};

#endif //UNTITLED_FILECONTROLLER_H
