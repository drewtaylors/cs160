#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"
#include "assert.h"
#include <typeinfo>
#include <stdio.h>

class Codegen : public Visitor
{
	private:

	FILE * m_outputfile;
	SymTab *m_st;

	// basic size of a word (integers and booleans) in bytes
	static const int wordsize = 4;

	int label_count; //access with new_label

	// ********** Helper functions ********************************

	// this is used to get new unique labels (cleverly named label1, label2, ...)
	int new_label() { return label_count++; }

	// this mode is used for the code
	void set_text_mode() { fprintf( m_outputfile, ".text\n\n"); }
	
	// PART 1:
	// 1) get arithmetic expressions on integers working:
	//	  you wont really be able to run your code,
	//	  but you can visually inspect it to see that the correct
	//    chains of opcodes are being generated.
	// 2) get function calls working:
	//    if you want to see at least a very simple program compile
	//    and link successfully against gcc-produced code, you
	//    need to get at least this far
	// 3) get boolean operation working
	//    before we can implement any of the conditional control flow 
	//    stuff, we need to have booleans worked out.  
	// 4) control flow:
	//    we need a way to have if-elses and for loops in our language. 
	//
	// Hint: Symbols have an associated member variable called m_offset
	//    That offset can be used to figure out where in the activation 
	//    record you should look for a particuar variable

	///////////////////////////////////////////////////////////////////////////////
	//
	//  function_prologue
	//  function_epilogue
	//
	//  Together these two functions implement the callee-side of the calling
	//  convention.  A stack frame has the following layout:
	//
	//                          <- SP (before pre-call / after post-ret)
	//  high -----------------
	//       | actual arg n  |
	//       | ...           |
	//       | actual arg 1  |  <- SP (just before call / just after ret)
	//       -----------------
	//       |  Return Addr  |  <- SP (just after call / just before ret)
	//       =================
	//       | previous %ebp |
	//       -----------------
	//       | temporary 1   |
	//       | ...           |
	//       | temporary n   |  <- SP (after prologue / before epilogue)
	//  low  -----------------
	//
	//
	//			  ||		
	//			  ||
	//			 \  /
	//			  \/
	//
	//
	//  The caller is responsible for placing the actual arguments
	//  and the return address on the stack. Actually, the return address
	//  is put automatically on the stack as part of the x86 call instruction.
	//
	//  On function entry, the callee
	//
	//  (1) allocates space for the callee's temporaries on the stack
	//  
	//  (2) saves callee-saved registers (see below) - including the previous activation record pointer (%ebp)
	//
	//  (3) makes the activation record pointer (frame pointer - %ebp) point to the start of the temporary region
	//
	//  (4) possibly copies the actual arguments into the temporary variables to allow easier access
	//
	//  On function exit, the callee:
	//
	//  (1) pops the callee's activation record (temporary area) off the stack
	//  
	//  (2) restores the callee-saved registers, including the activation record of the caller (%ebp)	 
	//
	//  (3) jumps to the return address (using the x86 "ret" instruction, this automatically pops the 
	//	  return address of the stack. After the ret, remove the arguments from the stack
	//
	//	For more info on this convention, see http://unixwiz.net/techtips/win32-callconv-asm.html
	//
	//	This convention is called __cdecl
	//
	//////////////////////////////////////////////////////////////////////////////
  
  void emit_prologue(SymName *name, unsigned int size_locals, unsigned int num_args)
  {
    // WRITEME
  }

  void emit_epilogue()
  {
    // WRITEME
  }
  
  // HERE: more functions to emit code

////////////////////////////////////////////////////////////////////////////////

public:
  
  Codegen(FILE * outputfile, SymTab * st)
  {
	m_outputfile = outputfile;
	m_st = st;
	
	label_count = 0;
  }
  
  void visitProgram(Program * p)
  {
    set_text_mode();
    // WRITEME
  }
  void visitFunc(Func * p)
  {
    // WRITEME
  }
  void visitFunction_block(Function_block * p)
  {
    // WRITEME
  }
  void visitNested_block(Nested_block * p)
  {
    // WRITEME
  }
  void visitAssignment(Assignment * p)
  {
    // WRITEME
  }
  void visitArrayAssignment(ArrayAssignment * p)
  {
    // WRITEME
  }
  void visitCall(Call * p)
  {
    // WRITEME
  }
  void visitArrayCall(ArrayCall *p)
  {
    // WRITEME
  }
  void visitReturn(Return * p)
  {
    // WRITEME
  }

  // control flow
  void visitIfNoElse(IfNoElse * p)
  {// WRITEME
    
  }
  void visitIfWithElse(IfWithElse * p)
  {
    // WRITEME
  }
  void visitForLoop(ForLoop * p)
  {
    // WRITEME
  }

  
  void visitNone(None *p)
  {
    // Nothing is emitted
  }
  
  // variable declarations (no code generation needed)
  void visitDecl(Decl * p)
  {
  }
  void visitParam(Param *p)
  {
  }
  
  // types (no code generation needed)
  void visitTInteger(TInteger * p)
  {
  }
  void visitTBoolean(TBoolean * p)
  {
  }
  void visitTIntArray(TIntArray * p)
  {
  }

