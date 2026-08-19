#include <iostream>
#include <string>
#include "Staffsystem.h"

using namespace std;

int main() {

    Staffsystem myStaff;
    myStaff.ShowMenu();
    
    int Select;
    while(cin >> Select && Select != 0) {
        switch(Select) {
            case 1: { //添加职工
                myStaff.AddStaff();
                break;
            }

            case 2: { //显示职工
                myStaff.ShowStaff();
                break;
            }

            case 3: { //删除职工
                myStaff.DeleteStaff();
                break;
            }

            case 4: { //修改职工
             //   myStaff.ModifyStaff();
                break;
            }

            case 5: { //查询职工
                if(!myStaff.CheckEmpty()) {
                    cout << "职工列表为空！" << endl;
                    system("pause");
                    system("cls");
                    break;
                }

                int i = myStaff.FindStaff();

                if(i == -1) cout << "查无此人！" << endl;
                else {
                    cout << "成功查找到该职工：" << endl;
                    myStaff.StaffArray[i]->showifo();
                }
                system("pause");
                system("cls");
                break;
            }

            case 6: { //按号排序
            //    myStaff.SortStaff();
                break;
            }

            case 7: { //清空文档

                break;
            }

            default: {
                cout << "输入有误，请重新输入！" << endl;
                system("pause");
                system("cls");
            }
                
        }
        myStaff.ShowMenu();
    }

    cout << "成功退出职工管理系统，欢迎下次使用！" << endl;

    system("pause");

    return 0;
} 