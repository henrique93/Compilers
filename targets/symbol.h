// $Id: symbol.h,v 1.4 2016/05/19 18:24:56 ist179042 Exp $ -*- c++ -*-
#ifndef __ZU_SEMANTICS_SYMBOL_H__
#define __ZU_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace zu {

    class symbol {
      basic_type *_type;
      std::string _name;
      long _value; // hack!
      bool _defined;
      int _offset;

    public:
      inline symbol(basic_type *type, const std::string &name, int offset, bool defined = true) :
          _type(type), _name(name),_defined(defined),_offset(offset) {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      inline long value() const {
        return _value;
      }
      inline long value(long v) {
        return _value = v;
      }

      inline bool defined(){
        return _defined;
      }

      inline void defined(bool defined){
        _defined = defined;
      }

      inline int offset(){ return _offset; }
      inline void offset(int offset){ _offset=offset; }

    };

} // zu

#endif