  // comparison operations
  void visitCompare(Compare * p)
  {
    // WRITEME
  }
  void visitNoteq(Noteq * p)
  {
    // WRITEME
  }
  void visitGt(Gt * p)
  {
    // WRITEME
  }
  void visitGteq(Gteq * p)
  {
    // WRITEME
  }
  void visitLt(Lt * p)
  {
    // WRITEME
  }
  void visitLteq(Lteq * p)
  {
    // WRITEME
  }

  // arithmetic and logic operations
  void visitAnd(And * p)
  {
     fprintf( m_outputfile, "#### AND\n");
     if (p -> m_attribute.m_lattice_elem != TOP) {
         fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
         return;
     }

     p -> visit_children(this);

     fprintf( m_outputfile, " popl %%ebx\n");
     fprintf( m_outputfile, " popl %%eax\n");
     fprintf( m_outputfile, " andl %%ebx, %%eax\n");
     fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitOr(Or * p)
  {
    fprintf( m_outputfile, "#### OR\n");
     if (p -> m_attribute.m_lattice_elem != TOP) {
         fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
         return;
     }

     p -> visit_children(this);

     fprintf( m_outputfile, " popl %%ebx\n");
     fprintf( m_outputfile, " popl %%eax\n");
     fprintf( m_outputfile, " orl %%ebx, %%eax\n");
     fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitMinus(Minus * p)
  {
   fprintf( m_outputfile, "#### MINUS\n");
   if (p -> m_attribute.m_lattice_elem != TOP) {
       fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
       return;
   }

   p -> visit_children(this);

    fprintf( m_outputfile, " popl %%ebx\n");
    fprintf( m_outputfile, " popl %%eax\n");
    fprintf( m_outputfile, " subl %%ebx, %%eax\n");
    fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitPlus(Plus * p)
  {
     fprintf( m_outputfile, "#### PLUS\n");
     if (p -> m_attribute.m_lattice_elem != TOP) {
         fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
         return;
     }

     p -> visit_children(this);

     fprintf( m_outputfile, " popl %%ebx\n");
     fprintf( m_outputfile, " popl %%eax\n");
     fprintf( m_outputfile, " addl %%ebx, %%eax\n");
     fprintf( m_outputfile, " pushl %%eax\n");

  }
  void visitTimes(Times * p)
  {
     fprintf( m_outputfile, "#### TIMES\n");
     if (p -> m_attribute.m_lattice_elem != TOP) {
         fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
         return;
     }

     p -> visit_children(this);

     fprintf( m_outputfile, " popl %%ebx\n");
     fprintf( m_outputfile, " popl %%eax\n");
     fprintf( m_outputfile, " imull %%ebx, %%eax\n");
     fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitDiv(Div * p)
  {
    fprintf( m_outputfile, "#### DIVIDE\n");
    if (p -> m_attribute.m_lattice_elem != TOP) {
         fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
         return;
    }

     p -> visit_children(this);

     fprintf( m_outputfile, " popl %%ebx\n");
     fprintf( m_outputfile, " popl %%eax\n");
     fprintf( m_outputfile, " idivl %%ebx, %%eax\n");
     fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitNot(Not * p)
  {
  fprintf( m_outputfile, "#### NOT\n");
         if (p -> m_attribute.m_lattice_elem != TOP) {
              fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
              return;
         }

          p -> visit_children(this);

          fprintf( m_outputfile, " popl %%eax\n");
          fprintf( m_outputfile, " not  %%eax\n");
          fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitUminus(Uminus * p)
  {
    fprintf( m_outputfile, "#### Uminus\n");
       if (p -> m_attribute.m_lattice_elem != TOP) {
            fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
            return;
       }

        p -> visit_children(this);

        fprintf( m_outputfile, " popl %%eax\n");
        fprintf( m_outputfile, " negl %%eax\n");
        fprintf( m_outputfile, " pushl %%eax\n");
  }
  void visitMagnitude(Magnitude * p)
  {
    fprintf( m_outputfile, "#### Magnitude\n");
           if (p -> m_attribute.m_lattice_elem != TOP) {
                fprintf( m_outputfile, " pushl $%d\n", p -> m_attribute.m_lattice_elem.value);
                return;
           }

            p -> visit_children(this);

//            cdq               // Expand sign of %eax into all of %edx
//             xorl %edx, %eax;
//             subl %edx, %eax;

            fprintf( m_outputfile, " popl %%ebx\n");
            fprintf( m_outputfile, "cdq\n");
            fprintf( m_outputfile, "xor %%ebx, %%eax\n");
            fprintf( m_outputfile, " subl %%eax, %%ebx\n");
            fprintf( m_outputfile, " pushl %%ebx\n");
  }

  // variable and constant access
  void visitIdent(Ident * p)
  {
    // WRITEME
  }
  void visitIntLit(IntLit * p)
  {
    // WRITEME
  }
  void visitBoolLit(BoolLit * p)
  {
    // WRITEME
  }
  void visitArrayAccess(ArrayAccess * p)
  {
    // WRITEME
  }

  // special cases
  void visitSymName(SymName * p)
  {
  }
  void visitPrimitive(Primitive * p)
  {
  }
};

