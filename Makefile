.PHONY: all format clean
.PHONY: pargen ccc misc lang cg ie ow

all: pargen ccc

format:
	clang-format --verbose -i `find ccc pargen cominc misc lang cg ie ow "(" -name "*.c" -or -name "*.h" ")" -and -not -name "stb_*.h"`

pargen: misc
	cd $@ && $(MAKE) all

ccc: misc lang cg ie ow
	cd $@ && $(MAKE) all

misc lang cg ie ow:
	cd $@ && $(MAKE) all

clean:
	for i in ccc pargen misc lang cg ie ow; do \
		( cd $$i && $(MAKE) clean ) ; \
	done
