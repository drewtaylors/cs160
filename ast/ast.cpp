//Automatically Generated C++ Abstract Syntax Tree Class Hierarchy

#include <algorithm>
#include "ast.hpp"
extern int yylineno;
#include "symtab.hpp"
#include "primitive.hpp"



/********* ProgramImpl ************/
 ProgramImpl::ProgramImpl(list<Func_ptr> *p1)  {
	m_func_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		(*m_func_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 ProgramImpl::ProgramImpl(const ProgramImpl & other) {
	m_func_list = new list<Func_ptr>;
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = other.m_func_list->begin();
	  m_func_list_iter != other.m_func_list->end();
	  ++m_func_list_iter){
		m_func_list->push_back( (*m_func_list_iter)->clone() );
	}
 }
 ProgramImpl &ProgramImpl::operator=(const ProgramImpl & other) { ProgramImpl tmp(other); swap(tmp); return *this; }
 void ProgramImpl::swap(ProgramImpl & other) {
	std::swap(m_func_list, other.m_func_list);
 }
 ProgramImpl::~ProgramImpl() {
 	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		delete( *m_func_list_iter );
	}
 }
 void ProgramImpl::visit_children( Visitor* v ) {
 	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		(*m_func_list_iter)->accept( v );
	}
 }
 void ProgramImpl::accept(Visitor *v) { v->visitProgramImpl(this); }
 ProgramImpl *ProgramImpl::clone() const { return new ProgramImpl(*this); }
 
 
/********* FuncImpl ************/
 FuncImpl::FuncImpl(Type *p1, SymName *p2, list<Decl_ptr> *p3, Function_block *p4)  {
	m_type = p1;
	m_symname = p2;
	m_decl_list = p3;
	m_function_block = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_type->m_parent_attribute = &m_attribute;
 	m_symname->m_parent_attribute = &m_attribute;
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->m_parent_attribute = &m_attribute;
	}
	m_function_block->m_parent_attribute = &m_attribute;
  }
 FuncImpl::FuncImpl(const FuncImpl & other) {
	m_type = other.m_type->clone();
	m_symname = other.m_symname->clone();
	m_decl_list = new list<Decl_ptr>;
	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = other.m_decl_list->begin();
	  m_decl_list_iter != other.m_decl_list->end();
	  ++m_decl_list_iter){
		m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	}
	m_function_block = other.m_function_block->clone();
 }
 FuncImpl &FuncImpl::operator=(const FuncImpl & other) { FuncImpl tmp(other); swap(tmp); return *this; }
 void FuncImpl::swap(FuncImpl & other) {
	std::swap(m_type, other.m_type);
	std::swap(m_symname, other.m_symname);
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_function_block, other.m_function_block);
 }
 FuncImpl::~FuncImpl() {
 	delete(m_type);
 	delete(m_symname);
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		delete( *m_decl_list_iter );
	}
	delete(m_function_block);
  }
 void FuncImpl::visit_children( Visitor* v ) {
 	m_type->accept( v );
 	m_symname->accept( v );
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->accept( v );
	}
	m_function_block->accept( v );
  }
 void FuncImpl::accept(Visitor *v) { v->visitFuncImpl(this); }
 FuncImpl *FuncImpl::clone() const { return new FuncImpl(*this); }
 
 
/********* Function_blockImpl ************/
 Function_blockImpl::Function_blockImpl(list<Decl_ptr> *p1, list<Func_ptr> *p2, list<Stat_ptr> *p3, Return *p4)  {
	m_decl_list = p1;
	m_func_list = p2;
	m_stat_list = p3;
	m_return = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->m_parent_attribute = &m_attribute;
	}
