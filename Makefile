.PHONY: all format clean
.PHONY: llpg ccc misc lang cg ie ow

all: llpg ccc

format:
	clang-format --verbose -i `find ccc llpg cominc misc lang cg ie ow "(" -name "*.c" -or -name "*.h" ")" -and -not -name "stb_*.h"`

llpg: misc
	cd $@ && $(MAKE) all

ccc: misc lang cg ie ow
	cd $@ && $(MAKE) all

misc lang cg ie ow:
	cd $@ && $(MAKE) all

clean:
	for i in ccc llpg misc lang cg ie ow; do \
		( cd $$i && $(MAKE) clean ) ; \
	done
