#ifndef __ZU_VARIABLE_DEC_NODE_H__
#define __ZU_VARIABLE_DEC_NODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/basic_type.h>
#include <string>

namespace zu {

  /**
   * Class for variable declaration nodes
   */
  class variable_dec_node: public cdk::basic_node {
	std::string *_varName;
	basic_type *_type;
	bool _local;
  public:

    inline variable_dec_node(int lineno, std::string *varName, basic_type *type,bool local) :
    cdk::basic_node(lineno), _varName(varName),_type(type),_local(local) {}

    inline variable_dec_node(int lineno, std::string &varName, basic_type *type,bool local) :
    cdk::basic_node(lineno), _varName(&varName),_type(type),_local(local) {}

    inline variable_dec_node(int lineno, std::string varName, basic_type *type,bool local) :
    cdk::basic_node(lineno), _varName(&varName), _type(type),_local(local) {}	

	inline basic_type* getType(){ return _type; }

	inline std::string* getVarName(){ return _varName; }
	
	inline bool getLocal(){ return _local; }
	/**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    virtual void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_dec_node(this, level);
    }

  };

} // zu

#endif
