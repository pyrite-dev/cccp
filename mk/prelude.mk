include $(TOP)/mk/config.mk

ALL_LANG = bcpl
ALL_ARCH = x86
ALL_OBJW = elf
INC = -I$(TOP)/cominc

.PHONY: all clean
.SUFFIXES: .c .o
