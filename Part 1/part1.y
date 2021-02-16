%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;
	node* mknode(char* token, node *left, node *right);
	void Printtree(node *tree);
	void printTree(node *tree);
	void printcomment(const char* str);
	void printTabs(int n);
	int printlevel=0;
	int yydebug=1; 
%}
%union{
	char* str;
	struct node* node;
	int num;
}



%token <str> COMMENT WHILE IF ELSE FOR 
%token <str> RETURN
%token <str> BOOL STRING CHARPTR CHAR INT INTPTR PROCEDUR
%token <str> AND ADDRESS EQL ASSINGMENT OR LENGTH GREATEREQL GREATER LESSEQL LESS NOTEQL NOT
%token <str> DIVISION PLUS MINUS MULTI VARIABLE
%token <str> STRING_LTL REAL_LTL CHAR_LTL NULLL
%token <str> MAIN IDENTIFIER SEMICOLON COMMA OPENPAREN CLOSEPAREN OPENBRACKET CLOSEBRACKET OPENBRACE CLOSEBRACE
%token <str> DECIMAL_LTL HEX_LTL BOOLTRUE BOOLFALSE  REAL REALPTR FUNCTION COLON  DEREFRENCE


%type <node> project program procedures main type_pro pro_body procedure 
%type <node> para_pro para_list declears declear var_id type_id RET
%type <node> stmnts stmnt stmnt_block new_block expr
%type <node> assmnt_stmnt lhs derefrence_expr address_exprs
%type <node> call_func address_expr expr_list paren_expr
%type <str> cmmnt

%left PLUS MINUS RETURN
%left MULTI DIVISION
%left EQL NOTEQL LESS LESSEQL GREATEREQL GREATER OR AND
%left SEMICOLON 
%right NOT CLOSEBRACE

%nonassoc IDENTIFIER 
%nonassoc OPENPAREN
%nonassoc IF
%nonassoc ELSE 

%%
 //Main project
project: cmmnt program { Printtree($2);};

program: procedures main {$$=mknode("CODE",$1,$2);}

 //comments
cmmnt: COMMENT cmmnt| {$$=NULL;};

 //this is the main
main: PROCEDUR MAIN OPENPAREN CLOSEPAREN OPENBRACE pro_body CLOSEBRACE
{
$$=mknode("    (PROC",
mknode("\n\tMain",mknode("\n",NULL,NULL),NULL),
mknode("ARGS",NULL,$6));
}	| {$$=NULL;};

//functions
procedures: procedures  procedure {$$=mknode("",$1,$2);}
	| {$$=NULL;};

//function
procedure: FUNCTION IDENTIFIER OPENPAREN para_pro CLOSEPAREN cmmnt RETURN type_pro  OPENBRACE  pro_body RET CLOSEBRACE
{ 
		$$=mknode("FUNC\n",mknode($2,mknode("\n",NULL,NULL),mknode("ARGS",$4,mknode("return",$8,NULL))),mknode("",$10,$11));	
}
| PROCEDUR IDENTIFIER OPENPAREN para_pro CLOSEPAREN  OPENBRACE  pro_body CLOSEBRACE
{
	$$=mknode("PROC",mknode($2,mknode("\n",NULL,NULL),NULL),mknode("ARGS",$4,$7));
};


//list of parameter for function or not
para_pro: para_list {$$=$1;}
| {$$=NULL;};

//list of parameter

para_list: var_id COLON type_id {$$=mknode("(",$3,mknode("",$1,mknode(")",NULL,NULL)));}
	|  para_list SEMICOLON cmmnt  para_list 
	{$$=mknode("",$1,mknode("",$4,NULL));};

 //Procedure body
pro_body: cmmnt  procedures declears stmnts 
{
	$$=mknode("(BODY\n", mknode("",$2,NULL),mknode("",$3,mknode("",$4,mknode("}",NULL,NULL))));
};


//list of declears
declears: declears declear  {$$=mknode("",$1,$2);} | {$$=NULL;}  ;

//declaration of varibals/ 
declear: VARIABLE var_id COLON type_id cmmnt SEMICOLON cmmnt
{
	$$=mknode("var", $4,$2);
};

