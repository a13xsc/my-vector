#!/bin/bash

no_tests=10
grade=0
no_leaks=0
no_errors=0

make clean

mkdir output

for i in $(seq 1 $(($no_tests))); do
	make test"$i"
	if [ $? -eq 0 ]; then
		./test"$i" &> "output/test"$i".out"
	else
		echo "" > "output/test"$i".out"
	fi
done

for i in $(seq 1 $(($no_tests))); do
	if [[ -z $(diff "output/test"$i".out" "ref/test"$i".ref") ]]; then 
		grade=$(($grade+10));
		echo "test"$i".............$(tput setaf 2)10$(tput sgr0)"
	else
		echo "test"$i"............. $(tput setaf 1)0$(tput sgr0)"
		diff -q "output/test"$i".out" "ref/test"$i".ref"
	fi
done

# valgrind errors
for i in $(seq 1 $(($no_tests))); do
	ls ./test"$i" &> /dev/null
	if [ $? -eq 0 ]; then
		valgrind -q --log-file=a.out ./test"$i" > /dev/null; 
		if [[ -z $(cat a.out) ]]; then
			no_errors=$((no_errors+1));
		else 
			rm -rf a.out;
			break;
		fi
	fi
	rm -rf a.out
done
#end valgrind errors

if [ $no_errors -eq 0 ]; then
	echo "GRADE.................................$(tput setaf 1)$grade$(tput sgr0)";
	exit -1
fi

if [ $no_errors -ne $no_tests ]; then
	echo "Valgrind errors, so I can not give grade. Need human assistance."
	exit -1
fi

# valgrind bonus
for i in $(seq 1 $(($no_tests))); do
	ls ./test"$i" &> /dev/null
	if [ $? -eq 0 ]; then
		valgrind -q --leak-check=full --log-file=a.out ./test"$i" > /dev/null; 
		if [[ -z $(cat a.out) ]]; then
			no_leaks=$((no_leaks+1));
		else 
			echo "Homework has leaks => no bonus :(";
			rm -rf a.out;
			break;
		fi
	fi
	rm -rf a.out
done


if [ $no_leaks -eq $no_tests ]; then
	grade=$((grade+10))
fi
#end valgrind bonus

echo ""
if [ $grade -ge 100 ]; then
	echo "GRADE.................................$(tput setaf 2)$grade$(tput sgr0)";
elif [ $grade -eq 0 ]; then 
	echo "GRADE.................................$(tput setaf 1)$grade$(tput sgr0)";
else
	echo "GRADE.................................$grade";
fi;

make clean &> /dev/null
