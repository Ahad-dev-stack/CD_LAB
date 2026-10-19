
%{
#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *left, *right;
};

struct node* create(char c, struct node* l, struct node* r) {
    struct node* n = malloc(sizeof(struct node));
    n->data = c;
    n->left = l;
    n->right = r;
    return n;
}

void print(struct node* n) {
    if (n == NULL) return;
    printf("%c ", n->data);
    print(n->left);
    print(n->right);
}

int yylex(void);
void yyerror(char *s);
%}

%union {
    struct node* ptr;
}

%token NUMBER
%type <ptr> E T F

%start E

%%

E : E '+' T  { $$ = create('+', $1, $3); }
  | T        { $$ = $1; }
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
        print($$.ptr);
    }
    return 0;
}
