%{
	#define _GNU_SOURCE
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	typedef enum {false,true} bool;
	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
		char *code;
		char *var;
		char *label;
		char *truelabel;
		char *falselabel;
		int sum;
	} node;

	typedef struct Arguments
	{
		char * name;
		char * type;
		char * len;
	}Arguments;

    	typedef struct Function 
	{
        char * name;
		struct Arguments * args;
        char *returnType; 
		int CountArguments;
		int findreturn;
    	} Function;

	typedef struct Varaiables
	{	int IsArgument;
		char *name;
		char *value;
		char *type;
		char * len;
	}Varaiable;

	typedef struct code
	{	
		int place;
		char *name;
		Varaiable * var;
		int CountVars;
		int CountFuncs;
		Function ** func;
		struct code * nextLevel;
		struct code * previusLevel;
	}code;
	
	char * TypeofExpr(node *,code*);
	Arguments * MakeArguments(node *,int *);
	void AddNewFunction(char * name,Arguments * args,node *returnType,int CountArguments,code*);
	void AddNewVariable(Arguments * args,int,int,code * scooope);
	code* mkcode(char *);
	node* mknode(char* token, node *left, node *right);
	int yylex();
	int yyerror(char *e);
	void push(code* from,char*);
	code* OwnCode=NULL;
	code* CodeList(code * codey);
	static int scope=0;
	void syntaxMKscope(node *tree,code * scope);
	char* FindFunction(node * tree,code * scooope,int* count);
	char *FindVariable(node * tree,code * scooope);
	Arguments * FunctionCallArgs(code *,node *tree,int * count);
	int MainFlag=false;
	char* SelfBuiltstrcat(char*des,char*src);
	char* SelfBuiltstrcat2(char*des,char*src);
	char *WordReplacement(const char *s, const char *oldW, const char *newW);
	static node * InitialNode;
	int PopParameters(Arguments * args,int count);
	void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	void AddNewCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel);
	char* NewVariable();
	char* NewLabel();
	char* Generatee(char*,char*,char*,char*,char*);
	static int t=0;
	static int l=0;
	static int line=0;
	char * MakeSpace(char *label);
	void calc3AC(node * tree);	
%}
%union
{
    struct node *node;
    char *str;
}

%token <str> COMMENT WHILE IF ELSE 
%token <str> RETURN
%token <str> BOOL STRING CHARPTR CHAR INT INTPTR PROCEDUR
%token <str> AND ADDRESS EQL ASSINGMENT OR LENGTH GREATEREQL GREATER LESSEQL LESS NOTEQL NOT
%token <str> DIVISION PLUS MINUS MULTI VARIABLE
%token <str> STRING_LTL REAL_LTL CHAR_LTL NULLL
%token <str> MAIN IDENTIFIER SEMICOLON COMMA OPENPAREN CLOSEPAREN OPENBRACKET CLOSEBRACKET OPENBRACE CLOSEBRACE
%token <str> DECIMAL_LTL HEX_LTL BOOLTRUE BOOLFALSE  REAL REALPTR FUNCTION COLON  DEREFRENCE 

%left IDENTIFIER OR AND 
%left  NOTEQL LESS LESSEQL GREATEREQL GREATER 
%left PLUS MINUS RETURN
%left MULTI DIVISION
%left SEMICOLON EQL
%right NOT CLOSEBRACE

%nonassoc OPENPAREN
%nonassoc IF
%nonassoc ELSE 

%type <node> address_expr stmnts stmnt_block derefrence_expr expr_list call_func 
%type <node> expr lhs assmnt_stmnt new_block 
%type <node> stmnt type_pro type_id var_id declear paren_expr
%type <node> pro_body para_list para_pro procedure procedures
%type <node> main program project declears 
%%
 
project: cmmnt program {InitialNode = $2; syntaxMKscope($2,OwnCode);  calc3AC($2);}; 

program: procedures main{$$=mknode("CODE",$1,$2);  }

cmmnt: COMMENT cmmnt {;}| ;

main: PROCEDUR MAIN OPENPAREN CLOSEPAREN cmmnt OPENBRACE pro_body CLOSEBRACE
{
$$=mknode("Main",mknode("ARGS",NULL,$7),NULL);
t=0;

};

procedures: procedures  procedure {$$=mknode("procedures",$1,$2);}
	| {$$=NULL;};

procedure: FUNCTION IDENTIFIER OPENPAREN para_pro CLOSEPAREN cmmnt RETURN type_pro  OPENBRACE  pro_body CLOSEBRACE
{ 
		$$=mknode("FUNC",mknode($2,mknode("",NULL,NULL),mknode("ARGS",$4,mknode("Return",$8,NULL))),mknode("",$10,NULL));
		t=0; 
}
| PROCEDUR IDENTIFIER OPENPAREN para_pro CLOSEPAREN  OPENBRACE  pro_body CLOSEBRACE
{
	$$=mknode("PROC",mknode($2,mknode("",NULL,NULL),NULL),mknode("ARGS",$4,$7));
	t=0; 
};

para_pro: para_list {$$=$1;}
| {$$=NULL;};

para_list: var_id COLON type_id {$$=mknode("(",$3,mknode("",$1,mknode(")",NULL,NULL)));}
	|  para_list SEMICOLON cmmnt  para_list {$$=mknode("",$1,mknode("",$4,NULL));}	;

pro_body: cmmnt  procedures declears stmnts 
{
	$$=mknode("BODY", mknode(" ",$2,NULL),mknode(" ",$3,mknode(" ",$4,mknode(" ",NULL,NULL))));
	
};

declears: declears declear  {$$=mknode("",$1,$2);} | {$$=NULL;}  ;

declear: VARIABLE var_id COLON type_id cmmnt SEMICOLON cmmnt
{
	$$=mknode("var", $4,$2);
};

var_id: IDENTIFIER COMMA var_id {$$=mknode($1, mknode(" ", $3, NULL),NULL);}
	| IDENTIFIER {$$=mknode($1, NULL, NULL);} ;

type_id: BOOL {$$=mknode("boolean", NULL, NULL);}
	| STRING OPENBRACKET DECIMAL_LTL CLOSEBRACKET {$$=mknode("string", mknode("[",mknode("$3",NULL,NULL),NULL), NULL);}
	| CHAR {$$=mknode("char", NULL, NULL);}
	| INT {$$=mknode("int", NULL, NULL);}
	| REAL {$$=mknode("real", NULL, NULL);}
	| INTPTR {$$=mknode("int*", NULL, NULL);}
	| CHARPTR {$$=mknode("char*", NULL, NULL);}
	| REALPTR {$$=mknode("real*", NULL, NULL);};

