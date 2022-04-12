#!/bin/bash

qemu-system-x86_64 \
  -kernel ./vmlinux \
  -initrd ./initramfs.cpio.gz \
  -append "console=ttyS0 kaslr panic=-1" \
  -monitor none \
  -nographic \
  -no-reboot \
  -cpu qemu64,+smep,+smap\
  -m 256M \
  -s
