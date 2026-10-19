
%{
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node *root;

struct node* create(char c, struct node* l, struct node* r) {
    struct node* n = malloc(sizeof(struct node));
    n->data = c;
    n->left = l;
    n->right = r;
    return n;
}

void print(struct node* n) {
    if (!n) return;
    printf("%c ", n->data);
    print(n->left);
    print(n->right);
}

int yylex(void);
void yyerror(char *s);
%}

%union { struct node* ptr; }
%token NUMBER
%type <ptr> E T F

%%

E : E '+' T  { $$ = create('+', $1, $3); root = $$; }
  | T        { $$ = $1; root = $$; }
  ;

T : T '*' F  { $$ = create('*', $1, $3); }
  | F        { $$ = $1; }
  ;

F : NUMBER   { $$ = create('N', NULL, NULL); }
  ;

%%

void yyerror(char *s) {
    printf("Invalid expression\n");
}

int main() {
    printf("Enter expression: ");
    if (yyparse() == 0) {
        printf("AST (Preorder): ");
        print(root);
    }
    return 0;
}
