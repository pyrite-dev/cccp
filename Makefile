.PHONY: all format clean
.PHONY: ccc lang cg ie ow

all: ccc

format:
	clang-format --verbose -i `find ccc lang cg ie ow -name "*.c" -or -name "*.h"`

ccc: lang cg ie ow
	cd $@ && $(MAKE) all

lang cg ie ow:
	cd $@ && $(MAKE) all

clean:
	for i in ccc lang cg ie ow; do \
		( cd $$i && $(MAKE) clean ) ; \
	done