//	list<Func_ptr>::iterator m_func_list_iter;
//	for(m_func_list_iter = m_func_list->begin();
//	  m_func_list_iter != m_func_list->end();
//	  ++m_func_list_iter){
//		(*m_func_list_iter)->m_parent_attribute = &m_attribute;
//	}
//	list<Stat_ptr>::iterator m_stat_list_iter;
//	for(m_stat_list_iter = m_stat_list->begin();
//	  m_stat_list_iter != m_stat_list->end();
//	  ++m_stat_list_iter){
//		(*m_stat_list_iter)->m_parent_attribute = &m_attribute;
//	}
	m_return->m_parent_attribute = &m_attribute;
  }
 Function_blockImpl::Function_blockImpl(const Function_blockImpl & other) {
	m_decl_list = new list<Decl_ptr>;
	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = other.m_decl_list->begin();
	  m_decl_list_iter != other.m_decl_list->end();
	  ++m_decl_list_iter){
		m_decl_list->push_back( (*m_decl_list_iter)->clone() );
	}
	m_func_list = new list<Func_ptr>;
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = other.m_func_list->begin();
	  m_func_list_iter != other.m_func_list->end();
	  ++m_func_list_iter){
		m_func_list->push_back( (*m_func_list_iter)->clone() );
	}
	m_stat_list = new list<Stat_ptr>;
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = other.m_stat_list->begin();
	  m_stat_list_iter != other.m_stat_list->end();
	  ++m_stat_list_iter){
		m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	}
	m_return = other.m_return->clone();
 }
 Function_blockImpl &Function_blockImpl::operator=(const Function_blockImpl & other) { Function_blockImpl tmp(other); swap(tmp); return *this; }
 void Function_blockImpl::swap(Function_blockImpl & other) {
	std::swap(m_decl_list, other.m_decl_list);
	std::swap(m_func_list, other.m_func_list);
	std::swap(m_stat_list, other.m_stat_list);
	std::swap(m_return, other.m_return);
 }
 Function_blockImpl::~Function_blockImpl() {
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		delete( *m_decl_list_iter );
	}
	list<Func_ptr>::iterator m_func_list_iter;
	for(m_func_list_iter = m_func_list->begin();
	  m_func_list_iter != m_func_list->end();
	  ++m_func_list_iter){
		delete( *m_func_list_iter );
	}
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		delete( *m_stat_list_iter );
	}
	delete(m_return);
  }
 void Function_blockImpl::visit_children( Visitor* v ) {
 	list<Decl_ptr>::iterator m_decl_list_iter;
	for(m_decl_list_iter = m_decl_list->begin();
	  m_decl_list_iter != m_decl_list->end();
	  ++m_decl_list_iter){
		(*m_decl_list_iter)->accept( v );
	}
//	list<Func_ptr>::iterator m_func_list_iter;
//	for(m_func_list_iter = m_func_list->begin();
//	  m_func_list_iter != m_func_list->end();
//	  ++m_func_list_iter){
//		(*m_func_list_iter)->accept( v );
//	}
//	list<Stat_ptr>::iterator m_stat_list_iter;
//	for(m_stat_list_iter = m_stat_list->begin();
//	  m_stat_list_iter != m_stat_list->end();
//	  ++m_stat_list_iter){
//		(*m_stat_list_iter)->accept( v );
//	}
	m_return->accept( v );
  }
 void Function_blockImpl::accept(Visitor *v) { v->visitFunction_blockImpl(this); }
 Function_blockImpl *Function_blockImpl::clone() const { return new Function_blockImpl(*this); }
 
 
/********* Nested_blockImpl ************/
 Nested_blockImpl::Nested_blockImpl(list<Stat_ptr> *p1)  {
	m_stat_list = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Nested_blockImpl::Nested_blockImpl(const Nested_blockImpl & other) {
	m_stat_list = new list<Stat_ptr>;
	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = other.m_stat_list->begin();
	  m_stat_list_iter != other.m_stat_list->end();
	  ++m_stat_list_iter){
		m_stat_list->push_back( (*m_stat_list_iter)->clone() );
	}
 }
 Nested_blockImpl &Nested_blockImpl::operator=(const Nested_blockImpl & other) { Nested_blockImpl tmp(other); swap(tmp); return *this; }
 void Nested_blockImpl::swap(Nested_blockImpl & other) {
	std::swap(m_stat_list, other.m_stat_list);
 }
 Nested_blockImpl::~Nested_blockImpl() {
 	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		delete( *m_stat_list_iter );
	}
 }
 void Nested_blockImpl::visit_children( Visitor* v ) {
 	list<Stat_ptr>::iterator m_stat_list_iter;
	for(m_stat_list_iter = m_stat_list->begin();
	  m_stat_list_iter != m_stat_list->end();
	  ++m_stat_list_iter){
		(*m_stat_list_iter)->accept( v );
	}
 }
 void Nested_blockImpl::accept(Visitor *v) { v->visitNested_blockImpl(this); }
 Nested_blockImpl *Nested_blockImpl::clone() const { return new Nested_blockImpl(*this); }
 
 
