%.d: %.c
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's!\($*\)\.o[ :]*!\1.o $@:!g' < $@.$$$$ > $@; \
	rm -f $@.$$$$