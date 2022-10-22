
VPATH = include:lib:realize:source
vpath %.c source;realize;
vpath %.o lib;
vpath %.h include;

suffix := .c
cc = gcc
ifeq ($(cc), g++)
	suffix := .cpp
endif


clientRely = client cliserv unp

clientRelyObjs = $(clientRely:%=%.o)


target : client service

client : %(clientRelyObjs)
	%(cc) %(clientRelyObjs) -o client

%(clientRelyObjs) : %.o : %$(suffix)
	$(cc) -c $< -o lib/$@ -Iinclude


.PHONY : cleanall cleanobj cleantarget
cleanall : cleanobj cleantarget
cleanobj :
	rm -f lib/*.o
cleantarget :
	rm -f client service