#ifndef EVALUATE_H_INCLUDED 
#define EVALUATE_H_INCLUDED
/* include guard to avoid including prototypes more than once*/ 
/* prototypes for functions eval_op and eval*/

long eval_op(long x, char* op, long y);

long eval(mpc_ast_t* t);

#endif  