/********* DeclImpl ************/
 DeclImpl::DeclImpl(Type *p1, list<SymName_ptr> *p2)  {
	m_type = p1;
	m_symname_list = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_type->m_parent_attribute = &m_attribute;
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		(*m_symname_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 DeclImpl::DeclImpl(const DeclImpl & other) {
	m_type = other.m_type->clone();
	m_symname_list = new list<SymName_ptr>;
	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = other.m_symname_list->begin();
	  m_symname_list_iter != other.m_symname_list->end();
	  ++m_symname_list_iter){
		m_symname_list->push_back( (*m_symname_list_iter)->clone() );
	}
 }
 DeclImpl &DeclImpl::operator=(const DeclImpl & other) { DeclImpl tmp(other); swap(tmp); return *this; }
 void DeclImpl::swap(DeclImpl & other) {
	std::swap(m_type, other.m_type);
	std::swap(m_symname_list, other.m_symname_list);
 }
 DeclImpl::~DeclImpl() {
 	delete(m_type);
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		delete( *m_symname_list_iter );
	}
 }
 void DeclImpl::visit_children( Visitor* v ) {
 	m_type->accept( v );
 	list<SymName_ptr>::iterator m_symname_list_iter;
	for(m_symname_list_iter = m_symname_list->begin();
	  m_symname_list_iter != m_symname_list->end();
	  ++m_symname_list_iter){
		(*m_symname_list_iter)->accept( v );
	}
 }
 void DeclImpl::accept(Visitor *v) { v->visitDeclImpl(this); }
 DeclImpl *DeclImpl::clone() const { return new DeclImpl(*this); }
 
 
