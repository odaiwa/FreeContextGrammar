%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#define false 0
	#define true 1

	typedef struct node
	{
		char *token;
		struct node *left;
		struct node *right;
	} node;

	typedef struct args
	{
		char * name;
		char * type;
		char * len;
	}args;

    typedef struct Function 
	{
        char * name;
		struct args * args;
        char *returnType; 
		int countArgs;
		int findreturn;
    } Function;

	typedef struct Varaiables
	{	int isArg;
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
		int countvar;
		int funcionCounter;
		Function ** func;
		struct code * nxtLEVEL;
		struct code * previosLEVEL;
	}code;

	char * typeOfExp(node *,code*);
	args * mkArgs(node *,int *);
	void addFunction(char * name,args * args,node *returnType,int countArgs,code*);
	void addvar(args * args,int,int,code * scooope);
	code* mkcode(char *);
	node* mknode(char* token, node *left, node *right);
	int yylex();
	int yyerror(char *e);
	void push(code* from,char*);
	int printlevel=0;
	code* mycode=NULL;
	code* CodeList(code * codey);
	static int scope=0;
	void MakeScpSyntx(node *tree,code * scope);
	char* findfunc(node * tree,code * scooope);
	char *findvar(node * tree,code * scooope);
	args * callfuncargs(code *,node *tree,int * count);
	int flagMain=false;
	
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

%left EQL NOTEQL LESS LESSEQL GREATEREQL GREATER OR AND
%left PLUS MINUS RETURN
%left MULTI DIVISION
%left SEMICOLON 
%right NOT CLOSEBRACE

%nonassoc IDENTIFIER 
%nonassoc OPENPAREN
%nonassoc IF
%nonassoc ELSE 


%type <node> address_expr stmnts stmnt_block derefrence_expr expr_list call_func 
%type <node> expr lhs assmnt_stmnt new_block 
%type <node> stmnt type_pro type_id var_id declear paren_expr
%type <node> pro_body para_list para_pro procedure procedures
%type <node> main program project declears 
%%
 //Main project
 
project: cmmnt program { MakeScpSyntx($2,mycode); }; 

program: procedures main{$$=mknode("CODE",$1,$2);}

 //comments
cmmnt: COMMENT cmmnt | ;

 //this is the main
main: PROCEDUR MAIN OPENPAREN CLOSEPAREN OPENBRACE pro_body CLOSEBRACE
{
$$=mknode("Main",mknode("ARGS",NULL,$6),NULL);
};

//functions
procedures: procedures  procedure {$$=mknode("",$1,$2);}
	| {$$=NULL;};

//function
procedure: FUNCTION IDENTIFIER OPENPAREN para_pro CLOSEPAREN cmmnt RETURN type_pro  OPENBRACE  pro_body CLOSEBRACE
{ 
		$$=mknode("FUNC",mknode($2,mknode(" ",NULL,NULL),mknode("ARGS",$4,mknode("Return",$8,NULL))),mknode("",$10,NULL));

}
| PROCEDUR IDENTIFIER OPENPAREN para_pro CLOSEPAREN  OPENBRACE  pro_body CLOSEBRACE
{
	$$=mknode("PROC",mknode($2,mknode("",NULL,NULL),NULL),mknode("ARGS",$4,$7));
};


//list of parameter for function or not
para_pro: para_list {$$=$1;}
| {$$=NULL;};

//list of parameter

para_list: var_id COLON type_id {$$=mknode("(",$3,mknode("",$1,mknode(")",NULL,NULL)));}
	|  para_list SEMICOLON cmmnt  para_list {$$=mknode("",$1,mknode("",$4,NULL));}	;

 //Procedure body
