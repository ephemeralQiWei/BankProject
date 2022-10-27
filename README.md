# BankProject
A simple bank project based on C/C++


多个用户同时登陆一个账号，阻止其他相同账号登陆
对登陆的账号记录，客户退出则剔除该记录。客户登陆则查询该记录。
目前打算使用hashtable存储记录



# database
## bank card table
bank_card_number customer_id_number password Binding_phone_number
全使用char*，即字符串

## customer information table
id_number name sex birth_date  home_address
字符串    字符串 布尔  日期类型   字符串

## bank card balance table
bank_card_number balance dead/current_deposit Deposit_interest_rate Deposit_start_time(dead deposit) Deposit_duration(dead deposit) 

## log table
日期 时间 银行卡号 业务（存、取、转入、转出、修改个人信息） 相关信息（存、取、转入、转出金额；修改个人什么信息）


