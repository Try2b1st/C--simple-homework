//
// Created by ��ˮ����С���� on 2023/6/13.
//

#ifndef UNTITLED_USERCONTROLLER_H
#define UNTITLED_USERCONTROLLER_H

#include <regex>

using namespace std;

class UserController {
public:
    static bool UserIsAdmin(string userName, string passWord) {
        //����������ʽ
        regex regEx("[ _`~!@#$%^&*()+=|{}':;',\\[\\].<>/?~��@#��%����&*��������+|{}������������������������\n\r\t]");

        //���û����Ƿ��ǰ��������ַ�
        bool result = regex_search(userName, regEx);
        if (result) {
            return false;
        }

        if (userName == "wsRoot" && passWord == "123456789") {
            return true;
        } else {
            return false;
        }

    }
};

#endif //UNTITLED_USERCONTROLLER_H