pro_body: cmmnt  procedures declears stmnts 
{
	$$=mknode("BODY", mknode(" ",$2,NULL),mknode(" ",$3,mknode(" ",$4,mknode(" ",NULL,NULL))));
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
	| STRING OPENBRACKET DECIMAL_LTL CLOSEBRACKET {$$=mknode("string", mknode("[",mknode("$3",NULL,NULL),NULL), NULL);}
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
stmnt_block: stmnt {$$=$1;}|declear {$$=$1;}|procedure {$$=$1;} |SEMICOLON  {$$=mknode("",NULL,NULL);};

//new block in stmnts
new_block: OPENBRACE procedures cmmnt declears stmnts CLOSEBRACE cmmnt
{
	$$=mknode("{",$2,mknode("", $4,mknode("", $5,("}",NULL,NULL))));
};

//Statment
stmnt: IF OPENPAREN expr CLOSEPAREN  stmnt_block 
{
	$$=mknode("if",
	mknode("(", $3, 
	mknode(")",NULL,NULL)),$5);
}%prec IF
| IF OPENPAREN expr CLOSEPAREN   stmnt_block    ELSE  stmnt_block  
{
	$$=mknode("if-else",
	mknode("", $3, 
	mknode("",NULL,NULL)),
	mknode("",$5,
	mknode("",$7,NULL)));
}
| WHILE cmmnt OPENPAREN expr CLOSEPAREN  stmnt_block  
{
	$$=mknode("while",
	mknode("(", $4, 
	mknode(")",NULL,NULL)),$6);
}
| assmnt_stmnt SEMICOLON cmmnt {$$=mknode("",$1,NULL);}
| expr SEMICOLON cmmnt {$$=$1;}
| RETURN expr SEMICOLON cmmnt {$$=mknode("return",$2,NULL);}
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
| address_expr {$$=$1;}
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
	| address_expr {$$=$1;}
	| derefrence_expr {$$=$1;}
	| call_func cmmnt {$$=$1;}
	| DECIMAL_LTL {$$=mknode($1,mknode("INT",NULL,NULL),NULL);}
	| HEX_LTL {$$=mknode($1,mknode("HEX", NULL, NULL),NULL);}
	| CHAR_LTL {$$=mknode($1,mknode("CHAR", NULL, NULL),NULL);}
	| REAL_LTL {$$=mknode($1,mknode("REAL", NULL, NULL),NULL);}
	| STRING_LTL {$$=mknode($1,mknode("STRING", NULL, NULL),NULL);}
	| BOOLFALSE {$$=mknode($1,mknode("BOOLEAN", NULL, NULL),NULL);}
	| BOOLTRUE {$$=mknode($1,mknode("BOOLEAN", NULL, NULL),NULL);}
	| LENGTH IDENTIFIER LENGTH 
	{
		$$=mknode("|",
		mknode($2,NULL,NULL),
		mknode("|",NULL,NULL));
	}
	| IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode("onevariable",mknode($1,mknode("[",$3,mknode("]",NULL,NULL)),NULL),NULL);}
	| IDENTIFIER {$$=mknode("onevariable",mknode($1,NULL,NULL),NULL);}
	| NULLL {$$=mknode("null",NULL,NULL);};

//address expression like &id

//address_exprs:ADDRESS address_exprs {$$=mknode($1,$2,NULL);} | address_expr {$$=$1;};

address_expr: ADDRESS IDENTIFIER {$$=mknode("&",mknode($2,NULL,NULL),NULL);}
	| ADDRESS OPENPAREN IDENTIFIER CLOSEPAREN {$$=mknode("&",mknode("(",mknode($3,NULL,NULL),NULL),mknode(")",NULL,NULL));}
	| ADDRESS IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode("&", mknode($2,mknode("[",$4,mknode("]",NULL,NULL)),NULL),NULL);}
	| ADDRESS OPENPAREN IDENTIFIER OPENBRACKET expr CLOSEBRACKET CLOSEPAREN 
	{
		$$=mknode("&",
		mknode("(", 
		mknode($3,mknode("[",$5,mknode("]",NULL,NULL)),NULL)
		,mknode(")",NULL,NULL)),NULL);
	};
