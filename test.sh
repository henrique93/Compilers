#! /bin/bash

# (c) 2016 by Nuno Silva

TESTDIR=/home/klang/Downloads/tests-zu-daily-201604071153/
TESTOUTDIR=/tmp/$USER/out/

test -n "$1" && ZU="$1" || ZU="./zu"
ZU_CMD="$ZU"
#ZU_CMD="$ZU --tree"

function color { COLOR=$1; shift; echo -e "\e[${COLOR}m$@\e[0m" ;}

function red    { color 31 "$@" ;}
function green  { color 32 "$@" ;}
function yellow { color 33 "$@" ;}
function blue   { color 36 "$@" ;}
function gray   { color 90 "$@" ;}
function fatal  { red "fatal: "; echo "$@"; exit 1; }

mkdir -p $TESTOUTDIR
test -r $TESTDIR    || fatal "Test dir '$TESTDIR' not found"
test -w $TESTOUTDIR || fatal "Output fir 'TESTOUTDIR' not found"
if test -z "$1"; then
	test -x $ZU || fatal "$ZU not found. Are you in the project's folder? Did you compile it?"
fi

yellow "Running tests from '$TESTDIR'..."
OK=0
DIFF=0
FAIL=0
NOEXEC=0
TOTAL=0
function inc { let "$1++"; }
function rok {   inc TOTAL; inc OK;   green OK; true; }
function rdiff { inc TOTAL; inc DIFF; yellow DIFF; true; }
function rfail { inc TOTAL; inc FAIL; red "FAIL $1"; true;}
function rnoexec { inc TOTAL; inc NOEXEC; red "NOEXEC ($1 failed)"; true;}
for f in $(find "$TESTDIR" -maxdepth 1 | sort -h ); do
	if test -f $f; then
		NAME=$(basename $f | sed 's/\.zu//')
		blue $NAME
		cat $f | while read l; do gray "$l"; done >&2
		
		rm -f $TESTOUTDIR/$NAME
		error_in="zu not run"
		if ! $ZU > $TESTOUTDIR/$NAME.asm < $f ; then
			error_in="zu"
		else
			if ! yasm -felf32 $TESTOUTDIR/$NAME.asm -o $TESTOUTDIR/$NAME.o ; then
				error_in="yasm"
			else
				if ! ld -m elf_i386 -o $TESTOUTDIR/$NAME $TESTOUTDIR/$NAME.o -lrts; then
					error_in="ld"
				fi
			fi
		fi
		
		if test -x $TESTOUTDIR/$NAME; then
			$TESTOUTDIR/$NAME > $TESTOUTDIR/$NAME.out
			RET=$?
			if test $RET -eq 0; then
				if colordiff --ignore-all-space --ignore-tab-expansion --ignore-blank-lines --strip-trailing-cr  $TESTDIR/expected/$NAME.out $TESTOUTDIR/$NAME.out; then
					rok
				else
					rdiff
				fi
			else
				rfail $RET
			fi
		else
			rnoexec "$error_in"
		fi
	fi
done

gray -------------------------
green "OK: $OK"
yellow "DIFF: $DIFF"
red   "FAIL: $FAIL"
red   "NOEXEC: $NOEXEC"
echo  "TOTAL: $TOTAL"
