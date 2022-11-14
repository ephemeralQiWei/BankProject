#include "cliserv.h"
#include "customer.h"
#include "unp.h"
#include "structs.h"


int main(int argc, char* argv[])
{
    unsigned int visitor = login_page(); // register new customer
    switch (visitor) {
        case 1: goto customer; break;
        default: err_sys("not visitor\n");
    }
    
    struct customer_info ci;
    unsigned int business;
    struct response res;
    struct name_balance nb;

    int sockfd;

customer:
    sockfd = customer_login(&ci, &nb);
    printf("您好, %s！\n您的账户余额: %f元\n", nb.name, nb.balance);
    _Bool over = 0;
    while (!over) {
        business = dispaly_client_operator();
        switch (business) {
            case 1: save_money(); break;
            case 2: withdraw_money(); break;
            case 3: transfer_account(); break;
            case 4: modify_user_information(); break;
            default: err_sys("not business\n");
        }
    }
goto end;

administrator:
goto end;

end:
    ;

}


/*
    用对象封装，比如 客户、管理者（有共同的抽象基类，有纯虚方法execute（））  对应着不同的对象，  但是在获得对象之后都执行execute方法
    每个对象都有各自的成员方法，对应着不同的功能，而execute方法会调用对应的功能成员函数，完成对应角色的任务。
    这样的话，该程序具有扩张性，当有新的角色使用客户端，则继承抽象基类，实现纯虚方法即可，并根据自己需求的功能实现自己的成员函数

*/