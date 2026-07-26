TOP = ..

include $(TOP)/mk/prelude.mk

NAME = ccc
all: $(NAME)$(EXEC)

OBJS = main.o cmd.o
DEPS = ../lang/*/*.a ../cg/*/*.a ../ie/*/*.a ../ow/*/*.a
LIBS += $(DEPS)

include $(TOP)/mk/rules.mk
