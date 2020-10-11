#include <stdio.h>
#include <stdlib.h>
#include "mpc.h"
#include "evaluate.h"

#ifdef __linux__
#include <editline/readline.h>
#include <editline/history.h>
#else 
printf("This lisp interpreter doesn't run on your platform");
exit(EXIT_FAILURE);
#endif 


int main(int argc, char** argv) {

	/*
	Create a parser for lisp language
	*/

	mpc_parser_t* Number = mpc_new("number");
	mpc_parser_t* Operator = mpc_new("operator");
	mpc_parser_t* Expr = mpc_new("expr");
	mpc_parser_t* Lispy = mpc_new("lispy");

	/* Define grammer for language */
	mpca_lang(MPCA_LANG_DEFAULT, 
		"number : /-?[0-9]+/; \
		operator : '+' | '-' | '/' | '*'; \
		expr : <number> | '(' <operator> <expr>+ ')'; \
		lispy : /^/  <operator> <expr>+ /$/;", \
	Number, Operator, Expr, Lispy);

	puts("Lisp Interpreter Version 1.0.0");
	puts("Press CTRL + C to Exit \n");

	/* repl */
	while (1) {

		char* input = readline("Interpreter> ");

		/*Add history */
		add_history(input);

		//printf("%s\n", input);
		/*parse user input */
		mpc_result_t r;
		if (mpc_parse("<stdin>", input, Lispy, &r)) {
			/*print abstract syntax tree */
			//mpc_ast_print(r.output);

			long result = eval(r.output);
			printf("%li\n", result);
			mpc_ast_delete(r.output);

		} else {

			mpc_err_print(r.error);
			mpc_err_delete(r.error);
		}

		//fputs("YourName> ", stdout);
		//fgets(input, 1024, stdin);

		printf("Interpreter> %s\n", input);
		free(input);
	}

	mpc_cleanup(4, Number, Operator, Expr, Lispy);

	return 0;
}