/********* Assignment ************/
 Assignment::Assignment(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 Assignment::Assignment(const Assignment & other) {
	m_symname = other.m_symname->clone();
	m_expr = other.m_expr->clone();
 }
 Assignment &Assignment::operator=(const Assignment & other) { Assignment tmp(other); swap(tmp); return *this; }
 void Assignment::swap(Assignment & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 Assignment::~Assignment() {
 	delete(m_symname);
 	delete(m_expr);
  }
 void Assignment::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr->accept( v );
  }
 void Assignment::accept(Visitor *v) { v->visitAssignment(this); }
 Assignment *Assignment::clone() const { return new Assignment(*this); }
 
 
/********* ArrayAssignment ************/
 ArrayAssignment::ArrayAssignment(SymName *p1, Expr *p2, Expr *p3)  {
	m_symname = p1;
	m_expr_1 = p2;
	m_expr_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 ArrayAssignment::ArrayAssignment(const ArrayAssignment & other) {
	m_symname = other.m_symname->clone();
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 ArrayAssignment &ArrayAssignment::operator=(const ArrayAssignment & other) { ArrayAssignment tmp(other); swap(tmp); return *this; }
 void ArrayAssignment::swap(ArrayAssignment & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 ArrayAssignment::~ArrayAssignment() {
 	delete(m_symname);
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void ArrayAssignment::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void ArrayAssignment::accept(Visitor *v) { v->visitArrayAssignment(this); }
 ArrayAssignment *ArrayAssignment::clone() const { return new ArrayAssignment(*this); }
 
 
/********* Call ************/
 Call::Call(SymName *p1, SymName *p2, list<Expr_ptr> *p3)  {
	m_symname_1 = p1;
	m_symname_2 = p2;
	m_expr_list = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname_1->m_parent_attribute = &m_attribute;
 	m_symname_2->m_parent_attribute = &m_attribute;
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		(*m_expr_list_iter)->m_parent_attribute = &m_attribute;
	}
 }
 Call::Call(const Call & other) {
	m_symname_1 = other.m_symname_1->clone();
	m_symname_2 = other.m_symname_2->clone();
	m_expr_list = new list<Expr_ptr>;
	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = other.m_expr_list->begin();
	  m_expr_list_iter != other.m_expr_list->end();
	  ++m_expr_list_iter){
		m_expr_list->push_back( (*m_expr_list_iter)->clone() );
	}
 }
 Call &Call::operator=(const Call & other) { Call tmp(other); swap(tmp); return *this; }
 void Call::swap(Call & other) {
	std::swap(m_symname_1, other.m_symname_1);
	std::swap(m_symname_2, other.m_symname_2);
	std::swap(m_expr_list, other.m_expr_list);
 }
 Call::~Call() {
 	delete(m_symname_1);
 	delete(m_symname_2);
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		delete( *m_expr_list_iter );
	}
 }
 void Call::visit_children( Visitor* v ) {
 	m_symname_1->accept( v );
 	m_symname_2->accept( v );
 	list<Expr_ptr>::iterator m_expr_list_iter;
	for(m_expr_list_iter = m_expr_list->begin();
	  m_expr_list_iter != m_expr_list->end();
	  ++m_expr_list_iter){
		(*m_expr_list_iter)->accept( v );
	}
 }
 void Call::accept(Visitor *v) { v->visitCall(this); }
 Call *Call::clone() const { return new Call(*this); }
 
 
/********* ArrayCall ************/
 ArrayCall::ArrayCall(SymName *p1, Expr *p2, SymName *p3, list<Expr_ptr> *p4)  {
	m_symname_1 = p1;
	m_expr_1 = p2;
	m_symname_2 = p3;
	m_expr_list_2 = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname_1->m_parent_attribute = &m_attribute;
 	m_expr_1->m_parent_attribute = &m_attribute;
 	m_symname_2->m_parent_attribute = &m_attribute;
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		(*m_expr_list_2_iter)->m_parent_attribute = &m_attribute;
	}
 }
 ArrayCall::ArrayCall(const ArrayCall & other) {
	m_symname_1 = other.m_symname_1->clone();
	m_expr_1 = other.m_expr_1->clone();
	m_symname_2 = other.m_symname_2->clone();
	m_expr_list_2 = new list<Expr_ptr>;
	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = other.m_expr_list_2->begin();
	  m_expr_list_2_iter != other.m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		m_expr_list_2->push_back( (*m_expr_list_2_iter)->clone() );
	}
 }
 ArrayCall &ArrayCall::operator=(const ArrayCall & other) { ArrayCall tmp(other); swap(tmp); return *this; }
 void ArrayCall::swap(ArrayCall & other) {
	std::swap(m_symname_1, other.m_symname_1);
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_symname_2, other.m_symname_2);
	std::swap(m_expr_list_2, other.m_expr_list_2);
 }
 ArrayCall::~ArrayCall() {
 	delete(m_symname_1);
 	delete(m_expr_1);
 	delete(m_symname_2);
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		delete( *m_expr_list_2_iter );
	}
 }
 void ArrayCall::visit_children( Visitor* v ) {
 	m_symname_1->accept( v );
 	m_expr_1->accept( v );
 	m_symname_2->accept( v );
 	list<Expr_ptr>::iterator m_expr_list_2_iter;
	for(m_expr_list_2_iter = m_expr_list_2->begin();
	  m_expr_list_2_iter != m_expr_list_2->end();
	  ++m_expr_list_2_iter){
		(*m_expr_list_2_iter)->accept( v );
	}
 }
 void ArrayCall::accept(Visitor *v) { v->visitArrayCall(this); }
 ArrayCall *ArrayCall::clone() const { return new ArrayCall(*this); }
 
 
/********* IfNoElse ************/
 IfNoElse::IfNoElse(Expr *p1, Nested_block *p2)  {
	m_expr = p1;
	m_nested_block = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block->m_parent_attribute = &m_attribute;
  }
 IfNoElse::IfNoElse(const IfNoElse & other) {
	m_expr = other.m_expr->clone();
	m_nested_block = other.m_nested_block->clone();
 }
 IfNoElse &IfNoElse::operator=(const IfNoElse & other) { IfNoElse tmp(other); swap(tmp); return *this; }
 void IfNoElse::swap(IfNoElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block, other.m_nested_block);
 }
 IfNoElse::~IfNoElse() {
 	delete(m_expr);
 	delete(m_nested_block);
  }
 void IfNoElse::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block->accept( v );
  }
 void IfNoElse::accept(Visitor *v) { v->visitIfNoElse(this); }
 IfNoElse *IfNoElse::clone() const { return new IfNoElse(*this); }
 
 
