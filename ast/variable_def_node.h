#ifndef __ZU_VARIABLE_DEF_NODE_H__
#define __ZU_VARIABLE_DEF_NODE_H__

#include <cdk/ast/basic_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/basic_type.h>
#include <string>

namespace zu {

  /**
   * Class for variable declaration nodes
   */
  class variable_def_node: public cdk::basic_node {
	std::string *_varName;
	basic_type *_type;
	cdk::expression_node *_value;
	bool _local;
  public:

    inline variable_def_node(int lineno, std::string *varName, basic_type *type,cdk::expression_node *value,bool local) :
    cdk::basic_node(lineno), _varName(varName),_type(type),_value(value),_local(local) {}

    inline variable_def_node(int lineno, std::string &varName, basic_type *type,cdk::expression_node *value,bool local) :
    cdk::basic_node(lineno), _varName(&varName),_type(type), _value(value),_local(local) {}

    inline variable_def_node(int lineno, std::string varName, basic_type *type,cdk::expression_node *value,bool local) :
    cdk::basic_node(lineno), _varName(&varName), _type(type),_value(value),_local(local) {}	

	inline basic_type* getType(){ return _type; }

	inline cdk::expression_node *getValue(){ return _value; }

	inline std::string* getVarName(){ return _varName; }
	
	inline bool getLocal(){return _local; }
	/**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    virtual void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_def_node(this, level);
    }

  };

} // zu

#endif