//list of id like a,b,c/
var_id: IDENTIFIER COMMA var_id {$$=mknode($1, mknode(" ", $3, NULL),NULL);}
	| IDENTIFIER {$$=mknode($1, NULL, NULL);} ;


//types without string/
type_id: BOOL {$$=mknode("boolean", NULL, NULL);}
	| STRING OPENBRACKET DECIMAL_LTL CLOSEBRACKET {$$=mknode("string", NULL, NULL);}
	| CHAR {$$=mknode("char", NULL, NULL);}
	| INT {$$=mknode("int", NULL, NULL);}
	| REAL {$$=mknode("real", NULL, NULL);}
	| INTPTR {$$=mknode("int*", NULL, NULL);}
	| CHARPTR {$$=mknode("char*", NULL, NULL);}
	| REALPTR {$$=mknode("real*", NULL, NULL);};



//type for returning from a function
type_pro: BOOL {$$=mknode("boolean", NULL, NULL);}
 	| STRING {$$=mknode("string", NULL, NULL);}
	| CHAR {$$=mknode("char", NULL, NULL);}
	| INT {$$=mknode("int", NULL, NULL);}
	| REAL {$$=mknode("real", NULL, NULL);}
	| INTPTR {$$=mknode("int*", NULL, NULL);}
	| CHARPTR {$$=mknode("char*", NULL, NULL);}
	| REALPTR {$$=mknode("real*", NULL, NULL);};
	

//Statments
stmnts: stmnts stmnt {$$=mknode("",$1,$2);} | {$$=NULL;};

//stmnt_block
stmnt_block: stmnt {$$=$1;}|RETURN expr SEMICOLON {$$=mknode("return",$2,NULL);};

//new block in stmnts
new_block: OPENBRACE cmmnt declears stmnts RET CLOSEBRACE cmmnt
{
	$$=mknode("{",$3,mknode("", $4, mknode("",$5,mknode("}",NULL,NULL))));
};


RET: RETURN expr SEMICOLON cmmnt {$$=mknode("return",$2,NULL);}| {$$=NULL;};

//Statment
stmnt: IF OPENPAREN expr CLOSEPAREN  stmnt_block 
{
	$$=mknode("if",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),$5);
}%prec IF
// 1     2      3       4             5            6      7
|  IF OPENPAREN expr CLOSEPAREN   stmnt_block    ELSE  stmnt_block  
{
	$$=mknode("if-else",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),
	mknode("",$5,
	mknode("",$7,NULL)));
}
| WHILE cmmnt OPENPAREN expr CLOSEPAREN  stmnt_block  
{
	$$=mknode("while",
	mknode("(", $4, 
	mknode(")",NULL,NULL)),$6);
}
| FOR cmmnt OPENPAREN assmnt_stmnt SEMICOLON expr SEMICOLON assmnt_stmnt CLOSEPAREN stmnt_block 
{
		$$= mknode("for",
			mknode("(",
			mknode("",$4,$6),
			mknode("",$8,
			mknode(")",NULL,NULL))),$10);		
}
| assmnt_stmnt SEMICOLON cmmnt {$$=mknode("",$1,NULL);}
| expr SEMICOLON cmmnt {$$=$1;}
| new_block {$$=$1;};




//assiment statment
assmnt_stmnt: lhs ASSINGMENT expr 
{
	$$=mknode("=",$1,$3);
};


//lefd hand side id
lhs: IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
{
	$$=mknode($1, mknode("[",$3,mknode("]",NULL,NULL)), NULL);
} 
| IDENTIFIER {$$=mknode($1,NULL,NULL);}
| derefrence_expr{$$=$1;} ;


	
//Expresion
expr:  OPENPAREN expr CLOSEPAREN {$$=mknode("(",$2,mknode(")",NULL,NULL));}|
//bool oper
    expr EQL expr {$$=mknode("==",$1,$3);}
	| expr NOTEQL expr {$$=mknode("!=",$1,$3);}
	| expr GREATEREQL expr {$$=mknode(">=",$1,$3);}
	| expr GREATER expr {$$=mknode(">",$1,$3);}
	| expr LESSEQL expr {$$=mknode("<=",$1,$3);}
	| expr LESS expr {$$=mknode("<",$1,$3);}
	| expr AND expr {$$=mknode("&&",$1,$3);}
	| expr OR expr {$$=mknode("||",$1,$3);}