/********* IfWithElse ************/
 IfWithElse::IfWithElse(Expr *p1, Nested_block *p2, Nested_block *p3)  {
	m_expr = p1;
	m_nested_block_1 = p2;
	m_nested_block_2 = p3;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
 	m_nested_block_1->m_parent_attribute = &m_attribute;
 	m_nested_block_2->m_parent_attribute = &m_attribute;
  }
 IfWithElse::IfWithElse(const IfWithElse & other) {
	m_expr = other.m_expr->clone();
	m_nested_block_1 = other.m_nested_block_1->clone();
	m_nested_block_2 = other.m_nested_block_2->clone();
 }
 IfWithElse &IfWithElse::operator=(const IfWithElse & other) { IfWithElse tmp(other); swap(tmp); return *this; }
 void IfWithElse::swap(IfWithElse & other) {
	std::swap(m_expr, other.m_expr);
	std::swap(m_nested_block_1, other.m_nested_block_1);
	std::swap(m_nested_block_2, other.m_nested_block_2);
 }
 IfWithElse::~IfWithElse() {
 	delete(m_expr);
 	delete(m_nested_block_1);
 	delete(m_nested_block_2);
  }
 void IfWithElse::visit_children( Visitor* v ) {
 	m_expr->accept( v );
 	m_nested_block_1->accept( v );
 	m_nested_block_2->accept( v );
  }
 void IfWithElse::accept(Visitor *v) { v->visitIfWithElse(this); }
 IfWithElse *IfWithElse::clone() const { return new IfWithElse(*this); }
 
 
/********* ForLoop ************/
 ForLoop::ForLoop(Stat *p1, Expr *p2, Stat *p3, Nested_block *p4)  {
	m_stat_1 = p1;
	m_expr = p2;
	m_stat_2 = p3;
	m_nested_block = p4;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_stat_1->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
 	m_stat_2->m_parent_attribute = &m_attribute;
 	m_nested_block->m_parent_attribute = &m_attribute;
  }
 ForLoop::ForLoop(const ForLoop & other) {
	m_stat_1 = other.m_stat_1->clone();
	m_expr = other.m_expr->clone();
	m_stat_2 = other.m_stat_2->clone();
	m_nested_block = other.m_nested_block->clone();
 }
 ForLoop &ForLoop::operator=(const ForLoop & other) { ForLoop tmp(other); swap(tmp); return *this; }
 void ForLoop::swap(ForLoop & other) {
	std::swap(m_stat_1, other.m_stat_1);
	std::swap(m_expr, other.m_expr);
	std::swap(m_stat_2, other.m_stat_2);
	std::swap(m_nested_block, other.m_nested_block);
 }
 ForLoop::~ForLoop() {
 	delete(m_stat_1);
 	delete(m_expr);
 	delete(m_stat_2);
 	delete(m_nested_block);
  }
 void ForLoop::visit_children( Visitor* v ) {
 	m_stat_1->accept( v );
 	m_expr->accept( v );
 	m_stat_2->accept( v );
 	m_nested_block->accept( v );
  }
 void ForLoop::accept(Visitor *v) { v->visitForLoop(this); }
 ForLoop *ForLoop::clone() const { return new ForLoop(*this); }
 
 
/********* None ************/
 None::None()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 None::None(const None & other) {
 }
 None &None::operator=(const None & other) { None tmp(other); swap(tmp); return *this; }
 void None::swap(None & other) {
 }
 None::~None() {
  }
 void None::visit_children( Visitor* v ) {
  }
 void None::accept(Visitor *v) { v->visitNone(this); }
 None *None::clone() const { return new None(*this); }
 
 
