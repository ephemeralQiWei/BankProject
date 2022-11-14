
VPATH = include:lib:realize:source
vpath %.c source:realize
vpath %.o lib
vpath %.h include:/home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/include

headpath = include /home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/include
linkedpath = /home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/lib

suffix := .c
cc = gcc
ifeq ($(cc), g++)
	suffix := .cpp
endif


clientRely = client customer
servRely = service server
collectiveReliances = cliserv unp warpsock

clientRelyObjs = $(clientRely:%=%.o) $(collectiveReliances:%=%.o)
servRelyObjs = $(servRely:%=%.o) $(collectiveReliances:%=%.o)

target : client service

client : $(clientRelyObjs)
	$(cc) $(patsubst %.o,lib/%.o, $^) -o $@

service : ${servRelyObjs}
	$(cc) $(patsubst %.o,lib/%.o, $^) -o $@ -L/home/qiwei/下载/mysql-8.0.31-linux-glibc2.12-x86_64/lib -lmysqlclient

$(clientRely:%=%.o) : %.o : %$(suffix)
	$(cc) -g -c $< -o lib/$@ $(headpath:%=-I%)

$(servRely:%=%.o) : %.o : %$(suffix)
	$(cc) -g -c $< -o lib/$@ $(headpath:%=-I%)

$(collectiveReliances:%=%.o) : %.o : %$(suffix)
	$(cc) -g -c $< -o lib/$@ $(headpath:%=-I%)

.PHONY : target cleanall cleanobj cleantarget
cleanall : cleanobj cleantarget
cleanobj :
	rm -f lib/*.o
cleantarget :
	rm -f client service