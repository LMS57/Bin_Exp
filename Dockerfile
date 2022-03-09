FROM docker.io/library/debian@sha256:2906804d2a64e8a13a434a1a127fe3f6a28bf7cf3696be4223b06276f32f1f2d

RUN apt-get update -y && apt-get install xinetd -y

RUN mkdir -p /chall

ADD ./buffer_overflow /chall/buffer_overflow
ADD ./format_string /chall/format_string
ADD ./rop /chall/rop
ADD ./type_confusion /chall/type_confusion
ADD ./heap /chall/uheap

#ADD chall.sh /chall
ADD setup.sh /bin/setup.sh
ADD init.sh /bin
#ADD chall.xinetd /etc/xinetd.d/chall

RUN chmod 700 /bin/setup.sh && \
	chmod 700 /bin/init.sh && \
	/bin/setup.sh
#RUN groupadd -r chall && useradd -r -g chall chall && \
#    chown -R root:chall /chall && \
#    chmod 750 /chall/chall.sh && \
#    chmod 750 /chall/chall && \
#    chmod 440 /chall/flag.txt && \

RUN service xinetd restart

ENTRYPOINT [ "/bin/init.sh" ]