/********* ReturnImpl ************/
 ReturnImpl::ReturnImpl(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 ReturnImpl::ReturnImpl(const ReturnImpl & other) {
	m_expr = other.m_expr->clone();
 }
 ReturnImpl &ReturnImpl::operator=(const ReturnImpl & other) { ReturnImpl tmp(other); swap(tmp); return *this; }
 void ReturnImpl::swap(ReturnImpl & other) {
	std::swap(m_expr, other.m_expr);
 }
 ReturnImpl::~ReturnImpl() {
 	delete(m_expr);
  }
 void ReturnImpl::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void ReturnImpl::accept(Visitor *v) { v->visitReturnImpl(this); }
 ReturnImpl *ReturnImpl::clone() const { return new ReturnImpl(*this); }
 
 
/********* TInteger ************/
 TInteger::TInteger()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TInteger::TInteger(const TInteger & other) {
 }
 TInteger &TInteger::operator=(const TInteger & other) { TInteger tmp(other); swap(tmp); return *this; }
 void TInteger::swap(TInteger & other) {
 }
 TInteger::~TInteger() {
  }
 void TInteger::visit_children( Visitor* v ) {
  }
 void TInteger::accept(Visitor *v) { v->visitTInteger(this); }
 TInteger *TInteger::clone() const { return new TInteger(*this); }
 
 
/********* TBoolean ************/
 TBoolean::TBoolean()  {
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
 }
 TBoolean::TBoolean(const TBoolean & other) {
 }
 TBoolean &TBoolean::operator=(const TBoolean & other) { TBoolean tmp(other); swap(tmp); return *this; }
 void TBoolean::swap(TBoolean & other) {
 }
 TBoolean::~TBoolean() {
  }
 void TBoolean::visit_children( Visitor* v ) {
  }
 void TBoolean::accept(Visitor *v) { v->visitTBoolean(this); }
 TBoolean *TBoolean::clone() const { return new TBoolean(*this); }
 
 
/********* TIntArray ************/
 TIntArray::TIntArray(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 TIntArray::TIntArray(const TIntArray & other) {
	m_primitive = other.m_primitive->clone();
 }
 TIntArray &TIntArray::operator=(const TIntArray & other) { TIntArray tmp(other); swap(tmp); return *this; }
 void TIntArray::swap(TIntArray & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 TIntArray::~TIntArray() {
 	delete(m_primitive);
  }
 void TIntArray::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void TIntArray::accept(Visitor *v) { v->visitTIntArray(this); }
 TIntArray *TIntArray::clone() const { return new TIntArray(*this); }
 
 
/********* And ************/
 And::And(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 And::And(const And & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 And &And::operator=(const And & other) { And tmp(other); swap(tmp); return *this; }
 void And::swap(And & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 And::~And() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void And::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void And::accept(Visitor *v) { v->visitAnd(this); }
 And *And::clone() const { return new And(*this); }
 
 
/********* Div ************/
 Div::Div(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Div::Div(const Div & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Div &Div::operator=(const Div & other) { Div tmp(other); swap(tmp); return *this; }
 void Div::swap(Div & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Div::~Div() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Div::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Div::accept(Visitor *v) { v->visitDiv(this); }
 Div *Div::clone() const { return new Div(*this); }
 
 
/********* Compare ************/
 Compare::Compare(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Compare::Compare(const Compare & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Compare &Compare::operator=(const Compare & other) { Compare tmp(other); swap(tmp); return *this; }
 void Compare::swap(Compare & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Compare::~Compare() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Compare::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Compare::accept(Visitor *v) { v->visitCompare(this); }
 Compare *Compare::clone() const { return new Compare(*this); }
 
 
/********* Gt ************/
 Gt::Gt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Gt::Gt(const Gt & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Gt &Gt::operator=(const Gt & other) { Gt tmp(other); swap(tmp); return *this; }
 void Gt::swap(Gt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gt::~Gt() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Gt::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Gt::accept(Visitor *v) { v->visitGt(this); }
 Gt *Gt::clone() const { return new Gt(*this); }
 
 
/********* Gteq ************/
 Gteq::Gteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Gteq::Gteq(const Gteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Gteq &Gteq::operator=(const Gteq & other) { Gteq tmp(other); swap(tmp); return *this; }
 void Gteq::swap(Gteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Gteq::~Gteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Gteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Gteq::accept(Visitor *v) { v->visitGteq(this); }
 Gteq *Gteq::clone() const { return new Gteq(*this); }
 
 
/********* Lt ************/
 Lt::Lt(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Lt::Lt(const Lt & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Lt &Lt::operator=(const Lt & other) { Lt tmp(other); swap(tmp); return *this; }
 void Lt::swap(Lt & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lt::~Lt() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Lt::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Lt::accept(Visitor *v) { v->visitLt(this); }
 Lt *Lt::clone() const { return new Lt(*this); }
 
 
/********* Lteq ************/
 Lteq::Lteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Lteq::Lteq(const Lteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Lteq &Lteq::operator=(const Lteq & other) { Lteq tmp(other); swap(tmp); return *this; }
 void Lteq::swap(Lteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Lteq::~Lteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Lteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Lteq::accept(Visitor *v) { v->visitLteq(this); }
 Lteq *Lteq::clone() const { return new Lteq(*this); }
 
 
/********* Minus ************/
 Minus::Minus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Minus::Minus(const Minus & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Minus &Minus::operator=(const Minus & other) { Minus tmp(other); swap(tmp); return *this; }
 void Minus::swap(Minus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Minus::~Minus() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Minus::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Minus::accept(Visitor *v) { v->visitMinus(this); }
 Minus *Minus::clone() const { return new Minus(*this); }
 
 
/********* Noteq ************/
 Noteq::Noteq(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Noteq::Noteq(const Noteq & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Noteq &Noteq::operator=(const Noteq & other) { Noteq tmp(other); swap(tmp); return *this; }
 void Noteq::swap(Noteq & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Noteq::~Noteq() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Noteq::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Noteq::accept(Visitor *v) { v->visitNoteq(this); }
 Noteq *Noteq::clone() const { return new Noteq(*this); }
 
 
/********* Or ************/
 Or::Or(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Or::Or(const Or & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Or &Or::operator=(const Or & other) { Or tmp(other); swap(tmp); return *this; }
 void Or::swap(Or & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Or::~Or() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Or::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Or::accept(Visitor *v) { v->visitOr(this); }
 Or *Or::clone() const { return new Or(*this); }
 
 
/********* Plus ************/
 Plus::Plus(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Plus::Plus(const Plus & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Plus &Plus::operator=(const Plus & other) { Plus tmp(other); swap(tmp); return *this; }
 void Plus::swap(Plus & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Plus::~Plus() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Plus::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Plus::accept(Visitor *v) { v->visitPlus(this); }
 Plus *Plus::clone() const { return new Plus(*this); }
 
 
/********* Times ************/
 Times::Times(Expr *p1, Expr *p2)  {
	m_expr_1 = p1;
	m_expr_2 = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr_1->m_parent_attribute = &m_attribute;
 	m_expr_2->m_parent_attribute = &m_attribute;
  }
 Times::Times(const Times & other) {
	m_expr_1 = other.m_expr_1->clone();
	m_expr_2 = other.m_expr_2->clone();
 }
 Times &Times::operator=(const Times & other) { Times tmp(other); swap(tmp); return *this; }
 void Times::swap(Times & other) {
	std::swap(m_expr_1, other.m_expr_1);
	std::swap(m_expr_2, other.m_expr_2);
 }
 Times::~Times() {
 	delete(m_expr_1);
 	delete(m_expr_2);
  }
 void Times::visit_children( Visitor* v ) {
 	m_expr_1->accept( v );
 	m_expr_2->accept( v );
  }
 void Times::accept(Visitor *v) { v->visitTimes(this); }
 Times *Times::clone() const { return new Times(*this); }
 
 
/********* Not ************/
 Not::Not(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Not::Not(const Not & other) {
	m_expr = other.m_expr->clone();
 }
 Not &Not::operator=(const Not & other) { Not tmp(other); swap(tmp); return *this; }
 void Not::swap(Not & other) {
	std::swap(m_expr, other.m_expr);
 }
 Not::~Not() {
 	delete(m_expr);
  }
 void Not::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Not::accept(Visitor *v) { v->visitNot(this); }
 Not *Not::clone() const { return new Not(*this); }
 
 
/********* Uminus ************/
 Uminus::Uminus(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Uminus::Uminus(const Uminus & other) {
	m_expr = other.m_expr->clone();
 }
 Uminus &Uminus::operator=(const Uminus & other) { Uminus tmp(other); swap(tmp); return *this; }
 void Uminus::swap(Uminus & other) {
	std::swap(m_expr, other.m_expr);
 }
 Uminus::~Uminus() {
 	delete(m_expr);
  }
 void Uminus::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Uminus::accept(Visitor *v) { v->visitUminus(this); }
 Uminus *Uminus::clone() const { return new Uminus(*this); }
 
 
/********* Magnitude ************/
 Magnitude::Magnitude(Expr *p1)  {
	m_expr = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_expr->m_parent_attribute = &m_attribute;
  }
 Magnitude::Magnitude(const Magnitude & other) {
	m_expr = other.m_expr->clone();
 }
 Magnitude &Magnitude::operator=(const Magnitude & other) { Magnitude tmp(other); swap(tmp); return *this; }
 void Magnitude::swap(Magnitude & other) {
	std::swap(m_expr, other.m_expr);
 }
 Magnitude::~Magnitude() {
 	delete(m_expr);
  }
 void Magnitude::visit_children( Visitor* v ) {
 	m_expr->accept( v );
  }
 void Magnitude::accept(Visitor *v) { v->visitMagnitude(this); }
 Magnitude *Magnitude::clone() const { return new Magnitude(*this); }
 
 
/********* Ident ************/
 Ident::Ident(SymName *p1)  {
	m_symname = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
  }
 Ident::Ident(const Ident & other) {
	m_symname = other.m_symname->clone();
 }
 Ident &Ident::operator=(const Ident & other) { Ident tmp(other); swap(tmp); return *this; }
 void Ident::swap(Ident & other) {
	std::swap(m_symname, other.m_symname);
 }
 Ident::~Ident() {
 	delete(m_symname);
  }
 void Ident::visit_children( Visitor* v ) {
 	m_symname->accept( v );
  }
 void Ident::accept(Visitor *v) { v->visitIdent(this); }
 Ident *Ident::clone() const { return new Ident(*this); }
 
 
/********* ArrayAccess ************/
 ArrayAccess::ArrayAccess(SymName *p1, Expr *p2)  {
	m_symname = p1;
	m_expr = p2;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_symname->m_parent_attribute = &m_attribute;
 	m_expr->m_parent_attribute = &m_attribute;
  }
 ArrayAccess::ArrayAccess(const ArrayAccess & other) {
	m_symname = other.m_symname->clone();
	m_expr = other.m_expr->clone();
 }
 ArrayAccess &ArrayAccess::operator=(const ArrayAccess & other) { ArrayAccess tmp(other); swap(tmp); return *this; }
 void ArrayAccess::swap(ArrayAccess & other) {
	std::swap(m_symname, other.m_symname);
	std::swap(m_expr, other.m_expr);
 }
 ArrayAccess::~ArrayAccess() {
 	delete(m_symname);
 	delete(m_expr);
  }
 void ArrayAccess::visit_children( Visitor* v ) {
 	m_symname->accept( v );
 	m_expr->accept( v );
  }
 void ArrayAccess::accept(Visitor *v) { v->visitArrayAccess(this); }
 ArrayAccess *ArrayAccess::clone() const { return new ArrayAccess(*this); }
 
 
/********* IntLit ************/
 IntLit::IntLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 IntLit::IntLit(const IntLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 IntLit &IntLit::operator=(const IntLit & other) { IntLit tmp(other); swap(tmp); return *this; }
 void IntLit::swap(IntLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 IntLit::~IntLit() {
 	delete(m_primitive);
  }
 void IntLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void IntLit::accept(Visitor *v) { v->visitIntLit(this); }
 IntLit *IntLit::clone() const { return new IntLit(*this); }
 
 
/********* BoolLit ************/
 BoolLit::BoolLit(Primitive *p1)  {
	m_primitive = p1;
	m_attribute.lineno = yylineno;
	m_parent_attribute = NULL;
	m_primitive->m_parent_attribute = &m_attribute;
  }
 BoolLit::BoolLit(const BoolLit & other) {
	m_primitive = other.m_primitive->clone();
 }
 BoolLit &BoolLit::operator=(const BoolLit & other) { BoolLit tmp(other); swap(tmp); return *this; }
 void BoolLit::swap(BoolLit & other) {
	std::swap(m_primitive, other.m_primitive);
 }
 BoolLit::~BoolLit() {
 	delete(m_primitive);
  }
 void BoolLit::visit_children( Visitor* v ) {
 	m_primitive->accept( v );
  }
 void BoolLit::accept(Visitor *v) { v->visitBoolLit(this); }
 BoolLit *BoolLit::clone() const { return new BoolLit(*this); }
 
 

