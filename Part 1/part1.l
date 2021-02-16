/*Scanner-file*/
%{
#include<stdio.h>
#include<string.h>
%}

%%
  /*Types /*Keywords Lexemes*/
bool {return BOOL;}
char {return CHAR;}
int {return INT;}
real {return REAL;}
string {return STRING;}
int\* {return INTPTR;}
char\* {return CHARPTR;}
real\* {return REALPTR;}

  /*Statement -Loops*/
if {return IF;}
else {return ELSE;}
while {return WHILE;}
for {return FOR;}
var {return VARIABLE;}
func {return FUNCTION;}
proc {return PROCEDUR;}
null {return NULLL;}
Main {return MAIN;}
 
  /*Operators*/
"&&" {return AND;}
"/" {return DIVISION;}
"=" {return ASSINGMENT;}
"==" {return EQL;}
">" {return GREATER;}
">=" {return GREATEREQL;}
"<" {return LESS;}
"<=" {return LESSEQL;}
"-" {return MINUS;}
"!" {return NOT;}
"!=" {return NOTEQL;}
"||" {return OR;}
"+" {return PLUS;}
"*" {return MULTI;}
"&" {return ADDRESS;}
"^" {return DEREFRENCE;}

  /*Other Lexemes*/
"|" {return LENGTH;}
";" {return SEMICOLON;}
":" {return COLON;}
"," {return COMMA;}
"{" {return OPENBRACE;}
"}" {return CLOSEBRACE;}
"(" {return OPENPAREN;}
")" {return CLOSEPAREN;}
"[" {return OPENBRACKET;}
"]" {return CLOSEBRACKET;}
 
 "/""%".*"%""/" {yylval.str=strdup(yytext);return COMMENT;}

  /*Literl*/
return {return RETURN;}
true {return BOOLTRUE;}
false {return BOOLFALSE;}
[a-zA-Z][a-zA-Z0-9_]* {yylval.str=strdup(yytext);return IDENTIFIER;}
"\""[^"]*"\"" {yylval.str=strdup(yytext);return STRING_LTL;}
\'.\' {yylval.str=strdup(yytext);return CHAR_LTL;}
[+-]?[1-9][0-9]*|[0-9] {yylval.str=strdup(yytext);return DECIMAL_LTL;}
0(x|X)[0-9A-F]+ {yylval.str=strdup(yytext);return HEX_LTL;}
[-+]?[0-9]*\.?[0-9]*[eE]?[-+]?[0-9]+ {yylval.str=strdup(yytext);return REAL_LTL;}


[\n] {yylineno++;} //For each line (enter=\n), do yylineo+=1
[ \t]+ ;
. return yytext[0];
%%

