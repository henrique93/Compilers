#!/bin/bash

#echo "You want all the tests?"
#read cenas

#if test $cenas=="y";then
echo "-----START TESTS-----"

for i in $(ls ~/Downloads/tests-zu-daily-201604071153/*.zu) ;do 
	./zu $i; 
done

echo "-----END TESTS-----"
#fi
