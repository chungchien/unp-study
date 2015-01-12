.PHONY: all clean lib

all:
	@echo "nothing to do"

lib:
	$(MAKE) -C lib

clean:
	$(MAKE) clean -C lib
