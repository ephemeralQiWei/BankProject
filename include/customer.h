#pragma once

#include "structs.h"

int customer_login(struct customer_info *ci, struct name_balance *nb);

unsigned int login_page();

unsigned int dispaly_client_operator();

void save_money();

void withdraw_money();

void transfer_account();

void modify_user_information();