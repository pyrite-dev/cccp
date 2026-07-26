.PHONY: all format clean
.PHONY: ccc misc lang cg ie ow

all: ccc

format:
	clang-format --verbose -i `find ccc misc lang cg ie ow "(" -name "*.c" -or -name "*.h" ")" -and -not -name "stb_*.h"`

ccc: misc lang cg ie ow
	cd $@ && $(MAKE) all

misc lang cg ie ow:
	cd $@ && $(MAKE) all

clean:
	for i in ccc misc lang cg ie ow; do \
		( cd $$i && $(MAKE) clean ) ; \
	done
