// $Id: xml_writer.cpp,v 1.21 2016/05/20 05:24:07 ist179042 Exp $ -*- c++ -*-
#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void zu::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    if(node->node(i) != nullptr) node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  processSimple(node, lvl);
}

void zu::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  processSimple(node, lvl);
}

//---------------------------------------------------------------------------

inline void zu::xml_writer::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

void zu::xml_writer::do_id_node(zu::id_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void zu::xml_writer::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void zu::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_and_node(zu::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void zu::xml_writer::do_or_node(zu::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void zu::xml_writer::do_not_node(zu::not_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_continue_node(zu::continue_node * const node, int lvl) {
  os() << "<continue_node/>"<<std::endl;
}

void zu::xml_writer::do_break_node(zu::break_node * const node, int lvl) {
  os() << "<break_node/>" << std::endl;
}

void zu::xml_writer::do_return_node(zu::return_node * const node, int lvl) {
  os() << "<return_node/>" << std::endl;
}

                                                                           //---------------------------------------------------------------------------

void zu::xml_writer::do_pos_node(zu::pos_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_index_node(zu::index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("pointer", lvl +2 );
  node->getPointer()->accept(this, lvl + 4);
  closeTag("pointer",lvl + 2);

  openTag("offset", lvl + 2);
  node->getIndex()->accept(this,lvl + 4);
  closeTag("offset", lvl + 4);

}

void zu::xml_writer::do_malloc_node(zu::malloc_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  os()<<"<malloc size='"<<node->getSize()<<"'/>"<<std::endl;
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_rvalue_node(zu::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_lvalue_node(zu::lvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  os()<<"<lvalue/>"<<std::endl;
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_assignment_node(zu::assignment_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  openTag("lvalue", lvl + 2);
  node->lvalue()->accept(this, lvl + 4);
  closeTag("lvalue", lvl + 2);
  openTag("rvalue", lvl + 2);
  node->rvalue()->accept(this, lvl + 4);
  closeTag("rvalue", lvl + 2);
  closeTag(node, lvl);
}


void zu::xml_writer::do_variable_node(zu::variable_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  os() << "<variable name='" << *(node->getVarName()) << "' />"<<std::endl;

}

void zu::xml_writer::do_variable_dec_node(zu::variable_dec_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  os() << "<var_dec type='" << proccessBasicType(node->getType()) <<"' local='"<<node->getLocal() <<"' />" << std::endl;
}

void zu::xml_writer::do_variable_def_node(zu::variable_def_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  os() << "<var_def type='" << proccessBasicType(node->getType()) <<"' local='"<<node->getLocal()<<"' name='"<< *(node->getVarName()) <<"' >" << std::endl;
  openTag("value",lvl+2);
  node->getValue()->accept(this,lvl+4);
  closeTag("value",lvl-2);
  os() << "</var_def>" << std::endl;
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_function_def_node(zu::function_def_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  os() << "<function_def_node function_name='" << *(node ->getFunctionName())<<"' return_type='" << proccessBasicType(node->getReturnType()) <<"' local='"<< node->getLocal()<<"'>";
  openTag( "defaultReturn", lvl+2);
  node->getDefaultReturn()->accept( this, lvl+2);
  closeTag("defaultReturn",lvl+2);
  /* openTag("function_name", lvl + 2);
  node -> getFunctionName();
  closeTag("function_name", lvl - 2);

  openTag("arguments", lvl + 2);
  node -> getArgs() -> accept (this, lvl + 4);
  closeTag("arguments", lvl - 2);

  openTag("return_type", lvl + 2);
  proccessBasicType( node->getReturnType() , lvl + 2);
  closeTag("return_type", lvl - 2);
  */
  openTag("block", lvl + 2);
  if(node->getBlock()!= nullptr) node -> getBlock() -> accept (this, lvl + 4);
  closeTag("block", lvl - 2);

  /*openTag("local", lvl + 2);
  node -> getLocal();
  closeTag("local", lvl - 2);

  openTag("default_return", lvl + 2);
  node -> getDefaultReturn() -> accept (this, lvl + 4);*/
  //os() << "</function_def_node>"<<std::endl;

  closeTag(node, lvl);
}

void zu::xml_writer::do_function_call_node(zu::function_call_node * const node, int lvl) {
	os() << "<function_call name='" << *(node->getFunctionName())<< "' >";
	openTag("args",lvl + 2);
	if(node->getArgs()!=nullptr) node->getArgs()->accept(this,lvl+4);
	closeTag("args",lvl-2);
}

void zu::xml_writer::do_function_dec_node(zu::function_dec_node * const node, int lvl) {
	os() << "<function_call name='" << *(node->getFunctionName())<< "' return-type='"<< proccessBasicType(node->getReturnType())<<"' >"<<std::endl;
	openTag("args",lvl + 2);
	if(node->getArgs()!=nullptr) node->getArgs()->accept(this,lvl+4);
	closeTag("args",lvl-2);
	os() << "</function_call>" << std::endl;
}


//---------------------------------------------------------------------------

void zu::xml_writer::do_evaluation_node(zu::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}
    cdk::expression_node *_argument;
void zu::xml_writer::do_println_node(zu::println_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node,lvl);
	openTag("to-print",lvl+2);
	node->argument()->accept(this,lvl+4);
	closeTag("to-print",lvl+2);
	closeTag(node,lvl);
}

void zu::xml_writer::do_print_node(zu::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_read_node(zu::read_node * const node, int lvl) {
  openTag(node, lvl);
  node->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_for_node(zu::for_node * const node, int lvl) {
    CHECK_TYPES(_compiler, _symtab, node);
    openTag(node,lvl);
    openTag("initialization",lvl+2);
    if(node->init()!=nullptr) node->init()->accept(this,lvl+2);
    closeTag("initialization",lvl+2);

    openTag("condition",lvl+2);
    if(node->condition()!=nullptr) node->condition()->accept(this,lvl+2);
    closeTag("condition",lvl+2);

    openTag("increment",lvl+2);
    if(node->increment()!=nullptr) node->increment()->accept(this,lvl+2);
    closeTag("increment",lvl+2);
    closeTag(node,lvl);
}

//---------------------------------------------------------------------------

void zu::xml_writer::do_if_node(zu::if_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void zu::xml_writer::do_if_else_node(zu::if_else_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}
