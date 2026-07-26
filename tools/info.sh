#!/bin/sh
w() {
	pre="$2/"
	pre2="/$2"
	suf="_$2"
	if [ "x$2" = "x" ]; then
		pre=""
		pre2=""
		suf=""
	fi

	echo "INC += -I\$(TOP)/$1$pre2" > $1/$2/InfoMakefile
	echo "DEPS += \$(TOP)/$1/$pre$1$suf.a" >> $1/$2/InfoMakefile
	echo "LIBS += \$(TOP)/$1/$pre$1$suf.a" >> $1/$2/InfoMakefile
}

w misc

cat mk/prelude.mk | grep ALL_LANG | cut -d= -f2 | while read i; do
	w lang $i
done
cat mk/prelude.mk | grep ALL_ARCH | cut -d= -f2 | while read i; do
	w cg $i
	w ie $i
done
cat mk/prelude.mk | grep ALL_OBJW | cut -d= -f2 | while read i; do
	w ow $i
done