//aritmetical operator
	| expr PLUS expr {$$=mknode("+",$1,$3);}
	| expr MINUS expr {$$=mknode("-",$1,$3);}
	| expr MULTI expr {$$=mknode("*",$1,$3);}
	| expr DIVISION expr {$$=mknode("/",$1,$3);}
//not operator
	| NOT expr {$$=mknode("!",$2,NULL);}
	| address_exprs {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func cmmnt {$$=$1;}
	| DECIMAL_LTL {$$=mknode($1,NULL,NULL);}
	| HEX_LTL {$$=mknode($1,NULL,NULL);}
	| CHAR_LTL {$$=mknode($1,NULL,NULL);}
	| REAL_LTL {$$=mknode($1,NULL,NULL);}
	| STRING_LTL {$$=mknode($1,NULL,NULL);}
	| BOOLFALSE {$$=mknode($1,NULL,NULL);}
	| BOOLTRUE {$$=mknode($1,NULL,NULL);}
	| LENGTH IDENTIFIER LENGTH 
	{
		$$=mknode("|",
		mknode($2,NULL,NULL),
		mknode("|",NULL,NULL));
	}
	| IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode($1,mknode("[",$3,mknode("]",NULL,NULL)),NULL);}
	| IDENTIFIER {$$=mknode($1,NULL,NULL);}
	| NULLL {$$=mknode("null",NULL,NULL);};

//address expression like &id

address_exprs:ADDRESS address_exprs {$$=mknode($1,$2,NULL);} | address_expr {$$=$1;};

address_expr: ADDRESS IDENTIFIER {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
	| ADDRESS OPENPAREN IDENTIFIER CLOSEPAREN {$$=mknode("&",mknode("(",mknode($3,NULL,NULL),NULL),mknode(")",NULL,NULL));}
	| ADDRESS IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode("&", mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));}
	| ADDRESS OPENPAREN IDENTIFIER OPENBRACKET expr CLOSEBRACKET CLOSEPAREN 
	{
		$$=mknode("&",
		mknode("(", 
		mknode($3,NULL,NULL),
		mknode("[",$5,NULL)), 
		mknode("]",NULL,mknode(")",NULL,NULL)));
	};
//value expression like ^id


	derefrence_expr: DEREFRENCE IDENTIFIER {$$=mknode("^",mknode($2,NULL,NULL),NULL);}
	| DEREFRENCE OPENPAREN expr CLOSEPAREN {$$=mknode("^",mknode("(",$3,NULL),mknode(")",NULL,NULL));}
	| DEREFRENCE IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode($1, mknode($2,NULL,NULL), mknode("[",$4,mknode("]",NULL,NULL)));};

	//list of expreession
expr_list: expr COMMA expr_list {$$=mknode("",$1,mknode(",",$3,NULL));} 
	| expr {$$=mknode("",$1,NULL);}
	| {$$=NULL;};

paren_expr:OPENPAREN expr_list CLOSEPAREN {$$=$2;};
//call func rul 
call_func: IDENTIFIER paren_expr {$$=mknode("Call func",mknode($1,NULL,NULL),mknode("ARGS",$2,NULL));} ;
%%

#include "lex.yy.c"

int main()
{
	return yyparse();	
}

/* allocation for node*/
node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	return newnode;
}

void printTabs(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf(" ");
}




