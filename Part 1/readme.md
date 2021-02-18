a simple compiler for a Free Context Grammar.
in this part I've mainly worked on the Scanner and Parser, to check syntax if it's legal or not(for the given language).

this code creates a Abstract Syntax Tree for the given Code.

you can run the code by doing the following command :<br>
`1. lex part1.l`<br>
`2. yacc part1.y`<br>
`3. cc -o outputFile y.tab.c –ll –Ly`<br>
`4. ./outputFile<checkFile.t`<br>

in place of outputFile you can name it any thing you want but don't forget to write the same file name in step 4.
checkFile presents the check File also you name it anything you want.
<hr>
<br>
Some Code snips:<br><br>

```
proc foo(x,y,z:int;f:real){
  if(x>y){
    x=x+f;
  }
  else{
    y=x+y+z;
    x=f*2;
    z=f;
  }
}

func goo() return char{
  return 'a';
}
```


Abstract Syntax Tree:<br>

```
(CODE
(PROC
foo
(ARGS
(int x y z)
(real f)
(BODY
  (IF-ELSE
(> x y)
(BLOCK
(=y (+(+x y)z))
(=x(*f 2 ))
(= z f )
)
))
)
)
FUNC 
goo
(ARGS NONE)
(RET char )
(BODY
  )
(RET 'a')
)
```
