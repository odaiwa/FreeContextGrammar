a simple compiler for a Free Context Grammar.
in this part I've mainly worked on the Semantic Rules, to check Semantic if it's legal or not(for the given language).

this code checkes if the given code is semantically Correct.

you can run the code by doing the following command :
`1. lex part2.l`
`2. yacc part2.y`
`3. cc -o outputFile y.tab.c –ll –Ly`
`4. ./outputFile<checkFile.t`

in place of outputFile you can name it any thing you want but don't forget to write the same file name in step 4.
checkFile presents the check File also you name it anything you want.


Some Examples For Code With semantic Errors:
this codee example contains two mains and that is not allowed in the language.
`proc Main(){
	var x : int;
	if(x != x)
	{
		x = 3;
	}
}
proc Main(){
	var x : int;
	if(x != x)
	{
		x = 3;
	}
}`	

Semantic Error Returned:
  Error syntax error at line 11
  does not accept 'proc'
