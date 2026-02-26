# TODO: Create a script that parse the .test file into input and output format
#       The scripts would parse it line-by-line and each line's output would be piped to the program's binary stdin as 'args'
#
#       Format:
#       ```test
#       [args1,args2,args3,...,argsN]
#       ans1 ans2 ans3 ... ansN
#       ```
#           args (stdin) would be the input
#           ans (stdout) woudl be the output
#
#       The script would check whether the stdout from the binary matches the 'ans' from .test file
#       If yes, echo the passing test cases and the execution time for each tc
#       If no, echo the failing test cases and the expected vs given output