//value expression like ^id
//derefrence_exprs:DEREFRENCE derefrence_exprs {$$=mknode($1,$2,NULL);} | derefrence_expr {$$=$1;};

	derefrence_expr: DEREFRENCE IDENTIFIER {$$=mknode("^",mknode($2,NULL,NULL),NULL);}
	| DEREFRENCE OPENPAREN expr CLOSEPAREN {$$=mknode("^",mknode("(",$3,NULL),mknode(")",NULL,NULL));}
	| DEREFRENCE IDENTIFIER OPENBRACKET expr CLOSEBRACKET 
	{$$=mknode($1, mknode($2,mknode("[",$4,mknode("]",NULL,NULL)),NULL), NULL);};

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
	int x= yyparse();
	if(x==0)
	{
	printf("Code is Valid\n"); 
	}
	return x;
}

args * callfuncargs(code * scooope,node *tree,int * count)
{
	args  *arr=NULL,ar[50];
	char* type,*len;
	while(tree!=NULL)
	{
		ar[(*count)++].type=typeOfExp(tree->left,scooope);
		if(tree->right!=NULL)
			tree=tree->right->left;
		else
			tree=NULL;
	}
	arr=(args*)malloc(sizeof(args)*(*count));
	for(int i=0;i<*count;i++)
		arr[i].type=ar[i].type;
	return arr;
}

char* findfunc(node * tree,code * scooope)
{
	code*temp=scooope;
	args* args;
	int find=false,flag=true;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->funcionCounter;i++)
		if(strcmp(tree->left->token,temp->func[i]->name)==0)
		{
			find=true;
			flag=true;
			int count=0;
			args=callfuncargs(scooope,tree->right->left,&count);
			//printf("%d %d ",count,temp->func[i]->countArgs);
			if(count==temp->func[i]->countArgs)
			{
				for(int j=0;j<count;j++)
				{
					//printf("%s %s",args[j].type,temp->func[i]->args->type);
					if(strcmp(args[j].type,temp->func[i]->args->type)!=0)
						flag=false;
				}
				if(flag==true)
					return temp->func[i]->returnType;
			}
		}
		temp=temp->previosLEVEL;
	}
	printf("Semantic ERORR\nCannot use Function [%s] before it has been declared in scope %s in func/proc %s\n",tree->left->token,scooope->name,mycode->func[mycode->funcionCounter-1]->name);
	if(find==true)
		printf("Function has been found but with other args type \n");
		exit(1);
}

char *findvar(node * tree,code * scooope)
{
	code*temp=scooope;
	if(strcmp(tree->token,"onevariable")==0)
		tree=tree->left;
	while(temp!=NULL)
	{
		for(int i=0;i<temp->countvar;i++)
		if(strcmp(tree->token,temp->var[i].name)==0)
		{
			if(tree->left!=NULL && strcmp(tree->left->token,"[")==0)
			{
				if(strcmp(temp->var[i].type,"string")==0)
					if(strcmp(typeOfExp(tree->left->left,scooope),"int")==0)
					{
						return "char";
					}
					else
					{
						printf("Semantic Error\nindex can be only type of integer Format(<string>[<int>]) in func/proc [%s]\n",mycode->func[mycode->funcionCounter-1]->name);
						exit(1);
					}
				else
				{
					printf("Semantic Error\n[] operation can be only applied on string Format (<string>[<int>]) in func/proc %s\n",mycode->func[mycode->funcionCounter-1]->name);
					exit(1);
				}
			}
			else
			return temp->var[i].type;
		}
		temp=temp->previosLEVEL;
	}
	printf("Semantic Error\nusing variable %s not found in func/proc %s\nor it has been used before declaring it\n",tree->token,mycode->func[mycode->funcionCounter-1]->name);
	exit(1);
}