type_pro: BOOL {$$=mknode("boolean", NULL, NULL);}
 	| STRING {$$=mknode("string", NULL, NULL);}
	| CHAR {$$=mknode("char", NULL, NULL);}
	| INT {$$=mknode("int", NULL, NULL);}
	| REAL {$$=mknode("real", NULL, NULL);}
	| INTPTR {$$=mknode("int*", NULL, NULL);}
	| CHARPTR {$$=mknode("char*", NULL, NULL);}
	| REALPTR {$$=mknode("real*", NULL, NULL);};
	

stmnts: stmnts stmnt   { $$=mknode("stmnts",$1,$2); if(strcmp($2->token, "if") == 0||strcmp($2->token, "if-else") == 0||strcmp($2->token, "while") == 0){ if($$->sum==0) {addCode($2,NULL,NULL,NewLabel(),NULL,NULL); $$->sum=1;}}   }| {$$=NULL;};


stmnt_block: stmnt {$$=$1; if(strcmp($1->token, "if") == 0||strcmp($1->token, "if-else") == 0||strcmp($1->token, "while") == 0) addCode($1,NULL,NULL,NewLabel(),NULL,NULL);}|declear {$$=$1;}|procedure {$$=$1;} |SEMICOLON  {$$=mknode("",NULL,NULL);};

new_block: OPENBRACE procedures cmmnt declears stmnts CLOSEBRACE cmmnt
{
	$$=mknode("{",$2,mknode("", $4,mknode("", $5,("}",NULL,NULL))));
	
}

stmnt: IF OPENPAREN expr CLOSEPAREN  stmnt_block 
{
	$$=mknode("if",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),$5);
	addCode($3,NULL,NULL,NULL,NewLabel(),NULL);
	
	
}%prec IF
| IF OPENPAREN expr CLOSEPAREN   stmnt_block    ELSE  stmnt_block  
{
	$$=mknode("if-else",
	mknode("", $3, 
	mknode("",NULL,NULL)),
	mknode("",$5,
	mknode("",$7,NULL)));
	addCode($3,NULL,NULL,NULL,NewLabel(),NULL);
	addCode($3,NULL,NULL,NULL,NULL,NewLabel());
}
| WHILE cmmnt OPENPAREN expr CLOSEPAREN  stmnt_block  
{
	$$=mknode("while",
	mknode("(", $4, 
	mknode(")",NULL,NULL)),$6);
addCode($$,NULL,NULL,NULL,NewLabel(),NULL);
	addCode($$,NULL,NULL,NULL,NULL,NewLabel());
}
| assmnt_stmnt SEMICOLON cmmnt {$$=mknode("assmnt_stmnt",$1,NULL);  }
| expr SEMICOLON cmmnt {$$=$1;}
| RETURN expr SEMICOLON cmmnt {$$=mknode("return",$2,NULL);}
| new_block {$$=$1;} ;

assmnt_stmnt: lhs ASSINGMENT expr 
{
	$$=mknode("=",$1,$3);
};

lhs: IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
{
	$$=mknode($1, mknode("[",$3,mknode("]",NULL,NULL)), NULL);
} 
| IDENTIFIER {$$=mknode($1,NULL,NULL);}
| address_expr {$$=$1;}
| derefrence_expr{$$=$1;} ;

expr:  OPENPAREN expr CLOSEPAREN {$$=mknode("(",$2,mknode(")",NULL,NULL));}|
    expr EQL expr {$$=mknode("==",$1,$3); }
	| expr NOTEQL expr {$$=mknode("!=",$1,$3);}
	| expr GREATEREQL expr {$$=mknode(">=",$1,$3);}
	| expr GREATER expr {$$=mknode(">",$1,$3);}
	| expr LESSEQL expr {$$=mknode("<=",$1,$3);}
	| expr LESS expr {$$=mknode("<",$1,$3);}

	| expr AND expr {$$=mknode("&&",$1,$3); addCode($1,NULL,NULL,NULL,NewLabel(),NULL); }
	| expr OR expr {$$=mknode("||",$1,$3); addCode($1,NULL,NULL,NULL,NULL,NewLabel());  }

	| expr PLUS expr {$$=mknode("+",$1,$3); }
	| expr MINUS expr {$$=mknode("-",$1,$3); }
	| expr MULTI expr {$$=mknode("*",$1,$3); }
	| expr DIVISION expr {$$=mknode("/",$1,$3);}
	| NOT expr {$$=mknode("!",$2,NULL);}
	| address_expr {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func cmmnt {$$=$1;}
	| DECIMAL_LTL {$$=mknode($1,mknode("INT",NULL,NULL),NULL);}
	| HEX_LTL {$$=mknode($1,mknode("HEX", NULL, NULL),NULL);}
	| CHAR_LTL {$$=mknode($1,mknode("CHAR", NULL, NULL),NULL);}
	| REAL_LTL {$$=mknode($1,mknode("REAL", NULL, NULL),NULL);}
	| STRING_LTL {$$=mknode($1,mknode("STRING", NULL, NULL),NULL);}
	| BOOLFALSE {$$=mknode($1,mknode("BOOLEAN", NULL, NULL),NULL);}
	| BOOLTRUE {$$=mknode($1,mknode("BOOLEAN", NULL, NULL),NULL); }
	| LENGTH IDENTIFIER LENGTH 
	{
		$$=mknode("|",
		mknode($2,NULL,NULL),
		mknode("|",NULL,NULL));
	}
	| IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode("solovar",mknode($1,mknode("[",$3,mknode("]",NULL,NULL)),NULL),NULL);}
	| IDENTIFIER {$$=mknode("solovar",mknode($1,NULL,NULL),NULL);}
	| NULLL {$$=mknode("null",NULL,NULL);};

address_expr: ADDRESS IDENTIFIER {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
	| ADDRESS OPENPAREN IDENTIFIER CLOSEPAREN {$$=mknode("&",mknode("(",mknode($3,NULL,NULL),NULL),mknode(")",NULL,NULL));}
	| ADDRESS IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode("&", mknode($2,mknode("[",$4,mknode("]",NULL,NULL)),NULL),NULL);
	}
	| ADDRESS OPENPAREN IDENTIFIER OPENBRACKET expr CLOSEBRACKET CLOSEPAREN 
	{
		$$=mknode("&",
		mknode("(", 
		mknode($3,mknode("[",$5,mknode("]",NULL,NULL)),NULL)
		,mknode(")",NULL,NULL)),NULL);
	};

