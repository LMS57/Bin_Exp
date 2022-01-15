#!/bin/bash

COUNTER=3000

for dir in /chall/*; do
	echo $dir
	counter2=0
	for x in $dir/*; do
		echo $x
		echo -e "#!/bin/sh

		cd $x && ./chall" >> $x/chall.sh
		groupadd -r $COUNTER -g $COUNTER 
		useradd -r -g $COUNTER $COUNTER && \
		chown -R root:$COUNTER $x && \
		chmod 750 $x/* 
		echo -e "service $COUNTER
		{
		disable = no
		socket_type = stream
		protocol = tcp
		wait = no
		user = $COUNTER
		type = UNLISTED
		bind = 0.0.0.0
		port = $COUNTER
		server = $x/chall.sh
		per_source = 10
		}
		" >> /etc/xinetd.d/$COUNTER
		COUNTER=$((COUNTER+1))
	done
done
