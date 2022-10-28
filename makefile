
VPATH = include:lib:realize:source
vpath %.c source;realize;
vpath %.o lib;
vpath %.h include;

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
	$(cc) -g -c $< -o lib/$@ -Iinclude

service : ${servRelyObjs}
	$(cc) $^ -o service

$(servRelyObjs) : %.o : %$(suffix)
	$(cc) -g -c $< -o lib/$@ -Iinclude

.PHONY : cleanall cleanobj cleantarget
cleanall : cleanobj cleantarget
cleanobj :
	rm -f lib/*.o
cleantarget :
	rm -f client service