derefrence_expr: DEREFRENCE IDENTIFIER {$$=mknode("^",mknode($2,NULL,NULL),NULL);addCode($$,"",SelfBuiltstrcat("*",$2),NULL,NULL,NULL);}
	| DEREFRENCE OPENPAREN expr CLOSEPAREN {$$=mknode("^",mknode("(",$3,NULL),mknode(")",NULL,NULL));addCode($$,$3->code,SelfBuiltstrcat("*",$3->var),NULL,NULL,NULL);}
	| DEREFRENCE IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode($1, mknode($2,mknode("[",$4,mknode("]",NULL,NULL)),NULL), NULL);
	};


expr_list: expr COMMA expr_list {$$=mknode("expr_list",$1,mknode(",",$3,NULL));} 
	| expr {$$=mknode("expr_list",$1,NULL);}
	| {$$=NULL;};

paren_expr:OPENPAREN expr_list CLOSEPAREN {$$=$2;};

call_func: IDENTIFIER paren_expr {$$=mknode("Call func",mknode($1,NULL,NULL),mknode("ARGS",$2,NULL)); 

} ;
%%
	#include "lex.yy.c"
int main()
{
	int x= yyparse();
	if(x==0)
	{
		printf("Code Valid\n");
	}
	printf("%s",InitialNode->code);
	return x;
	
}