char * typeOfExp(node * tree,code* scooope){
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
		if(strcmp(typeOfExp(tree->left,scooope),"boolean")==0)
			msg="boolean";
		else{
			printf("Semantic Error\nOperation ! can be applied only on bool data type\n");
			exit(1);
		}

		if(strcmp(tree->token,"|")==0)
		if(strcmp(typeOfExp(tree->left,scooope),"string")==0)
			msg="int";
		else{
			printf("Semantic Error\nOperation Length [||] can be only applied to string types in func/proc [%s]\n",mycode->func[mycode->funcionCounter-1]->name);
			exit(1);
		}

		if(strcmp(tree->token,"==")==0||strcmp(tree->token,"!=")==0)
		{
			if(strcmp(typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope))==0&&strcmp(typeOfExp(tree->right,scooope),"string")!=0)
				msg="boolean";
			else{
				printf("Semantic Error\nOperation [%s] can be applied only on similar data types <bool>,<int>,<real>,<char>\n",tree->token);
				exit(1);
			}
		}

		if(strcmp(tree->token,">=")==0||strcmp(tree->token,">")==0||strcmp(tree->token,"<=")==0||strcmp(tree->token,"<")==0)
		{
			if((strcmp(typeOfExp(tree->left,scooope),"int")==0||strcmp(typeOfExp(tree->left,scooope),"real")==0)&&(strcmp(typeOfExp(tree->right,scooope),"int")==0||strcmp(typeOfExp(tree->right,scooope),"real")==0))
				msg="boolean";
			else{
				printf("Semantic Error\nOperation [%s] can only be applied on ,<int>,<real>\n",tree->token);
				exit(1);
			}
		}

		if(strcmp(tree->token,"&&")==0||strcmp(tree->token,"||")==0)
		{

			if(strcmp(typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope))==0&&strcmp(typeOfExp(tree->right,scooope),"boolean")==0)
				msg="boolean";
			else{
				printf("Semantic Error\ncan't apply [%s] between [%s] and [%s] in func/proc [%s]\n",tree->token,typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope),mycode->func[mycode->funcionCounter-1]->name);
				exit(1);
			}
		}

		if(strcmp(tree->token,"-")==0||strcmp(tree->token,"+")==0)
		{
			if((strcmp(typeOfExp(tree->left,scooope),"int")==0||strcmp(typeOfExp(tree->left,scooope),"real")==0)&&(strcmp(typeOfExp(tree->right,scooope),"int")==0||strcmp(typeOfExp(tree->right,scooope),"real")==0))
			{
				if(strcmp(typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope))==0&&strcmp(typeOfExp(tree->left,scooope),"int")==0)
				msg="int";
			else
				msg="real";
			}

			if(strcmp(typeOfExp(tree->right,scooope),"int")==0&&(strcmp(typeOfExp(tree->left,scooope),"char*")==0||strcmp(typeOfExp(tree->right,scooope),"int*")==0||strcmp(typeOfExp(tree->right,scooope),"real*")==0)){
				msg=typeOfExp(tree->left,scooope);
			}
			else if(strcmp(msg,"")==0)
			{
				printf("Semantic Error\nOperation [%s] is only applied to <int>,<real>\n",tree->token);
				exit(1);
			}
		}
		if(strcmp(tree->token,"*")==0||strcmp(tree->token,"/")==0)
		{
			if((strcmp(typeOfExp(tree->left,scooope),"int")==0||strcmp(typeOfExp(tree->left,scooope),"real")==0)&&(strcmp(typeOfExp(tree->right,scooope),"int")==0||strcmp(typeOfExp(tree->right,scooope),"real")==0))
			{
				if(strcmp(typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope))==0&&strcmp(typeOfExp(tree->left,scooope),"int")==0)
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
		if(strcmp(tree->token,"&")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=typeOfExp(tree->left->left,scooope);
			else{
				msg=typeOfExp(tree->left,scooope);
				
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
		if(strcmp(tree->token,"^")==0)
		{
			if(strcmp(tree->left->token,"(")==0)
				msg=typeOfExp(tree->left->left,scooope);
			else
				msg=typeOfExp(tree->left,scooope);
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
			msg=typeOfExp(tree->left,scooope);
		if(strcmp(tree->token,"Call func")==0)
			msg=findfunc(tree,scooope);		
	}
	if(strcmp(msg,"")==0)
		msg=findvar(tree,scooope);
	return msg;
}
void push(code* from,char* name)
{
	code * point;
	if(mycode==NULL)
		mycode=mkcode(name);
	else{
		point=mycode;
		while(point->nxtLEVEL!=NULL)
			point=point->nxtLEVEL;
			point->nxtLEVEL=mkcode(name);
			point->nxtLEVEL->previosLEVEL=from;
	}
}

code* mkcode(char* name)
{	
	code *newlvl = (code*)malloc(sizeof(code));
	newlvl->place=++scope;
	newlvl->name=name;
	newlvl->var=NULL;
	newlvl->countvar=0;
	newlvl->func=NULL;
	newlvl->funcionCounter=0;
	newlvl->nxtLEVEL=NULL;
	newlvl->previosLEVEL=NULL;
	return newlvl;
}

void addvar(args * args,int countvars,int isArg,code * scooope){
	if(countvars==0)
	return;
	Varaiable* temp;
	code * codey=scooope;
	for(int i=0;i<countvars;i++)
		for(int j=0;j<countvars;j++)
	if(i!=j && strcmp(args[j].name,args[i].name)==0 )
	{
		printf("sorry you can't some vars %s in one declear",args[i].name);
		code * t=codey->previosLEVEL;
		while(t->previosLEVEL!=NULL && t->previosLEVEL->funcionCounter==0)
			t=t->previosLEVEL;
		if(t->func!=NULL)
		printf(",in func %s\n",t->func[t->funcionCounter-1]->name);
			else
		printf("\n");
		exit(1);
	}
	if(codey->var==NULL)
	{ 
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*countvars);
	}
	else
	{
		temp=codey->var;
		codey->var=(Varaiable*) malloc(sizeof(Varaiable)*(codey->countvar+countvars));
		for(int i=0;i<codey->countvar;i++)
		{
			for(int j=0;j<countvars;j++)
			{
				if(strcmp(temp[i].name,args[j].name)==0 )
				{
					printf("Semantic Error\ncan't declare var [%s] in the same scope more than one time",temp[i].name);
					code * t=codey->previosLEVEL;
					while(t->previosLEVEL!=NULL && t->previosLEVEL->funcionCounter==0)
						t=t->previosLEVEL;
					if(t->func!=NULL)
					printf(",in func %s\n",t->func[t->funcionCounter-1]->name);
					else
					printf("\n");
					exit(1);
				}
			}
			codey->var[i]=temp[i];	
		}
	}
	for(int j=0;j<countvars;j++)
	{
		codey->var[codey->countvar].name=args[j].name;
		codey->var[codey->countvar].value=NULL;
		codey->var[codey->countvar].isArg=isArg;
		codey->var[codey->countvar].len=args[j].len;
		codey->var[(codey->countvar)++].type=args[j].type;
	}
	/*printf("vars in scope %s \n",codey->name);
	for(int i=0;i<codey->countvar;i++)
	{
		printf("%s %s,", codey->var[i].name,codey->var[i].type);
	}printf("\nend vars scope %d\n",codey->place);*/
}

void addFunction(char * name,args * args,node *returnType,int countArgs,code * scooope){
	Function** temp;
	code * codey=scooope;
	for(int i=0;i<countArgs;i++)
		for(int j=0;j<countArgs;j++)
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
		codey->func=(Function**) malloc(sizeof(Function*)*(codey->funcionCounter+1));
		for(int i=0;i<codey->funcionCounter;i++)
		{
				if(strcmp(temp[i]->name,name)==0 )
				{
					printf("Semantic Error\ncan't declare function [%s] more than one time in the same scope \n",temp[i]->name);
					exit(1);
				}
				codey->func[i]=temp[i];
		}
	}
		codey->func[codey->funcionCounter]=(Function*) malloc(sizeof(Function));
		codey->func[codey->funcionCounter]->name=name;
		codey->func[codey->funcionCounter]->args=args;
		if(returnType==NULL)
		codey->func[codey->funcionCounter]->returnType=NULL;
		else{
		if(strcmp(returnType->token,"string")==0)
			{
				printf("ERORR,return type func %s cant be string\n",name);
				exit(1);
			}
		codey->func[codey->funcionCounter]->returnType=returnType->token;
		}
		codey->func[codey->funcionCounter]->countArgs=countArgs;
		codey->func[codey->funcionCounter]->findreturn=false;
		++(codey->funcionCounter);
}

