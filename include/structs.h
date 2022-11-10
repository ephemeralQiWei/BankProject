#pragma once

#define ACCOUNT_LEN 30

struct customer_info
{
    char card_no[20];  // length of card number is 19
    char password[20];
};

struct save_withdraw //sw
{
    unsigned int swcode;  // 0: save;  1: withdraw;
    double money;
};

struct user_info_modify //uim
{
    unsigned int uimcode;  // 0: password;  1: phone number;
    char newInfo[30];
};

struct transfer_account //ta
{
    char target_account[ACCOUNT_LEN];
    double money;
};

struct request
{
    unsigned int req_code;
    union {
        struct save_withdraw sw;
        struct user_info_modify uim;
        struct transfer_account ta;
    };
};


struct name_balance
{
    char name[30];
    double balance;
}

struct response
{
    unsigned int res_code;
    union {
        struct name_balance nb;
        struct user_info_modify uim;
        struct transfer_account ta;
    };
};