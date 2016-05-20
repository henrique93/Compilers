#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "targets/postfix_size.h"
#include "ast/all.h"  // all.h is automatically generated


void zu::postfix_size::do_malloc_node(zu::malloc_node * const node, int lvl){
  node->accept(this, lvl);
}
void zu::postfix_size::do_variable_dec_node(zu::variable_dec_node * const node, int lvl){
  _value += node->getType()->size();
}

void zu::postfix_size::do_sequence_node(cdk::sequence_node * const node, int lvl){
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl);
}
void zu::postfix_size::do_double_node(cdk::double_node * const node, int lvl){}
void zu::postfix_size::do_integer_node(cdk::integer_node * const node, int lvl){}
void zu::postfix_size::do_string_node(cdk::string_node * const node, int lvl){}
void zu::postfix_size::do_neg_node(cdk::neg_node * const node, int lvl){}
void zu::postfix_size::do_add_node(cdk::add_node * const node, int lvl){}
void zu::postfix_size::do_sub_node(cdk::sub_node * const node, int lvl){}
void zu::postfix_size::do_mul_node(cdk::mul_node * const node, int lvl){}
void zu::postfix_size::do_div_node(cdk::div_node * const node, int lvl){}
void zu::postfix_size::do_mod_node(cdk::mod_node * const node, int lvl){}
void zu::postfix_size::do_lt_node(cdk::lt_node * const node, int lvl){}
void zu::postfix_size::do_le_node(cdk::le_node * const node, int lvl){}
void zu::postfix_size::do_ge_node(cdk::ge_node * const node, int lvl){}
void zu::postfix_size::do_gt_node(cdk::gt_node * const node, int lvl){}
void zu::postfix_size::do_ne_node(cdk::ne_node * const node, int lvl){}
void zu::postfix_size::do_eq_node(cdk::eq_node * const node, int lvl){}
void zu::postfix_size::do_if_node(zu::if_node * const node, int lvl){}
void zu::postfix_size::do_if_else_node(zu::if_else_node * const node, int lvl){}
void zu::postfix_size::do_lvalue_node(zu::lvalue_node * const node, int lvl){}
void zu::postfix_size::do_rvalue_node(zu::rvalue_node * const node, int lvl){}
void zu::postfix_size::do_evaluation_node(zu::evaluation_node * const node, int lvl){}
void zu::postfix_size::do_print_node(zu::print_node * const node, int lvl){}
void zu::postfix_size::do_read_node(zu::read_node * const node, int lvl){}
void zu::postfix_size::do_assignment_node(zu::assignment_node * const node, int lvl){}
void zu::postfix_size::do_println_node(zu::println_node * const node, int lvl){}
void zu::postfix_size::do_break_node(zu::break_node * const node, int lvl){}
void zu::postfix_size::do_continue_node(zu::continue_node * const node, int lvl){}
void zu::postfix_size::do_or_node(zu::or_node * const node, int lvl){}
void zu::postfix_size::do_and_node(zu::and_node * const node, int lvl){}
void zu::postfix_size::do_for_node(zu::for_node * const node, int lvl){}
void zu::postfix_size::do_pos_node(zu::pos_node * const node, int lvl){}
void zu::postfix_size::do_return_node(zu::return_node * const node, int lvl){}
void zu::postfix_size::do_not_node(zu::not_node * const node, int lvl){}
void zu::postfix_size::do_variable_node(zu::variable_node * const node, int lvl){}
void zu::postfix_size::do_variable_def_node(zu::variable_def_node * const node, int lvl){}
void zu::postfix_size::do_function_call_node(zu::function_call_node * const node, int lvl){}
void zu::postfix_size::do_function_def_node(zu::function_def_node * const node, int lvl){
  _value += node->getReturnType()->size();
  node->getBlock()->accept(this, lvl);
}
void zu::postfix_size::do_function_dec_node(zu::function_dec_node * const node, int lvl){}
void zu::postfix_size::do_id_node(zu::id_node * const node, int lvl){}
void zu::postfix_size::do_index_node(zu::index_node * const node, int lvl){}