void Printtree(node* tree)
{
	//int printlvl=0;
	int flag = 4;
	if(strcmp(tree->token, "var") == 0)
	{
		printf("(DECLARE ");
		flag=2;
	}
	else if(strcmp(tree->token, "TYPE") == 0)
	{
		printf("(TYPE ");
		flag=2;
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		printf("(IF\n");
		flag = 1;
	}
	else if(strcmp(tree->token, "while") == 0)
	{
		printf("(WHILE\n");
		flag = 1;
	}
	else if(strcmp(tree->token, "for") == 0)
	{
		printf("(FOR\n");
		flag = 1;
	}
	else if(strcmp(tree->token, "FUNCTION") == 0 ||strcmp(tree->token, "CODE") == 0||strcmp(tree->token, "Call FUNC") == 0)		{
		printf("(%s \n",tree->token);
		flag= 2;
	}

	else if(strcmp(tree->token, "PROC") == 0)
		{
		printf("(%s \n",tree->token);
		flag= 2;
	}
	
		else if(strcmp(tree->token, "ARGS") == 0)
	{
		printf("(ARGS ");
		if(tree->left)
		{
			flag = 2;
			printf("\n");

		}
		else{
			printf(" NONE)\n");
		}
	}
	else if(strcmp(tree->token, "if-else") == 0)
	{
		printf("(IF-ELSE\n");
		//printTabs(printlevel);
		printlevel--;
		flag = 1;
	}
	else if(strcmp(tree->token, "return") == 0)
	{
		printf("(RET ");
		flag = 2;
	}
	else if(strcmp(tree->token, "{") == 0)
	{
        printf("(BLOCK\n");
	}
	else if(strcmp(tree->token, "}") == 0)
	{
		printf(")\n");
	}
	else if(strcmp(tree->token, "") == 0);
	else if(strcmp(tree->token, "(") == 0)
			printf("(");
	else if(strcmp(tree->token, "\n") == 0)
			printf("\n");
	else if(strcmp(tree->token, ")") == 0)
			printf(")\n");
	else if(strcmp(tree->token, ",") == 0)
			printf(",");
			else if(strcmp(tree->token, ">") == 0 ){
				printf("> ");
			}
	else if(strcmp(tree->token, ";") == 0)
			printf("\n");
			
	else if(strcmp(tree->token, "&&") == 0 ){
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;}
				
	
	else if(strcmp(tree->token, "/") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;}
				
	
	else if(strcmp(tree->token, "=") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "==") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if
	(strcmp(tree->token, ">=") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "<") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "<=") == 0)	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "-") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "!") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "!=") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "||") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "+") == 0 )	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "*") == 0 )
		{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "&") == 0 )
		{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "^") == 0 )
		{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, "|") == 0 )
		{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;
				
	}
	else if(
	strcmp(tree->token, ",") == 0 )
	{
			printf("(%s",tree->token);
			flag=1;
			if(strcmp(tree->token, "=") == 0)
				flag=2;

	}
	else
	{
		if((tree && !tree->left && !tree->right)
		||strcmp(tree->token, "Main") == 0)
		{
			printf("%s ", tree->token);
		}
		else
		{
			printlevel++;
			printf("%s", tree->token);
			printlevel--;
		}
	}
	if (tree->left)
	{
		printlevel++;
		Printtree(tree->left);
		printlevel--;
	}

	if (tree->right)
	{
		printlevel++;
		Printtree(tree->right);
		printlevel--;
	}
	if(flag == 2)
		printf(")\n");

	if(flag == 1)
		printf(")");
	if(flag == 0)
		printf("\n)");
}


int tab_count=-1;


void printTree(node* tree)
{	
	tab_count++;

	if(strcmp(tree->token, "") == 0){
		tab_count--;
	}

	else if(tree->left != NULL){
		printTabs(tab_count);
		printf("(%s\n",tree->token);
	}

	else{
		printTabs(tab_count);
		printf(" %s \n",tree->token);
	}
	
	if(tree->left)printTree(tree->left);
	if(tree->right)printTree(tree->right);

	if(strcmp(tree->token, "") == 0){
		tab_count++;}
	else if((tree->left != NULL || tree->right != NULL) && (tree->token != "")){
		printTabs(tab_count);
		printf(")\n");
	}
	tab_count--;

}


void printcomment(const char *str){
	printf("This is comment [%s]\n",str);
	}

int yyerror(char *e)
{
	printf("Input Deniied");
	printf("\nError:%s,unexpected token %s at line %d\n" ,e,yytext,yylineno);

	
	return 0;
	

}

