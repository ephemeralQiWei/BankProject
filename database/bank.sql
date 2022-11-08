DROP TABLE IF EXISTS customer;
DROP TABLE IF EXISTS account;
DROP TABLE IF EXISTS curdep;

CREATE TABLE customer (
    IDNo        VARCHAR(18) primary key               comment '身份证号码',
	name        VARCHAR(20) not null                  comment '姓名',
    gender      TINYINT     not null DEFAULT 1        comment '性别', 
    nation      VARCHAR(20) not null DEFAULT '中国-汉族' comment '国家民族',
    birthday    DATE        not null                  comment '出生日期',
	address     VARCHAR(30) not null                  comment '常住户口所在地住址'
) comment '用户信息表' ;

CREATE TABLE account (
    accountNo   VARCHAR(18)         primary key     comment '账户号',
    IDNo        VARCHAR(18)         not null        comment '身份证号码',
    password    VARCHAR(28)         not null        comment '账户密码',
	business    SMALLINT unsigned   not null        comment '业务'
) comment '账户信息表' ;

CREATE TABLE curdep (
    accountNo   VARCHAR(18)     primary key             comment '账户号',
    balance     DOUBLE          check (balance >= 0)    comment '余额',
    settlement  DATE            not null                comment '上次结息时间'
) comment '活期存款表' ;

insert into customer(IDNo, name, gender, nation, birthday, address)
values('340823199704011111', 'qiwei', 1, '中国', '1997-04-01', '安徽');

insert into account(accountNo, IDNo, password, business)
values('987654321', '340823199704011111', '123456789', 1);
 
insert into curdep(accountNo, balance, settlement)
values('987654321', 98.43, '2020-02-02'); 

