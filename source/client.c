#include "cliserv.h"
#include "unp.h"
#include "structs.h"


int main(int argc, char* argv[])
{

    struct login_info account = login();

    unsigned int business = dispaly_client_operator();
    switch (business) {
        case 1: save_money(); break;
        case 2: withdraw_money(); break;
        case 3: transfer_account(); break;
        case 4: modify_user_information(); break;
        default:
    }
}