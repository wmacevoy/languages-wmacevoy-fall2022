# Exam Review Notes

## Computational Models

VonNeumann  (Harvard has a seperate code bus)
-> Where most languages live: Stack (grows in Frames as functions/methods are called, retreats when they return), Heap (garbage pail of information), Global memory (global / static vars live) also for literals/constants.
Neural Network
-> Edges and nodes are weighted graph ordered left to right.  Propegation rule: weight = sigma ( sum ( edge weights * incoming node weights)).   Hard problem is coming up with a good graph, designing and training such graphs is machine learning.

Quantum Computer (Probabilistic Computation)
x = 1 with prob .1, 2 with prob .9, ...
switch (x) {   case 1: case 2: ... }
## Language Types
Functional y=f(x)  (kind of need OO stuff to group things into x's and y's), Imperitive/Procedural (muffin recipe), Logical/constraint (focus on what the results need to be, not how to get them), Object-Oriented (oo groups ideas into "components") these fit better into the natural human model of thought.

## Regular Expressions
Describe sets of strings using a "calculus", starting from elemental sets epsilon (the empty set), a {"a"}.

xy = { s | s = a + b where a is in x and b is in y }
x|y = { s | s in x or s in y }
x{n,m} = like xxxx(n times)|xxxxx(n+ 1 times|...|xxxxxxx(m times)
x+=x{1,infinity}
x*=x{0,inifinty}
x?=x{0,1}

## Grammars

Grammars are like Reg. Exp, in that they describe a set of strings.  They do it as a set
of substitutions (or productions).  These productions also help structure the string.

"strings" are now a sequence of tokens (reserved words, ids, literals, operators, etc.)
In the grammar; tokens are the terminals. 

The non-terminals are typically conceptual components (T for term, BLOCK, program, etc.)  They eventually mean some specific sequence of tokens after enough substitutions in the
grammer.  The tree of substitutions is the parse tree.

tokens(terminals) = { '+', '-', '*', '/', '(', ')', id, num }
non-terminals = { S, E, T, F }
S -> E
E -> E '+' T | E '-' T | T
T -> T '*' F | T '/' F | F
F -> id | num | ( E )


## Compiler / Interpreter Design Basics

bytes -> (utf8) unicode -> (reg ex) tokens -> 
   (recursive descent/shift-reduce parser) parse tree -> "back end"

Ex questions:

Q. Give examples of a functional language (or parts of a language that are functional)

Q. What is problem is best solved procedurally?  When the clearest way to describe something is the steps to produce the outcome.  Since most computers are VonNeumann (procedural) machines, 
the end result has to be procedural so compiler builders and low-level designers are probably
procedural.

Functional - when there are lots of interacting parts, functional approach simplifies understanding
the "state" - since there is no state.  They are also easier to test.

Q. Make a parse tree for 3-5+2 using the grammar ....

Q. Write some algorithm procedurally & functionally.

def fib(k):
  x0 = 0
  x1 = 1
  for i in range(k):
    x2 = x1 + x0
    x0 = x1
    x1 = x2
  return x0

def fib(k):
   return k if k <= 1 else fib(k-1)+fib(k-2)

Q. Why is it important to restrict a language?  How do they interact?  C++ source vs HTML - compatibilty, speed, security.

Q. Whats the difference between pass-by-value and pass-by-reference?

Q. Give an example of an OO pattern that may be helpful in a design.