args * mkArgs(node *tree,int *count){
	args  *arr=NULL,ar[50];
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
		arr=(args*)malloc(sizeof(args)*(*count));
		for(int i=0;i<*count;i++){
			arr[i].name=ar[i].name;
			arr[i].type=ar[i].type;
		}
	}
	return arr;
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

int yyerror(char *e)
{
	int yydebug=1; 
	printf("Error [%s] at line %d\n",e,yylineno);
	printf("does not accept '%s'\n",yytext);
	
	return 0;
}

code* CodeList(code * codey)
{
	code * scooope=codey;
	if(scooope!=NULL)
	while(scooope->nxtLEVEL!=NULL)
		scooope=scooope->nxtLEVEL;
	return scooope;
}

void MakeScpSyntx(node *tree,code * scooope){

	if(strcmp(tree->token, "=") == 0 )
	{
		if(!(strcmp(typeOfExp(tree->right,scooope),"NULL")==0&& (strcmp(typeOfExp(tree->left,scooope),"real*")==0||strcmp(typeOfExp(tree->left,scooope),"int*")==0||strcmp(typeOfExp(tree->left,scooope),"char*")==0)))
		if(strcmp(typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope))!=0)
		{
			printf("Semntic Error\nCannot assign [%s] to [%s] in func/proc %s\n",typeOfExp(tree->left,scooope),typeOfExp(tree->right,scooope),mycode->func[mycode->funcionCounter-1]->name);
			exit(1);
		}
	}
	else if(strcmp(tree->token, "var") == 0)
	{
		int countvar=0;
		args * var=mkArgs(tree,&countvar);
		addvar(var,countvar,0,scooope);
	}
	else if(strcmp(tree->token, "if") == 0)
	{
		if(strcmp(typeOfExp(tree->left->left,scooope),"boolean")!=0)
		{
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}

		if(strcmp(tree->right->token,"{")!=0)
		{
			push(scooope,tree->token);
			if (tree->left) 
				MakeScpSyntx(tree->left,CodeList( scooope->nxtLEVEL));
	
			if (tree->right)
				MakeScpSyntx(tree->right,CodeList( scooope->nxtLEVEL));
        	scope--;
			return;
		}

	}
		else if(strcmp(tree->token, "while") == 0)
	{
		if(strcmp(typeOfExp(tree->left->left,scooope),"boolean")!=0)
		{
			printf("Semantic Error\nWhile Condition must be a boolean expreession\n");
			exit(1);
		}
		if(strcmp(tree->right->token,"{")!=0)
		{
			push(scooope,tree->token);
			if (tree->left) 
				MakeScpSyntx(tree->left,CodeList( scooope->nxtLEVEL));
			if (tree->right)
				MakeScpSyntx(tree->right,CodeList( scooope->nxtLEVEL));
        	scope--;
			return;
		}
	}
			
	else if(strcmp(tree->token, "FUNC") == 0 )
	{
        int count=0;
		args * arg=mkArgs(tree->left->right->left,&count);
		addFunction(tree->left->token,arg,tree->left->right->right->left,count,scooope);
		push(scooope,tree->token);
		addvar(arg,count,1,CodeList(scooope));
	if (tree->left) 
		MakeScpSyntx(tree->left,CodeList(scooope->nxtLEVEL));
	if (tree->right)
		MakeScpSyntx(tree->right,CodeList( scooope->nxtLEVEL));
		if(scooope->func[scooope->funcionCounter-1]->findreturn==false)
		{
			printf("ERORR,in func %s not find return\n",tree->left->token);
			exit(1);
		}
        scope--;		
		return;
	}
    else if(strcmp(tree->token, "PROC") == 0)
	{
        int count=0;
		args * arg=mkArgs(tree->right->left,&count);
		addFunction(tree->left->token,arg,NULL,count,scooope);
		push(scooope,tree->token);
		addvar(arg,count,1,CodeList(scooope));
	if (tree->left) 
		MakeScpSyntx(tree->left,CodeList( scooope->nxtLEVEL));
	
	if (tree->right)
		MakeScpSyntx(tree->right,CodeList( scooope->nxtLEVEL));
		scope--;	
		return;
    }

	else if(strcmp(tree->token, "Call func") == 0)
	{
		findfunc(tree,scooope);
	
	}
	else if(strcmp(tree->token, "CODE") == 0)
	{
	push(NULL,tree->token);
	if (tree->left) 
		MakeScpSyntx(tree->left,mycode);
	
	if (tree->right)
		MakeScpSyntx(tree->right,mycode);
		scope--;
		return;
	}
    else if(strcmp(tree->token, "BODY") == 0)
	{     
    }
	else if(strcmp(tree->token, "ARGS") == 0)
	{     
    }
    else if(strcmp(tree->token, "Main") == 0)
	{
		if(flagMain==true && strcmp(scooope->name,"CODE")==0)
		{
			printf("Main needs to be one anad only and not inside a func/proc\n");
			exit(1);
		}
		flagMain=true;
		addFunction(tree->token,NULL,NULL,0,scooope);
		push(scooope,tree->token);
	if (tree->left) 
		MakeScpSyntx(tree->left,CodeList( scooope->nxtLEVEL));
	if (tree->right)
		MakeScpSyntx(tree->right,CodeList( scooope->nxtLEVEL));
        scope--;
		return;      
    }       
	else if(strcmp(tree->token, "if-else") == 0)
	{
		if(strcmp(typeOfExp(tree->left->left,scooope),"boolean")!=0)
		{
			printf("ERORR, in if expr most be type boolean\n");
			exit(1);
		}
		if(strcmp(tree->right->left->token,"{")!=0)
		{
			push(scooope,tree->token);
			MakeScpSyntx(tree->right->left,CodeList( scooope->nxtLEVEL));
			scope--;
			push(scooope,tree->token);
			MakeScpSyntx(tree->right->right->left,CodeList( scooope->nxtLEVEL));
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
			temp=temp->previosLEVEL;
			flag=false;
		}
		if(flag==false)
		{
			if(strcmp(typeOfExp(tree->left,scooope),temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->returnType))
			{
			printf("ERORR,return no some type in func %s \n",temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->name);
			printf("%s ,%s %s\n",typeOfExp(tree->left,scooope),temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->returnType,temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->name);
            exit(1);
			}
		}
		else{
		if(temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->returnType!=NULL){
			if(0==strcmp(typeOfExp(tree->left,scooope),temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->returnType))
			{
				temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->findreturn=true;
			}
		    else
            {
		    	printf("Semantic Error\nreturn type is not as declared in Function [%s] \n",temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->name);
		    	printf("returned [%s] supposed to be [%s] Function [%s]\n",typeOfExp(tree->left,scooope),temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->returnType,temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->name);
                exit(1);
		    }
		}
		else
		{
			printf("ERORR,return cant be in proc %s\n",temp->previosLEVEL->func[temp->previosLEVEL->funcionCounter-1]->name);
			exit(1);
		}  
		}  
	}
	else if(strcmp(tree->token, "{") == 0)
	{
    push(scooope,tree->token);
	if (tree->left) 
		MakeScpSyntx(tree->left,CodeList( scooope->nxtLEVEL));
	
	if (tree->right)
		MakeScpSyntx(tree->right,CodeList( scooope->nxtLEVEL));
        scope--;
		return;			
	}
    else if(strcmp(tree->token, "onevariable") == 0 )
	{
		findvar(tree->left,scooope);
	}
	if (tree->left) 
		MakeScpSyntx(tree->left,scooope);
	
	if (tree->right)
		MakeScpSyntx(tree->right,scooope);
}