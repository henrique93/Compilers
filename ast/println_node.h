// $Id: println_node.h,v 1.3 2016/05/20 05:24:07 ist179042 Exp $ -*- c++ -*-
#ifndef __ZU_PRINTLNNODE_H__
#define __ZU_PRINTLNNODE_H__

#include "print_node.h"

namespace zu {

  /**
   * Class for describing print nodes.
   */
  class println_node: public print_node {
    cdk::expression_node *_argument;

  public:
    inline println_node(int lineno, cdk::expression_node *argument) :
      print_node(lineno,argument){
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_println_node(this, level);
    }

  };

} // zu

#endif
