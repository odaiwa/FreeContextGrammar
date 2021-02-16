a simple compiler for a Free Context Grammar.
in this part I've mainly worked on the Three Address Code (TAC) generator for the language.

this code generates Three Address Code.

you can run the code by doing the following command :<br>
`1. lex part3.l`,<br>
`2. yacc part3.y`<br>
`3. cc -o outputFile y.tab.c –ll –Ly`<br>
`4. ./outputFile<checkFile.t`<br>

in the place of output file you can name it any thing you want but forget to write the same file name in step 4.

Some Examples For Code to Three-Address-Code:<br>
Input:<br>
```
func foo(x:real)return int
{
  var a:int;
  a=23;
  if(a==23)
    a=10;
  else
    a=19;
  return a;
}
proc Main()
{
  var i,a,c,b:int;
  a=0;
  while(a<0){
    b=foo(3.14);
    a=a+b;
  }
}
```
<hr>
Output:<br>
```

```
foo:
  BeginFunc
  a=23
  if a == 23 goto L1
  goto L2
L1: a=10
  goto L3
L2: a=19
L3: return a
  EndFunc

Main:
  BeginFunc
  a=0
L4: if a<0 goto L5
  goto L6
L5: PushParam 3.14
  t0 = LCALL foo
  PopParams 8
  b=t0
  t1=a+b
  a=t1
  goto L4
L6: EndFunc
