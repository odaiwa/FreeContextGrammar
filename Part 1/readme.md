a simple compiler for a Free Context Grammar.
in this part I've mainly worked on the Scanner and Parser, to check syntax if it's legal or not(for the given language).

this code creates a Abstract Syntax Tree for the given Code.

you can run the code by doing the following command :
`1. lex part1.l`
`2. yacc part1.y`
`3. cc -o outputFile y.tab.c –ll –Ly`
`4. ./outputFile<checkFile.t`

in the place of output file you can name it any thing you want but forget to write the same file name in step 4.
