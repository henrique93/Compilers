#ifndef __ZU_MALLOCNODE_H__
#define __ZU_MALLOCNODE_H__

#include <cdk/ast/expression_node.h>
#include <string>

namespace zu {

  /**
   * Class for describing the indexation ('[]') operator
   */
  class malloc_node: public cdk::expression_node {
    private:
			cdk::expression_node *_size;
	public:
    /**
     * @param lineno source code line number for this node
     * @param arg operand
     */
    inline malloc_node(int lineno,cdk::expression_node *size) :
        cdk::expression_node(lineno),_size(size) {
    }

	cdk::expression_node* getSize(){ return _size; }


    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_malloc_node(this, level);
    }

  };

} // zu

#endif
