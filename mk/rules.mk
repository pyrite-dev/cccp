$(NAME).a: $(OBJS) $(DEPS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(NAME)$(EXEC): $(OBJS) $(DEPS)
	$(CC) $(LDFLAGS) $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -f *.o $(NAME) $(NAME).exe $(NAME).a
