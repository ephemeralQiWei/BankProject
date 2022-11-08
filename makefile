
VPATH = include:lib:realize:source
vpath %.c source:realize
vpath %.o lib
vpath %.h include:/home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/include

headpath = include /home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/include

suffix := .c
cc = gcc
ifeq ($(cc), g++)
	suffix := .cpp
endif


clientRely = client cliserv unp customer warpsock
servRely = service cliserv unp server warpsock

clientRelyObjs = $(clientRely:%=%.o)
servRelyObjs = $(servRely:%=%.o)

target : client service

client : $(clientRelyObjs)
	$(cc) $^ -o client

$(clientRelyObjs) : %.o : %$(suffix)
	$(cc) -g -c $< -o lib/$@ $(headpath:%=-I%)

service : ${servRelyObjs}
	$(cc) $^ -o service -L/home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/lib -lmysqlclient

$(servRelyObjs) : %.o : %$(suffix)
	$(cc) -g -c $< -o lib/$@ $(headpath:%=-I%)

.PHONY : target cleanall cleanobj cleantarget
cleanall : cleanobj cleantarget
cleanobj :
	rm -f lib/*.o
cleantarget :
	rm -f client service