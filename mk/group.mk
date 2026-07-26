include $(TOP)/mk/prelude.mk

.PHONY: $(ALL_$(TYPE))

all: $(ALL_$(TYPE))

$(ALL_$(TYPE)):
	cd $@ && $(MAKE) all

clean:
	for i in $(ALL_$(TYPE)); do \
		( cd $$i && $(MAKE) clean ) ; \
	done