char* FindFunction(node * tree,code * scooope,int * countParams)
{
	code*temp=scooope;
	Arguments* args;
	int find=false,flag=true;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->CountFuncs;i++)
		if(strcmp(tree->left->token,temp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			args=FunctionCallArgs(scooope,tree->right->left,&count);
			if(count==temp->func[i]->CountArguments)
			{
				for(int j=0,t=count-1;j<count;j++,t--)
				{
					if(strcmp(args[j].type,temp->func[i]->args[t].type)!=0)
						flag=false;
				}
				if(flag==true){
					if(countParams!= NULL)
						*countParams = PopParameters(args,count);
					return temp->func[i]->returnType;
				}
			}
		}
		temp=temp->previusLevel;
	}
	printf("Semantic ERORR\nCannot use Function [%s] before it has been declared in scope %s in func/proc %s\n",tree->left->token,scooope->name,OwnCode->func[OwnCode->CountFuncs-1]->name);
	if(find==true)
		printf("Function has been found but with other args type \n");
		exit(1);
}
char *FindVariable(node * tree,code * scooope)
{
	code*temp=scooope;
	if(strcmp(tree->token,"solovar")==0)
		tree=tree->left;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->CountVars;i++)
		if(strcmp(tree->token,temp->var[i].name)==0)
		{
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(temp->var[i].type,"string")==0)
					if(strcmp(TypeofExpr(tree->left->left,scooope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("Semantic Error\nindex can be only type of integer Format(<string>[<int>]) in func/proc [%s]\n",OwnCode->func[OwnCode->CountFuncs-1]->name);
						exit(1);
					}
				else
				{
					printf("Semantic Error\n[] operation can be only applied on string Format (<string>[<int>]) in func/proc %s\n",OwnCode->func[OwnCode->CountFuncs-1]->name);
					exit(1);
				}
			}
			else
			return temp->var[i].type;
		}
		temp=temp->previusLevel;
	}
	printf("Semantic Error\nusing variable %s not found in func/proc %s\nor it has been used before declaring it\n",tree->token,OwnCode->func[OwnCode->CountFuncs-1]->name);
	exit(1);
	
}
char * TypeofExpr(node * tree,code* scooope){
	char* msg=(char*)malloc(sizeof(char)*7);
	msg="";
	if(strcmp(tree->token,"null")==0)
		msg="NULL";
	else
	if(tree->left!=NULL){
		if(strcmp(tree->left->token,"INT")==0)
			msg= "int";
		if(strcmp(tree->left->token,"HEX")==0)
			msg= "hex";
		if(strcmp(tree->left->token,"CHAR")==0)
			msg= "char";
		if(strcmp(tree->left->token,"REAL")==0)
			msg= "real";
		if(strcmp(tree->left->token,"STRING")==0)
			msg= "string";
		if(strcmp(tree->left->token,"BOOLEAN")==0)
			msg= "boolean";
		if(strcmp(tree->token,"!")==0)
		if(strcmp(TypeofExpr(tree->left,scooope),"boolean")==0)
			msg="boolean";
		else{
			printf("Semantic Error\nOperation ! can be applied only on bool data type\n");
			exit(1);
		}
		if(strcmp(tree->token,"|")==0)
		if(strcmp(TypeofExpr(tree->left,scooope),"string")==0)
		msg="int";
		else{
			printf("Semantic Error\nOperation Length [||] can be only applied to string types in func/proc [%s]\n",OwnCode->func[OwnCode->CountFuncs-1]->name);
			exit(1);
		}
		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0){
			if(strcmp(TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope))==0&&strcmp(TypeofExpr(tree->right,scooope),"string")!=0)
			msg="boolean";
			else{
				printf("Semantic Error\nOperation [%s] can be applied only on similar data types <bool>,<int>,<real>,<char>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(TypeofExpr(tree->left,scooope),"int")==0||strcmp(TypeofExpr(tree->left,scooope),"real")==0)&&(strcmp(TypeofExpr(tree->right,scooope),"int")==0||strcmp(TypeofExpr(tree->right,scooope),"real")==0))
			msg="boolean";
			else{
				printf("Semantic Error\nOperation [%s] can only be applied on ,<int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0){
			if(strcmp(TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope))==0&&strcmp(TypeofExpr(tree->right,scooope),"boolean")==0)
			msg="boolean";
			else{
			printf("Semantic Error\ncan't apply [%s] between [%s] and [%s] in func/proc [%s]\n",tree->token,TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope),OwnCode->func[OwnCode->CountFuncs-1]->name);
				exit(1);
			}
		}
		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(TypeofExpr(tree->left,scooope),"int")==0||strcmp(TypeofExpr(tree->left,scooope),"real")==0)&&(strcmp(TypeofExpr(tree->right,scooope),"int")==0||strcmp(TypeofExpr(tree->right,scooope),"real")==0))
			{
			if(strcmp(TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope))==0&&strcmp(TypeofExpr(tree->left,scooope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			if(strcmp(TypeofExpr(tree->right,scooope),"int")==0&&(strcmp(TypeofExpr(tree->left,scooope),"char*")==0||strcmp(TypeofExpr(tree->right,scooope),"int*")==0||strcmp(TypeofExpr(tree->right,scooope),"real*")==0)){
				msg=TypeofExpr(tree->left,scooope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("Semantic Error\nOperation [%s] is only applied to <int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0){
			if((strcmp(TypeofExpr(tree->left,scooope),"int")==0||strcmp(TypeofExpr(tree->left,scooope),"real")==0)&&(strcmp(TypeofExpr(tree->right,scooope),"int")==0||strcmp(TypeofExpr(tree->right,scooope),"real")==0)){
			if(strcmp(TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope))==0&&strcmp(TypeofExpr(tree->left,scooope),"int")==0)
			msg="int";
			else
			msg="real";
			}
			else
			{
				printf("Semantic Error\nOperation [%s] is only applied to <int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"&")==0){
			if(strcmp(tree->left->token,"(")==0)
				msg=TypeofExpr(tree->left->left,scooope);
			else{
				msg=TypeofExpr(tree->left,scooope);
				}
			if(strcmp(msg,"char")==0)
			msg="char*";
			else
			if(strcmp(msg,"int")==0)
			msg="int*";
			else
			if(strcmp(msg,"real")==0)
			msg="real*";
			else
			{
				printf("Semantic Error\nOperation [%s] can be applied only to <int>,<real>,<char>,<string>[<int>]\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"^")==0){
			if(strcmp(tree->left->token,"(")==0)
				msg=TypeofExpr(tree->left->left,scooope);
			else
				msg=TypeofExpr(tree->left,scooope);
			
			if(strcmp(msg,"char*")==0)
			msg="char";
			else
			if(strcmp(msg,"int*")==0)
			msg="int";
			else
			if(strcmp(msg,"real*")==0)
			msg="real";
			else
			{
				printf("Semantic Error\n[%s] can be applied only on pointers\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"(")==0)
			msg=TypeofExpr(tree->left,scooope);
		if(strcmp(tree->token,"Call func")==0)
			msg=FindFunction(tree,scooope,NULL);
	}
	if(strcmp(msg,"")==0)
		msg=FindVariable(tree,scooope);
	return msg;
}


Arguments * FunctionCallArgs(code * scooope,node *tree,int * count)
{
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	while(tree!=NULL)
	{
		ar[(*count)++].type=TypeofExpr(tree->left,scooope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;
	}
	arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}
void push(code* from,char* name){
	code * point;
	if(OwnCode==NULL)
		OwnCode=mkcode(name);
	else{
	point=OwnCode;
	while(point->nextLevel!=NULL)
		point=point->nextLevel;
	point->nextLevel=mkcode(name);
	point->nextLevel->previusLevel=from;
	}
}

code* mkcode(char* name)
{	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl->place=++scope;
	newlvl->name=name;
	newlvl->var=NULL;
	newlvl->CountVars=0;
	newlvl->func=NULL;
	newlvl->CountFuncs=0;
	newlvl->nextLevel=NULL;
	newlvl->previusLevel=NULL;
	return newlvl;
}

void AddNewVariable(Arguments * args,int CountVarss,int IsArgument,code * scooope){
	if(CountVarss==0)
	return;
	Varaiable* temp;
	code * codey=scooope;
	for(int i=0;i<CountVarss;i++)
		for(int j=0;j<CountVarss;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 ){
		printf("Can't declare variables mory than one time [%s]\n",args[i].name);
		code * t=codey->previusLevel;
		while(t->previusLevel!=NULL && t->previusLevel->CountFuncs==0)
			t=t->previusLevel;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->CountFuncs-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(codey->var==NULL){ 
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*CountVarss);
	}
	else
	{
		temp=codey->var;
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*(codey->CountVars+CountVarss));
		for(int i=0;i<codey->CountVars;i++){
			for(int j=0;j<CountVarss;j++){
				if(strcmp(temp[i].name,args[j].name)==0 ){
					printf("Semantic Error\ncan't declare var [%s] in the same scope more than one time",temp[i].name);
					code * t=codey->previusLevel;
					while(t->previusLevel!=NULL && t->previusLevel->CountFuncs==0)
						t=t->previusLevel;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->CountFuncs-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey->var[i]=temp[i];	
		}
	}
	for(int j=0;j<CountVarss;j++){
		codey->var[codey->CountVars].name=args[j].name;
		codey->var[codey->CountVars].value=NULL;
		codey->var[codey->CountVars].IsArgument=IsArgument;
		codey->var[codey->CountVars].len=args[j].len;
		codey->var[(codey->CountVars)++].type=args[j].type;
	}
}

void AddNewFunction(char * name,Arguments * args,node *returnType,int CountArguments,code * scooope){
	Function** temp;
	code * codey=scooope;
	for(int i=0;i<CountArguments;i++)
		for(int j=0;j<CountArguments;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 )
	{
		printf("Can't declare variable [%s] more that one time in func [%s]\n",args[i].name,name);
		exit(1);
	}
	if(codey->func==NULL)
	{ 
		codey->func=(Function**) malloc(sizeof(Function*));
	}
	else
	{
		temp=codey->func;
		codey->func=(Function**) malloc(sizeof(Function*)*(codey->CountFuncs+1));
		for(int i=0;i<codey->CountFuncs;i++)
		{
				if(strcmp(temp[i]->name,name)==0 )
				{
					printf("Semantic Error\ncan't declare function [%s] more than one time in the same scope \n",temp[i]->name);
					exit(1);
				}
				codey->func[i]=temp[i];
		}
	}
		codey->func[codey->CountFuncs]=(Function*) malloc(sizeof(Function));
		codey->func[codey->CountFuncs]->name=name;
		codey->func[codey->CountFuncs]->args=args;
		if(returnType==NULL)
		codey->func[codey->CountFuncs]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("Semantic Error\nFunction [%s] can't return string data type\n",name);
				exit(1);
			}
		codey->func[codey->CountFuncs]->returnType=returnType->token;
		}
		codey->func[codey->CountFuncs]->CountArguments=CountArguments;
		codey->func[codey->CountFuncs]->findreturn=false;
		++(codey->CountFuncs);
}

Arguments * MakeArguments(node *tree,int *count){
	Arguments  *arr=NULL,ar[50];
	char* type,*len;
	if(tree!=NULL)
	{
		node * temp1=tree,*temp=tree;
		do{
		if(strcmp(temp1->token, "")==0)
		{
			temp=temp1->right->left;
			temp1=temp1->left;
			
			
			if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
		{
			type=temp->left->token;
			if(temp->left->left!=NULL)
			len=temp->left->left->left->token;
			node * treee;
			treee=temp->right->left;
			do{
			ar[*count].name=treee->token;
			ar[*count].type=type;
			ar[*count].len=len;
			(*count)++;
			if(treee->left==NULL)
				treee=NULL;
			else
				treee=treee->left->left;
			}while(treee!=NULL);
		}
		}
		}while(strcmp(temp1->token, "(")!=0&&strcmp(temp->token, "var")!=0);
		temp=temp1;
		if(strcmp(temp->token, "(")==0||strcmp(temp->token, "var")==0)
		{
			type=temp->left->token;
			node * treee;
			if(strcmp(temp->token, "var")==0)
			treee=temp->right;
			else
			treee=temp->right->left;
			if(temp->left->left!=NULL)
			len=temp->left->left->left->token;
			do{
			ar[*count].name=treee->token;
			ar[*count].type=type;
			ar[*count].len=len;
			(*count)++;
			if(treee->left==NULL)
				treee=NULL;
			else
				treee=treee->left->left;
			}while(treee!=NULL);
		}
		arr=(Arguments*)malloc(sizeof(Arguments)*(*count));
		for(int i=0;i<*count;i++)
		{
			for(int j=0;j<*count;j++){
			}
			arr[i].name=ar[i].name;
			arr[i].type=ar[i].type;
		}
	}
	return arr;
}

node* mknode (char *token, node *left, node *right)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left=left;
	newnode->right=right;
	newnode->token=token;
	newnode->code=NULL;
	newnode->var=NULL;
	newnode->label=NULL;
	newnode->truelabel=NULL;
	newnode->falselabel=NULL;
    newnode->sum=0;
	return newnode;
}

int yyerror(char *e)
{
	int yydebug=1; 
	fflush(stdout);
	fprintf(stderr,"Error %s at line %d\n" ,e,yylineno);
	fprintf(stderr, "does not accept '%s'\n",yytext);
	exit(0);
	return 0;
}
code* CodeList(code * codey)
{
	code * scooope=codey;
	if(scooope!=NULL)
	while(scooope->nextLevel!=NULL)
		scooope=scooope->nextLevel;
	return scooope;
}

void syntaxMKscope(node *tree,code * scooope){
	if(strcmp(tree->token, "=") == 0 ){
		if(!(strcmp(TypeofExpr(tree->right,scooope),"NULL")==0&& (strcmp(TypeofExpr(tree->left,scooope),"real*")==0||strcmp(TypeofExpr(tree->left,scooope),"int*")==0||strcmp(TypeofExpr(tree->left,scooope),"char*")==0)))
		if(strcmp(TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope))!=0)
		{
			printf("Semntic Error\nCannot assign [%s] to [%s] in func/proc %s\n",TypeofExpr(tree->left,scooope),TypeofExpr(tree->right,scooope),OwnCode->func[OwnCode->CountFuncs-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int CountVars=0;
		Arguments * var=MakeArguments(tree,&CountVars);
		AddNewVariable(var,CountVars,0,scooope);
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(TypeofExpr(tree->left->left,scooope),"boolean")!=0)
		{
			printf("Semantic Error\nIF condition must be of kind boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(scooope,tree->token);
			if (tree->left) 
				syntaxMKscope(tree->left,CodeList( scooope->nextLevel));
			if (tree->right)
				syntaxMKscope(tree->right,CodeList( scooope->nextLevel));
        	scope--;
			return;
		}	
	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(TypeofExpr(tree->left->left,scooope),"boolean")!=0)
		{
printf("Semantic Error\nWhile Condition must be a boolean expreession\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(scooope,tree->token);
			if (tree->left) 
				syntaxMKscope(tree->left,CodeList( scooope->nextLevel));
			if (tree->right)
				syntaxMKscope(tree->right,CodeList( scooope->nextLevel));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree->token, "FUNC") == 0 )
	{
        int count=0;
		Arguments * arg=MakeArguments(tree->left->right->left,&count);
		AddNewFunction(tree->left->token,arg,tree->left->right->right->left,count,scooope);
		push(scooope,tree->token);
		AddNewVariable(arg,count,1,CodeList(scooope));
	if (tree->left) 
		syntaxMKscope(tree->left,CodeList( scooope->nextLevel));
	
	if (tree->right)
		syntaxMKscope(tree->right,CodeList( scooope->nextLevel));
		if(scooope->func[scooope->CountFuncs-1]->findreturn==false)
		{
			printf("Semantic Error\nFunction [%s] must return a value\n",tree->left->token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{
		
        int count=0;
		Arguments * arg=MakeArguments(tree->right->left,&count);
		AddNewFunction(tree->left->token,arg,NULL,count,scooope);
		push(scooope,tree->token);
		AddNewVariable(arg,count,1,CodeList(scooope));
	if (tree->left) 
		syntaxMKscope(tree->left,CodeList( scooope->nextLevel));
	
	if (tree->right)
		syntaxMKscope(tree->right,CodeList( scooope->nextLevel));
		scope--;	
		return;
    }
	else if(strcmp(tree->token, "Call func") == 0)
	{
		int count=0;
		FindFunction(tree,scooope,&count);
		tree->sum=count;
	  }
	else if(strcmp(tree->token, "CODE") == 0)
	{
		push(NULL,tree->token);
	if (tree->left) 
		syntaxMKscope(tree->left,OwnCode);
	
	if (tree->right)
		syntaxMKscope(tree->right,OwnCode);
		scope--;
		return;
	}
    else if(strcmp(tree->token, "Main") == 0)
	{
		if(MainFlag==true && strcmp(scooope->name,"CODE")==0)
		{
			printf("Main can't be in function/procedure\n");
			exit(1);
		}
		MainFlag=true;
		AddNewFunction(tree->token,NULL,NULL,0,scooope);
		push(scooope,tree->token);
	if (tree->left) 
		syntaxMKscope(tree->left,CodeList( scooope->nextLevel));
	if (tree->right)
		syntaxMKscope(tree->right,CodeList( scooope->nextLevel));
        scope--;
		return;
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(TypeofExpr(tree->left->left,scooope),"boolean")!=0)
		{
			printf("Semantic Error\nIF condition must be of kind boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->left->token,"{")!=0)
		{
			push(scooope,tree->token);
			syntaxMKscope(tree->right->left,CodeList( scooope->nextLevel));
			scope--;
			push(scooope,tree->token);
			syntaxMKscope(tree->right->right->left,CodeList( scooope->nextLevel));
        	scope--;
			return;
		}
	}
	else if(strcmp(tree->token, "return") == 0)
	{
		code * temp= scooope;
		int flag=true;
		while(strcmp(temp->name,"FUNC")!=0&&strcmp(temp->name,"PROC")!=0&&strcmp(temp->name,"CODE")!=0)
		{
			temp=temp->previusLevel;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(TypeofExpr(tree->left,scooope),temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->returnType))
			{
			printf("ERORR,return no some type in func %s \n",temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->name);
			printf("%s ,%s %s\n",TypeofExpr(tree->left,scooope),temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->returnType,temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->name);
			exit(1);
			}
		}
		else{
		if(temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->returnType!=NULL){
		if(0==strcmp(TypeofExpr(tree->left,scooope),temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->returnType)){
			temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->findreturn=true;
		}
		else{
			printf("Semantic Error\nreturn type is not as declared in Function [%s] \n",temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->name);
		    	printf("returned [%s] supposed to be [%s] Function [%s]\n",TypeofExpr(tree->left,scooope),temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->returnType,temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->name);
			exit(1);
		}
		}
		else
		{
			printf("Semantic Error\nProcedure cannot have return type [%s]\n",temp->previusLevel->func[temp->previusLevel->CountFuncs-1]->name);
			exit(1);
		}  
		}
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    push(scooope,tree->token);
	if (tree->left) 
		syntaxMKscope(tree->left,CodeList( scooope->nextLevel));
	if (tree->right)
		syntaxMKscope(tree->right,CodeList( scooope->nextLevel));
        scope--;
		return;				
	}
	else if(strcmp(tree->token, "solovar") == 0 )
	{
		FindVariable(tree->left,scooope);
	}
	if (tree->left) 
		syntaxMKscope(tree->left,scooope);
	
	if (tree->right)
		syntaxMKscope(tree->right,scooope);
}

int PopParameters(Arguments * args,int count){
	int size=0;
	for(int i =0;i<count;i++)
	{
		if(strcmp(args[i].type,"int")==0)
			size += 4;
		else if(strcmp(args[i].type,"char")==0)
			size += 1;
		else if(strcmp(args[i].type,"real")==0)
			size += 8;
		else if(strcmp(args[i].type,"string")==0)
			size += atoi(args[i].len);
		else if(strcmp(args[i].type,"boolean")==0)
			size += 4;
		else if(strcmp(args[i].type,"int*")==0)
			size += 4;
		else if(strcmp(args[i].type,"char*")==0)
			size += 4;
		else if(strcmp(args[i].type,"real*")==0)
			size += 4;
	}
	return size;
}

void addCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel){
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}
		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}
		if(label!=NULL&& node->label==NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}
		if(truelabel!=NULL && node->truelabel==NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}
	}
void AddNewCode(node* node,char *code,char *var,char *label,char *truelabel,char *falselabel)
	{
		if(code!=NULL){
		node->code=(char*)malloc(sizeof(char)*(1+strlen(code)));
		strcpy(node->code,code);
		}
		else if(node->code==NULL)
		{
		node->code=(char*)malloc(sizeof(char)*2);
		strcpy(node->code,"");
		}

		if(var!=NULL){
		node->var=(char*)malloc(sizeof(char)*(1+strlen(var)));
		strcpy(node->var,var);
		}
		else if(node->var==NULL)
		{
		node->var=(char*)malloc(sizeof(char)*2);
		strcpy(node->var,"");
		}

		if(label!=NULL){
		node->label=(char*)malloc(sizeof(char)*(1+strlen(label)));
		strcpy(node->label,label);
		}

		if(truelabel!=NULL){
		node->truelabel=(char*)malloc(sizeof(char)*(1+strlen(truelabel)));
		strcpy(node->truelabel,truelabel);
		}
		
		if(falselabel!=NULL && node->falselabel==NULL){
		node->falselabel=(char*)malloc(sizeof(char)*(1+strlen(falselabel)));
		strcpy(node->falselabel,falselabel);
		}
	}
	char* NewVariable(){
		char* x;
		asprintf(&x,"t%d",t++);
		return x;
	}
	char* NewLabel(){
		char* x;
		asprintf(&x,"L%d",++l);
		return x;
	}
	char* Generatee(char*s1,char*s2,char*s3,char*s4,char*s5)
	{
		char* x;
		asprintf(&x,"%s %s %s %s %s\n",s1,s2,s3,s4,s5);
		return x;
	}
char* SelfBuiltstrcat(char*des,char*src){
		char* tamp=des;
		char* num;
		asprintf(&num,"%d ",line++);
		if(src!=NULL){
			if(des==NULL){
				des=(char*)malloc((strlen(src)+1)*sizeof(char));
				strcpy(des,src);
				return des;
			}
		des=(char*)malloc((strlen(des)+strlen(src)+1+strlen(num))*sizeof(char));
		if(tamp!=NULL){
		strcat(des,tamp);
		}
		if(src!=NULL)
		{
		strcat(des,src);
		}
		}
		return des;
	}
 

char * MakeSpace(char *label)
{
	char * msg;
	char x=' ';
	int len = strlen(SelfBuiltstrcat(label,"\0"));
	if(label==NULL || !strcmp(label,""))
		msg="";
	else
		{
		asprintf(&msg,"%c",x);
		while(len<5){
			asprintf(&msg,"%c%s",x,msg);
			len++;
		}
		asprintf(&label,"%s: ",SelfBuiltstrcat(label,"\0"));
		msg=SelfBuiltstrcat(msg,label);
		}
		return msg;
}

char *WordReplacement(const char *s, const char *oldW, const char *newW) 
{ 
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
    for (i=0;s[i]!='\0';i++) 
    { 
        if (strstr(&s[i],oldW) == &s[i]) 
        { 
            cnt++; 
            i += oldWlen-1; 
        } 
    } 
    result=(char*)malloc(i+cnt*(newWlen-oldWlen)+1); 
    i = 0; 
    while (*s) 
    { 
        if (strstr(s, oldW) == s) 
        { 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    }
    result[i] = '\0'; 
    return result; 
}

void calc3AC(node * tree)
{
	if(strcmp(tree->token, "=") == 0 )
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	   addCode(tree,SelfBuiltstrcat(tree->right->code,Generatee(tree->left->var,"=",tree->right->var,"","")),NULL,NULL,NULL,NULL); 
	   return;  
	}
	else if(strcmp(tree->token, "if") == 0)
	{ 
		if(tree->left->left)
		addCode(tree->left->left,NULL,NULL,NULL,NULL,tree->label);
		if(tree->right)
		AddNewCode(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,SelfBuiltstrcat(tree->left->left->code,SelfBuiltstrcat(MakeSpace(tree->left->left->label),SelfBuiltstrcat(MakeSpace(tree->left->left->truelabel),SelfBuiltstrcat(tree->right->code,MakeSpace(tree->truelabel))))),NULL,NULL,NULL,NULL);
		return;
	}
else if(strcmp(tree->token, "if-else") == 0)
	{ 
		if(tree->right->left)
		addCode(tree->right->left,NULL,NULL,tree->label,NULL,NULL);			
		if(tree->right->right->left)
		AddNewCode(tree->right->right->left,NULL,NULL,tree->label,NULL,tree->label);
		if(tree->right->left)
		AddNewCode(tree->right->left,NULL,NULL,tree->label,NULL,tree->label);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat(tree->left->left->code,SelfBuiltstrcat(MakeSpace(tree->left->left->truelabel),tree->right->left->code))
		,SelfBuiltstrcat(SelfBuiltstrcat("goto ",SelfBuiltstrcat(SelfBuiltstrcat(tree->label,"\n"),SelfBuiltstrcat(MakeSpace(tree->left->left->falselabel),tree->right->right->left->code))),MakeSpace(tree->label))),NULL,NULL,NULL,NULL);
	return;
	}
	else if(strcmp(tree->token, "while") == 0)
	{ 
		if(tree->left->left)
			addCode(tree->left->left,NULL,NULL,NULL,tree->falselabel,tree->label);
		if(tree->right)
			AddNewCode(tree->right,NULL,NULL,tree->label,NULL,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat(SelfBuiltstrcat( MakeSpace(tree->truelabel),tree->left->left->code),MakeSpace(tree->falselabel)),
				SelfBuiltstrcat(tree->right->code,SelfBuiltstrcat(SelfBuiltstrcat("\tgoto ",SelfBuiltstrcat(tree->truelabel,"\n")),MakeSpace(tree->label)))),NULL,NULL,NULL,NULL);
		return ;
	}
	else if(strcmp(tree->token, "stmnts") == 0)
	{ 
		if(tree->right!=NULL)
			if(strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
				AddNewCode(tree->right,NULL,NULL,tree->label,NULL,NULL);
        if(tree->right!=NULL && tree->left!=NULL)
        if(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0)
				AddNewCode(tree->right,NULL,NULL,NULL,tree->left->right->label,NULL);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->right!=NULL && tree->left!=NULL)
                if((strcmp(tree->right->token, "while") == 0||strcmp(tree->right->token, "if-else") == 0)&&(strcmp(tree->left->right->token, "if") == 0||strcmp(tree->left->right->token, "if-else") == 0||strcmp(tree->left->right->token, "while") == 0))
                    addCode(tree,SelfBuiltstrcat(tree->left->code,&tree->right->code[8]),NULL,NULL,NULL,NULL);
                    else
					addCode(tree,SelfBuiltstrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
			else if(tree->right!=NULL)
            {
                if(strcmp(tree->right->token, "if-else") == 0||strcmp(tree->right->token, "while") == 0)
                    addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
                    else        
				    addCode(tree,SelfBuiltstrcat(tree->right->code ,MakeSpace(tree->right->label)),NULL,NULL,NULL,NULL);
            }else
				addCode(tree,"",NULL,NULL,NULL,NULL);	
	return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	 char*x; asprintf(&x," %s:\n",tree->left->token);addCode(tree,SelfBuiltstrcat(x,tree->right->right->code),NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "FUNC") == 0)
	{
		 if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
	 char*x; asprintf(&x," %s:\n",tree->left->token);addCode(tree,SelfBuiltstrcat(x,tree->right->left->code),NULL,NULL,NULL,NULL);
		return;
	}
		else if(strcmp(tree->token, "expr_list") == 0)
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->right==NULL)
				addCode(tree,SelfBuiltstrcat(tree->left->code,SelfBuiltstrcat("PushParam ",SelfBuiltstrcat(tree->left->var,"\n"))),NULL,NULL,NULL,NULL);
			else
				addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat(tree->left->code,SelfBuiltstrcat("PushParam ",SelfBuiltstrcat(tree->left->var,"\n"))),tree->right->left->code),NULL,NULL,NULL,NULL);
	}	
	else if(strcmp(tree->token, "Call func") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		char * x,*parm=(char*)malloc(sizeof(char));
		if(tree->right->left==NULL)
			strcpy(parm,"");
		else
			parm=tree->right->left->code;
		addCode(tree,NULL,NewVariable(),NULL,NULL,NULL);
		asprintf(&x,"%s%s = LCALL %s\n‪\tPopParameters %d‬‬‬‬\n",parm,tree->var,tree->left->token,tree->sum);
		addCode(tree,x,NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		 if(tree->left)
			addCode(tree,SelfBuiltstrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);
		else
			addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
		tree->code=WordReplacement(tree->code, "\n\n", "\n") ;
		char x='a',*y,*z;

		while (x<='z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=WordReplacement(tree->code, y, z) ;
			x++;
		}
		x='A';
				while (x<='Z')
		{
			asprintf(&y,"\n%c",x);
			asprintf(&z,"\n\t%c",x);
			tree->code=WordReplacement(tree->code, y, z) ;
			x++;
		}
		return;
	}
    else if(strcmp(tree->token, "BODY") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left){
		
		if(tree->right->right->left->code[strlen(SelfBuiltstrcat(tree->right->right->left->code,"\0"))-2]==':')
			addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"EndFunc\n"),NULL,NULL,NULL,NULL);
		else
		    addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat("\tBeginFunc‬‬\n",tree->right->right->left->code),"\tEndFunc\n"),NULL,NULL,NULL,NULL);
		}
		else		 addCode(tree,SelfBuiltstrcat("\tBeginFunc‬‬\n","\tEndFunc\n"),NULL,NULL,NULL,NULL);
		return;
	}
    else if(strcmp(tree->token, "Main") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		
		addCode(tree,SelfBuiltstrcat(" Main:\n",tree->left->right->code),NULL,NULL,NULL,NULL);
          return;   
    } 
	    else if(strcmp(tree->token, "procedures") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left!=NULL) addCode(tree,SelfBuiltstrcat(tree->left->code,tree->right->code),NULL,NULL,NULL,NULL);else addCode(tree,tree->right->code,NULL,NULL,NULL,NULL);
    return;
	}        

	else if(strcmp(tree->token, "return") == 0)
	{
		
		 if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);

		addCode(tree,SelfBuiltstrcat(tree->left->code,Generatee("return",tree->left->var,"","","")),NULL,NULL,NULL,NULL);
		return;
	}
	else if(strcmp(tree->token, "{") == 0)
	{ 
		if(tree->right->right->left) addCode(tree,NULL,NULL,tree->right->right->left->label,tree->right->right->left->truelabel,tree->right->right->left->falselabel); 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->right->right->left) addCode(tree,tree->right->right->left->code,tree->right->right->left->var,NULL,NULL,NULL); 
		return;			
	}
	else if(strcmp(tree->token, "}") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);           
    }
	else if(strcmp(tree->token, "assmnt_stmnt") == 0)
	{ if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
                     addCode(tree,tree->left->code,tree->left->var,tree->left->label,tree->left->truelabel,tree->left->falselabel); 
					 return;   
    }
	
    else if(strcmp(tree->token, "+") == 0 || 
            strcmp(tree->token, "*") == 0 || 
            strcmp(tree->token, "-") == 0 || 
            strcmp(tree->token, "/") == 0 )
	{
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,NULL,NewVariable(),NULL,NULL,NULL);
		addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat(tree->left->code,tree->right->code),Generatee(tree->var,"=",tree->left->var,tree->token,tree->right->var)),NULL,NULL,NULL,NULL);
    return;}
    
	else if(strcmp(tree->token, "&") == 0)
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				if((tree->left->left == NULL))
				addCode(tree,"",SelfBuiltstrcat("&",(tree->left->token)),NULL,NULL,NULL);
			else if(strcmp(tree->left->left->token,"[")==0)
					{
						char *x,*fv1,*fv2;
						asprintf(&fv1,"%s",NewVariable()); 
						asprintf(&fv2,"%s",NewVariable());
						asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var);
						addCode(tree,SelfBuiltstrcat(tree->left->left->left->code,x),fv2,NULL,NULL,NULL);
					}
				else if (tree->left->left->left==NULL)
				addCode(tree,"",SelfBuiltstrcat("&",(tree->left->left->token)),NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2;
				asprintf(&fv1,"%s",NewVariable());
				asprintf(&fv2,"%s",NewVariable()); 
				asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->left->token,fv2,fv1,tree->left->left->left->left->var); 
				addCode(tree,SelfBuiltstrcat(tree->left->left->left->left->code,x),fv2,NULL,NULL,NULL);
			}
	return;}
	else if(strcmp(tree->token, "^") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if((tree->left->left == NULL))
				addCode(tree,"",SelfBuiltstrcat("*",(tree->left->token)),NULL,NULL,NULL);
			else
			{
				addCode(tree,"",SelfBuiltstrcat("*",(tree->left->left->token)),NULL,NULL,NULL);
			}
			
	return;}
	else if(strcmp(tree->token, "==") == 0 || 
			strcmp(tree->token, ">") == 0 || 
			strcmp(tree->token, ">=") == 0 || 
			strcmp(tree->token, "<") == 0 || 
			strcmp(tree->token, "<=") == 0 || 
			strcmp(tree->token, "!=") == 0) 
	{ 

		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,SelfBuiltstrcat(SelfBuiltstrcat(tree->left->code,tree->right->code),SelfBuiltstrcat(Generatee("if",tree->left->var,tree->token,tree->right->var,SelfBuiltstrcat("goto ",SelfBuiltstrcat(tree->truelabel,"\n")))
				,SelfBuiltstrcat("\tgoto ",SelfBuiltstrcat(tree->falselabel,"\n")))),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "(") == 0)
	{
			addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "!") == 0)
	{ 
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
				
		 addCode(tree,tree->left->code,NULL,NULL,NULL,NULL);
		
	return;}
	else if(strcmp(tree->token, "||") == 0) 
	{
		addCode(tree->left,NULL,NULL,NULL,tree->truelabel,NULL);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,SelfBuiltstrcat(tree->left->code,SelfBuiltstrcat(MakeSpace(tree->left->falselabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "&&") == 0 )
	{
		
		addCode(tree->left,NULL,NULL,NULL,NULL,tree->falselabel);
		addCode(tree->right,NULL,NULL,NULL,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			addCode(tree,SelfBuiltstrcat(tree->left->code,SelfBuiltstrcat(MakeSpace(tree->left->truelabel),tree->right->code)),NULL,NULL,NULL,NULL);
	return;}
	else if(strcmp(tree->token, "null") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}	
	else if(strcmp(tree->token, "solovar") == 0 )
	{ 
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(tree->left->left==NULL)
				addCode(tree,"",tree->left->token,NULL,NULL,NULL);
			else
			{
				char *x,*fv1,*fv2; asprintf(&fv1,"%s",NewVariable()); asprintf(&fv2,"%s",NewVariable()); asprintf(&x,"\t%s = &%s\n\t%s = %s + %s\n",fv1,tree->left->token,fv2,fv1,tree->left->left->left->var); addCode(tree,SelfBuiltstrcat(tree->left->left->left->code,x),SelfBuiltstrcat("*",fv2),NULL,NULL,NULL);
			}	
	return;}
	else if((tree->left!=NULL)&&
			(strcmp(tree->left->token,"INT")==0||
			strcmp(tree->left->token,"HEX")==0||
			strcmp(tree->left->token,"CHAR")==0||
			strcmp(tree->left->token,"REAL")==0||
			strcmp(tree->left->token,"STRING")==0||
			strcmp(tree->left->token,"BOOLEAN")==0))
			{

			if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
			if(strcmp(tree->left->token,"STRING")==0)
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			else
			if(strcmp(tree->left->token,"BOOLEAN")==0)
			{
			if(strcmp(tree->token,"true")==0 && tree->truelabel!=NULL)	
			addCode(tree,SelfBuiltstrcat("goto ",SelfBuiltstrcat(tree->truelabel,"\n")),tree->token,NULL,NULL,NULL);
			else if(strcmp(tree->token,"false")==0 && tree->falselabel!=NULL)
			addCode(tree,SelfBuiltstrcat("goto ",SelfBuiltstrcat(tree->falselabel,"\n")),tree->token,NULL,NULL,NULL);
			else
			addCode(tree,tree->token,tree->token,NULL,NULL,NULL);
			}
			else
			addCode(tree,"",tree->token,NULL,NULL,NULL);
			return;}
	else if(strcmp(tree->token, "") == 0||strcmp(tree->token, " ") == 0)
	{
		if(tree->left)
		addCode(tree->left,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->right)
		addCode(tree->right,NULL,NULL,tree->label,tree->truelabel,tree->falselabel);
		if(tree->left!=NULL) calc3AC(tree->left); if(tree->right!=NULL) calc3AC(tree->right);
		if(tree->left && tree->right)
			addCode(tree,SelfBuiltstrcat(tree->left->code,tree->right->code),tree->right->var,NULL,NULL,NULL);
		else if(tree->left)
			addCode(tree,tree->left->code,tree->left->var,NULL,NULL,NULL);	
		else if(tree->right)
			addCode(tree,tree->right->code,tree->right->var,NULL,NULL,NULL);	
	return;
	}
	else
	{
	if (tree->left) 
		calc3AC(tree->left);
	if (tree->right)
		calc3AC(tree->right);
addCode(tree,"",tree->token,NULL,NULL,NULL);
	return;}
	if (tree->left) 
		calc3AC(tree->left);
	
	if (tree->right)
		calc3AC(tree->right);
}
