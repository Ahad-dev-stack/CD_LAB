%{
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
};

struct node* create(char data, struct node* left, struct node* right)
{
    struct node* n = malloc(sizeof(struct node));
    n->data = data;
    n->left = left;
    n->right = right;
    return n;
}

void print(struct node* root)
{
    if(root == NULL)
        return;

    printf("%c ", root->data);
    print(root->left);
    print(root->right);
}

int yylex();
void yyerror(char *s);

struct node* root;
%}

%union {
    struct node* ptr;
}

%token NUMBER
%type <ptr> E T F

%%

E : E '+' T { $$ = create('+', $1, $3); root = $$; }
  | T        { $$ = $1; root = $$; }
  ;

T : T '*' F { $$ = create('*', $1, $3); }
  | F        { $$ = $1; }
  ;

F : NUMBER  { $$ = create('N', NULL, NULL); }
  ;

%%

void yyerror(char *s)
{
    printf("Invalid Expression\n");
}

int main()
{
    printf("Enter expression: ");
    yyparse();

    printf("AST (Preorder): ");
    print(root);

    return 0;
}
