#!/bin/bash

# TODO: Create a script that parse the .test file into input and output format
#       The scripts would parse it line-by-line and each line's output would be piped to the program's binary stdin as 'args'
#
#       Format:
#       ```test
#       [args1 args2 args3 ... argsN]
#       ans1 ans2 ans3 ... ansN
#       ```
#           args (stdin) would be the input
#           ans (stdout) woudl be the output
#
#       The script would check whether the stdout from the binary matches the 'ans' from .test file
#       If yes, echo the passing test cases and the execution time for each tc
#       If no, echo the failing test cases and the expected vs given output
RED='\e[0;31m'
GREEN='\e[0;32m'
NC='\e[0m' # No Color (Reset)

FILENUM=$1
SOLUTION_DIR="./solutions/"
TESTFILE_DIR="./testfiles/"

# for arg in $@; do
#     if [[ $arg == "-p" ]]; then
#         echo $arg
#         shift 2
#         if [[ ! -z $arg ]]; then
#             echo $arg
#             continue
#         fi
#         continue
#     fi
# done

if [[ -z $FILENUM ]]; then
    read -p "File number: " FILENUM
fi

if [[ ! -d $SOLUTION_DIR ]]; then
    mkdir $SOLUTION_DIR
fi

if [[ ! -d $TESTFILE_DIR ]]; then
    mkdir $TESTFILE_DIR
fi

SOLUTION_FILE=$(ls -A --recursive ./solutions/ | grep "^$FILENUM.*\.c$")
TEST_FILE=$(echo "$SOLUTION_FILE" | grep -oP ".*(?=\.c$)").test

if [[ -z $SOLUTION_FILE ]]; then
    echo -e "${RED}ERROR! Solution for problem number ${FILENUM} does not exist!${NC}"
    echo -e "Make sure to place your file in '${SOLUTION_DIR}' with format:\n\n${GREEN}[problem_number]-[problem]-[title].c${NC}\n"
    exit 1
elif [[ ! -f $TESTFILE_DIR$TEST_FILE ]]; then
    echo -e "${RED}ERROR! Test file for problem number ${FILENUM} does not exist!${NC}"
    echo -e "Make sure to place your test file in '${TESTFILE_DIR}' with format:\n\n${GREEN}[problem_number]-[problem]-[title].test${NC}\n"
    exit 1
fi

# echo "Compiling $SOLUTION_FILE..."

if [[ -f test ]]; then
    make clean
fi

make filename=$SOLUTION_FILE

# TEST_COUNT=$(($(wc -l <./testfiles/$TEST_PATH) / 2))
COUNT=1

while read -r raw_input && read -r expected; do
    input_clean=${raw_input//[\[\]]/}

    start_time=$(date +%s%N)

    actual=$(echo "$input_clean" | ./test)

    end_time=$(date +%s%N)
    elapsed=$(((end_time - start_time) / 1000000))

    if [[ $actual == $expected ]]; then
        echo -e "TC ${COUNT}: ${GREEN}[PASS]${NC} ${elapsed}ms"
    else
        echo -e "TC ${COUNT}: ${RED}[FAIL]${NC}"
        echo -e "\tInput\t: $input_clean"
        echo -e "\t${GREEN}Expected: $expected${NC}"
        echo -e "\t${RED}Actual\t: $actual${NC}"
    fi

    ((COUNT++))
done <"$TESTFILE_DIR$TEST_FILE"
